/** 
 * Author: Miller Quintero
 * Date: Jun 13, 2024
 * Title: Advance Processing List ADT
 * Program: This program is an advance aplication of ADT(Abstract Data Type) lists
*/
#include <stdio.h>      // Library to use standard inputs and outputs
#include <stdint.h>     // Library to use integers defined by bits size
#include <stdlib.h>     // Library to can use the routines malloc and free, as well as pseudo-random generator functions
#include <stdbool.h>    // Library that brings boolean data types
#include <time.h>       // Library to use current time as seed generator
#include <math.h>       // Library with basic math functions
#include <assert.h>     // Library for the asserts control program

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
    struct list* next; // To can define a pointer to the structure itself, is necessary write struct tagName
}list;

/* Header proto-types functions */
void fillArrayData(int* array, uint16_t size);
void printArrayData(int* array,uint16_t size);
void printList(list* ADT, char* title);
list* createList(int d);
list* addList(list* h, int d);
list* arrayToList(int* array, uint16_t size);
bool isEmpty(const list* l);
uint16_t counterList(list* l);
void concatenateList(list** h1, list** h2);
void insertInsideList(list* p1, list* p2, list* element);

int main(void){
    uint16_t size1;
    uint16_t size2;
    printf("Write how many elements should have the list 1 to convert in ADT, no much more than 65535: ");
    scanf("%hu", &size1);
    printf("Now, write how many elements should have the list 2 to convert in ADT, no much more than 65535: ");
    scanf("%hu", &size2);
    // Assign dynamic memory for the custom size array
    int* array1 = malloc(sizeof(int)*size1);
    int* array2 = malloc(sizeof(int)*size2);

    // Pseudo-random seed to generate numbers
    srand(time(NULL));
    // Fill and print print the array with the pseudo-random data
    fillArrayData(array1, size1);
    printArrayData(array1,size1);
    printf("\n");
    fillArrayData(array2, size2);
    printArrayData(array2,size2);

    /* Declare and create the pointer to list, is important to know that if we try to manipulate or access to a pointer 
    that is only declare but not initialize, this gonna cause an assert */
    list* l1;
    list* l2;
    // List 3 will be a temporaly empty list
    list* l3 = NULL;
    l1 = arrayToList(array1,size1);
    l2 = arrayToList(array2,size2);

    printList(l1, "\nThe full list 1 is:");
    printf("\nThe amount of elements in list 1 is: %hu\n", counterList(l1));
    printList(l2, "\nThe full list 2 is:");
    printf("\nThe amount of elements in list 2 is: %hu\n", counterList(l2));
    printList(l3, "\nThe full list 3 is:");
    printf("\nThe amount of elements in list 3 is: %hu\n", counterList(l3));

    concatenateList(&l3,&l2);
    printf("After concatenate list 3 empty and list 2 in the first called into the function, we have:\n");
    printList(l3,"\nThe full list 3 is:");
    printf("\nThe amount of elements in list 3 is: %hu\n", counterList(l3));

    concatenateList(&l1,&l3);
    printf("After concatenate list 1 and list 3 in the first called into the function, we have:\n");
    printList(l1,"\nThe full list 1 is:");
    printf("\nThe amount of elements in list 1 is: %hu\n", counterList(l1));

    /* Let's free the heap memory, isn't really necessary in this case, 
    because always at the end of a program, the system free it automatically */
    free(l1);
    free(l2);
    /* If we try to free the list 3, the program will be abort, because this would be a double free
    due to the list 3 have the same pointer of the list 2, and this list was already free */
    // free(l3);
    free(array1);
    free(array2);

    return 0;
}

/** Function to fill the array data */
void fillArrayData(int* array, uint16_t size){
    for(uint16_t j = 0; j < size; j++){
        // Module the pseudo-random value, to get something in the correct range of 16 bits
        // The rand function only generates positive integers, for that reason we multiply for (-1)^j
        *(array+j) = (int)pow(-1,j)*rand()%(uint16_t)(pow(2,16)-1);    
    }
}

/** Function to print the array with its data */
void printArrayData(int* array,uint16_t size){
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
        // This is so important
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
list* arrayToList(int* array, uint16_t size){
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

/** Function that returns the amount of data on the ADT List */
uint16_t counterList(list* l){
    if(isEmpty(l)){
        return 0;
    }
    else{
        return 1+counterList(l->next);
    }
}

/** Function to concatenate 2 lists, having the second at the end of the first list, it works with pointers of pointers */
void concatenateList(list** h1, list** h2){
    if(isEmpty((*h1))){
        // Si desde un comienzo está vacía, simplemente h1 es el mismo puntero h2  
        *h1 = *h2;                                  
        printf("The first argument list is empty, so now, the first list is equal to second list.\n");
    }
    else{
        if((*h1)->next == NULL){
            (*h1)->next = *h2;
        }
        // This use recursivity
        else{
            concatenateList(&((*h1)->next), h2);
        }
    }
}

/** Function responsible of add a particular element, inside the list, between to specified list pointers */
void insertInsideList(list* p1, list* p2, list* element){
    assert(p1->next==p2);
    p1->next = element;
    element->next = p2;
}