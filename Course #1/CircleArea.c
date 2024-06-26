/** 
 * Author: Miller Quintero
 * Date: Apr 23, 2023
 * Program: Area or circle according to the radius input
*/

#include <stdio.h>
#define PI 3.14159  //Directiva de pre-procesamiento



/** Funcion principal*/
int main (void){
    // Inicializo variables
    double area = 0.0, radius = 0.0;
    //Tareas    
     printf("Enter radius in meters: ");
     scanf("%lf", &radius);
     area = PI * radius*radius;
     printf("radius of %f meters; area is %lf square meters \n", radius, area);
     return 0;
}