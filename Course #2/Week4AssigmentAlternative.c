/** 
 * Author: Miller Quintero
 * Date: Oct 16, 2024
 * Title: Week 4 Assigment Alternative
 * Program: This program is a solution for the problem 1, read a file with integers and compute its average and max value
*/
#include <stdio.h>      // Library for standard input and output
#include <stdint.h>     // Library for fixed-width integer types
#include <stdlib.h>     // Library for memory allocation and open files
#include <stdbool.h>    // Library for boolean data types
#include <time.h>       // Library to use current time as seed generator
#include <math.h>       // Library with basic math functions
#include <errno.h>      // Library to can access and use 'errno' variable for 'perror' function

#define MAX_VALUE       10
#define RANDOM          (int8_t)((rand()%MAX_VALUE) + 1)


/* Function prototypes */
void generateFileWithIntegers(const char* newFileName);
void readFileAndCalculate(const char* nameFile);

/** Main funciton */
int main(void){
    // Pseudo-random seed generator
    srand(time(NULL));

    // Receiving the name of the new file
    printf("Type the name you want for the file: ");
    uint8_t index = 0;
    char bufferName[64] = {0};
    char input = 0;
    uint8_t howMany = sizeof(bufferName)/sizeof(char);
    while((input != '\n')&&((index -1) < howMany)){
        input = (char)getchar();
        *(bufferName + index++) = input;
    }
    // Set the last character as null character to have a correct string
    *(bufferName + index - 1) = '\0';
    // Generating a file with random integers 
    generateFileWithIntegers(bufferName);

    // Specify the name of the file. If the code and file are in the same directory, this is sufficient. Otherwise, specify the path
    readFileAndCalculate(bufferName);

    return 0;
}

void generateFileWithIntegers(const char* newFileName){
    FILE* ptrFile = fopen(newFileName, "w");
    if(ptrFile == NULL){
        perror("Error opening file");
        return;
    }
    rewind(ptrFile);

    // Writing the numbers in the archive
    for(uint8_t i = 0; i <= MAX_VALUE; i++){
        fprintf(ptrFile,"%hhd ", RANDOM*(int8_t)pow(-1.0, RANDOM));
    }
    fclose(ptrFile);
}

/** Function that reads the file, saves the data and calculates the sum and average */
void readFileAndCalculate(const char* nameFile){
    FILE* ptrFile = fopen(nameFile, "r");
    if(ptrFile == NULL){
        perror("Error opening file");
        return;
    }
    rewind(ptrFile);

    int8_t size = 0;
    // Temporary value to save data from the file
    int tempValue = 0;

    // The first number in the file indicates the size of the array and must be positive
    fscanf(ptrFile,"%hhd", &size);
    size = abs(size);
    int8_t *array = (int8_t*)malloc(sizeof(int8_t)*size);

    uint16_t index = 0;
    // The for loop runs from 0 to size
    for(uint16_t i = 0; i < size; i++){
        // If we have a successful read... (It is neccesary that the condition be fscanf() == 1, to avoid incorrect reads)
        if(fscanf(ptrFile,"%d",&tempValue) == 1){
            *(array+index)= tempValue;
            index++;
        }
        // Otherwise, the data readed isn't a number
        else{
            // Use this function moves one character forward to ignore no numeric characters
            fgetc(ptrFile);
        }
    }
    fclose(ptrFile);

    // Initialize the sum as the first element's value, because if we initiliaze it as zero, it will nullify the sum and average
    double sum = (double)(*array);
    int8_t max = (*array);
    // And sum with the rest of rationals
    for(uint16_t j = 1; j < size-1; j++){
        sum += *(array+j);
        if(*(array+j) > max){
            max = *(array+j);
        }
        else{
            ;       // NOP
        }
    }

    FILE* ptrOutFile = fopen("answer-hw3", "w");
        if(ptrOutFile == NULL){
        perror("Error opening file");
        return;
    }
    rewind(ptrOutFile);

    // Printing
    printf("The average is %f.\n", sum/(double)size);
    printf("The maximum value is %hhd.\n", max);
    fprintf(ptrOutFile,"The average is %f.\n", sum/(double)size);
    fprintf(ptrOutFile,"The maximum value is %hhd.\n", max);

    fclose(ptrOutFile);
    free(array);
}