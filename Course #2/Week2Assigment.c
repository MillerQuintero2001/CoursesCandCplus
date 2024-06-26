/** 
 * Author: Miller Quintero
 * Date: Jun 11, 2024
 * Program: Dates of the year printer, with next day functions and structures
*/

#include <stdio.h>      // Library to use standard inputs and outputs
#include <stdint.h>     // Library to use integers defined by bits size

// Structures
typedef enum{
    JAN,FEB,MAR,APR,MAY,JUN,
    JUL,AUG,SEP,OCT,NOV,DEC
}month_t;

typedef struct{
    month_t month;
    uint8_t day;
}date_t;

/* Headers of the functions */
date_t nextDay(date_t* d);
void printDate(date_t d);

/* Main function with the task*/
int main(void){
    // Initialize with notation of array, because with pointer notation don't let initialize
    date_t dateList[5] = {{JAN,1}, {FEB,28}, {MAR,14}, {OCT,31}, {DEC,31}}; 
    // Iterate in the dates list
    for(uint8_t i = 0; i<5; i++){
        printf("The %u° date is:\n",i+1);
        printDate(*(dateList+i));
        printf("Its next day is:\n");
        printDate(nextDay(dateList+i));
        printf("\n");
    }
    return 0;
}

/** Function that return the next day according to the input date */
date_t nextDay(date_t* d){
    uint8_t limit = 0;
    date_t nextDate = {0};
    switch (d->month){
        // This months only have 30 days
        case (APR):
        case (JUN):
        case (SEP):
        case (NOV):
            limit = 30;
            break;
        // February has 28 days
        case (FEB):
            limit = 28;
            break; 
        // The others have 31 days   
        default:
            limit = 31;
            break;
    }

    // Limit day month control
    if(d->day+1 > limit){
        nextDate.day = 1;
        nextDate.month = (d->month+1)%12;
    }
    else{
        nextDate.day = d->day+1;
        nextDate.month = d->month;
    }
    return nextDate;
}

/** Function that prints dates */
void printDate(date_t d){
    const char* currentMonth[] = {"January", "February", "March", "April","May", "June",
     "July", "August", "September", "October", "November", "December"};
    printf("%s %u.\n", currentMonth[d.month], d.day);
}