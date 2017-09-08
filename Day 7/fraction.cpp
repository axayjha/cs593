#include <iostream>

using namespace std;

int gcd(int x, int y)
{
	if(x%y ==0) return y;
	else return gcd(y%x, x); 
}

class fraction
{
	int numerator, denominator;
	public:
		fraction(){}
		fraction(int , int);
		fraction(int n){fraction(n,1);}
		void reduce();	
		void set_n(int n){numerator = n;}	
		void set_d(int d){denominator = d;}
		int get_n(){return numerator;}
		int get_d(){return denominator;}
		
	
};

class fraction_d : public fraction
{
	public:
		fraction_d():fraction(){}
		fraction_d(int n, int d):fraction(n,d){}
		fraction_d(int n):fraction(n,1){}
		bool operator!()
		{
			return (get_n()==0) && (get_d()==0);
		}
		
};

fraction :: fraction (int n, int d)
{
	if(n==d==0) return;
	numerator  = n; denominator  = d;
}

void fraction::reduce()
{	
	int g = gcd(numerator, denominator);
	numerator /= g;
	denominator /= g;
}

int main()
{
	fraction_d f(0,0);
	if(!f) puts("f1 is invalid");
	fraction_d f2(6,4), f3(2);
	
}
