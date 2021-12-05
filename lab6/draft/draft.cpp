#include <iostream>
#include <cassert>
using namespace std;

double func(double a, double b)
{
	return (a + b);
}

int main()
{
	double a = 5, b = 3;
	assert(func(a, b) == a+b+1 && "y are gay");

	return 0;
}
