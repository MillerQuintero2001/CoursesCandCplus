/** 
 * Author: Miller Quintero
 * Date: Jun 10, 2024
 * Program: Example of use of different ways of pre-processor commands
*/

#include <stdio.h>      // Library to can control standard inputs and outputs
#include <stdint.h>     // Library to can define varibales with more control, standard integers
#include <stdlib.h>     // Library to can use rand() function
#include <time.h>       // Libreary to use a seed for pseudo-random numbers generator

#define MAX_ELEPHANT_SEAL_WT_MALE   8800
#define MIN_ELEPHANT_SEAL_WT_MALE   4400

#define RANGE       4400
#define POPULATION  1000
#define WEIGHT_OVER rand()%RANGE
#define WEIGHT  WEIGHT_OVER + MIN_ELEPHANT_SEAL_WT_MALE
#define FILL    for( i = 0; i < POPULATION; i++) \
                    data[i] = WEIGHT

/* Proto-types of functions */
void printArray(int* a, int size);

int main(void){
    // Neccesary declaration for the macrodefinition FILL
    int i; 
    // Array init necessary for the FILL macro
    int data[1000] = {0};
    // Generator seed, based on current time, we can use 0 or NULL
    srand(time(0)); 
    // All previous declaration are neccesary with the exact name to make FILL macro works correctly
    FILL;
    printArray(data, POPULATION);
    printf("\n");
    return 0;
}

void printArray(int* a, int size){
    for(int j = 0; j < size; j++){
        printf("%d\t", *(a+j));
        if((j+1)%10 == 0) printf("\n");
    }
}