/** 
 * Author: Miller Quintero
 * Date: Apr 30, 2023
 * Title: Size of 
 * Actions: Application of function "sizeof()"
*/

#include <stdio.h> // Pre-proccesing command

int main(void){
    printf("On my system \n");
    printf("Char is %lu bytes. \n", sizeof(char));
    printf("Short Int is %lu bytes. \n", sizeof(short int));
    printf("Int is %lu bytes. \n", sizeof(int));
    printf("Long int is %lu bytes. \n", sizeof(long int));
    printf("Float is %lu bytes. \n", sizeof(float));
    printf("Double is %lu bytes. \n", sizeof(double));
    printf("Long double is %lu bytes. \n", sizeof(long double));
    printf("Unsigned int is %lu bytes. \n", sizeof(unsigned int));
    printf("Unsigned long int is %lu bytes. \n", sizeof(unsigned long int));
    printf("Unsigned long long int (uint128_t) is %lu bytes. \n", sizeof(__uint128_t));
    return 0;
}