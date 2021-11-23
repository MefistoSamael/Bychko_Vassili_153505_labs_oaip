/*
Рекурсивная функция задана следующим образом:
f(0,0) = 1
f(n,r) = sigma(i=0;k-1)f(n-1,r-i) when [(n>0) and (0 <= r < n*(k-1)+1)]
f(n,r) = 0 otherwise
*/
#include <iostream>
using namespace std;

void check(long long& number);
int F(long long n, int r, long long k, long long t);

int main()
{
	long long k = 0;
	long long n = 0;
	long long t = 0;

	while (true)
	{
		int schet = 0;
		cout << "enter k ";
		check(k);
		cout << "enter n ";
		check(n);
		cout << "enter t ";
		check(t);
		bool b = 0;
		k = k % (long long)pow(10, 9);
		long long x = k;
		if (k == 0 && n == 0 && t == 0) break;
		/*for (int i = 0; i < n * (k - 1) + 1; i++)
		{
			x += F(n, i, k, t);
			
		}
		а это через рекурсию*/
		long long g = 1;
		long long cln = n;
		long long prod = 1;
		while (true)
		{
			g = 1;
			x = k;

			while (g < cln ) 
			{
				g *= 2;
				if (g > cln)
				{
					g /= 2;
					break;
				}
				x = (x * x) % (long long)pow(10, t);
			}

			cln -= g;
			prod = (prod*x)%(long long)pow(10,9);
			if (cln <= 0)
			{
				schet++;
				cout <<"\nCase #"<< schet << " : " << prod % (long long)pow(10, t) << "\n";
				break;
			}

			
			
			
		}
		/*while (g < n)
		{
			g *= 2;
			if (g > n)
			{
				g /= 2;
				break;
			}
			k = (k * k) % (long long)pow(10, 9);
		}


		for (int i = g; i < n; i++)
		{
			k = (k*x) % (long long)pow(10, 9);
		}
		cout << k % (long long)pow(10, t) << endl;
		*/
	}

	cout << "\nend";
	
	return 0;
}

int F(long long n, int r, long long k, long long t)
{
	if (n == 0 && r == 0) return 1;
	if (n > 0 && r < n * (k - 1) + 1 && r >= 0)
	{
		int sum = 0;
		for (int i = 0; i < k; i++)
		{
			//cout << "\nn = " << n << "\n";
			sum += F(n - 1, r - i, k,t);
		}
		//cout << "\n sum = " << sum << "\n";
		return sum%(int)pow(10,t);
	}
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

/*
while (cln != 0)
		{
			g = 1;
			x = k;

			while (g < cln ) //если что то пойдет не так, сделай n-1
			{
				g *= 2;
				if (g > cln)
				{
					g /= 2;
					break;
				}
				x = (x * x) % (long long)pow(10, 9);
			}
			//cout << "g =" << g << endl;

			cln -= g;
			//cout << "cln = " << cln << endl;
			prod = (prod * x) % (long long)pow(10, 9);



		}
*/