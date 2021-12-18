
#include <iostream>
using namespace std;

int conver(char s)
{
	if (s == '1') return 1;
	if (s == '0') return 0;
	else return 1234554431;
}

int main()
{
	int numb= 0;
	char enter;
	int bufl = 0;
	bool G = 0;
	cin >> enter;
	bufl = cin.rdbuf()->in_avail();
	cout << "bufl = " << cin.rdbuf()->in_avail() << endl;
	if (conver(enter) != 1)
	{
		numb += conver(enter) * pow(2, cin.rdbuf()->in_avail() -1);
	}
	else G = 1;
	for (int i = 0; i<= bufl-2;i++)
	{
		cin >> enter;
		numb += conver(enter) * pow(2, cin.rdbuf()->in_avail()-1);
	}
	if (G) numb *= -1;
	cout << numb << endl;
	for (int a = 31; a >= 0; a--)
	{
		bool b = ((1 << a) & numb);
		cout << b;
	}


	return 0;
}

