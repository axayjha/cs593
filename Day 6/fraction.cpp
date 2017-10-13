

#include <iostream>
using namespace std;

int gcd(int x, int y)
{
    if(x%y==0)
        return y;
    else 
        return gcd(y%x, x);    
}

class rational
{
    int numerator, denominator;
    public:
        inline rational(int x, int y);
        inline rational(int x);
        inline rational(){}
        inline rational(rational *);
        inline rational(rational &r1);
        void setD(int d){this->denominator=d;}
        void setN(int n){this->numerator=n;}
        int getD(){return denominator;}
        int getN(){return numerator;}
        rational add(rational r1);
        rational subtract(rational r1);
        rational multiply(rational r1);
        rational divide(rational r1);
        void increment();
        friend rational add(rational const& r1, rational const& r2);
        friend rational subtract(rational const& r1, rational const& r2);
        friend rational mul(rational const& r1, rational const& r2);
        friend rational div(rational const& r1, rational const& r2);
        //friend rational add(rational r1,rational r2);
        void display(){
            if(denominator==1)
                cout<< numerator << endl;
            else if(denominator<0)
            {
                int g=gcd(numerator, denominator);  
                cout<<-1*numerator/g<< "/"<<-1*denominator/g << endl;   
            }
            else
            {    
                int g=gcd(numerator, denominator);    
                cout<<numerator/g<< "/"<<denominator/g << endl;

            }
        }
};

rational rational::add(rational r1)
{
	rational r;
	int d= this->getD() * r1.getD();
    int n= this->getN()*r1.getD() + r1.getN()*this->getD();
    int g= gcd(d,n);
    r.setD(d/g);    
    r.setN(n/g); 
    return r;
}

rational add(rational const& s1, rational const &s2)
{
	rational &r1 = const_cast<rational&>(s1);
	rational &r2 = const_cast<rational&>(s2);
	rational r;
	int d= r1.getD() * r2.getD();
    int n= r2.getN()*r1.getD() + r1.getN()*r2.getD();
    int g= gcd(d,n);
    r.setD(d/g);    
    r.setN(n/g); 
    return r;
}

rational subtract(rational const& s1, rational const &s2)
{
	rational &r1 = const_cast<rational&>(s1);
	rational &r2 = const_cast<rational&>(s2);
	rational r;
	int d= r2.getD() * r1.getD();
    int n= r2.getN()*r1.getD() - r1.getN()*r2.getD();
    int g= gcd(d,n);
    r.setD(d/g);    
    r.setN(n/g); 
    return r;
}


rational mul(rational const& s1, rational const &s2)
{
	rational &r1 = const_cast<rational&>(s1);
	rational &r2 = const_cast<rational&>(s2);
	rational r;
	int d= r2.getD() * r1.getD();
    int n= r2.getN() * r1.getN();
    int g= gcd(d,n);
    r.setD(d/g);    
    r.setN(n/g); 
    return r;
}

rational div(rational const& s1, rational const &s2)
{
	rational &r1 = const_cast<rational&>(s1);
	rational &r2 = const_cast<rational&>(s2);
	rational r;
	int n= r1.getN() * r2.getD();
    int d= r1.getD() * r2.getN();
    int g= gcd(d,n);
    r.setD(d/g);    
    r.setN(n/g); 
    return r;
}



inline rational::rational(int x, int y){numerator=x; denominator=y;}

inline rational::rational(rational &r1)
{
	denominator = r1.denominator;
	numerator = r1.numerator;
}

inline rational::rational(rational *r1)
{
	denominator = r1->denominator;
	numerator = r1->numerator;
}

inline rational::rational(int x) { numerator  = x; denominator =1;}



rational rational::subtract(rational r1)
{
	rational r;
    int d= this->getD() * r1.getD();
    int n= this->getN()*r1.getD() - r1.getN()*this->getD();
    int g= gcd(d,n);
    r.setD(d/g);    
    r.setN(n/g); 
    return r;
}

rational rational::multiply(rational r1)
{
	rational r;
    int d= this->getD() * r1.getD();
    int n= this->getN() * r1.getN();
    int g= gcd(d,n);
    r.setD(d/g);    
    r.setN(n/g);
    return r;
}

rational rational::divide(rational r1)
{	
	rational r;
    int n= this->getN() * r1.getD();
    int d= this->getD() * r1.getN();
    int g= gcd(d,n);
    r.setD(d/g);    
    r.setN(n/g);
    return r;
}

void rational::increment()
{
	rational one(1,1);
	one.display();
	rational res;
	res = this->add(one);	
	this->setD(res.getD());
	this->setN(res.getN());
}



int main()
{
    rational r1(3,4), r2(1,4);    
    rational  f3 ;
    f3 = add(r1, rational(1,4));  
    f3.display();
}

