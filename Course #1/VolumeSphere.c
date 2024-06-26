/** 
 * Author: Miller Quintero
 * Date: May 5, 2023
 * Program: Volume of a Sphere
*/

#include <stdio.h> // Pre-proccesing command
#include <math.h>
#define PI 3.1415926535897932384

int main(void){

    double radius;
    printf("Enter radius:"); // The first problem is use ..”.. for string in place of .."..
    scanf("%lf", &radius);
    /* The second problem is in the next line, we should multiply for PI, and use the format %f or %lf to print the result
    in the original code, the format used was %d */
    printf("volume is : %lf \n", 4*PI*pow(radius,3)/3);
    return 0;
}