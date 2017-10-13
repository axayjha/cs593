#include <iostream>
using namespace std;
class matrix
{
	int arr[2][2];
	public:
		matrix(){}
		void set(int, int, int, int);
		matrix(matrix *m)
		{
			for(int i=0; i<2; i++) for(int j=0; j<2; j++) m->arr[i][j]  = arr[i][j];
		}
		
		matrix(matrix &m);
		int getElement(int i, int j){return arr[i][j];}
		void inverse();
		bool isSingular();
		void print();
		int determinant();
		matrix operator+(matrix m1);
		matrix operator+(int);
		friend matrix operator+(int x, matrix m1);
		matrix operator-(matrix m1);
		matrix operator-(int);
		friend matrix operator-(int x, matrix m1);
		matrix operator*(matrix m1);
		matrix operator*(int);
		friend matrix operator*(int x, matrix m1);
		int operator/(matrix m1);
		matrix operator/(int x);
		friend matrix operator/(int x, matrix m1);
		
};

matrix::matrix(matrix &m)
{
	for(int i=0; i<2; i++) for(int j=0; j<2; j++) arr[i][j] = m.arr[i][j];
}


matrix matrix::operator+(matrix m1)
{
	matrix m;
	int temp[2][2];
	for(int i=0; i<2; i++) 
		for(int j=0; j<2; j++) 
			 temp[i][j] = arr[i][j] + m1.getElement(i,j);
	m.set(temp[0][0], temp[0][1], temp[1][0], temp[1][1]);
	return m;		 
}

matrix matrix::operator+(int x)
{
	matrix m;
	int temp[2][2];
	for(int i=0; i<2; i++) 
		for(int j=0; j<2; j++) 
			 temp[i][j] = arr[i][j] + x;
	m.set(temp[0][0], temp[0][1], temp[1][0], temp[1][1]);
	return m;		 
}

matrix operator+(int x, matrix m1)
{
			 matrix m;
			 m= (m1+x);
			 return m;
}


matrix matrix::operator-(matrix m1)
{
	matrix m;
	int temp[2][2];
	for(int i=0; i<2; i++) 
		for(int j=0; j<2; j++) 
			 temp[i][j] = arr[i][j] - m1.getElement(i,j);
	m.set(temp[0][0], temp[0][1], temp[1][0], temp[1][1]);
	return m;		 
}

matrix matrix::operator-(int x)
{
	matrix m;
	int temp[2][2];
	for(int i=0; i<2; i++) 
		for(int j=0; j<2; j++) 
			 temp[i][j] = arr[i][j] - x;
	m.set(temp[0][0], temp[0][1], temp[1][0], temp[1][1]);
	return m;		 
}

matrix operator-(int x, matrix m1)
{
			 matrix m;
			 m= ((-1)*m1 + x);
			 return m;
}


matrix matrix::operator*(int x)
{
	matrix m;
	int temp[2][2];
	for(int i=0; i<2; i++) 
		for(int j=0; j<2; j++) 
			 temp[i][j] = arr[i][j] * x;
	m.set(temp[0][0], temp[0][1], temp[1][0], temp[1][1]);
	return m;		 
}

matrix operator*(int x, matrix m1)
{
			 matrix m;
			 m= (m1*x);
			 return m;
}

matrix matrix::operator*(matrix m1)
{
	matrix m;
	int temp[2][2];
	for(int i=0; i<2; i++) 
	{
		for(int j=0; j<2; j++) 
		{
			int c=0;
			for(int k=0; k<2; k++)
			{
				c+=arr[i][k]*m1.arr[k][j]	;
			}
			temp[i][j] = c;
		}
	}
	m.set(temp[0][0], temp[0][1], temp[1][0], temp[1][1]);
	return m;		 
}


int matrix::operator/(matrix m1)
{
	return this->determinant()/m1.determinant();	 
}

matrix matrix::operator/(int x)
{
	matrix m;
	int temp[2][2];
	for(int i=0; i<2; i++) 
		for(int j=0; j<2; j++) 
			 temp[i][j] = arr[i][j] / x;
	m.set(temp[0][0], temp[0][1], temp[1][0], temp[1][1]);
	return m;		 
}

matrix operator/(int x, matrix m1)
{
			 matrix m;
			 m= (m1/x);
			 return m;
}


void matrix::set(int a, int b, int c, int d)
{
	arr[0][0] = a; arr[0][1] = b; arr[1][0] = c; arr[1][1] = d;
}

int matrix:: determinant()
{

	return (arr[1][1] * arr[0][0] - arr[1][0] * arr[0][1]);
}


void matrix::inverse()
{
	int det = this->determinant();
	int a = arr[0][1], b = arr[1][0];
	arr[1][0] = a; arr[0][1] = b;
	for(int i=0; i<2; i++) for(int j=0; j<2; j++) arr[i][j]  = arr[i][j]/det;
}

void matrix::print()
{
	for(int i=0; i<2; i++) 
	{
		for(int j=0; j<2; j++)
			cout<< arr[i][j] << " ";
		cout << endl;	
	}
	
}

bool matrix::isSingular()
{
	if(arr[0][0]==arr[1][1]==1 && arr[1][0]==arr[0][1]==0)
		return true;
	return false;	
}

int main()
{
	matrix m1, m2, m3;
	m1.set(1,2,3,4);
	m1.print();
	m2.set(1,2,3,4);
	m3 = 5-m1; ;
	m3.print();
	
}
