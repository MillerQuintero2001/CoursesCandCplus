/** 
 * Author: Miller Quintero
 * Date: Jun 25, 2024
 * Program: Generate a linked ADT list that has as data a structure created with the data of an atom
 * (name, symbol, atomic weight), the list must be about the first 10 elements of the periodic table
 * and to add a hot taste, the implementation used a linked list that doesn't invert the introduced elements
*/

#include <stdio.h>      // Library to use standard inputs and outputs
#include <stdint.h>     // Library to use integers defined by bits size
#include <stdlib.h>     // Library to can use the routines malloc and free, as well as pseudo-random generator functions
#include <stdbool.h>    // Library that brings boolean data types

typedef struct atom_t{
    char* element;
    char* symbol;
    float atomicWeight;
}atom_t;

typedef struct list{
    atom_t dataAtom;
    struct list* next;
}list;

void fillAtomDataList(atom_t* arrayAtoms, uint8_t size);
list* createList(atom_t data);
list* addListNotInv(list* l, atom_t data);
bool isEmpty(const list* l);
void atomArrayToListNotInv(list** h, atom_t* dataArray, uint8_t size);
void printList(list* ADT, const char* title);

int main(void){
    char bufferMsg[128] = {0};
    uint8_t howMany = 0;
    do{
        printf("How many elements do you want to print with his information? (Max 10) ");
        scanf("%hhu", &howMany);
    } while( howMany > 10);

    atom_t listElements[howMany];
    fillAtomDataList(listElements, howMany);

    // Now, create the linked list with atom_t array data
    list *head = NULL;
    atomArrayToListNotInv(&head, listElements, howMany);

    sprintf(bufferMsg,"\033[1m\tNo.\tAtomic Weight\t\t%-8s\t\t%s\033[0m\n", "Name", "Symbol");
    printList(head, bufferMsg);

    free(head);
    return 0;
}

/** Function to fill an array with the element's info, according to the size */
void fillAtomDataList(atom_t* arrayAtoms, uint8_t size){
    char *elements[10] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron",
    "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon"};
    char *symbols[10] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne"};
    float weights[10] = {1.008f, 4.003f, 6.941f, 9.012f, 10.811f,
    12.011f, 14.007f, 15.999f, 18.998f, 20.180f};
    for(uint8_t i = 0; i < size; i++){
        (arrayAtoms+i)->element = *(elements+i);
        (arrayAtoms+i)->symbol = *(symbols+i);
        (arrayAtoms+i)->atomicWeight = *(weights+i);
    }
}

/** Function to create the list with the first element, using dynamic memory */
list* createList(atom_t data){
    list* l = (list*)malloc(sizeof(list));
    l->dataAtom = data;
    l->next = NULL;
    return l;
}

/** Function that adds elements to an already created list and not inverted his dataset */
list* addListNotInv(list* l, atom_t data){
    list* h = createList(data);
    l->next = h;
    return l;
}

/** Function that checks if the list is already empty */
bool isEmpty(const list* l){
    return (bool)(l == NULL);
}

/** Function that put the values on a list from an array by reference call, without inverse the order */
void atomArrayToListNotInv(list** h, atom_t* dataArray, uint8_t size){
    *h = createList(*dataArray);
    list* currentPtr = *h;
    for(uint8_t i = 1; i < size; i++){
        currentPtr = addListNotInv(currentPtr, *(dataArray+i));
        currentPtr = currentPtr->next;
    }
}

/** Functions responsible for print the linked list with all data */
void printList(list* h, const char* title){
    printf("%s", title);
    uint8_t counter = 0;
    while(!isEmpty(h)){
        printf("\t%hhu\t%9.3f\t\t%-8s\t\t%4s\n", counter+1, h->dataAtom.atomicWeight, h->dataAtom.element, h->dataAtom.symbol);
        h = h->next;
        counter++;
    }
}