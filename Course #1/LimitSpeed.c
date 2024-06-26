/** 
 * Author: Miller Quintero
 * Date: Jul 15, 2023
 * Program: This program determine the speeding ticker according to
 * speed value enter, using the ternary operator and switch case
*/
#include <stdio.h>


/* En este programa se usa el operador ternario de evaluador condicional anidado dentro de otro
 * esto permite englobar todos los rangos de valores en 3 números que determinan el caso, y así
 al pasar el switch case tenemos todo mucho más directo, así pues la idea valiosa es englobar varios
 posibles valores en un rango en un solo valor que representa el rango, y utilizarlo para las demás 
 acciones del programa
*/
int main(void){
    int speed;
    printf("\nEnter your speed as an integer:");
    scanf("%d", &speed);
    // Operador condicional anidado dentro de otro
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
        break; // El break del default no es necesario ya que es la última sentencia del switch-case, pero es buena práctica
    }
    return 0;
}