/*

C++ Lab Day 3
---------------
Q1. Implement a matrix class for 2X2 matrix. Include default
constructor (no args), copy constructor, an inverse function
that returns inverse of the matrix, a determinant function,
a boolean function isSingular() that returns 0 or 1 acc to 
whether determinant is 0 or not, and a print function to
print the matrix.

Akshay Anand
CSE 5th Sem
Aug, 2017

*/

#include <iostream>
using namespace std;

class matrix
{    
public:
    double arr[2][2];
    matrix(){}
    matrix(double, double, double, double);
    matrix(matrix &m);
    double determinant();
    bool isSingular();
    matrix inverse();    
    void print();
};

matrix::matrix(matrix &m)
{
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            arr[i][j] = m.arr[i][j];
}

matrix::matrix(double a, double b, double c, double d)
{
    arr[0][0]=a; arr[0][1]=b;
    arr[1][0]=c; arr[1][1]=d;
}


double matrix::determinant()
{
    return arr[1][1]*arr[0][0] - arr[1][0]*arr[0][1];
}

bool matrix::isSingular()
{
    if(this->determinant())
        return false;
    return true;    
}

matrix matrix::inverse()
{
    double d=this->determinant();
    matrix m1(*this);
    m1.arr[0][1]=this->arr[1][0]; m1.arr[1][0]=this->arr[0][1]; 
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            m1.arr[i][j] = m1.arr[i][j]/d;
    return m1;
}

void matrix::print()
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
            cout << arr[i][j] << " ";
        cout <<  endl;
    }

}

int main()
{
    matrix m1(1,2,3,4);
    m1.print();
    matrix m2;
    m2= m1.inverse();
    m2.print();
}

/* OUTPUT
------------
1 2
3 4
-0.5 -1.5
-1 -2

*/