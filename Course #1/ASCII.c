/** 
 * Author: Miller Quintero
 * Date: May 5, 2023
 * Program: Characters in C
*/

#include <stdio.h> // Pre-proccesing command

/** Main function */
int main (void){
    // Initialize variables
    char c = 'a';
    // Tasks    
     printf("The character 'a' in ASCII is %d \n",c);
     printf("The character in the program is '%c' \n", c);
     printf("The three consecutives characters are: %c%c%c \n",c,c+1,c+2);
     printf("The three bell rings chars are: %c%c%c \n", '\a','\a','\a');
     return 0;
}