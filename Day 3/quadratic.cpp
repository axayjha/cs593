/*

C++ Lab Day 3
---------------
Q3. WAP to find the roots of a quadratic equation
without using member function.

Akshay Anand
CSE 5th Sem
Aug, 2017

*/

#include <iostream>
#include <cmath>
using namespace std;

class quadratic
{
    int a, b, c;
public:
    quadratic(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }   
    int get_a(){return this->a;}
    int get_b(){return this->b;}
    int get_c(){return this->c;}
};

double root(quadratic *q)
{
    int a= q->get_a(), b=q->get_b(), c=q->get_c();
    double d= b*b- 4*a*c;
    if(d<0)
    {
        cout << "Imaginary roots" << endl;
        return -9999;
    }
    return (-1*b + sqrt(d))/(2*a);
}

int main()
{
    quadratic q(1,2,1);
    cout << "Root of the eqn = " << root(&q) << endl;
}

/* OUTPUT
------------
Root of the eqn = -1

*/
