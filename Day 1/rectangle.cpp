#include <iostream>
#include <iostream>
using namespace std;

class rectangle
{
    float length, breadth;
    public:
        rectangle(float length, float breadth) {set_length(length); set_breadth(breadth);}
        void set_length(float length){this->length = length;}
        void set_breadth(float breadth){this->breadth = breadth;}
        float get_breadth() {return this->breadth;}
        float get_length() {return this->length;}
        float area() {return length*breadth;}
        float perimeter() {return 2*(length+breadth);}
};

int main()
{
    rectangle r1(10, 10);
    cout << "Area = " << r1.area() << endl;
    cout << "Perimeter = " << r1.perimeter() << endl;
}