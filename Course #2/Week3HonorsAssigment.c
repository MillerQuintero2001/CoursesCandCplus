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
#include <errno.h>      // Library to work with 'errno' variable

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
dlist* addToFrontList(dlist* h, int d);
dlist* arrayToList(int* array, uint16_t size);
bool isEmpty(const dlist* l);
bool isOnlist(const dlist* l, const dlist* h);
uint16_t counterList(const dlist* h);
uint16_t counterListRecursive(const dlist* h);
void concatenateList(dlist** h1, dlist** h2);
void insertInsideList(dlist* p1, dlist* p2, dlist* element);
void deleteElementList(dlist* elem, dlist** h);
void deleteFullList(dlist** h);
void deleteFullListRecursive(dlist** h);
void deleteRepeatElements(dlist** h);
void swapElements(dlist* l1, dlist* l2);
void sortLinkedList(dlist* h);
void deleteAdjacentElements(dlist** h);

int main(void){
    // First, prepare the pseudo-random seed generator and the array
    srand(time(NULL));
    int* array = (int*)malloc(sizeof(dlist)*SIZE);
    fillArrayData(array, SIZE);
    // Copy array data to the doubly linked lists
    dlist *head1 = NULL, *head2 = NULL;
    head1 = arrayToList(array, SIZE);
    head2 = arrayToList(array, SIZE);
    // Since the array data is already in the doubly linked list, it is a good time to free that memory
    free(array);
    // Print the list
    printList(head1, "The list is:");

    // Declaration of variables to measure times
    clock_t start, end;
    double time = 0.0f;

    /* First way, first sort the list, then delete adjacent elements that are the same, 
    this method take advantage of the doubly linked list characteristic */
    start = clock();
    sortLinkedList(head1);
    deleteAdjacentElements(&head1);
    end = clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    printList(head1, "\nThe list after sort and delete the repeated elements is:");
    printf("By the first method sorting and deleting it took %.10f seconds.\n", time);
    
    // Second way, delete repeated elements by swepping the list comparing values
    start = clock();
    deleteRepeatElements(&head2);
    end = clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    printList(head2, "\nThe list after compare and delete the repeated elements is:");
    printf("By the second method comparing and deleting it took %.10f seconds.\n", time);

    // Free doubly linked list pointers memory
    free(head1);
    free(head2);

    /*NOTE: Despite the frist method take advantage of the doubly linked list nature, it took more time than
    the second method, due to the first method started sorting the linked list, but once it is sorted, the process
    of deleted repeated elements is the most eficient */
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

/** Function that prints the list ADT */
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

/** Function that creates the list with a first data */
dlist* createDoublyLinkedList(int d){
    dlist* head = (dlist*)malloc(sizeof(dlist));
    if(head == NULL){
        if(errno != 0){
            perror("Memory allocation failed.\n");
        }
        else{
            ;       // NOP action
        }
        return head;
    }
    else{
        head->data = d;
        head->next = NULL;
        head->prev = NULL;
        return head;
    }
}

/** Funtion to add elements to the list (the order is inverted), due to these are pointer, we can work with value directly */
dlist* addToFrontList(dlist* h, int d){
    dlist* newHead = createDoublyLinkedList(d);
    if(newHead != NULL){
        if(h == NULL){ //
            return newHead;
        }
        else{
            newHead->prev = NULL;
            newHead->next = h;
            h->prev = newHead;
            return newHead;
        }
    }
    else{
        perror("Memory allocation failed.\n");
        return newHead;
    }
}

/** Function responsible for copying the elements of the array to the list (the order is inverted by addList function)*/
dlist* arrayToList(int* array, uint16_t size){
    dlist* head = createDoublyLinkedList(*(array));
    for(uint16_t k = 1; k < size; k++){
        head = addToFrontList(head,*(array+k));
    }
    return head;
}

/** Function that checks if the list is already empty */
bool isEmpty(const dlist* l){
    return (bool)(l==NULL);
}   

/** Function to check if an element is linked in any part of a doubly linked list since the head indicated to the last */
bool isOnlist(const dlist* l, const dlist* h){
    while (!isEmpty(h)){
        if (l == h){
            return true;
        }
        h = h->next;
    }
    return false;
}

/** Function that returns the amount of data on the ADT list, this the best for long doyubly linked lists */
uint16_t counterList(const dlist* h){
    uint16_t counter = 0;
    while(!isEmpty(h)){
        counter++;
        h = h->next;
    }
    return counter;
}

/** Function that returns the amount of data on the ADT list using recursive, this is the best
 * for shorts doubly linked lists, not in longs cause recursivity is more memory intensive */
uint16_t counterListRecursive(const dlist* h){
    if(isEmpty(h)){
        return 0;
    }
    else{
        return 1+counterListRecursive(h->next);
    }
}

/** Function to concatenate 2 lists, having the second at the end of the first list, it works with pointers of pointers */
void concatenateList(dlist** h1, dlist** h2){
    if(isEmpty(*h2)){
        return;
    }
    else if(isEmpty(*h1)){
        // If since the beginning is empty, simplily h1 is the same pointer h2
        *h1 = *h2;                                  
        printf("The first argument list is empty, so now, the first list is equal to second list.\n");
    }
    else if((*h1)->next == NULL){
        (*h1)->next = *h2;     
    }
    else{
        /* This use recursivity, in case of list that are too long
        could be inneficient, so a loop alternative would be better */
        concatenateList(&((*h1)->next), h2);
    }
}

/** Function responsible of add a particular element, inside the list, between to specified list pointers */
void insertInsideList(dlist* p1, dlist* p2, dlist* element){
    //assert(p1->next==p2);
    if (p1 == NULL || p2 == NULL || element == NULL || p1->next != p2) {
        fprintf(stderr, "Error: Invalid insertion. Make sure p1 and p2 are contiguous and non-NULL.\n");
        /* In this case is better use 'fprintf' instead of 'perror', because 'perror' is more apropiated when
        use functions like fopen, read, malloc, calloc, realloc, due to 'perror' is asociated with a variable
        of name 'errno'*/
        //perror("Error: Invalid insertion. Make sure p1 and p2 are contiguous and non-NULL.\n");
        return;
    }
    else{
        p1->next = element;
        p2->prev = element;
        element->next = p2;
        element->prev = p1;
    }   
}

/** Function that deletes an element of the linked list, use a pointer to the pointer of the head related, this call is by reference */
void deleteElementList(dlist* elem, dlist** h){
    // If the element to delete or the head is NULL, we end the function
    if ((elem == NULL)||(*h == NULL)){
        return;
    } 
    // Else if the element to be deleted is the head
    else if (*h == elem) {
        *h = elem->next;
        (*h)->prev = NULL;
        // Free the memory allocated by the pointer
        free(elem);
        // Ensures the nullify
        elem = NULL;
    }
    /* Else, we have any other element (Note that we are checking if the elem is 
    on the doubly linked list that requieres more time, but is correctly */
    else{
        if(isOnlist(elem, *h)){
            // The next of the previous will be the next of the element to be deleted, as this previous element not be NULL
            if(!isEmpty(elem->prev)){
                (elem->prev)->next = elem->next;
            }
            else{
                ;   // NOP action
            }
            // If the element is not the last (elem->next will not be NULL), we can set the previous
            if(!isEmpty(elem->next)){
                (elem->next)->prev = elem->prev;
            }
            else{
                ;  // NOP action
            }
            free(elem);
            // Ensures the nullify
            elem = NULL;
        }
        else{
            return;
        }
    }
}

/** Function to delete the full linked list with iterations */
void deleteFullList(dlist** h){
    dlist* current = *h;
    dlist* next;
    while(current != NULL){
        next = current->next;  
        free(current);         
        current = next;     
    }
    // Set the head pointer to NULL to indicate the list is empty
    *h = NULL;  
}

/** Function to delete the full linked list with recursivity */
void deleteFullListRecursive(dlist** h){
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
    dlist* temp = compare->next;
    dlist* saveNext = temp->next;
    while(!isEmpty(compare)){
        // Temporaly pointer to compare  
        temp = compare->next; 
        while(!isEmpty(temp)){
            // Pointer to save the next value before delete something
            saveNext = temp->next;
            if(temp->data == compare->data){
                deleteElementList(temp,h);
            }
            else{
                ;   // NOP
            }
            // Assign 'temp' to the next element before deleted
            temp = saveNext;
        }
        // Get the next element to compare
        compare = compare->next;
    } 
}

/** Fuction to swap data between 2 elements from a doubly linked list */
void swapElements(dlist* l1, dlist* l2){
    int temp = l1->data;
    l1->data = l2->data;
    l2->data = temp;
}

/** Function that sorts the doubly linked list */
void sortLinkedList(dlist* h){
    dlist* currentPtr = h;
    uint16_t size = counterList(h);
    /* This loop indicates up to which element to analyze, it starts with
    the size of the list minus 1 and continues until the element just before
    the start, this is because at the end of the process, the first 2 
    elements are organized at the same time.  */
    for(uint16_t i = size - 1; i > 0; i--){
        /* This loop goes until 'i' indicates, because the rest of 
        the elements are already sorted, it sweps the linked list
        with the greatest element */     
        for(uint16_t j = 0; j < i; j++){
            if(currentPtr->data > currentPtr->next->data){
                swapElements(currentPtr, currentPtr->next);
            }
            else{
                ;   // NOP action
            }
            // Shifting the pointer
            currentPtr = currentPtr->next;
        }
        // Returning the pointer to the head
        currentPtr = h;
    }
}

/** Function responsible of delete adjacent elements that are equal, is necessary have the doubly linked list already sorted */
void deleteAdjacentElements(dlist** h){
    // Can start from the second element, because the algorithm analize next and previous elements
    dlist *currentPtr = (*h)->next;
    // Check that the current pointer isn't NULL (that indicates the end of the doubly linked list)
    while(!isEmpty(currentPtr)){
        // Check if the next isn't NULL, to avoid segmentation fault or memory access errors
        if((currentPtr->next != NULL)&&(currentPtr->data == currentPtr->next->data)){
            deleteElementList(currentPtr->next, h);
        }
        else{;}
        // Check if the previous isn't NULL, to avoid segmentation fault or memory access errors
        if((currentPtr->prev != NULL)&&(currentPtr->data == currentPtr->prev->data)){
            deleteElementList(currentPtr->prev, h);
        }
        else{;}
        // Shifting the pointer
        currentPtr = currentPtr->next;
    }
}