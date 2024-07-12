/** 
 * Author: Miller Quintero
 * Date: Jul 11, 2024
 * Title: Week 4 Assigment
 * Program: This program is a solution for the problem 2, creates a structure of 2 numbers to represent a rational number. it use files
*/

#include <stdio.h>      // Library to use standard inputs and outputs
#include <stdint.h>     // Library to use integers defined by bits size
#include <stdlib.h>     // Library to can use the routines malloc and free, as well as pseudo-random generator functions
#include <stdbool.h>    // Library that brings boolean data types

typedef struct{
    long int numerator;
    long int denominator;
}rational;

/* Headers of Proto-type functions */
void readFileAndCalculate(const char* nameFile);
rational addRationals(rational r1, rational r2);
rational subtractRationals(rational r1, rational r2);
rational multiplyRationals(rational r1, rational r2);
rational divideRationals(rational r1, rational r2);


int main(void){
    // Here, we write tha name of the file, if the code and file is on the same directoy, in other case would be necessary specify the path
    readFileAndCalculate("Week4.txt");
    return 0;
}

/** Function that reads the file, saves the data and calculates the sum and average */
void readFileAndCalculate(const char* nameFile){
    FILE* ptrFile = fopen(nameFile, "r");
    rewind(ptrFile);

    int16_t size = 0;
    // Temporary value to save data from the file
    int tempValue = 0;
    // False indicate that the value will be save in the numerator, true indicate denominator
    bool rationalIndicator = false;

    // The first number in the file indicates the size of the array and must be positive
    fscanf(ptrFile,"%hd", &size);
    size = abs(size);
    rational* array = malloc(sizeof(rational)*size);

    uint16_t index = 0;
    // The for cicle is from 0 to less than 2*size, because every rational element is composed of 2 integers
    for(uint16_t i = 0; i < 2*size; i++){
        // If we have a successful read... (Is neccesary that the condition be fscanf() == 1, to avoid incorrect reads)
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
        // In case that the size parameter be greater than the amount of data, we complete with 1
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

    // Here, we initialize the sum as the first rational, because if we initiliaze it as zero, it will anull the sum and average
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