/** 
 * Author: Miller Quintero
 * Date: Jun 27, 2024
 * Title: Double Spacing in Files
 * Program: This programs introduces us to the use of the main arguments, argc and argv[] to can execute a program with a command line
*/

#include <stdio.h>      // Library to use standard inputs and outputs
#include <stdint.h>     // Library to use integers defined by bits size
#include <stdlib.h>     // Library to can use the routines malloc, calloc, free, rewind, rand, exit, etc...
#include <stdbool.h>    // Library that brings boolean data types


/* Headers-Prototype Functions */
void readFile(FILE* filePtr, uint8_t** array, uint16_t* size);
void doubleSpacing(FILE* fileInPtr, FILE* fileOutPtr);
void printFile(FILE* filePtr);
void printData(uint8_t* array, uint16_t size);
float average(uint8_t* array, uint16_t size);

int main(int argc, char* argv[]){

    /* Control of the correct 3 arguments, the name of the compiled program, string of the input file and finally 
    the string of the output file, is SO IMPORTANT DO THIS CONTROL to stop the execution of command errors */
    if(argc != 3){
        printf("Need executable, input and output files.\n");
        // Use of exit program function from stdlib
        exit(1);
    }

    /* There is something important, if the file is in the same directory isn't necessary specify the path
    but, if the file isn't in the same directory code, will be necesarry indicate the exactly path.
    Finally, is also important indicate the file's extension */
    // Is necessary read and more permissions for the first file
    FILE* ptrFileIn = fopen(argv[1], "r+");
    if(ptrFileIn == NULL){
        perror("Error opening the file.\n");
        return 1;
    }
    else{
        ;       // NOP action
    }
    // The second file need write and more permissions, cause first we write into it, and after we read data from it
    FILE* ptrFileOut = fopen(argv[2], "w+");
    if(ptrFileOut == NULL){
        perror("Error opening the file.\n");
        return 1;
    }
    else{
        ;       // NOP action
    }

    /* NOTE: Although r+ and w+ give the same permissions (read and write), w+ create the file if it doesn't exist, or 
    if it exist, the content is delete */

    printf("My file %s as read is:\n", argv[1]);
    printFile(ptrFileIn);

    // Apply Double Space function and after, close the input file because t'is not going to be use in the rest of the program
    doubleSpacing(ptrFileIn, ptrFileOut);
    fclose(ptrFileIn);

    printf("And my file %s double spaced is:\n", argv[2]);
    printFile(ptrFileOut);

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
    readFile(ptrFileOut, &grades, &size);
    printf("The amount of data in the file is: %u\n", size);
    printData(grades,size);
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
            ;   // NOP action
        }
    }
}

/** Function that prints any file char by char */
void printFile(FILE* filePtr){
    int c;
    // Rewind to make it sure
    rewind(filePtr);
    while((c = getc(filePtr)) != EOF){
        putchar(c);
    }
    putchar('\n');
}

/** Function resposible of print the array data */
void printData(uint8_t* array, uint16_t size){
    for(uint8_t i = 1; i <= size; i++){
        printf("%3hu\t", *(array+i-1));
        if(i%5==0){
            printf("\n");
        }
        else{
            ;      // NOP action
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