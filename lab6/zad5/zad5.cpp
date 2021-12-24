#include <iostream>
using namespace std;

int search();

int mypow(int k, int n, int prec);

int main()
{
	int t = 0;
	cout << "Enter numb of data ";
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a = 0;
		a = search();
		cout << "answer = " << a << endl;
	}               

	return 0;
}

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

int search()
{
	long long answer = 0;
	cout << "Enter length of main string ";
	int mainlen = 0;
	cin >> mainlen;
	cout << "Enter precision of calculations ";
	int prec = 0;
	cin >> prec;
	cin.ignore(1);
	char* str1 = (char*)calloc(200, sizeof(char));
	cout << "Enter string with str1 ";
	cin.getline(str1, 199);
	cout << "Enter string with str2 ";
	char* str2 = (char*)calloc(200, sizeof(char));
	cin.getline(str2, 199);
	bool CheckEq = 0;
	if (strlen(str1) == strlen(str2))
	{
		CheckEq = 1;
		for (int i = 0; i < strlen(str1); i++)
		{
			if (str1[i] != str2[i])
			{
				CheckEq = 0;
				break;
			}
		}
	}
	if (strlen(str2) + strlen(str1) < mainlen)
	{
		answer = mypow(26, mainlen - strlen(str2) - strlen(str1), prec);
		if (!CheckEq) answer *= 2;
		return answer;
	}
	if (strlen(str2) + strlen(str1) == mainlen)
	{
		answer = 2;
		return answer;
	}
	if (strlen(str2) + strlen(str1) > mainlen)
	{
		bool A = 1;
		int n = 0;
		n = strlen(str2) + strlen(str1) - mainlen;
		//первое сравнение
			for (int i = strlen(str1) - n, j = 0; j < n; i++, j++)
			{
				if (str1[i] != str2[j]) A = 0;
			}
			if (A)
			{
				answer++;
				if (CheckEq) return answer;
			}
		//если первое сравнение не прошло меняем местами строки
		
		
			A = 1;
			for (int i = strlen(str1) - 1, j = 0; j < n; i--, j++)
			{
				if (str2[i] != str1[j]) A = 0;
			}
			if (A)
			{
				answer++;
				return answer;
			}
			return answer;
		
		
		return 0;

	}
}