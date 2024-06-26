/** 
 * Author: Miller Quintero
 * Date: Jun 10, 2024
 * Program: Example of use of different ways of pre-processor commands
*/

//#define NDEBUG // Este linea se puede "activar" en el compilador con la instrucción -DNDEBUG

#include <stdio.h>      // Library to can control standard inputs and outputs
#include <assert.h>     // Library to use asserts program
#include <ctype.h>      // Library with boolean processing

int main(void){
    double x,y;
    while(isalpha('a')){
        printf("Please enter 2 double number to execute a division:\n");
        scanf("%lf %lf", &x, &y);
        assert(y != 0);
        printf("%lf/%lf = %lf\n", x, y, x/y);
    }
    return 0;
}