/** 
 * Author: Miller Quintero
 * Date: Apr 30, 2023
 * Title: Average of 3 numbers
 * Actions: Take 3 initialize numbers and print the average
*/

#include <stdio.h> // Pre-proccesing command
int main()
{
    int a = 8, b = 9, c = 6; //Initialize
    float average = 0.0;
    printf("a = %d, b = %d, c = %d\n", a,b,c);
    average = (float)(a +b +c) / 3; // That's my first cast variable
    printf("Average = %f\n", average);
    return 0;
}