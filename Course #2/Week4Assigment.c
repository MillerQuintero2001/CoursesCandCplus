/** 
 * Author: Miller Quintero
 * Date: Jul 11, 2024
 * Title: Week 4 Assigment
 * Program: This program is a solution for the problem 2, creates a structure of 2 numbers to represent a rational number. It use files
*/

#include <stdio.h>      // Library for standard input and output
#include <stdint.h>     // Library for fixed-width integer types
#include <stdlib.h>     // Library for memory allocation and open files
#include <stdbool.h>    // Library for boolean data types
#include <time.h>       // Library to use current time as seed generator
#include <math.h>       // Library with basic math functions
#include <errno.h>      // Library to can access and use 'errno' variable for 'perror' function

#define MAX_VALUE       10
#define MAX_ELEMENTS    2*MAX_VALUE
#define RANDOM          (int8_t)((rand()%MAX_VALUE) + 1)

typedef struct{
    long int numerator;
    long int denominator;
}rational;

/* Function prototypes */
void generateFileWithIntegers(const char* newFileName);
void readFileAndCalculate(const char* nameFile);
rational addRationals(rational r1, rational r2);
rational subtractRationals(rational r1, rational r2);
rational multiplyRationals(rational r1, rational r2);
rational divideRationals(rational r1, rational r2);

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
    for(uint8_t i = 0; i <= MAX_ELEMENTS; i++){
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
    // False indicate that the value will be save in the numerator, true indicate denominator
    bool rationalIndicator = false;

    // The first number in the file indicates the size of the array and must be positive
    fscanf(ptrFile,"%hhd", &size);
    size = abs(size);
    rational* array = (rational*)malloc(sizeof(rational)*size);

    uint16_t index = 0;
    // The for loop runs from 0 to less than 2*size, because each rational element is composed of 2 integers
    for(uint16_t i = 0; i < 2*size; i++){
        // If we have a successful read... (It is neccesary that the condition be fscanf() == 1, to avoid incorrect reads)
        if(fscanf(ptrFile,"%d",&tempValue) == 1){
            if(!rationalIndicator){
                (*(array+index)).numerator = tempValue;
                rationalIndicator = true;
            }
            else{
                // Control in case of a zero
                (*(array+index)).denominator = (tempValue==0)? 1:tempValue;
                rationalIndicator = false;
                index++;
            }
        }
        // In case that the size parameter be greater than the amount of data, complete with 1
        else{
            if(!rationalIndicator){
                (*(array+index)).numerator = 1;
                rationalIndicator = true;
            }
            else{
                (*(array+index)).denominator = 1;
                rationalIndicator = false;
                index++;
            }
        }
    }
    fclose(ptrFile);

    // Initialize the sum as the first rational, because if we initiliaze it as zero, it will nullify the sum and average
    rational sum = *(array);
    // And sum with the rest of rationals
    for(uint16_t j = 0; j < size-1; j++){
        sum = addRationals(sum, *(array+(j+1)));
    }

    printf("The sum of all rationals is: %ld/%ld\n", sum.numerator, sum.denominator);
    printf("The average as a rational (fraction) is: %ld/%ld\n", sum.numerator, sum.denominator*size);
    printf("And the average as a float is: %.7f\n", ((float)(sum.numerator))/((float)(sum.denominator*size)));

    free(array);
}

/** Function to sum 2 rationals */
rational addRationals(rational r1, rational r2){
    rational result;
    result.denominator = r1.denominator * r2.denominator;
    result.numerator = (r1.numerator * r2.denominator) + (r2.numerator * r1.denominator);
    return result;
}

/** Function to subtract 2 rationals */
rational subtractRationals(rational r1, rational r2){
    rational result;
    result.denominator = r1.denominator * r2.denominator;
    result.numerator = (r1.numerator * r2.denominator) - (r2.numerator * r1.denominator);
    return result;
}

/** Function to multiply 2 rationals */
rational multiplyRationals(rational r1, rational r2){
    rational result;
    result.numerator = r1.numerator * r2.numerator;
    result.denominator = r1.denominator * r2.denominator;
    return result;
}

/** Function to divide 2 rationals */
rational divideRationals(rational r1, rational r2){
    rational invertedRational;
    invertedRational.numerator = r2.denominator;
    invertedRational.denominator = r2.numerator;
    return multiplyRationals(r1,invertedRational);
}