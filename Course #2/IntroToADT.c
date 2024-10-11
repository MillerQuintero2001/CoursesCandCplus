/** 
 * Author: Miller Quintero
 * Date: Jun 12, 2024
 * Program: This programs introduces us to the ADT lists, this case in one of a single element
*/

#include <stdio.h>      // Library to use standard inputs and outputs
#include <stdint.h>     // Library to use integers defined by bits size
#include <stdlib.h>     // Library to can use the routines malloc and free
#include <stdbool.h>

/*  THE MOST IMPORTANT NOTE: The pointers in C have a size according to the system architecture,
    in my case I have a x64 bits computer, for that reason, the pointers with my compiler have
    a size of 8 bytes (1 byte = 8 bits and 8x8=64), now there is an important concept know as 
    'padding' in C, which says that the compiler in order to have an optimized access and alignment
    to the structure and its data, stuffing the structure with others bytes, for that reason the 
    next structure have an integer of 4 bytes, a pointer of 8 bytes, but has a size of 16 bytes
    because there are 4 padding bytes more to put the pointer aligned. 
*/

typedef struct list{
    int data;
    struct list* next; // To can define a point to the structure itself, is necessary write struct tagName
}list;

/* Functions Proto-types */
void printList(list* ADT, const char* title);
bool isEmpty(const list* l);

int main(void){
    list simpleList = {0}; // Not use in this example
    list* head = malloc(sizeof(list));
    printf("sizeof(list) = %lu bytes.\n", sizeof(list));
    head->data = 5;
    head->next = NULL;
    printList(head, "Single element list is:");
    free(head);
    return 0;
}

void printList(list* ADT, const char* title){
    printf("%s\n", title);
    // This is equivalent to write ADT != NULL
    while(!isEmpty(ADT)){
        printf("\t%d\n", ADT->data);
        // This is so important
        ADT = ADT->next;
    }
}

bool isEmpty(const list* l){
    return (bool)(l==NULL);
}   