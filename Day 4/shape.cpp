#include <iostream>
using namespace std;

class shape
{
    double length;
public:
    shape(){}
    void set_length(int length)
    {
        this->length = length;
    }
    double get_length()
    {
        return this->length;
    }
};

class TwoD : public shape
{
    double breadth;
public:
    TwoD(double l, double b)
    {
        set_length(l);
        breadth = b;
    }

    void set_breadth(double b)
    {
        breadth = b;
    }

    double get_breadth()
    {
        return breadth;
    }

    double area()
    {
        return get_length()*breadth;
    }

    double perimeter()
    {
        return 2*(get_length() + breadth);
    }
};


class rectangle : public TwoD
{
public:
    rectangle(double l, double b) : TwoD(l,b){}
};

class square: public TwoD{
public:
    square(double l) : TwoD(l,l){}
};

class triangle : public TwoD
{
public:
    triangle (double l, double b) : TwoD(l,b) {}
    double area()
    {
        return 0.5*get_length()*get_breadth();
    }

    double perimeter()
    {
        return 3*get_breadth(); // yeah its an equilateral triangle. #MaH cOdE, mAh RulZZZZ
    }
};

// The point where I start to wonder what am i doing with my life. 

class ThreeD : public shape
{
    double breadth, height;
public:
    ThreeD(double l, double b, double h)
    {
        set_length(l);
        breadth = b;
        height = h;
    }

    void set_breadth(double b)
    {
        breadth = b;
    }

    double get_breadth()
    {
        return breadth;
    }

    void set_height(double h)
    {
        height = h;
    }

    double get_height()
    {
        return height;
    }

};


class box : public ThreeD{
public:
    box(double l, double b, double h) : ThreeD(l,b,h){}

    double area()
    {
        double l = get_length();
        double h = get_height();
        double b = get_breadth(); 
        return 2*(l*b + b*h + h*l);
    }

    double volume()
    {
        return get_length()*get_breadth()*get_height();
    }
};

int main()
{
    box b(4,4,4);
    cout << "Volume: " << b.volume() << endl;
}