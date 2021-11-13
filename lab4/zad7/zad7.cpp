#include <iostream>
using namespace std;

int main()
{
	int numb;
	cout << "enter number" << endl;
	cin >> numb;
	int amount = 0;
	for (numb; numb > 0; amount++)
	{
		cout << "number " << numb % 10 << " in place " << amount << endl;
		numb /= 10;
	}
	cout << "amount of spaces = " << amount << endl;

}
