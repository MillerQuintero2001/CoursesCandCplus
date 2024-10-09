/** 
 * Author: Miller Quintero
 * Date: Jul 19, 2023
 * Program: This code allow us obtain an average of an array grades, using functions,
 * for pointers-arrays purposes
*/

#include <stdio.h>      // Library to can use standard inputs/outputs
#include <stdint.h>     // Library can define variables with better memory control
#include <stdlib.h>     // Library standard of C with a lot of functions
#include <time.h>       // Library of time, to obtain real time compilation

/* Definition of prototypes functions */

double averageGrades(uint16_t quantity, uint8_t* schoolGrades);
void printGrades(uint16_t quantity, uint8_t grades[]);

/* Main-code */
int main(void){
    const uint16_t size = 1000;
    uint8_t grades[size];
    int i;
    // Generator seed of pseudo-random numbers
    srand(time(NULL)); 
    /* Fill array of grades with aleatories numbers between 0 to 100*/
    for(i = 0; i < size; i++){
        grades[i] = (uint8_t)abs(rand()%100);
    }
    printGrades(size,grades);
    printf("The average of the grades is %.4f",averageGrades(size,grades));
    return 0;
}

double averageGrades(uint16_t quantity, uint8_t* schoolGrades){
    double sum = 0;
    for(uint16_t j = 0; j < quantity; j++){
        sum+=*(schoolGrades+j);
    }
    return (sum/quantity);
}

void printGrades(uint16_t quantity, uint8_t grades[]){
    for(uint16_t j = 0; j < quantity; j++){
        printf("%d\t", grades[j]);
        if((j+1)%10 == 0){
            printf("\n");
        }
    }
}