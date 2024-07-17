/** 
 * Author: Miller Quintero
 * Date: Jul 16, 2024
 * Title: Doubly linked list
 * Program: This programs generate 200 numbers from 0 to 49, that are save in a doubly linked list, after, a routine 
 * that remove the duplicate data is runned
*/

#include <stdio.h>      // Library to use standard inputs and outputs
#include <stdint.h>     // Library to use integers defined by bits size
#include <stdlib.h>     // Library to can use the routines malloc and free, as well as pseudo-random generator functions
#include <stdbool.h>    // Library that brings boolean data types
#include <time.h>       // Library to use current time as seed generator
#include <math.h>       // Library with basic math functions
#include <assert.h>     // Library for the asserts control program
#include <ctype.h>      // Library for characters mapping

#define SIZE 200
#define MAX 49

// This is the structure of a doubly linked list
typedef struct dlist{
    int data;
    struct dlist* prev;
    struct dlist* next;  
}dlist;

/* Proto-types functions */
void fillArrayData(int* array, uint16_t size);
void printArrayData(int* array,uint16_t size);
void printList(dlist* h, const char* title);
dlist* createDoublyLinkedList(int d);
dlist* addToFrontList(dlist** h, int d);
dlist* arrayToList(int* array, uint16_t size);
bool isEmpty(const dlist* l);
uint16_t counterList(dlist* l);
void concatenateList(dlist** h1, dlist** h2);
void insertInsideList(dlist* p1, dlist* p2, dlist* element);
void deleteElementList(dlist* elem, dlist** h);
void deleteFullList(dlist** h);
void deleteRepeatElements(dlist** h);

int main(void){
    srand(time(NULL));
    int* array = malloc(sizeof(dlist)*SIZE);
    fillArrayData(array, SIZE);

    dlist* head = arrayToList(array, SIZE);
    printList(head, "The list is:");
    printf("The number of elements in the list is: %u\n", counterList(head));

    deleteRepeatElements(&head);
    printList(head, "\nThe list after delete the repeated elements is:");

    return 0;
}

/** Function to fill the array data */
void fillArrayData(int* array, uint16_t size){
    for(uint16_t j = 0; j < size; j++){
        // Module the pseudo-random value, by MAX = 49, to get values between [0,49]
        *(array+j) = rand()%(MAX+1);    
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
void printList(dlist* h, const char* title){
    printf("%s\n", title);
    // This is equivalent to write ADT != NULL
    uint16_t c = 1;
    if(!isEmpty(h)){
        while(!isEmpty(h)){
            printf("%d\t", h->data);
            if(c%10 == 0){
                printf("\n");
            }
            else{
            ; //Nop action
            }
            // This is so important
            h = h->next;
            c++;
        }
    }
    else{
        printf("Empty.");
    }
    printf("\n");
}

/* Function that creates the list with a first data */
dlist* createDoublyLinkedList(int d){
    dlist* head = (dlist*)malloc(sizeof(dlist));
    head->data = d;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

/** Funtion to add elements to the list (the order is inverted), we call the original value by reference to can modifity it*/
dlist* addToFrontList(dlist** h, int d){
    dlist* newHead = createDoublyLinkedList(d);
    if(*h == NULL){
        return newHead;
    }
    else{
        newHead->next = *h;
        // Use dereferencing operator to set the pointer to the previous element, THIS IS THE DOUBLY LINKED
        (*h)->prev = newHead;
        return newHead;
    }
}

/** Function responsible for copying the elements of the array to the list (the order is inverted by addList function)*/
dlist* arrayToList(int* array, uint16_t size){
    dlist* head = createDoublyLinkedList(*(array));
    for(uint16_t k = 1; k < size; k++){
        head = addToFrontList(&head,*(array+k));
    }
    return head;
}

/** Function that checks if the list is already empty */
bool isEmpty(const dlist* l){
    return (bool)(l==NULL);
}   

/** Function that returns the amount of data on the ADT List */
uint16_t counterList(dlist* h){
    if(isEmpty(h)){
        return 0;
    }
    else{
        return 1+counterList(h->next);
    }
}

/** Function to concatenate 2 lists, having the second at the end of the first list, it works with pointers of pointers */
void concatenateList(dlist** h1, dlist** h2){
    if(isEmpty((*h1))){
        // If since the beginning is empty, simplily h1 is the same pointer h2
        *h1 = *h2;                                  
        printf("The first argument list is empty, so now, the first list is equal to second list.\n");
    }
    else if((*h1)->next == NULL){
        (*h1)->next = *h2;     
    }
    else{
        // This use recursivity
        concatenateList(&((*h1)->next), h2);
    }
}

/** Function responsible of add a particular element, inside the list, between to specified list pointers */
void insertInsideList(dlist* p1, dlist* p2, dlist* element){
    assert(p1->next==p2);
    p1->next = element;
    p2->prev = element;
    element->next = p2;
    element->prev = p1;
}

/** Function that deletes an element of the linked list, use a pointer to the pointer of the head related, this call is by reference */
void deleteElementList(dlist* elem, dlist** h){
    // If the element to delete is NULL, we end the function
    if (elem == NULL){
        return;
    } 

    // Else if the element to be deleted is the head
    else if (*h == elem) {
        *h = elem->next;
        (*h)->prev = NULL;
    }

    // In other case
    else{
        // Change next only if the node to be deleted is not the last node
        if (!isEmpty(elem->next)) {
            (elem->next)->prev = elem->prev;
        }
        else{
            ;   // NOP
        }

        // Change prev only if the node to be deleted is not the first node
        if (elem->prev != NULL) {
            (elem->prev)->next = elem->next;
        }
        else{
            ;   // NOP
        }
    }
    // In any case, we free the memoery allocated by the pointer
    free(elem);
}

/** Function to delete the full linked list with recursivity */
void deleteFullList(dlist** h){
    dlist* temp;
    if(!isEmpty(*h)){
        temp = *h;
        deleteFullList(&((*h)->next));
        free(temp);
    }
    else{
        ;   // NOP
    }
    *h = NULL;
}

/** Function that deletes all repeated elements in the doubly linked list */
void deleteRepeatElements(dlist** h){
    // Pointer that will sweep thorugh the list
    dlist* compare = *h; 
    while(!isEmpty(compare)){
        // Temporaly pointer to compare  
        dlist* temp = compare->next; 
        while(!isEmpty(temp)){
            // Pointer to save the next value before delete something
            dlist* saveNext = temp->next;
            if(temp->data == compare->data){
                deleteElementList(temp,h);
            }
            else{
                ;   // NOP
            }
            // Assign temp to the next element before deleted
            temp = saveNext;
        }
        // Get the next element to compare
        compare = compare->next;
    } 
}