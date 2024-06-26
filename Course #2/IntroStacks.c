/** 
 * Author: Miller Quintero
 * Date: Jun 11, 2024
 * Program: Introduction to data stacks
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 1000
#define EMPTY -1
#define FULL (MAX_LEN-1)

typedef struct{
    char charStack[MAX_LEN];
    int16_t top; // Use a signed integer because EMPTY is -1, this must be so because in an array, the first element is at the index 0
}stack_t;

/* Proto-types of functions */
void push(char c, stack_t* dataStack);
char pop(stack_t* dataStack);
void reset(stack_t* dataStack, uint16_t topStack);
bool isStackEmpty(stack_t* dataStack);
bool isStackFull(stack_t* dataStack);


/** Main function with all actions of the program */
int main(void){
    // Initialize the variables
    stack_t stringStack = {0};
    char str[] = "Hi, I'm Miller Quintero";
    // With the inverse string we assign its size automatically
    char strBack[sizeof(str)/sizeof(char)] = {0};

    printf("Original message is: %s\n", str);

    // The first thing that we gonna do is reset the array into the stack structure
    reset(&stringStack, MAX_LEN);

    // Now, is time to save the characters into the stack
    uint8_t k = 0;
    while(*(str+k)!='\0'){
        push(*(str+(k++)),&stringStack);
    }
    // Here, we add the null character to make sure that all is gonna be okay, but the top of the stack is still the last character
    *(stringStack.charStack+k) = '\0';

    printf("The message in the stack is: %s\n", stringStack.charStack);
    k = 0;

    // Finally we put one by one in the inverted order
    uint16_t indexToReset = stringStack.top;
    while(!isStackEmpty(&stringStack)){
        *(strBack+(k++)) = pop(&stringStack);
    }
    printf("Inverted message is: %s\n", strBack);
    // Reset the stack
    reset(&stringStack, indexToReset);
    return 0;
}

void push(char c, stack_t* dataStack){
    dataStack->top++;
    *(dataStack->charStack+dataStack->top) = c;
}

char pop(stack_t* dataStack){
    return*(dataStack->charStack+dataStack->top--);
}

void reset(stack_t* dataStack, uint16_t topStack){
    for(uint16_t i = 0; i <= topStack; i++){
        *(dataStack->charStack+i) = '\0';
    }
    dataStack->top = EMPTY;
}

bool isStackEmpty(stack_t* dataStack){
    return (bool)(dataStack->top == EMPTY);
}

bool isStackFull(stack_t* dataStack){
    return (bool)(dataStack->top == FULL);
}