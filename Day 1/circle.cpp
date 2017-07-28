#include <iostream>
using namespace std;

#define PI 3.14159

class circle
{
    float radius;
    public:
        circle(float radius) {set(radius);}
        void set(float radius) {this->radius = radius;}
        float get() {return this->radius;}
        float area() {return PI*radius*radius;}
        float circumference() {return 2*PI*radius;}
};

int main()
{
    circle c1(10);
    cout << "Area = " << c1.area() << endl;
}