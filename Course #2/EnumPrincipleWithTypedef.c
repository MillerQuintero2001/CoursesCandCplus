/** 
 * Author: Miller Quintero
 * Date: Jun 09, 2024
 * Program: This code is a simple example of enum types simplified with a typedef
*/

#include <stdio.h>      // Library to can control standard inputs and outputs
#include <stdint.h>     // Library to can define varibales with more control, standard integers

// We can use this way to simplify more
typedef enum {
    SUN,MON,TUE,WED,THU,FRI,SAT}
    day;
/*  enum day{SUN,MON,TUE,WED,THU,FRI,SAT};
 typedef enum day day; */

/* Definition of prototypes functions */
void printDay(day);
day nextDay(day);

int main(void){
    printDay(5);
    printDay(FRI);
    printDay(7);
    printDay(nextDay(SAT));
    return 0;
}

void printDay(day dayOfWeek){
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

day nextDay(day dayOfWeek){
    return ((dayOfWeek+1)%7);
}