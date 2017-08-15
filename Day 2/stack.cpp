/*

C++ Lab Day 2
---------------
Q1. Define a stack class whose member variable is an array. 
Member functions are push() and pop().

Akshay Anand
CSE 5th Sem
Aug, 2017

*/

#include <iostream>
#define MAXSIZE 20
using namespace std;

class stack
{
    double data[MAXSIZE];
    int top;
    public:
        stack() {top=-1;};
        void push(double data);
        double pop();

};

void stack::push(double data)
{
    if(this->top >= MAXSIZE)
    {
        std::cout << "STACK OVERFLOW" << endl;
        return;
    }

    this->data[++(this->top)] = data;
}

double stack::pop()
{
    if(this->top < 0 )
    {
        std::cout << "STACK UNDERFLOW" << endl;
        return -99999999;
    }
    return this->data[(this->top)--];
}


int main()
{
    stack st;
    st.push(3.9898);
    st.push(4);
    st.push(3.9848);
    cout << st.pop() << endl;
}

/* OUTPUT
-----------
3.9848

*/