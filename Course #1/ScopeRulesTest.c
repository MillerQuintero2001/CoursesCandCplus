/** 
 * Author: Miller Quintero
 * Date: Jul 16, 2023
 * Program: Check the scope rules, see the limitations and useful life of the variables
*/

#include <stdio.h>

int i = 7;


int main(void){
    if(1){
        int i = 5;
        printf("i = %d\n", i);
        if(1){
            int i = 3;
            printf("i = %d\n", i);
        }
        printf("i = %d\n", i);
    }
    printf("i = %d\n", i);
    return 0;
}
