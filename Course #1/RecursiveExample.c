/** 
 * Author: Miller Quintero
 * Date: Jul 17, 2023
 * Program: This code allows us to observe the differences between a 
 * recursive solution method and a more orthodox method for factorials.
*/

#include <stdio.h>

/* Definición de prototipos de funciones */
long factorial(int n);
long factorial_recursive(int n);

int main(void){
    int how_many = 0, i;
    printf("Up to which factorial do you want to print? ");
    scanf("%d", &how_many);
    printf("\n %d Factorials list \n", how_many);
    for(i = 0; i<=how_many; i++){
        printf("\n%d\t%ld\n", i, factorial(i));
    }
    printf("\n\n");
    for(i = 0; i<=how_many; i++){
        printf("\n%d\t%ld\n", i, factorial_recursive(i));
    }
    printf("\n\n");
    return 0;
}

long factorial(int n){
    long f = 1;
    int i = 0;
    for(i = 1; i<= n; i++){
        f = f*i;
    }
    return f;
}

long factorial_recursive(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    else{
        return (factorial_recursive(n-1))*n;
    }
}