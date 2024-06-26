/** 
 * Author: Miller Quintero
 * Date: Jun 5, 2024
 * Program: Size of data types
*/

#include <stdio.h>  // Pre-proccesing command
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h> 

int main(void){

    printf("%lu\n",sizeof(uint8_t));
    printf("%lu\n",sizeof(uint16_t));
    printf("%lu\n",sizeof(uint32_t));
    printf("%lu\n",sizeof(uint64_t));
    printf("%lu\n",sizeof(__uint128_t));
    printf("%lu\n",sizeof(uint_fast8_t)); 
    printf("%lu\n",sizeof(uint_fast16_t));
    printf("%lu\n",sizeof(uint_fast32_t));
    printf("%lu\n",sizeof(uint_fast64_t));  
    printf("%lu\n",sizeof(uint_least8_t)); 
    printf("%lu\n",sizeof(uint_least16_t));
    printf("%lu\n",sizeof(uint_least32_t));
    printf("%lu\n",sizeof(uint_least64_t)); 
    printf("UintMax %lu\n",sizeof(uintmax_t));
    printf("UintPtr %lu\n",sizeof(uintptr_t));
    printf("%lu\n",sizeof(int8_t));
    printf("%lu\n",sizeof(int16_t));
    printf("%lu\n",sizeof(int32_t));
    printf("%lu\n",sizeof(int64_t));
    printf("%lu\n",sizeof(__int128_t));
    printf("%lu\n",sizeof(int_fast8_t));
    printf("%lu\n",sizeof(int_fast16_t));
    printf("%lu\n",sizeof(int_fast32_t));
    printf("%lu\n",sizeof(int_fast64_t));
    printf("%lu\n",sizeof(int_least8_t));
    printf("%lu\n",sizeof(int_least16_t));
    printf("%lu\n",sizeof(int_least32_t));
    printf("%lu\n",sizeof(int_least64_t));
    printf("IntMax %lu\n",sizeof(intmax_t));
    printf("IntPtr %lu\n",sizeof(intptr_t));
    printf("\n");
    printf("%lu\n",sizeof(char));
    printf("%lu\n",sizeof(signed char));
    printf("%lu\n",sizeof(unsigned char));
    printf("%lu\n",sizeof(short));
    printf("%lu\n",sizeof(signed short));
    printf("%lu\n",sizeof(unsigned short));
    printf("%lu\n",sizeof(int));
    printf("%lu\n",sizeof(long int));
    printf("%lu\n",sizeof(long long int));
    printf("%lu\n",sizeof(unsigned int));
    printf("%lu\n",sizeof(long unsigned int));
    printf("%lu\n",sizeof(long long unsigned int));
    printf("%lu\n",sizeof(float));
    printf("%lu\n",sizeof(double));
    printf("%lu\n",sizeof(long double));
    return 0;
}