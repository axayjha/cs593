#include <iostream>
using namespace std;
bool isUpper(char c){return (c<91 && c>64);}
bool isLower(char c){return (c>=97 && c<=123);}
class letter
{
    
    public:
        virtual void display(char)=0;
        
};

class upper: public letter
{
    
    public:
        upper(){}
        void display(char a)
        {
            if(isUpper(a))
                printf("%c\n", a);
            else 
                printf("%c\n", a-32);             
        }    
};

class lower: public letter
{
    public:
        lower(){}
        void display(char a)
        {
            if(isUpper(a))
                printf("%c\n", a+32);
            else 
                printf("%c\n", a);             
        }
};

class error: public letter
{
    public:
        error(){}
        void display(char a='a')
        {
            cout << "Error: Not a valid letter" << endl;
        }
};

class getChar
{    
    char c;
    public:
        
        getChar(){}
        void get(){
            c=getchar();
        }
        void display()
        {
            if(isUpper(c))
                lower().display(c);
                
            else if(isLower(c))
                upper().display(c); 
                
            else
                error().display(c);            
        }
};

int main()
{
    getChar g;    
    g.get();
    g.display();
}
