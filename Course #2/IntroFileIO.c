/** 
 * Author: Miller Quintero
 * Date: Jun 26, 2024
 * Title: Introduction to I/O File
 * Program: This programs introduces us to the manage of files with functions of stdio, example with grades from 0 to 100
*/

#include <stdio.h>      // Library to use standard inputs and outputs
#include <stdint.h>     // Library to use integers defined by bits size
#include <stdlib.h>     // Library to can use the routines malloc and free, as well as pseudo-random generator functions
#include <stdbool.h>    // Library that brings boolean data types

/* Headers-Prototype Functions */
void readFile(FILE* filePtr, uint8_t* array, uint32_t* size);
void printData(uint8_t* array, uint32_t size);
float average(uint8_t* array, uint32_t size);

int main(void){
    /* There is something important, if the file is in the same directory isn't necessary specify the path
    but, if the file isn't in the same direcoty of the code, will be necesarry indicate the exactly path.
    Finally, is also important indicate the file's extension */
    FILE* ptrFile = fopen("Grades.txt", "r");

    /* At the moment of declare a pointer data type (an array of that type of data), if we don't use the notation of [],
    will be necessary use malloc or calloc (a malloc function with 0 initialization by default) to assign heap memory */
    uint8_t* grades = calloc(8,sizeof(uint8_t));
    uint32_t size;
    readFile(ptrFile, grades, &size);
    printf("The amount of data in the file is: %u\n", size);
    printData(grades, size);
    printf("\nThe grades average is: %.3f.\n", average(grades, size));
    
    free(grades);
    return 0;
}

/** Function that reads the file and extract the data to save it inside of an array */
void readFile(FILE* filePtr, uint8_t* array, uint32_t* size){
    *size = 0; 
    uint8_t value = 0;
    // We rewind the file pointer, to make sure that we read from the beginning
    rewind(filePtr);
    // Here is so important use the correct format specifier
    while(fscanf(filePtr, "%hhu", &value) == 1){
        *(array+*size) = value;
        (*size)++;
    }
    fclose(filePtr);
}

/** Function resposible of print the array data */
void printData(uint8_t* array, uint32_t size){
    for(uint8_t i = 1; i <= size; i++){
        printf("%3hu\t", *(array+i-1));
        if(i%5==0){
            printf("\n");
        }
        else{
            ;
        }
    }
}

/** Function to calculate the average of an array with specified size */
float average(uint8_t* array, uint32_t size){
    uint16_t sum = 0;
    for(uint8_t i = 0; i < size; i++){
        sum += *(array+i);
    }
    return ((float)sum/(float)size);
}