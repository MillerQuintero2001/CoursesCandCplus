/** 
 * Author: Miller Quintero
 * Date: Jun 13, 2024
 * Program: This programs introduces us to the ADT(Abstract Data Type) lists, this case in one of a single element
*/

#include <stdio.h>      // Library to use standard inputs and outputs
#include <stdint.h>     // Library to use integers defined by bits size
#include <stdlib.h>     // Library to can use the routines malloc and free, as well as pseudo-random generator functions
#include <stdbool.h>    // Library that brings boolean data types
#include <time.h>       // Library to use current time as seed generator
#include <math.h>       // Library with basic math functions

/*  THE MOST IMPORTANT NOTE: The pointers in C have a size according to the system architecture,
    in my case I have a x64 bits computer, for that reason, the pointers with my compiler have
    a size of 8 bytes (1 byte = 8 bits and 8x8=64), now there is an important concept know as 
    padding in C, which says that the compiler in order to have an optimized access and alignment
    to the structure and its data, stuffing the structure with other bytes, for that reason the 
    next structure have an integer of 4 bytes, a pointer of 8 bytes, but has a size of 16 bytes
    because there are 4 padding bytes more to put the pointer aligned. 
*/

typedef struct list{
    int data;
    struct list* next; // To can define a point to the structure itself, is necessary write struct tagName
}list;

/* Header proto-types functions */
void fillArrayData(int* array, uint16_t size);
void printArrayData(int* array, uint16_t size);
void printList(list* ADT, char* title);
list* createList(int d);
list* addList(list* h, int d);
list* arrayToList(uint16_t* array, uint16_t size);
bool isEmpty(const list* l);

int main(void){
    uint16_t size;
    printf("Write how many elements should have the list to convert in ADT, no much more than 65535: ");
    scanf("%hu", &size);
    // Assign dynamic memory for the custom size array
    int* array = malloc(sizeof(int)*size);

    // Pseudo-random seed to generate numbers
    srand(time(NULL));
    // Fill and print the array with the pseudo-random data
    fillArrayData(array, size);
    printArrayData(array,size);

    // Declare and create the pointer to list, with the first array element
    list* head = createList(*(array));
    // Add the rest of the data
    for(uint16_t i = 1; i < size; i++){
        head = addList(head,*(array+i));
    }

    printList(head, "\nThe full list is:");

    /* Let's free the heap memory, isn't really necessary in this case, 
    because always at the end of a program, the system free it automatically */
    free(head);
    free(array);

    return 0;
}

/** Function to fill the array data */
void fillArrayData(int* array, uint16_t size){
    for(uint16_t j = 0; j < size; j++){
        // Module the pseudo-random value, to get something in the correct range of 16 bits
        // The rand function only generates positive integers, for that reason we sum the same sentence to have some negatives
        *(array+j) = rand()%(uint16_t)(pow(2,16)-1) - (rand()%(uint16_t)(pow(2,16)-1));    
    }
}

/** Function to print the array with its data */
void printArrayData(int* array, uint16_t size){
    for(uint16_t index = 0; index < size; index++){
        printf("%d\t", *(array+index));
        if((index+1)%10 == 0){
            printf("\n");
        }
    }
}

/** Functions that prints the list ADT */
void printList(list* ADT, char* title){
    printf("%s\n", title);
    // This is equivalent to write ADT != NULL
    uint16_t c = 1;
    while(!isEmpty(ADT)){
        printf("%d\t", ADT->data);
        if(c%10 == 0){
            printf("\n");
        }
        else{
            ; //Nop action
        }
        // This is so important, to get the next list element
        ADT = ADT->next;
        c++;
    }
}

/* Function that creates the list with a first data */
list* createList(int d){
    list* head = malloc(sizeof(list));
    head->data = d;
    head->next = NULL;
    return head;
}

/** Funtion to add elements to the list (the order is inverted)*/
list* addList(list* l, int d){
    list* h = createList(d);
    h->next = l;
    return h;
}

/** Function responsible for copying the elements of the array to the list (the order is inverted by addList function)*/
list* arrayToList(uint16_t* array, uint16_t size){
    list* head = createList(*(array));
    for(uint16_t k = 1; k < size; k++){
        head = addList(head,*(array+k));
    }
    return head;
}

/** Function that checks if the list is already empty */
bool isEmpty(const list* l){
    return (bool)(l==NULL);
}   