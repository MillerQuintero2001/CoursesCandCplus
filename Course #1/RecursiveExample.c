/** 
 * Author: Miller Quintero
 * Date: Jul 17, 2023
 * Program: This code allows us to observe the differences between a 
 * recursive solution method and a more orthodox method for factorials.
*/

#include <stdio.h>
#include <stdint.h>

/* Functions proto-types definitions */
uint64_t factorial(uint8_t n);
uint64_t factorial_recursive(uint8_t n);

/** Main function */
int main(void){
    uint8_t how_many = 0;
    do {
        printf("Up to which factorial from 0 to 20 do you want to print? ");
        scanf("%hhu", &how_many);
    } while (how_many > 20);
    
    printf("\n%d Factorials list \n", how_many);
    for(uint8_t i = 0; i<=how_many; i++){
        printf("\n%d\t%lu\n", i, factorial(i));
    }
    printf("\n\n");
    for(uint8_t i = 0; i<=how_many; i++){
        printf("\n%d\t%lu\n", i, factorial_recursive(i));
    }
    printf("\n\n");
    return 0;
}

uint64_t factorial(uint8_t n){
    uint64_t f = 1;
    uint8_t i = 0;
    for(i = 1; i<= n; i++){
        f = f*i;
    }
    return f;
}

uint64_t factorial_recursive(uint8_t n){
    if(n == 1 || n == 0){
        return 1;
    }
    else{
        return (factorial_recursive(n-1))*n;
    }
}