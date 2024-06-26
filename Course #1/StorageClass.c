/** 
 * Author: Miller Quintero
 * Date: Jul 17, 2023
 * Program: The purpose of this code is see the use
 * of types storage variables
*/

#include <stdio.h>


void f(void);   // Prototipo de función
int reps = 1; // Originalmente se declaraba como extern int, pero esto es solo cuando se usa una variable de otro archivo



int main(void){
    auto int i = 1;         // El almacenamiento automático es el que tiene por defecto cualquier variable declarada de forma simple en C
    const int Limit = 10;   // Este tipo de almacenamiento, como lo dice, deja el valor constante, solo puede ser leído pero no operado
    for( i = 1; i < Limit; i++){
        printf("i local = %d, reps global = %d\n", i, reps);
        f();
    }
    return 0;
}

void f(void){
    static int called = 1;  // Útil para funciones, el almacenamiento tipo estático, mantiene su valor entre llamadas de la función
    printf("f called #%d\n", called);
    called++;
    reps = reps + called;
}

