/** 
 * Author: Miller Quintero
 * Date: Jul 19, 2023
 * Program: This code allow us obtain an average of the simple array's elements, like grades between 0 and 100, 
 * and print de address memory using pointers.
*/

#include <stdio.h>

/* Functions proto-types declarations */
void swap_no_change(int i, int j);
void swap_change(int* i, int* j);
void swap_global_change(void);
int ag, bg;

int main(void){
    int a, b;
    printf("Please enter 2 values to load into variables 'a' and 'b', and then try to swap them\n");
    printf("First: ");
    scanf("%d", &a);
    printf("Second: ");
    scanf("%d", &b);
    ag = a;
    bg = b;

    printf("Ok, we have a = %d and b = %d, let's aplicate swap_no_change function.\n", a, b);
    swap_no_change(a,b);
    printf("We have: a = %d and b = %d, because this function is called by value, now let's see with global change function.\n", a, b);
    swap_global_change();
    printf("Now, a = %d, b = %d, because this function use a global variable.\n", ag, bg);
    printf("Right, let's try with swap_change function, a = %d, b = %d.\n", a, b);
    swap_change(&a,&b);
    printf("Now, a = %d, b = %d, because this function is called by reference.\n", a, b);
    return 0;
}


void swap_no_change(int i, int j){
    int temp = i;
    i = j;
    j = temp;
}

void swap_change(int* i, int* j){
    // Temporal variable, it takes the value that 'i' pointer pointers
    int temp = *i;
    /* Assigment of 'j' pointer value to the 'i' pointer value, to achieve that
    is necessary use dereference operator '*' for both */ 
    *i = *j;
    // Now, assign the temp variable value to 'j' pointer value
    *j = temp;
}

void swap_global_change(void){
    int temp = ag;
    ag = bg;
    bg = temp;   
}