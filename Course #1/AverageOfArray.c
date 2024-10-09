/** 
 * Author: Miller Quintero
 * Date: Jul 17, 2023
 * Program: This code allow us obtain an average of the simple array's elements, like grades between 0 and 100
*/

#include <stdio.h>      // Library to can use standard inputs and outputs
#include <stdint.h>     // Library to can define variables with more control, standard integers
#include <stdlib.h>     // Library of C standard with an wide varity of functions, to be able to use random generator function
#include <time.h>       // Library to be able to get current hour in real compile time, it's going to be used as pseudo-random seed

int main(void){
    const uint16_t size = 1000;
    uint8_t grades[size];
    double sum = 0.0;
    int i,j;
    srand(time(NULL)); // Pseudo-random seed
    /* Fill the grades's array with random integers */
    for(i = 0; i < size; i++){
        grades[i] = (uint8_t)abs(rand()%(100 + 1));
    }
    for(i = 0; i < size; i++){
        sum+= grades[i];
    }
    printf("\nThe average of the grades array is %lf \n", sum/size);

    /* Doing it now with pointers */
    sum = 0;
    for(j = 0; j < size; j++){       
        *(grades+j) = (uint8_t)abs(rand()%(100 + 1));
    }
    for(j = 0; j < size; j++){
        sum+= *(grades+j);
    }
    printf("\nThe average of the grades array is %lf \n", sum/size);

    return 0;

}