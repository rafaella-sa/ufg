 #include <stdio.h>
 void ordenar(int a, int b, int c){
    if (a < b)
           if (b < c) printf("%4d%4d%4d\n", a, b, c);
           else
               if (a < c) printf("%4d%4d%4d\n", a, c, b);
               else printf("%4d%4d%4d\n", c, a, b);
      else
           if (b < c)
               if (a < c) printf("%4d%4d%4d\n", b, a, c);
               else printf("%4d%4d%4d\n", b, c, a);
           else printf("%4d%4d%4d\n", c ,b, a);

 }
 int main(void){
        int a, b, c, i, cont;
        scanf("%d", &cont);
        for(i = 1; i <= cont; i++){
       scanf("%d", &a);
       scanf("%d", &b);
       scanf("%d", &c);
       ordenar(a, b, c);
        }
       return 0;
  }
