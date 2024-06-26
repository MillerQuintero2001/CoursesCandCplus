/** 
 * Author: Miller Quintero
 * Date: Apr 23, 2023
 * Title: Marathon distance in kilometers
 * Actions: Convert distance in miles or yards to kilometers
*/

#include <stdio.h> // Comando de prepocesador
// 1 mille is equal to 1760 yards
// 1 milles is equal to 1.6934 kilometers

/** Main function*/
int main (void){
    // Initialize variables
    int miles = 26, yards = 385;
    double kilometers = 0.0;
    //Tasks  
    kilometers = 1.609f*((double)miles + (double)yards/1760.00f); //Es importante ponerle decimal al 1760 para que esa division pueda dar un decimal y no quede limitada a ser un entero
    printf("\n The marathon of %u miles and %u yards, is equal to %lf kilometers. \n\n", miles, yards, kilometers);
    return 0;
}