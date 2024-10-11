/** 
 * Author: Miller Quintero
 * Date: Jul 20, 2023
 * Program: This code allow us sorting an array of elements, using merge sort method
*/

#include <stdio.h>      // Library to can use standard inputs/outputs
#include <stdint.h>     // Library can define variables with better memory control
#include <stdbool.h>    // Library that allow us define boolean variables
#include <string.h>     // Library with functions to manipulate strings and arrays
#include <stdlib.h>     // Library standard of C with a lot of functions
#include <time.h>       // Library of time, to obtain real time compilation

/* Definition of function prototypes */
void printArray(uint16_t size, uint16_t array[],  char* str);
void swap(uint16_t* i, uint16_t* j);
void bubbleSort(uint16_t size, uint16_t array[]);
void mergeSort(uint16_t sizeSource1, uint16_t sizeSource2, uint16_t sizeDest, uint16_t array1[], uint16_t array2[], uint16_t arrayDest[]);

/** Main function */
int main(void){
    uint16_t size1, size2;
    printf("How many elements do you want in the first array? ");
    while ((scanf("%hu", &size1) != 1)){
        printf("Invalid input for the first array size.\n");
    }

    printf("How many elements do you want in the second array? ");
    while ((scanf("%hu", &size2) != 1)){
        printf("Invalid input for the second array size.\n");
    }
    uint16_t grades1[size1];
    uint16_t grades2[size2];
    uint16_t grades[size1 + size2];
    // Pseudo-random seed generator
    srand(time(NULL));
    // Fill grades array with pseudo-random integers
    for(uint16_t i = 0; i < size1 + size2; i++){
        grades[i] = (uint16_t)abs(rand()%100 + 1);
    }
    /* Split the array in two halfs, memcpy function is going to be used, that allows
    take a source array and copy elements from it to a destiny source, specifing the
    pointers, and with the size in memory that the destiny array will
    have, the array length will be assign at the same time */
    memcpy(grades1, grades, size1*sizeof(uint16_t)); 
    memcpy(grades2, grades + size1, size2*sizeof(uint16_t)); 
    // Before send the 2 list to the merge sort function, is necessary sort it with bubble sort function
    bubbleSort(size1, grades1);
    bubbleSort(size2, grades2);

    // Now, it's time to apply merge sort algorithm
    mergeSort(size1, size2, size1+size2, grades1, grades2, grades);
    printArray(size1+size2, grades, "My sort grades are:\n");
    return 0;
}

void printArray(uint16_t size, uint16_t array[], char* str){
    printf("%s", str);
    for(uint16_t j = 0; j < size; j++){
        printf("%hu\t", array[j]);
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

void mergeSort(uint16_t sizeSource1, uint16_t sizeSource2, uint16_t sizeDest, uint16_t array1[], uint16_t array2[], uint16_t arrayDest[]){
    uint16_t i = 0, j = 0, k = 0;
    while((i < sizeSource1) && (j < sizeSource2)){
        /* Here we are using the ternary operator and post-increment. First check the condition, 
        then do the assignment, and finllay plus 1 to the corresponding counter index */
        arrayDest[k++] = (array1[i] < array2[j]) ? (array1[i++]):(array2[j++]);
    }
    while(i < sizeSource1){
        arrayDest[k++] = array1[i++];
    }
    while(j < sizeSource2){
        arrayDest[k++] = array2[j++];
    }
}