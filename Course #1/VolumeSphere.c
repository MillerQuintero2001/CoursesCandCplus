/** 
 * Author: Miller Quintero
 * Date: May 5, 2023
 * Program: Volume of a Sphere
*/

#include <stdio.h> // Pre-proccesing command
#include <math.h>
#define PI 3.1415926535897932384l

int main(void){

    double radius;
    printf("Enter radius:"); // The first problem is use ..”.. for string in place of .."..
    scanf("%lf", &radius);
    /* The second problem is in the next line, we should multiply for PI, and use the format %Lf to print the result
    in the original code, the format used was %d */
    printf("volume is : %.15Lf \n", 4.0l*PI*powl(radius,3.0l)/3.0l);
    return 0;
}