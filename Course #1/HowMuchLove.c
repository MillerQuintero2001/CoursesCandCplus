/** 
 * Author: Miller Quintero
 * Date: Jul 15, 2023
 * Program: Love you how much, with a while loop
*/

#include <stdio.h>

int main(void){
    int repeat = 0;
    printf("How strong is your love 1-10? : ");
    scanf("%d", &repeat);
    printf("\nI love you very");
    while(repeat > 0){
        printf("\nvery");
        repeat--;
    };
    printf(" much.\n\n");
    return 0;
}