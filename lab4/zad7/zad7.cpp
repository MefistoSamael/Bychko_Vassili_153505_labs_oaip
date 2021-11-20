#include <iostream>
using namespace std;

int main()
{
	int numb;
	int numb2;
	cout << "enter natural number" << endl;
	while (true)
	{
		cin >> numb;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "oops smth went wrong, try again" << endl;
		}
		if (numb < 0) cout << "numb must be natural" << endl;
		else break;
	}
	int amount = 0;
	for (numb; numb > 0; amount++)
	{
		cout << "number " << numb % 10 << " in place " << amount << endl;
		numb /= 10;
	}
	cout << "amount of spaces = " << amount << endl;

}
