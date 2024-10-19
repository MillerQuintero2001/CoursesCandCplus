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

#define MAX_VALUE_FIRST         10
#define MAX_VALUE               50
#define MAX_ELEMENTS            2*MAX_VALUE_FIRST

typedef struct{
    int64_t numerator;
    int64_t denominator;
}rational;

/* Function prototypes */
void generateFileWithIntegers(const char* newFileName);
void readFileAndCalculate(const char* nameFile);
rational addRationals(rational r1, rational r2);
rational subtractRationals(rational r1, rational r2);
rational multiplyRationals(rational r1, rational r2);
rational divideRationals(rational r1, rational r2);
int64_t getGCD(int64_t a, int64_t b);
rational simplifyFraction(rational r);

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

/** Function that generate a file with random integers */
void generateFileWithIntegers(const char* newFileName){
    FILE* ptrFile = fopen(newFileName, "w");
    if(ptrFile == NULL){
        perror("Error opening file");
        return;
    }
    rewind(ptrFile);

    int8_t numberOfData = (int8_t)(((rand()%MAX_VALUE_FIRST) + 1)*pow(-1.0, rand()));
    // First value that indicates number of elements to read
    fprintf(ptrFile,"%hhd ", numberOfData);
    // Writing the other numbers in the archive (should be 2*numberOfData because each rational needs 2 numbers)
    for(uint8_t i = 0; i < 2*abs(numberOfData); i++){
        fprintf(ptrFile,"%hhd ", (int8_t)(((rand()%MAX_VALUE) + 1)*pow(-1.0, rand())));
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
    int8_t tempValue = 0;
    // False indicate that the value will be save in the numerator, true indicate denominator
    bool rationalIndicator = false;

    // The first number in the file indicates the size of the array and must be positive
    fscanf(ptrFile,"%hhd", &size);
    size = abs(size);
    rational* array = (rational*)malloc(sizeof(rational)*size);

    uint8_t index = 0;
    // The for loop runs from 0 to less than 2*size, because each rational element is composed of 2 integers
    for(uint8_t i = 0; i < 2*size; i++){
        // If we have a successful read... (It is neccesary that the condition be fscanf() == 1, to avoid incorrect reads)
        if(fscanf(ptrFile,"%hhd",&tempValue) == 1){
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
    for(uint8_t j = 0; j < size-1; j++){
        sum = addRationals(sum, *(array+(j+1)));
    }

    printf("The sum of all rationals is: %ld/%ld\n", sum.numerator, sum.denominator);
    rational fractionSimple = simplifyFraction(sum);
    printf("The sum of all rationals simplified is: %ld/%ld\n", fractionSimple.numerator, fractionSimple.denominator);
    printf("The average as a rational (fraction) is: %ld/%ld\n", sum.numerator, sum.denominator*size);
    // Update to calculate the average simplified
    fractionSimple.denominator = fractionSimple.denominator*size;
    fractionSimple = simplifyFraction(fractionSimple);
    printf("The average as a rational (fraction simplified) is: %ld/%ld\n", fractionSimple.numerator, fractionSimple.denominator);
    printf("And the average as a float is: %.7f\n", ((float)(fractionSimple.numerator))/((float)(fractionSimple.denominator)));

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

// Function to calculate GCD
int64_t getGCD(int64_t a, int64_t b){
    while (b != 0) {
        int64_t temp = b;
        b = a % b;
        a = temp;
    }
    return (int64_t)abs(a);
}

/** Function so simplify a rational number as fraction */
rational simplifyFraction(rational r){
    // Simplify a lot with GCD
    rational simplified = r;
    int64_t gcd = getGCD(r.numerator,r.denominator);
    simplified.numerator = simplified.numerator/gcd;
    simplified.denominator = simplified.denominator/gcd;

    // End with the simplification using prime numbers
    uint8_t divisors[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 0};
    uint8_t i = 0;   
    while(divisors[i] != 0){
        while ((simplified.numerator % divisors[i] == 0)&&(simplified.denominator % divisors[i] == 0)){
            simplified.numerator = simplified.numerator/divisors[i];
            simplified.denominator = simplified.denominator/divisors[i];
    }
    i++;
    }
    return simplified;
}