/** 
 * Author: Miller Quintero
 * Date: Jun 10, 2024
 * Program: Frist aproximation to typedef structures and simple structures
*/

#include <stdio.h>      // Library to can control standard inputs and outputs
#include <stdint.h>     // Library to can define varibales with more control, standard integers

typedef struct {
    int pips;
    char suit;
}card;
int main(void){
    card c1;
    c1.pips = 7;
    c1.suit = 'H';
    printf("Tha card number is %u of the suit %c\n", c1.pips, c1.suit);
    // Ahora con puntero
    card* ptrCard1 = &c1;
    ptrCard1->pips = 8;
    ptrCard1->suit = 'S';
    printf("Tha card number changed by using pointer is %u of the suit %c\n", c1.pips, c1.suit);
    //Es necesario usar () porque el operador de acceso a miembros de estructura . tiene mayor precedencia que el de desreferenciación *
    (*ptrCard1).pips = 10;
    (*ptrCard1).suit = 'C';
    printf("Tha card number changed by using desreferenced pointer is %u of the suit %c\n", ptrCard1->pips, ptrCard1->suit);
    return 0;
}