#include <iostream>
using namespace std;

int main()
{
	int numb;
	cin >> numb;
	int n;
	if (numb < 0)
	{
		cout << "1";
		numb *= 1;
	}
	for (n = 0; pow(2, n) < numb; n++);
	int n2 = pow(2, n);
	bool B = 0;
	if (n2 == numb)
	{
		B = 1;
	}
	int j = 0;
	for (int i = numb; i > 0;)
	{
		j = i / n2;
		i -= j * n2;
		cout << j;
		n2 /= 2;
	}
	if (B)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "0";
		}
	}

	return 0;
}

