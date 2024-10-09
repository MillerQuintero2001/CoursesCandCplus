
/** 
 * Author: Miller Quintero
 * Date: May 5, 2023
 * Program: Fundamental Float Types
*/

#include <stdio.h> // Pre-proccesing command

/** Main function */
int main (void){
    double x = 1234.56789;
    double y = 0.0000154544845261;
    /*The format identifiers %g or %G selects scientific notation if the exponent is less than -4 (-5 to -infinite), otherwise, use decimal notation */
    printf("Valor 'x' con formato %%g: %.8g\n", x);
    printf("Valor 'x' con formato %%G: %#.8G\n", x);  
    printf("Valor 'y' con formato %%g: %g\n", y);
    printf("Valor 'y' con formato %%G: %G\n", y); 
    return 0;
}