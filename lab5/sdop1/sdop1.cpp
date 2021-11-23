/*
Определим следующую рекурсивную функцию F(n):
F(n) = 1) n%10,     if (n%10>0)
       2) 0,        if n = 0
       3) F(n/10),  otherwise

Определим функцию S (p, q) следующим образом:
S(p,q) = sigma(i=p;q)F(i)

По заданным p и q необходимо вычислить S (p, q).
*/

#include <iostream>
using namespace std;

void check(long long& number);//проверка ввода
long double S(long long p, long long q);
long long F(long long n);


int main()
{
    long long p = 0;
    long long q = 0;
    while (true)
    {
        cout << "enter p ";
		check(p);
		cout << "enter q ";
		check(q);
		if (p > q)
		{
			cout << "!WARNING!: p>q\ntry again\n";
			continue;
		}
		if (p == -1 && q == -1) break;
		cout << "sum = " << S(p,q) << "\n";
    }

	cout << "\nend";
    return 0;
}



void check(long long& number)
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
long double S(long long p, long long q)
{
	long double sum = 0;
	for (long long i = p; i < q + 1; i++)
	{
		sum += F(i);
	}
	return sum;
}

long long F(long long n)
{
	if (n % 10 > 0) return n % 10;
	if (n == 0) return 0;
	return F(n / 10);
}