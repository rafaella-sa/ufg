typedef struct DataType DataType;
typedef struct BTreeNode BTreeNode;
typedef struct BTree BTree;
typedef struct Result Result;
typedef unsigned int KeyType;

// Create an empty B-Tree:
BTree* BTreeCreate();

// Search for key 'k' in a B-Tree, starting with node 'x':
Result* BTreeSearch(BTreeNode *x, KeyType k);

// Split child y of node x (child y, pointed by index i in x)
void BTreeSplitChild(BTreeNode *x, int i, BTreeNode *y);

void BTreeInsertNonFull(BTreeNode *x, KeyType k);

void BTreeInsert(BTree *T, KeyType k);

void BTreePrint(BTreeNode *T);

void drive();
