/** 
 * Author: Miller Quintero
 * Date: Oct 11, 2024
 * Title: Introduction to I/O File Upgrade
 * Program: This programs introduces us to the manage of files with functions of stdio, example with
 * grades from 0 to 100, this version is an upgrade, using reallocation of dynamically allocated memory
*/

#include <stdio.h>      // Library to use standard inputs and outputs
#include <stdint.h>     // Library to use integers defined by bits size
#include <stdlib.h>     // Library to can use the routines malloc and free, as well as pseudo-random generator functions
#include <stdbool.h>    // Library that brings boolean data types

/* Headers-Prototype Functions */
void readFile(FILE* filePtr, uint8_t** array, uint16_t* size);
void printData(uint8_t* array, uint16_t size);
float average(uint8_t* array, uint16_t size);

int main(void){
    /* There is something important, if the file is in the same directory isn't necessary specify the path
    but, if the file isn't in the same direcoty of the code, will be necesarry indicate the exactly path.
    Finally, is also important indicate the file's extension (if the extension is on file name) */
    FILE* ptrFile = fopen("Grades.txt", "r");
    if(ptrFile == NULL){
        perror("Error opening the file.\n");
        return 1;
    }
    else{
        ;       // NOP action
    }

    /* At the moment of declare a pointer data type (an array of that type of data), if we don't use the notation of [],
    will be necessary use malloc or calloc (a malloc function with 0 initialization by default) to assign heap memory, but
    this is assuming a correct maximum size or quantity of the amount of grades in the file, if the size isn't correct,
    information will be lost or error are gonna be getting. For that reason, we could first counter the elements and after
    use calloc with the size, to finally re-enter into the file to save the grades. Or the finally used alternative is 
    initialize a simple data pointer as NULL, and with a function's reference call to the pointer, use 'realloc' for reallocation
    of dynamically allocated memory, with this, the number of entries to the file is only one */

    // Is so important initialize the pointer as NULL to avoid segmentation faults in realloc first call
    uint8_t* grades = NULL;
    uint16_t size;
    readFile(ptrFile, &grades, &size);
    printf("The amount of data in the file is: %u\n", size);
    printData(grades, size);
    printf("\nThe grades average is: %.3f.\n", average(grades, size));
    
    free(grades);
    return 0;
}

/** Function that reads the file and extract the data to save it inside of an array */
void readFile(FILE* filePtr, uint8_t** array, uint16_t* size){
    *size = 0; 
    uint8_t value = 0;
    // Rewind the file pointer, to make sure that we read from the beginning
    rewind(filePtr);
    int status;
    /* Here is so important use the correct format specifier to identify the number.
    Is necessary iterate until the end of the file to catch every note */
    while((status = fscanf(filePtr, "%hhu", &value)) != EOF){
        // Here we use the 'status' variable to know if the element read is a number
        if(status == 1){
            uint8_t* temp = (uint8_t*)realloc(*array, (*size+1)*sizeof(uint8_t));
            // Control of memory errors
            if(temp == NULL){
                perror("Error resizing memory.\n");
                free(*array); 
                fclose(filePtr);
            }
            // Save values
            else{
                *array = temp;
                *((*array) + *size) = value;
                (*size)++;
            }
        }
        // Otherwise, the data readed isn't a number
        else{
            // Use this function moves one character forward to ignore no numeric characters
            fgetc(filePtr);
        }  
    }
    fclose(filePtr);
}

/** Function resposible of print the array data */
void printData(uint8_t* array, uint16_t size){
    for(uint8_t i = 1; i <= size; i++){
        printf("%3hu\t", *(array+i-1));
        if(i%5==0){
            printf("\n");
        }
        else{
            ;   // NOP action
        }
    }
}

/** Function to calculate the average of an array with specified size */
float average(uint8_t* array, uint16_t size){
    uint16_t sum = 0;
    for(uint8_t i = 0; i < size; i++){
        sum += *(array+i);
    }
    return ((float)sum/(float)size);
}