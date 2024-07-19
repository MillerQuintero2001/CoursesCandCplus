/** 
 * Author: Miller Quintero
 * Date: Jul 18, 2024
 * Title: Factorial
 * Program: This programs prints a table of factorials as you wish
*/
#include <iostream>
using namespace :: std;

inline unsigned long factorial(unsigned int n);

int main(void) {
    unsigned short until;
    cout << "Input until what factorial will be printed: ";
    cin >> until;
    for(auto i = 0; i <= until; i++){
        cout << i << "! is equal to "<< factorial(i) << "." << endl;
    }
    cout << "That's all folks!" << endl;
    cout << "Sizeof(unsigned long) = " << sizeof(unsigned long) << endl;
    cout << "Sizeof(unsigned int) = " << sizeof(unsigned int) << endl;
    cout << "Sizeof(unsigned short) = " << sizeof(unsigned short) << endl;
    cout << "Sizeof(unsigned char) = " << sizeof(unsigned char) << endl;
    return 0;
}

inline unsigned long factorial(unsigned int n){
    if(n== 0){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}