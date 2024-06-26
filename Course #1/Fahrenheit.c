/** 
 * Author: Miller Quintero
 * Date: Apr 23, 2023
 * Title: Fahrenheit to Celcius
 * Actions: Convert temperature in Fahrenheit to Celcius
*/

#include <stdio.h> // Pre-proccesing command
// C = (F - 32)*(5/9)

/** Main function*/
int main (void){
    // Initialize variables
    double fahrenheit, celcius;
    printf("Please enter Fahrenheit temperature as a double float:");
    scanf("%lf", &fahrenheit);
    //Tasks  
    celcius= (fahrenheit - 32.00f)*(5.00f/9.00f); //Conversion
    printf("\n %lf° Fahrenheit is %lf° Celcius. \n\n", fahrenheit, celcius);
    return 0;
}

// Cuando las variables solo se van a usar una vez, la mejor práctica de programación es inicializarlas dentro de la función que las utiliza.