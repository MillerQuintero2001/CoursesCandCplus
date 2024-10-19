/** 
 * Author: Miller Quintero
 * Date: Jul 18, 2024
 * Title: Week 4 Assigment Honors
 * Program: This program reads a file, takes the first number as an indicator 
 * to know how many data read, and put this data in a binary tree and print it
*/

#include <stdio.h>      // Library for standard input and output
#include <stdint.h>     // Library for fixed-width integer types
#include <stdlib.h>     // Library for memory allocation and open files
#include <stdbool.h>    // Library for boolean data types
#include <time.h>       // Library to use current time as seed generator
#include <math.h>       // Library with basic math functions
#include <assert.h>     // Library for the asserts control program
#include <errno.h>      // Library to can access and use 'errno' variable for 'perror' function

#define MAX_ELEMENTS        31
#define MAX_VALUE           99

typedef struct node{
    int8_t d;
    struct node* left;
    struct node* right;
}node;

// Typedef to can refer to the structure with a pointer
typedef node *BTREE;

/* Function prototypes */
void generateFileWithIntegers(const char* newFileName);
void readFile(const char* nameFile, int8_t **ptrArray, uint8_t* howMany);
void printBinaryTree(BTREE root);
BTREE initNode(int8_t data, BTREE leftLeaf, BTREE rightLeaf);
BTREE createBinaryTree(int8_t * arrayData, uint8_t index, uint8_t size);

/** Main function */
int main(void){
    // Pseudo-random seed generator
    srand(time(NULL));

    // Receiving the name of the new file
    printf("Type the name you want for the input file, when it be ready press enter, an archive with random integers will be generated: ");
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

    // Declaration of variables to save the data and the amount of data
    int8_t *ptrData = NULL;
    uint8_t numberOfData = 0;
    readFile(bufferName, &ptrData, &numberOfData);

    // Generate binary tree with the data
    BTREE mainRoot = createBinaryTree(ptrData, 0, numberOfData);
    printf("\nThe binary tree is:\n");
    printBinaryTree(mainRoot);
    return 0;
}

/** Function that generate a file with random integers */
void generateFileWithIntegers(const char* newFileName){
    FILE* ptrFile = fopen(newFileName, "w");
    if(ptrFile == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    else{
        ;       // NOP action
    }
    rewind(ptrFile);

    int8_t numberOfData = (int8_t)(((rand()%MAX_ELEMENTS) + 1)*pow(-1.0, rand()));
    // First value that indicates number of elements to read
    fprintf(ptrFile,"%hhd ", numberOfData);
    // Writing the other numbers in the archive
    for(uint8_t i = 0; i < abs(numberOfData); i++){
        fprintf(ptrFile,"%hhd ", (int8_t)(((rand()%MAX_VALUE) + 1)*pow(-1.0, rand())));
    }
    fclose(ptrFile);
}

/** Function that reads the file and extract the data */
void readFile(const char* nameFile, int8_t **ptrArray, uint8_t* howMany){
    FILE* ptrFile = fopen(nameFile, "r");
    if(ptrFile == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    else{
        ;   // NOP action
    }
    rewind(ptrFile);
    int8_t size;
    if((fscanf(ptrFile,"%hhd",&size) == 1)&&(size != 0)){
        size = abs(size);
        *howMany = size;
        printf("File read succesfull!\n");
    }
    else{
        perror("Error trying to read the first parameter");
        exit(EXIT_FAILURE);
    }

    *ptrArray = (int8_t*)calloc(size, sizeof(int));
    if (*ptrArray == NULL) {
        perror("Error allocating memory");
        fclose(ptrFile);
        exit(EXIT_FAILURE);
    }
    else{
        ;       // NOP action
    }

    for (int8_t i = 0; i < size; i++) {
        if (fscanf(ptrFile, "%hhd", &((*ptrArray)[i])) != 1) {
            printf("Error reading data from file.\n");
            free(*ptrArray);
            fclose(ptrFile);
            exit(EXIT_FAILURE);
        }
    }
    fclose(ptrFile);
}

void printBinaryTree(BTREE root){
    if(root != NULL){
        printBinaryTree(root->left);
        printf("%hhd ", root->d);
        printBinaryTree(root->right);
    }
    else{
        ;
    }
}

BTREE initNode(int8_t data, BTREE leftLeaf, BTREE rightLeaf){
    BTREE t = malloc(sizeof(BTREE));
    t->d = data;
    t->left = leftLeaf;
    t->right = rightLeaf;
    return t;
}

BTREE createBinaryTree(int8_t* arrayData, uint8_t index, uint8_t size){
    if(index >= size){
        return NULL;
    }
    else{
        return(initNode(arrayData[index], createBinaryTree(arrayData, 2*index+1, size),
         createBinaryTree(arrayData, 2*index+2, size)));
    }
}