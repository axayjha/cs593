#include <iostream>
using namespace std;
class celcius;
class fahrenheit
{
	float temp;
	public:
		fahrenheit(){}
		fahrenheit(float value){temp = value;}
		friend celcius convert(fahrenheit);
		friend fahrenheit convert(celcius);
		void print(){cout<<temp<<" degF" << endl;}
		
};

class celcius
{
	float temp;
	public:
		celcius(){};
		celcius(float value){temp = value;}
		void print(){cout<<temp<<" degC" << endl;}
		friend celcius convert(fahrenheit);
		friend fahrenheit convert(celcius);
};

celcius convert(fahrenheit f)
{	
	celcius c;
	c.temp = (f.temp-32)*5/9;
	return c;	
} 

fahrenheit convert(celcius c)
{	
	fahrenheit f;
	f.temp = 9*c.temp/5 + 32;;
	return f;	
} 


int main()
{
	celcius c(100);
	fahrenheit f;
	f = convert(c);
	f.print();
	
}
