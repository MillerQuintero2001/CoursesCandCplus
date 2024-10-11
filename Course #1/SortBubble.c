/** 
 * Author: Miller Quintero
 * Date: Jul 20, 2023
 * Program: This code allow us sorting an array of elements, using bubble sort method
*/

#include <stdio.h>      // Library to can use standard inputs/outputs
#include <stdint.h>     // Library can define variables with better memory control
#include <stdbool.h>    // Library that allow us define boolean variables
#include <stdlib.h>     // Library standard of C with a lot of functions
#include <time.h>       // Library of time, to obtain real time compilation

/* Definition of function prototypes */
void printArray(uint16_t size, uint16_t array[],  char* str);
void swap(uint16_t* i, uint16_t* j);
void bubbleSort(uint16_t size, uint16_t array[]);

/* Macro-definitions */
#define SIZE 100

int main(void){
    clock_t inicio, fin;
    double tiempo = 0.0f;
    uint16_t grades[SIZE];
    int i;
    // Pseudo-random seed generator
    srand(time(NULL)); 
    // Fill grades array with pseudo-random integers
    for(i = 0; i < SIZE; i++){
        grades[i] = (uint16_t)abs(rand()%100 + 1);
    }
    printArray(SIZE, grades, "My grades are: \n");
    printf("\n\n");
    inicio = clock();
    bubbleSort(SIZE, grades);
    fin = clock();
    tiempo = (double)(fin-inicio)/CLOCKS_PER_SEC;
    printArray(SIZE, grades, "My sort grades are: \n");
    printf("The bubble sort time was %.10f seconds \n", tiempo);
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

void bubbleSort(uint16_t size, uint16_t array[]){
    /* Implementation of a flag variable to indicate that the list is 
    already sorted, and therefore no further computing time needs to 
    be spent, this is to maximize effectiveness */
    bool flagSort = false;
    // Counter of times that there is no swap happening
    uint16_t counter = 0;
    for(uint16_t k = 0; k < size; k++){
        for(uint16_t j = size - 1; j > k; j--){
            /* Before any action, if the 'counter' of sorted positions is
            equal to size - k - 1, where k means the analized position, it
            means that the arrray is already sorted, is necessary sustract -1
            to avoid one more no necessay iteration, cause the in the next
            iteration we reach k position in backwards and it's already sorted */
            if(counter >= (size - k - 1)){
                flagSort = true;
                break;
            }
            /* If the value previous to 'j' position is greater
            than 'j' position value, the positions need to be
            swap, to sort the list from minor to greater */
            else if(array[j-1] > array[j]){
                swap(&array[j-1], &array[j]);
            }
            /* Otherwise, sum 1 to the counter, 
            to can control of the sorted list */
            else{
                counter++;
            }
        }
        counter = 0;
        if(flagSort){
            flagSort = false;
            break;
        }
        else{
            continue;
        }
    }
}