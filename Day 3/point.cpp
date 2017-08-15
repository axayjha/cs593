/*

C++ Lab Day 3
---------------
Q2. Implement a point class of 3D points .
Include default constructor, a copy constructor,
a negate function to tranform that point into its negative.
A norm function to return the points distance from origin.
And a print function to print the coordinates of the point.

Akshay Anand
CSE 5th Sem
Aug, 2017

*/

#include <iostream>
#include <cmath>
using namespace std;

class point{
    double x,y,z;
public:
    point(double x, double y, double z) {
        this->x = x; this->y = y; this->z = z;
    }
    point(point &p);
    void negate();
    double norm();
    void print();


};

point::point(point &p)
{
    x=p.x; y=p.y; z=p.z;
}

void point::negate()
{
    x = -1*x; y = -1*y; z = -1*z;
}

double point::norm()
{
    return sqrt(x*x + y*y + z*z);
}

void point::print()
{
    cout << "( " << x << ", " << y << ", " << z << ")" << endl;
}

int main()
{
    point p(1,2,3);
    p.print();
    p.negate();
    p.print();
    cout << p.norm() << endl;

}

/* OUTPUT
-----------

( 1, 2, 3)
( -1, -2, -3)
3.74166

*/