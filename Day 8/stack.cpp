#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
const int SIZE = 10;

template <class stacktype> class stack
{
    stacktype st[SIZE];
    int tos;
    public:
        stack(){tos=0;}
        void push(stacktype ob);
        stacktype pop();
};

template <class stacktype> void stack<stacktype> :: push(stacktype ob)
{
    if(tos==SIZE)
    {
        cout << "STACK OVERFLOW" << endl;
        return;
    }
    else
        st[tos++]=ob;
}

template <class stacktype> stacktype stack<stacktype> :: pop()
{

    if(tos==0)
    {
        cout << "STACK UNDERFLOW" << endl;
        exit(0);
    }
    else return st[--tos];
}


int main()
{
    stack<int> st1;
    st1.push(3);

    stack <string>st2;
    st2.push("akshay");


    cout << st1.pop() << endl;
    cout <<st2.pop() << endl;
}
