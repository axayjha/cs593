/*

C++ Lab Day 2
---------------
Q3. Define a distance class with members feet and inch. Define a
constructor and destructor and a member function to access member
variables. Define a member function "add" which adds two distance
objects and stores the result in another distance object.

Akshay Anand
CSE 5th Sem
Aug, 2017

*/

#include <iostream>
// not using namespace std as another definition of distance exists there

class distance
{
    int feet, inch;
public:
    distance(){}
    distance(int feet, int inch){
        this->feet=feet; this->inch=inch;
        }
    ~distance(){}    
    void setF(int f){feet=f;}
    void setI(int i){inch=i;}
    int getF(){return feet;}
    int getI(){return inch;}
    distance add(distance d1);   
    void display(){std::cout<<feet<<"\' "<<inch << "\"" <<std::endl;}

};

distance distance::add(distance d1)
{
    distance sum;
    int i= this->getI() + d1.getI();
    int f = this->getF() + d1.getF();
    if(i>=12)
    {
        i-=12;
        f+=1;
    }
    sum.setF(f);
    sum.setI(i);
    return sum;
}


int main()
{
    distance d1(6,1);
    distance d2(6,11);
    distance d3 = d1.add(d2);    
    d3.display(); 
    
}

/*
OUTPUT
--------
13' 0"

*/