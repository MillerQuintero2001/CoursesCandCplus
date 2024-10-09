/** 
 * Author: Miller Quintero
 * Date: Jul 19, 2023
 * Program: This code allow us obtain an average of the simple array's elements, like grades between 0 and 100, 
 * and print de address memory using pointers.
*/

#include <stdio.h>      // Library to can use standard inputs and outputs
#include <stdint.h>     // Library to can define variables with more control, standard integers
#include <stdlib.h>     // Library of C standard with an wide varity of functions, to be able to use random generator function
#include <time.h>       // Library to be able to get current hour in real compile time, it's going to be used as pseudo-random seed

int main(void){
    const uint16_t size = 500;
    uint16_t grades[size];
    double sum = 0.0;
    // Inicializamos un variable de tipo puntero a un double, y le asignamos la dirección de memoria de la variable "sum"
    double *ptrSum = &sum;
    int i;
    srand(time(NULL)); // Pseudo-random seed
    // Fill the grades's array with random integers 
    for(i = 0; i < size; i++){
        grades[i] = (uint16_t)abs(rand())%(100+1);
    }
    for(i = 0; i < size; i++){
        sum+= grades[i];
    }
    printf("\nThe average of the grades array is %lf \n", sum/size);

    // Is necessary cast to unsigned long long to can print all that long direction without compiler warnings */
    printf("\nsum variable is at %p, or %lu and his value is %lf \n", ptrSum, (unsigned long)ptrSum, *ptrSum);

    /* NOTE: Here the cast takes precedence over the sum, inthe result it will be possible to see that from the first element
    of the array to the fifth, there are 20 additional ones that represent 5*4, since each element is a 4-byte unsigned int */
    printf("And the grades are at %lu to %lu and the 6th value is %u", (unsigned long)grades, (unsigned long)(grades+5), *(grades+5));

    /* An important observation is that to can print it, is necessary use the  unsigned long character identifier (%lu), but
    This is just for the sake of being able to print such large memory values, as in reality the elements of the "grades" 
    array are all 4-byte unsigned ints, not 8-byte unsigned longs. */

    return 0;

}