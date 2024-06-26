/** 
 * Author: Miller Quintero
 * Date: Jun 25, 2024
 * Program: Generate a linked ADT list with 100 random integers and sort them
*/

#include <stdio.h>      // Library to use standard inputs and outputs
#include <stdint.h>     // Library to use integers defined by bits size
#include <stdlib.h>     // Library to can use the routines malloc and free, as well as pseudo-random generator functions
#include <stdbool.h>    // Library that brings boolean data types
#include <time.h>       // Library to use current time as seed generator
#include <math.h>       // Library with basic math functions

// Macro-proccesing directive to generate a random integer
#define RANDOM_NUMBER (int16_t)(rand()%(int16_t)((pow(2,16)-1)/2.0f))

typedef struct list{
    int16_t data;
    struct list* next; // To can define a pointer to the structure itself, is necessary write struct tagName
}list;

/* Definition of prototypes functions */
void printList(list* ADT, char* title);
list* createList(int16_t d);
list* addList(list* l, int16_t d);
list* arrayToList(int* array, int16_t size);
bool isEmpty(const list* l);
uint16_t counterList(list* l);
void swapElementsList(list* l1, list* l2);
void bubbleSort(list* l);

int main(void){

    // Pseudo-random seed generator
    srand(time(NULL));

    clock_t inicio, fin;
    double tiempo = 0.0f;

    // Create the list with the first random number
    list* list100data = createList(RANDOM_NUMBER);
    // From 1 to 100, we have 99 new numbers
    for (uint8_t i = 1; i < 100; i++){
        // We add a random integer with random sign into the list
        list100data = addList(list100data, (uint16_t)pow(-1, RANDOM_NUMBER)*RANDOM_NUMBER);
    }

    // Now with the data generated, we are going to sort the list by bubble sort
    printList(list100data, "This is the list before sort:\n");

    inicio = clock();
    bubbleSort(list100data);
    fin = clock();
    tiempo = (double)(fin-inicio)/CLOCKS_PER_SEC;
    printList(list100data,"This is the list after sort:\n");
    printf("The bubble sort time was %.10f seconds \n", tiempo);

    /* We free the memory used with the list pointer, is a  good practice but isn't really 
    necesarry because it always do autocatically at the end of the program */
    free(list100data);

    return 0;
}

/** Functions that prints the list ADT */
void printList(list* ADT, char* title){
    printf("%s\n", title);
    // This is equivalent to write ADT != NULL
    uint16_t c = 1;
    while(!isEmpty(ADT)){
        printf("%6d\t", ADT->data);
        if(c%5 == 0){
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
list* createList(int16_t d){
    list* head = malloc(sizeof(list));
    head->data = d;
    head->next = NULL;
    return head;
}

/** Funtion to add elements to the list (the order is inverted)*/
list* addList(list* l, int16_t d){
    list* h = createList(d);
    h->next = l;
    return h;
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

/** Function that swap values on the list by reference call */
void swapElementsList(list* l1, list* l2){
    int16_t temporal = l1->data;
    l1->data = l2->data;
    l2->data = temporal;
}

/** Function that sorts the ADT list from the smallest to bigest number */
void bubbleSort(list* l){
    // Save the list pointer
    list* currentP = l;
    for(uint8_t j = 0; j < counterList(l); j++){
        while(!isEmpty(l->next)){
            if(l->data > l->next->data){
                swapElementsList(l, l->next);
            }
            else{
                ; //NOP
            }
            l = l->next;
        }
        l = currentP;
    }
}
