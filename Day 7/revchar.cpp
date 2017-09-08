#include <iostream>
#include <cstdlib>
#include <cstring>
#define SIZE 10

using namespace std;

int main()
{
	char *str = (char *)malloc(SIZE*sizeof(char));
	strcpy(str, "Akshay");
	cout << str << endl;
	for(int i=0, n=strlen(str); i<n/2; i++)
		str[i]^=str[n-i-1]^=str[i]^=str[n-i-1];		
	cout << str << endl;
	
}
