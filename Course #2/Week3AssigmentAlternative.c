/** 
 * Author: Miller Quintero
 * Date: Jun 25, 2024
 * Program: Generate a linked ADT list that has as data a structure created with the data of an atom
 * (name, symbol, atomic weight), the list must be about the first 10 elements of the periodic table
*/

#include <stdio.h>      // Library to use standard inputs and outputs
#include <stdint.h>     // Library to use integers defined by bits size
#include <stdlib.h>     // Library to can use the routines malloc and free, as well as pseudo-random generator functions
#include <stdbool.h>    // Library that brings boolean data types
#include <time.h>       // Library to use current time as seed generator
#include <math.h>       // Library with basic math functions

typedef struct atom_t{
    char* element;
    char* symbol;
    float atomicWeight;
}atom_t;

typedef struct list{
    atom_t dataAtom;
    struct list* next; // To can define a pointer to the structure itself, is necessary write struct tagName
}list;

void fillAtomDataList(atom_t* arrayAtoms, uint8_t size);

int main(void){
    uint8_t howMany = 0;
    do{
        printf("How many elements do you want to print with his information? (Max 10) ");
        scanf("%hhu", &howMany);
    } while( howMany > 10);

    atom_t listElements[10] = {0};
    fillAtomDataList(listElements, howMany);
    printf("\033[1m\tNo.\tAtomic Weight\t\t  Name\t\t\tSymbol\033[0m\n");
    for(uint8_t j = 0; j < howMany; j++){
        printf("\t%2hhu\t%9.3f\t\t%s\t%11s\n", j+1, (listElements+j)->atomicWeight, (listElements+j)->element, (listElements+j)->symbol);
    }
    return 0;
}

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