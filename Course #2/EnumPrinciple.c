/** 
 * Author: Miller Quintero
 * Date: Jun 09, 2024
 * Program: This code is a simple example of enum types
*/

#include <stdio.h>      // Library to can control standard inputs and outputs
#include <stdint.h>     // Library to can define varibales with more control, standard integers

enum day {SUN,MON,TUE,WED,THU,FRI,SAT};

/* Function Proto-types */
void printDay(enum day dayOfWeek);
enum day nextDay(enum day dayOfWeek);

int main(void){
    printDay(5);
    printDay(FRI);
    printDay(7);
    printDay(nextDay(SAT));
    return 0;
}

void printDay(enum day dayOfWeek){
    switch (dayOfWeek){
    case(SUN):
        printf("Sunday\n");
        break;
    case(MON):
        printf("Monday\n");
        break;
    case(TUE):
        printf("Tuesday\n");
        break;
    case(WED):
        printf("Wednesday\n");
        break;   
    case(THU):
        printf("Thursday\n");
        break; 
    case(FRI):
        printf("Friday\n");
        break;
    case(SAT):
        printf("Saturday\n");
        break;    
    default:
        printf("Erroneus day\n");
        break;
    }
}

enum day nextDay(enum day dayOfWeek){
    return ((dayOfWeek+1)%7);
}