/** 
 * Author: Miller Quintero
 * Date: Jul 18, 2024
 * Title: Intro to Classes
 * Program: This programs introduces to basic classes in C++
*/

#include <iostream>
using namespace std;

// First we use the attribute 'class" to define the object rectangle
class rectangle{
    // Now, define what methods will be public
    public:
        // This is the constructor method of the class
        rectangle(double h, double w): height(h), width(w){};
        // This is the function that returns the area
        double area(){return height*width;}
    private:
        // In private we define the height and the width
        double height,width;
};

int main(void){
    // Here, the object is created
    rectangle r(2.5,2.1);
    // Save the area, accesing to the area method by the object
    double a = r.area();
    // Print the result
    cout << "The area of the rectangle is "<< a << " u²." << endl;
    return 0;
}