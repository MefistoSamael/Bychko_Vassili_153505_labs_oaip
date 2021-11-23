/*
Пусть f(n) - наибольший нечетный делитель натурального числа n. По заданному
натуральному n необходимо вычислить значение суммы f(1) + f(2) + ... + f(n).
*/

#include <iostream>
using namespace std;

void check(int& number);//проверка ввода
void calc(const int& n, long long& sum);

int main()
{

	int n = 0;
	while (cin >> n)
	{
		long long sum = 0;
		calc(n, sum);
	}
	
	return 0;
}

void check(int& number)
{
	while (true)
	{
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "oops, smth went wrong, try again\n";
		}
		else break;
	}
}

void calc(const int& n, long long& sum)
{
	for (int i = 1; i < n + 1; i++)
	{
		if (i % 2 != 0)
		{
			sum += i;
			continue;
		}
		else
		{
			int j = 0;
			for (j = i; j % 2 == 0; )
			{
				j /= 2;
			}
			sum += j;
		}
	}
	cout << "sum = " << sum << "\n";
}