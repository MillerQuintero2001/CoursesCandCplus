/** 
 * Author: Miller Quintero
 * Date: Jun 11, 2024
 * Program: Dates of the year printer, with next day functions and structures
*/

#include <stdio.h>      // Library to use standard inputs and outputs
#include <stdint.h>     // Library to use integers defined by bits size
#include <stdbool.h>    // Library that brings boolean data types

// Created data type structs
typedef enum{
    JAN,FEB,MAR,APR,MAY,JUN,
    JUL,AUG,SEP,OCT,NOV,DEC
}month_t;

/* Here there's something interesting, the order in that the structure is declared affets its final size
in bytes, this due to the 'padding', to optimize the size, is better write thinking in memory blocks of
4 bytes; all enums have 4 bytes by default, for that reason the month_t has 4 bytes, so is better if 
this is wrote first, after, day and year have 1 byte and 2 bytes respectly, together are 3 bytes, and the 
compiler adds 1 padding byte to complete 4 bytes, for a final size of 8 bytes. If the month_t member is
put in the middle of the structure (between day and year), there will be more padding bytes, resulting
in a structure of 12 bytes, 1 byte for day with 3 padding bytes, 4 bytes of month_t, and 2 bytes for 
the year with 2 padding bytes */
typedef struct{
    month_t month;
    uint8_t day;
    uint16_t year; 
}date_t;

/* Functions Proto-types */
date_t nextDay(date_t* d);
bool isLeapYear(uint16_t year);
void printDate(date_t d);

/* Main function with the tasks */
int main(void){
    // Initialize with array notation
    date_t dateList[6] = {{JAN,1,2024}, {FEB,28,2023}, {MAR,14,2024}, {OCT,31,1944}, {DEC,31,2001}, {FEB,28,2400}}; 
    // Iterate in the dates list
    uint8_t size = (uint8_t)sizeof(dateList)/sizeof(date_t);
    for(uint8_t i = 0; i < size; i++){
        printf("The %u° date is:\n",i+1);
        printDate(*(dateList+i));
        printf("Its next day is:\n");
        printDate(nextDay(dateList+i));
        printf("\n");
    }
    return 0;
}

/** Function that returns the next day according to the input date */
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
            limit = (isLeapYear(d->year)) ? 29:28;
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
        nextDate.year = (d->month == DEC)?(d->year + 1):(d->year);
    }
    else{
        nextDate.day = d->day+1;
        nextDate.month = d->month;
         nextDate.year = d->year;
    }
    return nextDate;
}

bool isLeapYear(uint16_t year){
    return (((year % 4 == 0)&&(year % 100 != 0)) ? (true):(((year % 100 == 0)&&(year % 400 == 0)) ? (true):(false)));
}

/** Function that prints dates */
void printDate(date_t d){
    const char* currentMonth[] = {"January", "February", "March", "April","May", "June",
     "July", "August", "September", "October", "November", "December"};
    printf("%s %hhu of %hu.\n", currentMonth[d.month], d.day, d.year);
}