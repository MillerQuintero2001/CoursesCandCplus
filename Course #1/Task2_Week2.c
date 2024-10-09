/** 
 * Author: Miller Quintero
 * Date: May 6, 2023
 * Program: Return sine of a value between 0 and 1 (noninclusive)
*/

#include <stdio.h> // Pre-proccesing command por input and output standard
#include <math.h> // Pre-proccesing commando to import math library

#define MY_PI 3.1415926535897932384


/** Main function */
int main (void) {
    // Initialize variables
    double value = 0.0;
    double sine_value = 0.0;
    // Actions   
    printf("Please, input a value between 0 and 2*PI to calculate the sine: ");
    scanf("%lf", &value);
    if(value >= 0 && value <= 2*MY_PI){
        // This sine receives the argument value in radians
        sine_value = sin(value); 
        printf("Sine(%lf) = %lf\n", value, sine_value);
    }
    else{
        printf("Error: Input value must be between 0 and 1 (non-inclusive).\n");
    }
    return 0;
}
