/** 
 * Author: Miller Quintero
 * Date: Jul 18, 2024
 * Title: Miles to Kilometers
 * Program: This programs prints the input miles convert in kilometers in C++
*/
#include <iostream>
using namespace :: std;
const double milesToKm = 1.60934;

inline double convert(double miles);

int main(void) {
    // We initialize with a valid value to avoid errors
    double miles = 1;
    while(miles != 0){
        cout << "Input distance in milles, must be different from 0, or the program will end: ";
        cin >> miles;
        cout << "\nThe miles in kilometers are " << convert(miles) <<" km." << endl;
    }
    cout << endl;
    return 0;
}

inline double convert(double miles){
    return miles*milesToKm;
}