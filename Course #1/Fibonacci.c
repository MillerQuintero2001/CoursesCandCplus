/** 
 * Author: Miller Quintero
 * Date: Jul 17, 2023
 * Program: This code allow us obtain a "n" terms of Fibonacci Series, using for a side
 * an iterative function, and for the other side recursive function.
*/

#include <stdio.h>
#include <stdint.h>

uint64_t fibonacci(uint16_t);
uint64_t fibonacci_recursive(uint16_t);

int main(void){
    uint16_t term;
    printf("Up to which n-th term of the Fibonacci series do you want to print? ");
    scanf("%hu", &term);
    
    printf("\nWith iterative function \n");
    for(uint16_t j = 0; j < term; j++){
        printf("#%hu Term:\t%lu\n", j+1, fibonacci(j));
    }

    printf("With recursive function \n");
    for(uint16_t j = 0; j < term; j++){
        printf("#%hu Term:\t%lu\n", j+1, fibonacci_recursive(j));
    }
    return 0;
}


uint64_t fibonacci(uint16_t n){
    if(n <= 2){if(n == 2){return 1;}else{return n;}}
    else{
        uint64_t f1 = 1;
        uint64_t f2 = 0;
        uint64_t f_old = 0;
        uint16_t i;
        for(i = 0; i < n; i++){
            f_old = f2;
            f2 = f1 + f2;
            f1 = f_old;
        }
        return f2;
    }
}

uint64_t fibonacci_recursive(uint16_t n){
    if(n <= 1){return n;}
    else{
        return (fibonacci_recursive(n-1) + fibonacci_recursive(n-2));
    }
}