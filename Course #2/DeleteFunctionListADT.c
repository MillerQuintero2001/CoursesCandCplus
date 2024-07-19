/** 
 * Author: Miller Quintero
 * Date: Jul 15, 2024
 * Title: Delete Function List ADT
 * Program: This program is an advance aplication of ADT(Abstract Data Type) lists, that includes the delete element function
*/

#include <stdio.h>      // Library to use standard inputs and outputs
#include <stdint.h>     // Library to use integers defined by bits size
#include <stdlib.h>     // Library to can use the routines malloc and free, as well as pseudo-random generator functions
#include <stdbool.h>    // Library that brings boolean data types
#include <time.h>       // Library to use current time as seed generator
#include <math.h>       // Library with basic math functions
#include <assert.h>     // Library for the asserts control program
#include <ctype.h>      // Library for characters mapping


typedef struct list{
    int data;
    struct list* next; // To can define a pointer to the structure itself, is necessary write struct tagName
}list;

/* Proto-types functions */
void fillArrayData(int* array, uint16_t size);
void printArrayData(int* array,uint16_t size);
void printList(list* h, const char* title);
list* createList(int d);
list* addToFrontList(list* h, int d);
list* arrayToList(int* array, uint16_t size);
bool isEmpty(const list* l);
uint16_t counterList(list* l);
void concatenateList(list** h1, list** h2);
void insertInsideList(list* p1, list* p2, list* element);
void deleteElementList(list* elem, list** prev, list** h);
void deleteFullList(list** h);

int main(void){
    uint16_t size1;
    uint16_t size2;
    printf("Write how many elements should have the list 1 to convert in ADT, no much more than 65535: ");
    scanf("%hu", &size1);
    printf("Now, write how many elements should have the list 2 to convert in ADT, no much more than 65535: ");
    scanf("%hu", &size2);
    // Assign dynamic memory for the custom size array
    int* array1 = (int*)malloc(sizeof(int)*size1);
    int* array2 = (int*)malloc(sizeof(int)*size2);

    // Pseudo-random seed to generate numbers
    srand(time(NULL));
    // Fill and the array with the pseudo-random data
    fillArrayData(array1, size1);
    fillArrayData(array2, size2);

    list* h1 = arrayToList(array1, size1);
    list* h2 = arrayToList(array2, size2);

    printList(h1, "\nThe list 1 is:");
    printList(h2, "\nThe list 2 is:");

    concatenateList(&h1,&h2);
    printList(h1, "\nAfter concatenate h1 and h2, the list 1 is:");

    // Here, the second element will be delete
    deleteElementList(h1->next, &h1, &h1);
    printList(h1, "\nThe list 1 after delete the second element is:");

    // Here, the first element will be delete, due to there is no elment before the first, the argument "prev" is NULL
    deleteElementList(h1, NULL, &h1);
    printList(h1, "\nThe list 1 after delete the first element is:");

    // Remember the function needs the element to delete, the pointer to the previous element pointer and the pointer to head pointer
    deleteElementList(h2->next->next, &(h2->next), &h1);
    printList(h1, "\nThe list 1 after delete the next element to h2->next is:");
    printf("\n");

    // deleteFullList(&h2);
    // printList(h2, "\nThe list 2 all delete is:");

    /* NOTE: We can't delete full list h2 and print h1 after, because the reference has lost, we should
    go to the end of the h1 and asiggn NULL to the next element*/
    deleteFullList(&h1);
    printList(h1, "\nAnd the list 1 all delete is:");
    printf("h1 #elements is: %u.\n", counterList(h1));

    return 0;
}

/** Function to fill the array data */
void fillArrayData(int* array, uint16_t size){
    for(uint16_t j = 0; j < size; j++){
        // Module the pseudo-random value, to get something in the correct range of 16 bits
        // The rand function only generates positive integers, for that reason we multiply for (-1)^j
        *(array+j) = rand()%(uint16_t)(pow(2,16)-1) - (rand()%(uint16_t)(pow(2,16)-1));    
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
void printList(list* h, const char* title){
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
        printf("Empty.\n");
    }

}

/* Function that creates the list with a first data */
list* createList(int d){
    list* head = (list*)malloc(sizeof(list));
    head->data = d;
    head->next = NULL;
    return head;
}

/** Funtion to add elements to the list (the order is inverted)*/
list* addToFrontList(list* l, int d){
    list* h = createList(d);
    h->next = l;
    return h;
}

/** Function responsible for copying the elements of the array to the list (the order is inverted by addList function)*/
list* arrayToList(int* array, uint16_t size){
    list* head = createList(*(array));
    for(uint16_t k = 1; k < size; k++){
        head = addToFrontList(head,*(array+k));
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
void insertInsideList(list* p1, list* p2, list* element){
    assert(p1->next==p2);
    p1->next = element;
    element->next = p2;
}

/** Function that deletes an element of the linked list, use pointers to the pointers prev and head related 
 * with the element, to secure that the call is by reference with that pointers */
void deleteElementList(list* elem, list** prev, list** h){
    // If the previous element is NULL, is because this is the head
    if((prev == NULL)||(*prev == NULL)){
        *h = elem->next;
    }
    // Check if the previous list element is the head (this is the specific case for 2th element)
    else if(*h == *prev){
        (*h)->next = elem->next;
    }
    else{
        (*prev)->next = elem->next;
    }
    free(elem);
}

/** Function to delete the full linked list with recursivity */
void deleteFullList(list** h){
    list* temp;
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