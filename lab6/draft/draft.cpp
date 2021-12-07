//
// После каждого слова текста, оканчивающегося заданной 
// подстрокой, вставить указанный символ.
//
#include <iostream>
#include <cassert>
#include <stdlib.h>
using namespace std;


int mypow(int k, int n, int prec)
{
	long long x = k;
	long long g = 1;
	long long cln = n;
	long long prod = 1;
	while (true)
	{
		g = 1;
		x = k;

		while (g < cln)
		{
			g *= 2;
			if (g > cln)
			{
				g /= 2;
				break;
			}
			x = (x * x) % prec;
		}

		cln -= g;
		prod = (prod * x) % prec;
		if (cln <= 0)
		{
			return prod % prec;
		}
	}
}

int main()
{
	int k = 26;
	int n = 3;
	int prec = 1000;
	int answer = 0;
	cout << "answer = " << mypow(26, 3, 1000);



	return 0;
}