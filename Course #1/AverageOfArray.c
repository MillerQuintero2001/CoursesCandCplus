/** 
 * Author: Miller Quintero
 * Date: Jul 17, 2023
 * Program: This code allow us obtain an average of the simple array's elements, like grades between 0 and 100
*/

#include <stdio.h>      // Librería para poder tener las entradas y salidas estándar
#include <stdint.h>     // Librería para poder definir variables con mayor control, enteros estándar
#include <stdlib.h>     // Librería estándar de C con gran variedad de funciones, para poder usar función aleatoria 
#include <time.h>       // Librería para obtener la hora en tiempo de compilación, se usará como semilla aleatoria

int main(void){
    const uint16_t size = 1000;
    uint8_t grades[size];
    double sum = 0.0;
    int i,j;
    srand(time(NULL)); // Semilla generadora de números pseudo-aleatorios
    /* Rellenamos la lista de notas con enteros aleatorios*/
    for(i = 0; i < size; i++){
        grades[i] = (uint8_t)abs(rand()%100 + 1);
    }
    for(i = 0; i < size; i++){
        sum+= grades[i];
    }
    printf("\nThe average of the grades array is %lf \n", sum/size);

    /* Haciéndolo ahora con punteros*/
    sum = 0;
    for(j = 0; j < size; j++){       
        *(grades+j) = (uint8_t)abs(rand()%100 + 1);
    }
    for(j = 0; j < size; j++){
        sum+= *(grades+j);
    }
    printf("\nThe average of the grades array is %lf \n", sum/size);

    return 0;

}