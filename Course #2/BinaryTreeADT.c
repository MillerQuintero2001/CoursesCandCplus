/** 
 * Author: Miller Quintero
 * Date: Jun 23, 2024
 * Title: Binary Tree ADT (Abstract Data Type)
 * Program: This programs introduces us to the ADT(Abstract Data Type) binary trees
*/

#include <stdio.h>      // Library to use standard inputs and outputs
#include <stdint.h>     // Library to use integers defined by bits size
#include <stdlib.h>     // Library to can use the routines malloc and free, as well as pseudo-random generator functions
#include <stdbool.h>    // Library that brings boolean data types
#include <time.h>       // Library to use current time as seed generator
#include <math.h>       // Library with basic math functions
#include <assert.h>     // Library for the asserts control program

typedef struct node{
    char d;
    struct node* left;
    struct node* right;
}node;

typedef node *BTREE;

/* Header Prototype-Fuunctions */
void printBinaryTree(BTREE root);
BTREE initNode(char data, BTREE leftLeaf, BTREE rightLeaf);
BTREE createBinaryTree(char * arrayData, uint16_t index, uint16_t size);

int main (void){
    char data[] = {'a', 'b', 'c', 'd', 'e'};
    BTREE b = createBinaryTree(data,0, sizeof(data)/sizeof(char));
    printBinaryTree(b);
    return 0;
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


BTREE initNode(char data, BTREE leftLeaf, BTREE rightLeaf){
    BTREE t = malloc(sizeof(BTREE));
    t->d = data;
    t->left = leftLeaf;
    t->right = rightLeaf;
    return t;
}

BTREE createBinaryTree(char* arrayData, uint16_t index, uint16_t size){
    if(index >= size){
        return NULL;
    }
    else{
        return(initNode(arrayData[index], createBinaryTree(arrayData, 2*index+1, size),
         createBinaryTree(arrayData, 2*index+2, size)));
    }
}