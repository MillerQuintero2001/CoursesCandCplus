/** 
 * Author: Miller Quintero
 * Date: Jun 10, 2024
 * Program: Example of use of different ways of pre-processor commands
*/

// This line disables asserts, can be also implemented by terminal compilation with the instruction "gcc -DNDEBUG code.c"
//#define NDEBUG 

#include <stdio.h>      // Library to can control standard inputs and outputs
#include <assert.h>     // Library to use asserts program
#include <ctype.h>      // Library with boolean processing

int main(void){
    double x,y;
    while(isblank('\t')){
        printf("Please enter 2 double number to execute a division:\n");
        scanf("%lf %lf", &x, &y);
        assert(y != 0);
        printf("%lf/%lf = %lf\n", x, y, x/y);
        char x = toupper('c');
        int numChar = printf("Upper %c, lower %c.\n", x, tolower(x));
        printf("%hd.\n",numChar);
    }
    return 0;
}