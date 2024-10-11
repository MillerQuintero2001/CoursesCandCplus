/** 
 * Author: Miller Quintero
 * Date: Jun 13, 2024
 * Title: Advance Standard I/O
 * Program: This program show us another modifiers or controlers in standard output
*/
#include <stdio.h>      // Library to use standard inputs and outputs
#include <stdint.h>     // Library to use integers defined by bits size

int main(void){
    int n;
    uint8_t data[] = {92, 45, 1};
    double decimal[] = {45.24,-78.656,94142.12646};
    char string[] = {'a','b','c'};
    for(uint8_t i = 0; i<sizeof(data)/sizeof(uint8_t); i++){
        /*  1. When whe put '%0a' before the format specifier of a number, we make that 
            the data prints with leading zeros until complete 'a' digits, for example
            the number 92, with %02u, will not have zeros because the data already 
            have 2 digits, but with %05u, it's going to have 3 leading zeros */
        printf("\nThe #%u data is %02hhu.", i, data[i]);
        printf("\nThe #%u data is %05hhu.", i, data[i]);
        /*  2. When we put '%a' (without leading zero) before the format specifier of
            a number or char, it gonna be print with 'a' characters, and if is 
            necessary this gonna be do with blank spaces, but again, for example the
            number 92, already have 2 characters, for that reason, it will have only
            1 blank space, and if we write %-a, the blank spaces will be on the right
            side, let's see it in the next for cycle with characters */     
        printf("\nThe #%u data is %3hhu.", i, data[i]);
        printf("\nThe #%u data is %-3hhu.", i, data[i]);
    }
    
    printf("\n");
    for(uint8_t i = 0; i<sizeof(string)/sizeof(char); i++){
        printf("\nThe #%u char is %2c.", i, string[i]);
        printf("\nThe #%u char is %-2c.", i, string[i]);
    }
    printf("\n");
    for(uint8_t i = 0; i<sizeof(string)/sizeof(char); i++){
        /*  3. Now, is well known that if we put %.a, this indicate that the data should 
        be printed with 'a' decimal digits, but is important to see that if we use %.aE,
        the data will be print with 'a' decimals but in scientific notation, and it implies
        that there will be only one integer digit, is important to have it present */    
        printf("\nThe #%u double is %-12.3E.", i, decimal[i]);
        printf("\nThe #%u double is %-12.5E.", i, decimal[i]);
        printf("\nThe #%u double is %-12.5f.", i, decimal[i]);
        printf("\nThe #%u double is %-22.3F.", i, decimal[i]);
    }
    /*  4. Finally, with the format specifier '%n', we can save by call reference in an integer;
        the number of printed characters with the current printf() function, before the call */
    putchar('\n');
    printf("Hello frie%nnds", &n);
    printf("\nThe number of characters before the use of %%n is %d.\n",n);
    return 0;
}