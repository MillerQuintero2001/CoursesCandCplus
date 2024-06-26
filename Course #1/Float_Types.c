
/** 
 * Author: Miller Quintero
 * Date: May 5, 2023
 * Program: Fundamental Float Types
*/

#include <stdio.h> // Pre-proccesing command

/** Funcion principal*/
int main (void){
    double x = 1234.56789;
    double y = 0.0000154544845261;
    /* El formato %g o %G selecciona notación científica si el exponente es menor a -4, de lo contrario se imprime en decimal */
    printf("Valor 'x' con formato %%g: %.8g\n", x);
    printf("Valor 'x' con formato %%G: %#.8G\n", x);  
    printf("Valor 'y' con formato %%g: %g\n", y);
    printf("Valor 'y' con formato %%G: %G\n", y); 
    return 0;
}