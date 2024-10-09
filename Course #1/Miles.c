/** 
 * Author: Miller Quintero
 * Date: Apr 25, 2023
 * Title: Marathon distance in kilometers
 * Actions: Convert distance in miles or yards to kilometers
*/

#include <stdio.h> // Comando de prepocesador
// 1 mille is equal to 1760 yards
// 1 mille is equal to 1.6934 kilometers

/** Main function*/
int main (void){
    // Initialize variables
    double miles, yards;
    double kilometers;
    /* Tasks */
    printf("Please, enter the miles as double float: ");
    scanf("%lf", &miles);
    printf("Please, enter the yards as double float: ");
    scanf("%lf", &yards);
    // It is important to put a decimal in 1760 so that this division can give a decimal and not be limited to being an integer.
    kilometers = 1.609f * ((double)miles + (double)yards/1760.0f); 
    printf("\n A marathon is %lf kilometers.\n", kilometers);
    return 0;
}