/** 
 * Author: Miller Quintero
 * Date: Jul 18, 2024
 * Title: HelloWorldC++
 * Program: This programs prints a "Hello World" in C++
*/
#include <iostream>
using namespace :: std;

/** Main function */
int main(void) {
    /*If we don't write the directive 'namespace :: std', 
    we should write: std::cout << "Hello World" << std::endl; */
    // 'endl' do the same that '\n', a line jump
    cout << "Hello World" << endl;
    return 0;
}
