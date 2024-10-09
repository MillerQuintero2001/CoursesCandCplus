/** 
 * Author: Miller Quintero
 * Date: Jul 17, 2023
 * Program: The purpose of this code is see the use
 * of types storage variables
*/

#include <stdio.h>

/* Function proto-type definition */
void f(void);   
// Originally this variable was declared as extern int, but this is only when a variable from another archive is used
int reps = 1; 


int main(void){
    // Automatic storage is the storage by default of any variable declared in a simple way in C
    auto int i = 1;
    // Constant stoarage, keeps the variable's value conbstant, it can be read and use, but not changed         
    const int Limit = 10;
    for( i = 1; i < Limit; i++){
        printf("i local = %d, reps global = %d\n", i, reps);
        f();
    }
    return 0;
}

void f(void){
    /* Static keyword is useful for functions, to keep his value between calls, which means no matter 
    the explicit declaration of 'static int called = 1', the variable receive a global variable treatment */
    static int called = 1;
    printf("f called #%d\n", called);
    called++;
    reps = reps + called;
}

