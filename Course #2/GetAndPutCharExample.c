/** 
 * Author: Miller Quintero
 * Date: Oct 10, 2024
 * Program: Example of 'getc' and 'putc' functions use
*/

#include <stdio.h>      // Library to can control standard inputs and outputs

int main(void){
    char c;
    printf("Write one text line (ends with 'Enter'):\n");

    /* You can write everything as you want, until input '\n', and after, all characters
    will be printed, note that 'getchar()' can be replaced by getc(stdin), this function
    also need press 'Enter' to continue */
    while ((c = getchar()) != '\n') {
        printf("You have entered %c.\n", c);
    }

    /* Note that scanf requieres press 'Enter' to proceed with the input lecture; after scan
    the input value, an echo is done with 'putc' function, this could be replaced by 'putchar()' */
    while(c != 'H'){
        scanf("%c", &c);
        putc(c,stdout);
    }
    printf("\nEnd of the program.\n");
    return 0;

    /* Observation: 'putchar' and 'getchar' are specific statements of 'putc' and 'getc', this last 2 
    general functions can be used with a file pointer, to read or write in it. Another very
    important thing to highlight is that this functions saves several inputs in something like a
    common buffer, that use both functions */
}