/** 
 * Author: Miller Quintero
 * Date: Oct 12, 2024
 * Program: This program receive a number from user input and generate X employees with it, a print its information
*/

#include <stdio.h>      // Library to use standard inputs and outputs
#include <stdint.h>     // Library to use integers defined by bits size
#include <stdbool.h>    // Library that brings boolean data types
#include <stdlib.h>     // Libreary standard of C with a lot of important functions
#include <time.h>       // Library with time functions, current time used as seed generator

typedef enum deparment_t{
    HR,
    SALES,
    RESEARCH,
    SOFTWARE,
    EXECUTIVE
}deparment_t;

typedef struct employee_t{
    deparment_t typeEmployment;
    uint32_t annualSalary;
    uint32_t socialSecurityID;
}employee_t;

/* Functions Proto-types */
void generateRandomEmployment(employee_t* listJobs, uint8_t size);
void printEmployments(employee_t* listJobs, uint8_t size);

/** Main function */
int main(void){
    uint8_t howMany;
    do{
        printf("Please, input how many employees you want to generate, no more than 255: ");
        scanf("%hhu", &howMany);
    }while(howMany > 255);
    employee_t jobs[howMany];
    srand(time(NULL));
    generateRandomEmployment(jobs, howMany);
    printEmployments(jobs, howMany);
    return 0;
}


void generateRandomEmployment(employee_t* listJobs, uint8_t size){
    for(uint8_t i = 0; i < size; i++){
        (listJobs+i)->typeEmployment = ((deparment_t)rand())%(EXECUTIVE+SALES);
        uint32_t salaryPerYear;
        switch ((listJobs+i)->typeEmployment){
        case (HR):
            salaryPerYear = 74000 + rand()%15000;
            break;
        case (SALES):
            salaryPerYear = 80000 + rand()%5000;
            break;
        case (RESEARCH):
            salaryPerYear = 87000 + rand()%30000;
            break;
        case (SOFTWARE):
            salaryPerYear = 120000 + rand()%50000;
            break;
        case (EXECUTIVE):
            salaryPerYear = 150000 + rand()%100000;
            break;
        default:
            salaryPerYear = 0;
            break;
        }
        (listJobs+i)->annualSalary = salaryPerYear;
        (listJobs+i)->socialSecurityID = rand()%100000 + 10000000;
    }
}

void printEmployments(employee_t* listJobs, uint8_t size){
    for(uint8_t k = 0; k < size; k++){
        printf("Employee #%hhu:\n", k+1);
        char *strEmployee;
        switch ((listJobs+k)->typeEmployment){
        case (HR):
            strEmployee = "Human Resources";
            break;
        case (SALES):
            strEmployee = "Sales";
            break;
        case (RESEARCH):
            strEmployee = "Research";
            break;
        case (SOFTWARE):
            strEmployee = "Software";
            break;
        case (EXECUTIVE):
            strEmployee = "Executive";
            break;
        default:
            strEmployee = "No registered";
            break;
        }
        printf("Deparment: %s.\n", strEmployee);
        printf("Annual Salary: $%u.\n", (listJobs+k)->annualSalary);
        printf("Social Security Number: ID#%u.\n", (listJobs+k)->socialSecurityID);
        putchar('\n');  
    }
}