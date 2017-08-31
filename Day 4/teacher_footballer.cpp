#include <iostream>
#include <string>
using namespace std;

class person{
    string name, profession; 
    int age;
public:
    person(string n, string profession, int a)
    {
        name=n; age=a;
    }
    void display()
    {
        cout << "Name = " << name << endl;
        cout << "Age = " << age << endl;
    }

    void walk()
    {
        cout << "I'm walking" << endl;
        // yeah you are a 3rd yr CS student and writing this function.
        // strangle yourself to death.
    }

    void talk()
    {
        cout << "I'm talking" << endl;
        // I'm puking blood
    }

};

class math_teacher : public person{
public:
    math_teacher(string name, int age) : person(name, "Math teacher", age){}

    void teach_math()
    {
        cout << "I'm teaching Math" << endl;
        // I need to wash hands after finishing this code        
    }

};


class footballer : public person{
public:
    footballer(string name, int age) : person(name, "Footballer", age){}

    void play_football()
    {
        cout << "I'm playing football" << endl;
        // ... and with my life    
        // T_T    
    }

};

int main()
{
    footballer f("akshay", 21);
    f.play_football();
}