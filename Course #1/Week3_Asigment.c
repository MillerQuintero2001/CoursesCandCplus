/** 
 * Author: Miller Quintero
 * Date: Jul 16, 2023
 * Program: This program prints a table of sines and cosines between 0 and 1, using for loop
*/

/* Some importants includes*/
#include <stdio.h>
#include <math.h>
#include <stdint.h>

int main (void){
    /* Declarations of varibles */
    double argument = 0.0;
    while(argument <= 1.0f){
        printf("Sin(%lf) = %lf\t Cos(%lf) = %lf\n", argument, sin(argument), argument, cos(argument));
        argument+=1.00f/50.0f;
    }
    return 0;
}