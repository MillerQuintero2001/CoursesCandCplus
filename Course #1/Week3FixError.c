/** 
 * Author: Miller Quintero
 * Date: Jul 16, 2023
 * Program: This print a table of 30 different values of sine, using a for loop
*/
#include<stdio.h>
#include<math.h> /* has  sin(), abs(), and fabs() */
int main(void){ 
   double interval;
   int i;
   for(i = 0; i <30; i++){
      interval = i/10.0;
      // The mistake in this code was the using of abs() function, we shuould use fabs(), because these are floating values
      printf("sin( %lf ) = %lf \t", interval, fabs(sin(interval)));
      if((i+1)%6==0){
         printf("\n");
      }
   }
   printf("\n+++++++\n");
   return 0;
}