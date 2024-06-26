/** 
 * Author: Miller Quintero
 * Date: Jul 20, 2023
 * Program: This code allow us sorting an array of elements, using bubble sort method
*/

#include <stdio.h>      // Library to can use standard inputs/outputs
#include <stdint.h>     // Library can define variables with better memory control
#include <stdbool.h>    // Library that allow us define boolean variables
#include <stdlib.h>     // Library standard of C with a lot of functions
#include <time.h>       // Library of time, to obtain real time compilation

/* Definition of prototypes functions */
void swap(uint16_t* i, uint16_t* j);
void printArray(uint16_t size, uint16_t array[],  char* str);
void bubbleSort(uint16_t size, uint16_t array[]);


int main(void){
    clock_t inicio, fin;
    double tiempo = 0.0f;
    const uint16_t size = 1000;
    uint16_t grades[size];
    int i;
    srand(time(NULL)); // Semilla generadora de números pseudo-aleatorios
    /* Rellenamos la lista de notas con enteros aleatorios*/
    for(i = 0; i < size; i++){
        grades[i] = (uint16_t)abs(rand()%100 + 1);
    }
    printArray(size, grades, "My grades are: \n");
    printf("\n\n");
    inicio = clock();
    bubbleSort(size, grades);
    fin = clock();
    tiempo = (double)(fin-inicio)/CLOCKS_PER_SEC;
    printArray(size, grades, "My sort grades are: \n");
    printf("The bubble sort time was %.10f seconds \n", tiempo);
    return 0;
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

void printArray(uint16_t size, uint16_t array[], char* str){
    printf("%s", str);
    for(uint16_t j = 0; j < size; j++){
        printf("%u\t", array[j]);
        if((j+1)%10 == 0){
            printf("\n");
        }
    }
}

void bubbleSort(uint16_t size, uint16_t array[]){
    /*Implementamos una variable bandera que indica que 
    la lista ya está ordenada y por tanto no hay seguir
    gastando tiempo de computación, máxima efectividad */
    bool flagSort = false;
    // Contador para el número de veces que no está ocurriendo un intercambio
    uint16_t counter = 0;
    for(uint16_t k = 0; k < size; k++){
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