/** 
 * Author: Miller Quintero
 * Date: Jul 21, 2023
 * Program: This code allow us sorting an array of elements, using merge sort method
*/

#include <stdio.h>      // Library to can use standard inputs/outputs
#include <stdint.h>     // Library can define variables with better memory control
#include <stdbool.h>    // Library that allow us define boolean variables
#include <string.h>     // Library with functions to manipulate strings and arrays
#include <stdlib.h>     // Library standard of C with a lot of functions
#include <time.h>       // Library of time, to obtain real time compilation

/* Definition of prototypes functions */
void printArray(uint16_t size, uint16_t array[],  char* str);
void swap(uint16_t* i, uint16_t* j);
void merge(uint16_t size, uint16_t array1[], uint16_t array2[], uint16_t arrayFinal[]);
void mergeSort(uint16_t key[], uint16_t size);

/* Macro-definitions */
#define SIZE 512

int main(void){
    uint16_t grades[SIZE];
    // Pseudo-random seed generator
    srand(time(NULL));
    // Fill grades array with pseudo-random integers
    for(uint16_t i = 0; i < SIZE; i++){
        grades[i] = (uint16_t)abs(rand()%100 + 1);
    }
    /* Application of the new function MergeSort that have the clasic merge 
    function inside itself, now, this version allows work directly with a
    single list without previously split it in 2 already sorted lists */
    mergeSort(grades, SIZE);
    printArray(SIZE, grades, "My sort grades are: \n");
    return 0;
}

void printArray(uint16_t size, uint16_t array[], char* str){
    printf("%s", str);
    for(uint16_t j = 0; j < size; j++){
        printf("%u\t", array[j]);
        if((j+1)%10 == 0){
            printf("\n");
        }
    }
}

void swap(uint16_t* i, uint16_t* j){
    // Temporary variable that copies the value pointed by the pointer 'i'
    uint16_t temp = *i;
    /* Assign pointer 'i' the value pointed by 'j' pointer. To indicate that 
    this is the value, is necessary use dereference operator for both*/
    *i = *j;
    // Assign as value pointed by 'j' pointer, the temporal value saved previously
    *j = temp;
}

void merge(uint16_t size, uint16_t array1[], uint16_t array2[], uint16_t arrayFinal[]){
    uint16_t i = 0, j = 0, k = 0;
    while((i < size) && (j < size)){
        /* Here we are using the ternary operator and post-increment. First check the condition, 
        then do the assignment, and finllay plus 1 to the corresponding counter index */
        arrayFinal[k++] = (array1[i] < array2[j]) ? (array1[i++]):(array2[j++]);
    }
    while(i < size){
        arrayFinal[k++] = array1[i++];
    }
    while(j < size){
        arrayFinal[k++] = array2[j++];
    }
}

/** This function can sort an array, using the merge sort method, this only works with arrays whose size is a power of 2 */
void mergeSort(uint16_t key[], uint16_t size){
    uint16_t j, k;
    uint16_t w[size];
    /* When they are powers of 2, it orders first, the algorithm 
    first sorts 2 by 2, then 4 by 4, and so on. */
    for(k = 1; k < size; k *= 2){
        for(j = 0; j < size - k; j += 2*k){
            merge(k, key + j, key + j + k, w + j);
        }
        // Update of the array, this an important step
        for(j = 0; j < size; j++){
            key[j] = w[j];
        }
    }
}