/** 
 * Author: Miller Quintero
 * Date: Jul 13, 2023
 * Program: Determinate according to a simple integer, if the limit of speed
 * has been exceed.
*/

#include <stdio.h>

int main(void){
    int speed;
    printf("\nPlease, enter your speed as an integer:");
    scanf("%d", &speed);
    if(speed < 65){
        printf("\nNo speeding a ticket\n\n");
    }
    else{
        printf("\nSpeeding ticket\n\n");
    }
    return 0;
}