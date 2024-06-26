/** 
 * Author: Miller Quintero
 * Date: Apr 30, 2023
 * Title: Expression and Evaluation
 * Actions: Verify actions and prority of the operator in expressions and evaluations
*/

#include <stdio.h> // Pre-proccesing command
int main()
{
    int a = 5, b = 7, c = 0, d = 0; //Initialize
    c = a - b;
    printf("a = %d, b = %d, c = %d, d = %d \n", a,b,c,d);
    c = b - a;
    printf("a = %d, b = %d, c = %d, d = %d \n", a,b,c,d);
    c = a / b ; d = b / a;
    printf("a = %d, b = %d, c = %d, d = %d \n", a,b,c,d);
    c = a % b ; d = b % a;
    printf("a = %d, b = %d, c = %d, d = %d \n", a,b,c,d);
    c = -a - b; d = -b -a;
    printf("a = %d, b = %d, c = %d, d = %d \n", a,b,c,d);
    c = ++a + b++; d+= 5;
    printf("a = %d, b = %d, c = %d, d = %d \n", a,b,c,d);
    return 0;
}