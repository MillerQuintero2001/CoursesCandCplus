/** 
 * Author: Miller Quintero
 * Date: Jul 15, 2023
 * Program: This program determine the speeding ticker according to
 * speed value enter, using the ternary operator and switch case
*/
#include <stdio.h>


/* This program uses ternary operator with nesting, this allow cover all range values in only 3 numbers to determine the case, so, when it
 * enters to the switch-case, we have everything more direct. So the valuable idea is to encompass several possible values ​​in a range into a 
 * single value that represents the range, and use it for the other actions of the program. */
int main(void){
    int speed;
    printf("Enter your speed as an integer: ");
    scanf("%d", &speed);
    // Ternary operator nested within another
    speed = (speed <= 65)? (65):((speed <= 70)? (70):(90));
    switch (speed)
    {
    case 65:
        printf("\nNo speeding Ticket\n\n");
        break;

    case 70:
    printf("\nSpeeding Ticket\n\n");
        break;

    case 90:
        printf("\nExpensive speeding Ticket\n\n");
        break;    

    default:
        printf("\nIncorrect speed \n\n");
        break; // This 'break' isn't necessary, due to this is the last switch-case sentence, but is a good practice write it
    }
    return 0;
}