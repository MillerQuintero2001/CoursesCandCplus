/** 
 * Author: Miller Quintero
 * Date: Jul 16, 2023
 * Program: This program print square and cube of numbers with functions
*/

#include <stdio.h>

/* Functions proto-types definitions */
// Note that only the type of argument is required, variable name isn't mandatory
double square(double);
double cube(double);

int main(void){
    // Declaration of 3 integer variables, one of them, 'how many' is already initialize in 0
    int how_many = 0,i,j;
    printf("I want square and cube for 1 to n, where n is: ");
    scanf("%d", &how_many);
    printf("square and cubes by interval of 0.1\n");

    for(i = 1; i < how_many; i++){
        for(j = 0; j <= 10; j++){
            printf("\n%lf\t%lf\t%lf",i + j/10.0, square(i + j/10.0), cube(i + j/10.0));
        }
    }
    printf("\n\n");
    return 0;
}

double square(double x){
    return x*x;
}

double cube(double x){
    return x*x*x;
}