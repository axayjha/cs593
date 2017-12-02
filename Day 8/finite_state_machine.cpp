#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class text
{
    char str[50];
    public:
        text (){strcpy(str, "");}
        void getText();
        void display(){ cout << str << endl; }
};

void text::getText()
{
    char buffer[50];
    strcpy(buffer, "");
     
    char c;
    state0:
        c= getchar();
        if(c=='"') goto stateFirstQuote;
        else if(c==EOF) goto stateFinal;
        else goto state0;
        
    stateFirstQuote:
        c=getchar();
        if(c=='"'){ strcpy(str, buffer); goto state0;}
        else if(c==EOF) goto stateFinal;
        else
        {   
            char temp[] = {c, '\0'};
            strcat(buffer, temp);
            goto stateFirstQuote;
        }
        
    stateFinal:
        return;    
}

int main()
{
    text t1;
    t1.getText();
    t1.display();
}
