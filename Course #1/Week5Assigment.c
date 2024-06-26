/** 
 * Author: Miller Quintero
 * Date: Jul 22, 2023
 * Program: This code reads a .txt text file with weight data for a population 
 * of 1000 elephants, saves the data in an array, and calculates the average weight.
*/

// Include importants libraries
#include <stdio.h>      // Library for standard inputs and outputs
#include <stdint.h>     // Library of standard integers, to have better memory control
#include <stdbool.h>    // LIbrary of standard boolean, to can declare boolean variables

/* Definition of proto-types functions */
bool readData(char* strPath, uint32_t arraySave[], uint16_t size);
double calculateAverage(uint32_t arrayData[], uint16_t size);

// Matrix size macro-definition
#define SIZE 1000


int main(void){
    // Array where elephant population weight data will be saved
    uint32_t elephantData[SIZE] = {0};
    // Flag variable in which a "true" will be saved if the file was read correctly
    bool flagReadArchive; 

    // File reading, data storage and boolean return.
    /* NOTE: Here, if you want to run this code, CHANGE the file path to your path, check that your file has 
    only integer values, copy it exactly as it is on the course website, and make sure your path is correct as well. */
    flagReadArchive = readData("/home/miller/Escritorio/ElephantData.txt", elephantData, SIZE);

    // If the archive has been read successfully, print the average
    if(flagReadArchive){
        printf("The average weight of the elephants population is %.3f\n", calculateAverage(elephantData, SIZE));
    }
    // Else, print error message
    else{
        printf("Error reading data, verify your file.\n");
    }
    return 0;
}


/** Function that reads the .txt file, and saves the data in an array based on size*/
bool readData(char* strPath, uint32_t arraySave[], uint16_t size){
    // Variable to store the read value
    uint16_t value;  
    // Variable to store the value of the index    
    uint16_t i = 0;
    // Open file using PC path specified as string
    FILE *file = fopen(strPath, "r");

    // If the archive is empty, return false
    if(file == NULL){
        return false;
    }
    // Else, save the values in the array
    else{
        while((fscanf(file, "%hu", &value) == 1) && (i < size)){
            arraySave[i] = value;
            i++;
        }
        // Close file
        fclose(file);
        return true;
    }
}

/** Function that receives an array of integers and calculates the average value, based on the size of the array.*/
double calculateAverage(uint32_t arrayData[], uint16_t size){
    uint32_t sum = 0;
    for(uint16_t i = 0; i < size; i++){
        sum += arrayData[i];
    }
    return (double)sum / (double)size;
}