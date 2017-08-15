/*

C++ Lab Day 2
---------------
Q2. Define a rational number class with member functions add, subtract,
multiply and divide.

Akshay Anand
CSE 5th Sem
Aug, 2017

*/

#include <iostream>
using namespace std;

int gcd(int x, int y)
{
    if(x%y==0)
        return y;
    else 
        return gcd(y%x, x);    
}

class rational
{
    int numerator, denominator;
    public:
        rational(int x, int y){numerator=x; denominator=y;}
        void setD(int d){this->denominator=d;}
        void setN(int n){this->numerator=n;}
        int getD(){return denominator;}
        int getN(){return numerator;}
        void add(rational r1);
        void subtract(rational r1);
        void multiply(rational r1);
        void divide(rational r1);
        void display(){
            if(denominator==1)
                cout<< numerator << endl;
            else if(denominator<0)
            {
                int g=gcd(numerator, denominator);  
                cout<<-1*numerator/g<< "/"<<-1*denominator/g << endl;   
            }
            else
            {    
                int g=gcd(numerator, denominator);    
                cout<<numerator/g<< "/"<<denominator/g << endl;

            }
        }

};

void rational::add(rational r1)
{
    int d= this->getD() * r1.getD();
    int n= this->getN()*r1.getD() + r1.getN()*this->getD();
    int g= gcd(d,n);
    this->setD(d/g);    
    this->setN(n/g); 
}

void rational::subtract(rational r1)
{
    int d= this->getD() * r1.getD();
    int n= this->getN()*r1.getD() - r1.getN()*this->getD();
    int g= gcd(d,n);
    this->setD(d/g);    
    this->setN(n/g); 
}

void rational::multiply(rational r1)
{
    int d= this->getD() * r1.getD();
    int n= this->getN() * r1.getN();
    int g= gcd(d,n);
    this->setD(d/g);    
    this->setN(n/g);
}

void rational::divide(rational r1)
{
    int n= this->getN() * r1.getD();
    int d= this->getD() * r1.getN();
    int g= gcd(d,n);
    this->setD(d/g);    
    this->setN(n/g);
}

int main()
{
    rational r1(3,4);
    r1.display();
    rational r2(6,4);
    r2.display();
    //r1.add(r2);
    r1.divide(r2);
    r1.display();   
}

/* OUTPUT
-------------

3/4
3/2
1/2

*/