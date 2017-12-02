#include <iostream>
using namespace std;
class complex
{
	int real, imaginary;
	public:
		complex(int r, int i) {real=r; imaginary=i;}
		complex(complex &);
		complex(){}
		~complex(){}
		int get_real(){return real;}
		int get_imaginary(){return imaginary;}
		void set_real(int r){real=r;}
		void set_imaginary(int i){imaginary =i;}
		void print(){cout<< real << " + i" <<imaginary << endl;}
		void increment(){real++;}
		void accumulate(complex c)
		{
			real+=c.get_real();
			imaginary+=c.get_imaginary();
		}
		
};

complex::complex(complex &c)
{
	real =c.real; imaginary = c.imaginary;
}

complex add(complex c1, complex c2)
{

	int r =(c1.get_real()+c2.get_real());
	int i= (c1.get_imaginary()+c2.get_imaginary());
	complex c(r, i);
	return c;
}

complex multiply(complex c1, complex c2)
{
	complex res;
	res.set_real(c1.get_real()*c2.get_real() - c1.get_imaginary()*c2.get_imaginary());
	res.set_imaginary(c1.get_real()*c2.get_imaginary() + c1.get_imaginary()*c2.get_real());
	return res;	
}

int main()
{
	complex c1(5,4);
	complex c2(3,2);
	complex c3;
	c3 = add(c1, c2);
	c3.print();
	multiply(c1, c2).print();
}


