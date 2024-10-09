/** 
 * Author: Miller Quintero
 * Date: May 6, 2023
 * Program: Program to check some questions about final exam
*/

#include <stdio.h>

/* Functions proto-types declarations */
int function(int num);
int foobar(int * n);
int mystery(int p, int q);

/** Main function */
int main(void){
    int a = 1, b = 2, c = 3;
    printf("b = %d\n", b);
    printf("foobar(b) = %d \n",foobar(&b));
    printf("b = %d \n", b);
    printf("%d yes",function(a));
    printf("\nHELLO\t\tWORLD\n");
    int r = 3%4;
    printf("\n %d \n", r);
    printf("%d\n", mystery(2,7));
    return 0;
    
}

int function(int num){
    double f;
    f = num +1;
    return f;
}
int foobar(int* n){
    *n = *n + 1;
    return *n;
}
int mystery(int p, int q){
    int r;
    if((r = p%q) == 0){
        return q;
    }
    else{return mystery(q,r);}
}