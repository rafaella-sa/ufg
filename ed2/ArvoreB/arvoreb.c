#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "arvoreb.h"

#define N 100
#define M 4

struct DataType{
  int value;
};

struct BTreeNode{
  short leaf;
  int keyCount;
  KeyType keys[M-1];
  DataType *data[M-1];
  BTreeNode *pointers[M]; // for the time being, the entire B-Tree
                        // is kept in main memory
};

struct BTree{
  BTreeNode* root;
};

struct Result{
  BTreeNode* node;
  int index;
};

// Create an empty B-Tree:
BTree* BTreeCreate(){
  BTree *T = malloc(sizeof(BTree));

  // For the time being, the entire B-Tree is kept in main memory
  //x = ALLOCATE_NODE();
  BTreeNode *x = malloc(sizeof(BTreeNode));

  x->leaf = 1; // True
  x->keyCount = 0;

  // For the time being, the entire B-Tree is kept in main memory
  //DISK_WRITE(x);

  T->root = x;
  return T;
}

// Search for key 'k' in a B-Tree, starting with node 'x':
Result* BTreeSearch(BTreeNode *x, KeyType k){
  int i = 0;
  while (i < x->keyCount && k > x->keys[i])
    i++;
  if (i < x->keyCount && k == x->keys[i]){
    Result *result = malloc(sizeof (Result));
    result->node = x;
    result->index = i;
    return result;
  }
  if (x->leaf) return NULL;
  else {
    // Note:
    // For the time being, we keep the entire B-Tree in main memory!
    //
    //DISK_READ(x->pointers[i]);

    return BTreeSearch(x->pointers[i], k);
  }
}

// Split child y of node x (child y, pointed by index i in x)
void BTreeSplitChild(BTreeNode *x, int i, BTreeNode *y){
  //BTreeNode z = ALLOCATE_NODE();
  BTreeNode *z = malloc(sizeof(BTreeNode));
  z->leaf = y->leaf;
  z->keyCount = M/2 - 1;
  int j;
  for (j = 0; j < M/2-1; j++){
    z->keys[j] = y->keys[j+(M/2)]; // copy the 2nd half of keys from y to z
    z->data[j] = y->data[j+(M/2)]; // copy the 2nd half of data pointers
  }

  if (!y->leaf)
    for (j = 0; j < M/2; j++)
      z->pointers[j] = y->pointers[M/2 + j]; // copy 2nd half of child pointers

  y->keyCount = M/2 - 1;

  for (j = x->keyCount; j >= i+1; j--)
    x->pointers[j+1] = x->pointers[j];
  x->pointers[i+1] = z;

  for (j = x->keyCount-1; j>=i; j--){
    x->keys[j+1] = x->keys[j];
    x->data[j+1] = x->data[j];
  }
  x->keys[i] = y->keys[M/2];
  x->data[i] = y->data[M/2];

  x->keyCount++;

  // You're going to implement this later
  //DISK_WRITE(Y,Z,X);
}

void BTreeInsertNonFull(BTreeNode *x, KeyType k){
  int i = x->keyCount-1;
  if (x->leaf){
    while (i >= 0 && k < x->keys[i]){
      x->keys[i+1] = x->keys[i];
      i--;
    }
    x->keys[i+1] = k;
    x->keyCount++;
    //Note: for the moment, B-Tree will be kept in main memory
    //DISK_WRITE(x);

  } else{
    while (i >= 0 && k < x->keys[i]) i--;
    i++;

    // Note: for the moment, B-Tree will be kept in main memory
    //DISK_READ(x.pointers[i]);

    if (x->pointers[i]->keyCount == M - 1){
      BTreeSplitChild(x, i, x->pointers[i]);
      if (k > x->keys[i])
	i++;
      BTreeInsertNonFull(x->pointers[i], k);
    }
    }
}

void BTreeInsert(BTree *T, KeyType k){
  BTreeNode *r = T->root;
  BTreeNode *s;
  if (r->keyCount == M-1){
    //s = ALLOCATE_NODE();
    s = (BTreeNode*) malloc(sizeof(BTreeNode));

    T->root = s;
    s->leaf = 0;
    s->keyCount = 0;
    s->pointers[0] = r;
    BTreeSplitChild(s, 1, r);
    BTreeInsertNonFull(s, k);
  } else
    BTreeInsertNonFull(r, k);
}

void BTreePrint(BTreeNode *T){
    int i;
    if(T == NULL){
        printf("Arvore vazia!\n");
        return;
    }
    for(i = 0; i < T->keyCount; i++){
        BTreePrint(T->pointers[i]);
        printf("%d ", T->keys[i]);
        printf("\n");
    }
    BTreePrint(T->pointers[i]);
}

void drive(){
    BTree *T;
    T = BTreeCreate();
    char option = 's';
    printf("Teste de arvore B\n\n");
    do{
        printf("Deseja inserir um elemento? (S)im / (N)ao\n");
        scanf("%c", &option);
        if(option == 's' || option == 'S'){
            int chave;
            printf("Digite a chave:\n");
            scanf("%d", &chave);
            BTreeInsert(T, chave);
            printf("Chave inserida com sucesso!\n");
        }
    }while(option == 's' || option == 'S');
    printf("Arvore B gerada:\n\n");
    BTreePrint(T->root);
    option = 's';
    do{
        printf("Deseja pesquisar por um elemento? (S)im / (N)ao\n");
        scanf("%c", &option);
        if(option == 's' || option == 'S'){
            int chave;
            printf("Digite a chave:\n");
            scanf("%d", &chave);
            Result* result = BTreeSearch(T->root, chave);
            if(result == NULL)
                printf("Chave nao encontrada!\n");
            else
                printf("Chave encontrada!\nIndice: %d\n", result->index);
        }
    }while(option == 's' || option == 'S');
}
