#include <iostream>
#define MAX 50

using namespace std;

template <class type> void swap(type &a, type &b)
{
	type temp = a;
	a=b;
	b=temp;
}

template <class type> class Stack
{
	type arr[MAX];
	int tos;
public:
	Stack()
	{
		tos=-1;
	}
	void push(type a);

	type pop();
};

template <class type> void Stack<type> :: push(type a)
{
	if(tos==MAX)
	{
		cout << "STACK OVERFLOW" << endl;
		return;
	}
	arr[++tos] = a;
}

template <class type> type Stack<type> :: pop()
{
	if(tos==-1)
	{
		cout << "STACK UNDERFLOW" << endl;
		return -99999;
	}
	return arr[tos--];
}	

int main()
{
	Stack <int>s1;
	s1.push(2);
	s1.push(3);

	cout << s1.pop() << endl;


}