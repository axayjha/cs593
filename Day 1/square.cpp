#include <iostream>
#include <iostream>
using namespace std;

class square
{
    float edge;
    public:
        square(float edge) {set_edge(edge);}
        void set_edge(float edge){this->edge = edge;}
        float get_edge() {return this->edge;}
        float area() {return edge*edge;}
        float perimeter() {return 4*edge;}
};

int main()
{
    square s1(10);
    cout << "Area = " << s1.area() << endl;
    cout << "Perimeter = " << s1.perimeter() << endl;
}