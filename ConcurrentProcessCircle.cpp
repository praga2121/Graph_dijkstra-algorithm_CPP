/*References:
1. https://www.w3resource.com/cpp-exercises/basic/cpp-basic-exercise-43.php
2. https://www.techcrashcourse.com/2017/01/cpp-program-to-calculate-area-circumference-of-circle.html
3. https://www.code4example.com/cpp/cpp-program-to-calculate-area-and-perimeter-of-circle/
*/

#include<bits/stdc++.h>
#include <math.h>
# define M_PI           3.14159265358979323846  /* pi */

using namespace std;

const double PI = M_PI;

pair<double, double> calculate (double radius) {
    pair<double, double> result;    //storing area and perimeters for each circle in pair
    result.first = PI * radius * radius;    //area of the circle with radius 'radius'
    result.second = 2 * PI * radius;    //perimeter of the circle with radius 'radius'

    return result;
}

int main() {
    double radius[10];  //array to store radius of all 10 circles
    cout<<"Enter radius of 10 circles: " <<endl;
    for (int i=0; i<10; i++) {
        cin>>radius[i];
    }

    // to print in a table like structure
    cout
        << left
        << setw(10)
        << "Radius"
        << left
        << setw(15)
        << "Perimeter"
        << left
        << setw(15)
        << "Area"
        << endl;

    for (int i=0; i<10; i++) {
        //function call for each circle
        pair<double, double> resultForCurrentCircle = calculate(radius[i]);

        // to print in a table like structure
        cout
            << left
            << setw(10)
            << radius[i]
            << left
            << setw(15)
            << resultForCurrentCircle.second
            << left
            << setw(15)
            << resultForCurrentCircle.first
            << endl;

    }
    return 0;
}
