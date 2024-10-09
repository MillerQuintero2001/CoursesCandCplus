/** 
 * Author: Miller Quintero
 * Date: Jul 13, 2023
 * Program: Determinate simple use of an umbrella according
 * to if outside is true, and rain is true
*/

#include <stdio.h>
int main(){
    int outside, wheather;
    printf("\nEnter if outside 1 true 0 false: ");
    scanf("%d", &outside);
    printf("\nEnter if rain 1 true 0 false: ");
    scanf("%d", &wheather);
    if(outside && wheather){
        printf("\nPlease use an umbrella. \n");
    }
    else{
        printf("\nDress normally. \n\n");
    }
    return 0;
}