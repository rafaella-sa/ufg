#include <stdio.h>
void main(){
    int i;
    float H = 0;
    for (i = 1; i <= 50; i++){
        H = H + ((2*i)-1)/i;
        printf("%d/%d\n",((2*i)-1),i);
    }
    printf("%f\n", H);
}

