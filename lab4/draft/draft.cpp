#include <iostream>
using namespace std;

int main()
{
	int g = 0;
	int size = 6;
	int numb;
	cin >> numb;
	double* array = new double [size] {96, 141, 190, 252, 325, 355};
	double t = 0.00096;
	for (int i = 2; i < size + 1; i++)
	{
		t += array[i] * 0.000001 * 9 * pow(10, -i);
	}
	int amount = 0;
	


	cout << g;

}
