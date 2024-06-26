/** 
 * Author: Miller Quintero
 * Date: May 5, 2023
 * Program: Fundamental Integer Types
*/

#include <stdio.h>  // Pre-proccesing command

/** Funcion principal*/
int main (void){
    // Initialize variables
    short short_value = 32767; // Max positive value representable in short signed integer, when we exceed it we go to the negatives, and when we pass 65536 there is an overflow
    int int_value = 123;
    unsigned int uint_value = 4294967295; // Max value representable in unsigned integer 2^(32)
    long long_value = 21474836474561561;
    //Tareas    
     printf("short_value = %hd, divide by int 2 is %hd \n",short_value, short_value/2);
     printf("short_value = %hd, divide by float 2 is %f \n",short_value, short_value/2.0);
     printf("%d as a char is '%c' \n",int_value, int_value);
     printf("sizes in bytes of short, int, unsigned and long on my machine:");
     printf("%lu, %lu, %lu, %lu\n",sizeof(short_value),sizeof(int_value),sizeof(uint_value),sizeof(long_value));
     return 0;
}