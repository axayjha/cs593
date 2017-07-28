#include <iostream>
#include <cstdlib>
using namespace std;

class temperature
{
    float degC, degF;
    public:
        temperature(int value, char unit)
        {
            //Constructor
            set(value, unit);
        }

        void set(int value, char unit)
        {
            
            if(unit == 'f' || unit == 'F')
            {
                degF = value;
                degC = (degF-32)*5/9;
            }
            
            else if(unit == 'c' || unit == 'C')
            {
                degC = value;
                degF = 9*degC/5 + 32;
            }

            else
            {
                cout << "Invalid input!" << endl;
                exit(0);
            }
        }

        void display()
        {
            cout << "Temperature: " << endl;
            cout << "degC: " << degC << "\t degF: " << degF << endl;
        }

};


int main()
{
    temperature t1(-40, 'f');
    t1.display();
    t1.set(212, 'f');
    t1.display();
}