#include <iostream>
#include <string>
using namespace std;

class person{
    string name;
    int age;
    public:
        person(string n, int a)
        {
            name =n;
            age=a;
        }
        void set_name(string n)
        {
            name=n;
        }

        string get_name()
        {
            return name;
        }

        void set_age(int a)
        {
            age=a;
        }
        int get_age()
        {
            return age;
        }
};

class faculty : public person{
    int salary; 
    public:
        faculty(string n, int a, int s) : person(n,a)
        {
            salary=s;
        }
        void set_salary(int s)
        {
            salary = s;
        }
        int get_salary()
        {
            return salary;
        }
};

// This code is cool ...
// ...maybe for commerce and arts students 

// ok carry on
// don't read these comments!
// these won't get compiled!
// or fetch you marks!

class student: public person{
    string dept;
    public:
        student(string n, int a, string d): person(n,a)
        {
            dept = d;
        }
        void set_dept(string d)
        {
            dept = d;
        }
        string get_dept()
        {
            return dept;
        }
};

class TA: public faculty, public student
{
    public:
        TA(string n, int a, string d, int s) : faculty(n,a,s), student(n,a,d){}
};

int main()
{
    TA t1("Akshay", 21, "CSE", 40000);
    cout << "TA name: " << t1.faculty::get_name()<<endl;
}