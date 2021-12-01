#include <iostream>
using namespace std;

double func(double a, double b)
{
	return (a + b);
}

int main()
{
	int a = 7;
	int b = 5;
	double* ptr = &func();
	double** ptr2 = &ptr;
	cout << ptr2;
	cout << ptr;
	cout << func(a, b);



	return 0;
}
