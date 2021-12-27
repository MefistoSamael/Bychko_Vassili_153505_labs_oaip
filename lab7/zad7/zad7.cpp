#include <iostream>
using namespace std;

int search(int a, int b)
{
	while (a <= b >> 1)
	{
		return search(a + a, b);
	}
	return a;
}

int diff(int a, int b)
{
	return a + ~b + 1;
}


int main()
{
	int numb = 0;
	while (numb != -1)
	{
		cout << "Enter -1 to stop loop\n";
		cout << "Enter numb ";
		cin >> numb;
		int n;
		int i;
		//для 5
		n = 5;
		i = 0;
		for (i = numb; i >= n; )
		{
			i = diff(i, search(n, i));
		}
		if (i == 0) cout << numb << " could be divided by " << n << " without reminder\n";
		else cout << numb << " couldn't be divided by " << n << " without reminder\n";

		//для 73
		n = 73;
		i = 0;
		for (i = numb; i >= n; )
		{
			i = diff(i, search(n, i));
		}
		if (i == 0) cout << numb << " could be divided by " << n << " without reminder\n";
		else cout << numb << " couldn't be divided by " << n << " without reminder\n";

		//для 151
		n = 151;
		i = 0;
		for (i = numb; i >= n; )
		{
			i = diff(i, search(n, i));
		}
		if (i == 0) cout << numb << " could be divided by " << n << " without reminder\n";
		else cout << numb << " couldn't be divided by " << n << " without reminder\n";
	}


	return 0;
}
