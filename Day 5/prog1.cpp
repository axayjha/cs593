#include <iostream>
#include <string>
using namespace std;

class Driver
{
	string name;
	int age;
	public:
		Driver(){}
		Driver(string n, int a )
		{
			name=n; age=a;
		}
		Driver(Driver &d);
		~Driver(){};
		string getname(){return name;}
		int getage(){return age;} 
		void print();
};
Driver::Driver(Driver &d)
{
	name = d.name;
	age = d.age;
}
void Driver::print()
{
	cout<< "Name: " << name << endl;
	cout<< "Age: " << age << endl;
}

class automobile
{
	string maker; int year; Driver driver;
	public:
		automobile(string m, int y, Driver d)
		{
		
			maker = m; year = y; driver=d;
		}
		automobile(automobile &a);
		~automobile(){}
		void print()
		{			
			this->driver.print();
			cout<< "Maker: " << maker << endl;
			cout<< "Year: " << year << endl;
		}
		
		
};

automobile::automobile(automobile &a)
{
	maker = a.maker;
	year = a.year;
	driver = a.driver;
}

automobile* initiate()
{
	string name, maker;
	int age, year;
	cout<< "Enter name of the driver: ";
	cin >> name;
	cout<< "Enter age of the driver: ";
	cin >>age;
	Driver d(name, age);
	
	cout<< "Enter maker of the automobile: ";
	cin >> maker;
	cout<< "Enter the year: ";
	cin >> year;
	automobile *am = new automobile(maker, year, d);
	return am;
}

int main()
{
		automobile *a = initiate();
		
		a->print();
}
