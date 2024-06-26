/** 
 * Author: Miller Quintero
 * Date: Jul 21, 2023
 * Program: This code allow us sorting an array of elements, using merge sort method
*/

#include <stdio.h>      // Library to can use standard inputs/outputs
#include <stdint.h>     // Library can define variables with better memory control
#include <stdbool.h>    // Library that allow us define boolean variables
#include <string.h>     // Library with functions to manipulate strings and arrays
#include <stdlib.h>     // Library standard of C with a lot of functions
#include <time.h>       // Library of time, to obtain real time compilation

/* Definition of prototypes functions */
void printArray(uint16_t size, uint16_t array[],  char* str);
void swap(uint16_t* i, uint16_t* j);
void bubbleSort(uint16_t size, uint16_t array[]);
void merge(uint16_t size, uint16_t array1[], uint16_t array2[], uint16_t arrayFinal[]);
void mergeSort(uint16_t key[], uint16_t size);

/* Macro-definitions */
#define SIZE 512

int main(void){
    uint16_t grades[SIZE];

    int i;
    srand(time(NULL)); // Semilla generadora de números pseudo-aleatorios
    /* Rellenamos las listas de notas con enteros aleatorios*/
    for(i = 0; i < SIZE; i++){
        grades[i] = (uint16_t)abs(rand()%100 + 1);
    }

    /* Aplicamos la nueva funcioń de MergeSort que tiene la Merge clásica
    dentro de si, ahora esta versión permite trabajar directamente con una
    sola lista sin dividirla previamente en 2 listas ya ordenadas */
    mergeSort(grades, SIZE);
    printArray(SIZE, grades, "My sort grades are: \n");
    return 0;
}


void printArray(uint16_t size, uint16_t array[], char* str){
    printf("%s", str);
    for(uint16_t j = 0; j < size; j++){
        printf("%u\t", array[j]);
        if((j+1)%10 == 0){
            printf("\n");
        }
    }
}


void swap(uint16_t* i, uint16_t* j){
    // Variable temporal, toma el valor al que apunta el puntero 'i'
    uint16_t temp = *i;
    /*Asignamos al puntero 'i' el valor del puntero 'j', para indicar 
    que es el valor toca usar operador de desreferencia (*) para ambos*/ 
    *i = *j;
    // Asignamos como valor al que apunta 'j' el temporal guardado anteriormente
    *j = temp;
}

void bubbleSort(uint16_t size, uint16_t array[]){
    /*Implementamos una variable bandera que indica que 
    la lista ya está ordenada y por tanto no hay seguir
    gastando tiempo de computación, máxima efectividad */
    bool flagSort = false;
    // Contador para el número de veces que no está ocurriendo un intercambio
    uint16_t counter = 0;
    //uint16_t control;
    for(uint16_t k = 0; k < size; k++){
        //printArray(size, array, "inside bubble\n");
        //printf("k = %u, Enter any integer to do a simple bubbleSort: ",k);
        //scanf("%hu", &control);
        for(uint16_t j = size - 1; j > k; j--){
            /* Antes de cualquier acción, si el contador de posiciones 
            ordenadas es igual al tamaño menos la posición que se 
            analiza+2, ya que el máximo indice de la lista es size -1,
            pero como el último elemento no se le hace swap, por eso -2 */
            if(counter >= (size - (k+2))){
                flagSort = true;
                break;
            }
            /* Si el valor antes de la posición j, es mayor
            al de j, intercambiamos lugares, para ordenar
            la lista de menor a mayor */
            else if(array[j-1] > array[j]){
                swap(&array[j-1], &array[j]);
            }
            /* De lo contrario, aumentamos en 1 el contador
            para hacer control de que la lista está ordenada */
            else{
                counter++;
            }
        }
        counter = 0;
        if(flagSort){
            flagSort = false;
            break;
        }
    }
}

void merge(uint16_t size, uint16_t array1[], uint16_t array2[], uint16_t arrayFinal[]){
    uint16_t i = 0;
    uint16_t j = 0;
    uint16_t k = 0;
    while((i < size) && (j < size)){
        if(array1[i] < array2[j]){
            /*Aquí como estamos usando el post-incremento, primero se hace la acción
            de los arreglos con esos valores en los indices, y luego se incrementa
            en uno las variables de indíces contadores */ 
            arrayFinal[k++] = array1[i++];
        }
        else{
            arrayFinal[k++] = array2[j++];
        }
    }
    while(i < size){
        arrayFinal[k++] = array1[i++];
    }
    while(j < size){
        arrayFinal[k++] = array2[j++];
    }
}

/** This function can order an array, using merge method, this only works with arrays of size 2^n*/
void mergeSort(uint16_t key[], uint16_t size){
    uint16_t j, k;
    uint16_t w[size];

    /* When they are powers of 2, it orders first, the algorithm 
    first sorts 2 by 2, then 4 by 4, and so on. */
    for(k = 1; k < size; k *= 2){
        for(j = 0; j < size - k; j += 2*k){
            merge(k, key + j, key + j + k, w + j);
        }
        // Update of the array
        for(j = 0; j < size; j++){
            key[j] = w[j];
        }
    }
}
