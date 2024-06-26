/** 
 * Author: Miller Quintero
 * Date: Apr 25, 2023
 * Title: Marathon distance in kilometers
 * Actions: Convert distance in miles or yards to kilometers
*/

#include <stdio.h> // Comando de prepocesador
// 1 mille is equal to 1760 yards
// 1 milles is equal to 1.6934 kilometers

/** Main function*/
int main (void){
    // Initialize variables
    double miles, yards;
    double kilometers;
    // Tasks
    printf("Please, enter the miles as double float:");
    scanf("%lf", &miles);
    printf("Please, enter the yards as double float:");
    scanf("%lf", &yards);
    kilometers = 1.609f * ((double)miles + (double)yards/1760.0f); //Es importante ponerle decimal al 1760 para que esa division pueda dar un decimal y no quede limitada a ser un entero
    printf("\n A marathon is %lf kilometers. \n", kilometers);
    return 0;
}