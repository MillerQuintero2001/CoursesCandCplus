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

typedef struct node{
    int d;
    struct node* left;
    struct node* right;
}node;

// Typdef to can refer to the structure with a pointer
typedef node *BTREE;

/* Header Prototype-Fuunctions */
void readFile(const char* nameFile);
void printBinaryTree(BTREE root);
BTREE initNode(int data, BTREE leftLeaf, BTREE rightLeaf);
BTREE createBinaryTree(int * arrayData, uint16_t index, uint16_t size);

int main(void){
    return 0;
}

void readFile(const char* nameFile){
    FILE* ptrFile = fopen(nameFile, "r");
    if(ptrFile == NULL){
        perror("Error opening file");
        return;
    }
    else{
        ;   // NOP
    }
    rewind(ptrFile);
    int size;
    if(fscanf(ptrFile,"%d",&size) == 1){
        size = abs(size);
        printf("File read succesfull!\n");
    }
    else{
        perror("Error trying to read the first parameter");
        return;
    }
    int* array = (int*)calloc(size, sizeof(int));
    int tempValue = 0;
    for(uint16_t i = 0; i < size; i++){
        if(fscanf(ptrFile,"%d",&tempValue) == 1){
            *(array+i) = tempValue;
        }
        else{
            *(array+i) = 0;
        }
    }
}


void printBinaryTree(BTREE root){
    if(root != NULL){
        printBinaryTree(root->left);
        printf("%c, ", root->d);
        printBinaryTree(root->right);
    }
    else{
        ;
    }
}

BTREE initNode(int data, BTREE leftLeaf, BTREE rightLeaf){
    BTREE t = malloc(sizeof(BTREE));
    t->d = data;
    t->left = leftLeaf;
    t->right = rightLeaf;
    return t;
}

BTREE createBinaryTree(int* arrayData, uint16_t index, uint16_t size){
    if(index >= size){
        return NULL;
    }
    else{
        return(initNode(arrayData[index], createBinaryTree(arrayData, 2*index+1, size),
         createBinaryTree(arrayData, 2*index+2, size)));
    }
}