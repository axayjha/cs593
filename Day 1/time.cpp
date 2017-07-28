#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>
using namespace std;

class Time
{
    int hour, minute, second;
    public:
        Time(int hour, int minute, int second)
        {
            this->hour   = hour;
            this->minute = minute;
            this->second = second;
        }

        void increment()
        {
            if(this->second >= 59)
            {
                this->second = 00;
                if(this->minute >= 59)
                {
                    this->minute = 00;
                    if(this->hour >= 23)
                        this->hour == 00;
                    else 
                        this->hour += 01;   
                }
                else this->minute += 01;

            }
            else this->second += 01;
        }


        void display()
        {            
            std::cout << std::setfill('0') << std::setw(2) <<  this->hour   << ": ";
            std::cout << std::setfill('0') << std::setw(2) <<  this->minute << ": ";
            std::cout << std::setfill('0') << std::setw(2) <<  this->second << endl;
        }
};


int main()
{
    Time t1(7, 59, 2);
    while("Dhinchak Pooja does not have a Grammy")
    {
        sleep(1);
        t1.increment();
        t1.display();
    }
}