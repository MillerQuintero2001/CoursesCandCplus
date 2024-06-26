/** 
 * Author: Miller Quintero
 * Date: Jul 19, 2023
 * Program: This code allow us obtain an average of the simple array's elements, like grades between 0 and 100, 
 * and print de address memory using pointers.
*/

#include <stdio.h>      // Librería para poder tener las entradas y salidas estándar
#include <stdint.h>     // Librería para poder definir variables con mayor control, enteros estándar
#include <stdlib.h>     // Librería estándar de C con gran variedad de funciones, para poder usar función aleatoria 
#include <time.h>       // Librería para obtener la hora en tiempo de compilación, se usará como semilla aleatoria

int main(void){
    const uint16_t size = 500;
    uint16_t grades[size];
    double sum = 0.0;
    // Inicializamos un variable de tipo puntero a un double, y le asignamos la dirección de memoria de la variable "sum"
    double *ptrSum = &sum;
    int i;
    srand(time(NULL)); // Semilla generadora de números pseudo-aleatorios
    /* Rellenamos la lista de notas con enteros aleatorios*/
    for(i = 0; i < size; i++){
        grades[i] = (uint16_t)abs(rand());
    }
    for(i = 0; i < size; i++){
        sum+= grades[i];
    }
    printf("\nThe average of the grades array is %lf \n", sum/size);

    /* Es necesario castear a unsgined long long para poder imprimir toda esa gigante dirección de memoria sin warnings */
    printf("\nsum variable is at %p, or %lu and his value is %lf \n", ptrSum, (unsigned long)ptrSum, *ptrSum);

    /* OJO, acá el casteo tiene precedencia sobre la suma, en
    el resultado se podrá evidenciar que desde el primer elemento
    del arreglo hasta el quinto, hay 20 adicionales que representan 5*4,
    ya que cada elemento es un unsigned int de 4 bytes */
    printf("And the grades are at %lu to %lu and the 6th value is %u", (unsigned long)grades, (unsigned long)(grades+5), *(grades+5));

    /* Una observación importante es que para imprimir usamos el identificador de caracter de un unsigned long (%lu), pero 
    esto es solo para cuestiones de poder imprimir dichos valores de memoria tan grandes, pues en realidad los elementos del
    arreglo "grades" son todos unsigned int de 4 bytes, no unsigned long de 8 bytes. */

    return 0;

}