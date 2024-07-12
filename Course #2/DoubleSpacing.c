/** 
 * Author: Miller Quintero
 * Date: Jun 27, 2024
 * Title: Double Spacing in Files
 * Program: This programs introduces us to the use of the main arguments, argc and argv[] to can execute program as command line
*/

#include <stdio.h>      // Library to use standard inputs and outputs
#include <stdint.h>     // Library to use integers defined by bits size
#include <stdlib.h>     // Library to can use the routines malloc, calloc, free, rewind, rand, exit, etc...
#include <stdbool.h>    // Library that brings boolean data types


/* Headers-Prototype Functions */
void readFile(FILE* filePtr, uint8_t* array, uint32_t* size);
void doubleSpacing(FILE* fileInPtr, FILE* fileOutPtr);
void printFile(FILE* filePtr);
void printData(uint8_t* array, uint32_t size);
float average(uint8_t* array, uint32_t size);

int main(int argc, char* argv[]){

    /* Control of the correct 3 arguments, the name of the compiled program, string of the input file and finally 
    the string of the output file, is SO IMPORTANT DO THIS CONTROL to stop the execution of command errors */
    if(argc != 3){
        printf("Need executable, input and output files.\n");
        // Use of exit program function from stdlib
        exit(1);
    }

    /* There is something important, if the file is in the same directory isn't necessary specify the path
    but, if the file isn't in the same direcoty of the code, will be necesarry indicate the exactly path.
    Finally, is also important indicate the file's extension */
    // We need given read and more permissions for the first file
    FILE* ptrFileIn = fopen(argv[1], "r+");
    // The second file need wirte and more permissions, cause first we write into it, and after we read data from it
    FILE* ptrFileOut = fopen(argv[2], "w+");

    /* NOTE: Although r+ and w+ give the same permissions (read and write), w+ create the file if it doesn't exist, or 
    if it exist, the content is destroy */

    printf("My file %s as read is:\n", argv[1]);
    printFile(ptrFileIn);
    printf("\n");

    // Double Space function and after, close the input file because is not going to use in the rest of the program
    doubleSpacing(ptrFileIn, ptrFileOut);
    fclose(ptrFileIn);

    printf("And my file %s double spaced is:\n", argv[2]);
    printFile(ptrFileOut);
    printf("\n");

    /* At the moment of declare a pointer data type (an array of that type of data), if we don't use the notation of [],
    will be necessary use malloc or calloc (a malloc function with 0 initialization by default) to assign heap memory */
    uint8_t* grades = calloc(8,sizeof(uint8_t));
    uint32_t size;
    readFile(ptrFileOut, grades, &size);
    printf("The amount of data in the file is: %u\n", size);
    printData(grades,size);
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

/** Function to copy the info from the input to output file with double space */
void doubleSpacing(FILE* fileInPtr, FILE* fileOutPtr){   
    int c;
    // Rewind to make it sure
    rewind(fileInPtr);
    rewind(fileOutPtr);
    while((c = getc(fileInPtr)) != EOF){
        putc(c, fileOutPtr);
        // Check if the character is a white space to repeat it and do the double space
        if(c == ' '){
            putc(' ', fileOutPtr);
        }
        else{
            ;   // NOP
        }
    }
}

/** Function that prints any file char by char*/
void printFile(FILE* filePtr){
    int c;
    // Rewind to make it sure
    rewind(filePtr);
    while((c = getc(filePtr)) != EOF){
        putc(c, stdout);
    }
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