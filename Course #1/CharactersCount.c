/** 
 * Author: Miller Quintero
 * Date: Jul 15, 2023
 * Program: This program count numbers, letters, blanks and special characters
*/

#include <stdio.h>

int main(void) {
    int blanks = 0, digits = 0, letters = 0, others = 0;
    int c;  // Variable para almacenar el valor entero del carácter

    // El EOF significa End of the File, y en Linux se especifíca con Ctrl+D
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
        } else if ((c >= '0') && (c <= '9')) {
            ++digits;
        } else if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))) {
            ++letters;
        } else {
            ++others;
        }
    }

    printf("\nblanks = %d, digits = %d, letters = %d, others = %d\n", blanks, digits, letters, others);
    return 0;
}
