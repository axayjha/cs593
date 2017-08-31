#include <iostream>
using namespace std;

class simple_base
{
    int base_var;
    public:
        simple_base(){
            cout << "simple_base called" << endl;
        }
};

class simple_derived : public simple_base{
    public:
        simple_derived(): simple_base()
        {
            cout << "simple_derived called" << endl;
        }
};

class multilevel_derived : public simple_derived
{
    public:
        multilevel_derived(): simple_derived()
        {
            cout << "multiple_derived called" << endl;
        }
};

class heirarchical_derived : public simple_base{
public:
    heirarchical_derived() : simple_base(){
        cout<< "heirarchical_derived called" << endl;
    }
};

class multiple_derived: public simple_derived, public heirarchical_derived
{
public:
    multiple_derived(): simple_derived(), heirarchical_derived()
    {
        cout <<"multiple_derived called" << endl;
    }
};

// trying to understand?
// don't even bother

int main()
{
    multiple_derived s;
}