#include <iostream>
using namespace std;

int fuk(int a);

int main()
{
	long long res = 0;//ответ
	int numbl = 0;//число повтор€ющихс€ букв
	long long div = 1;//
	char str[15];
	cout << "Enter string :";
	cin.getline(str, 14);
	for (int i = 0; i < strlen(str) - 1; i++)
	{
		if (str[i] == '*') continue;
		numbl = 1;
		for (int g = i + 1; g < strlen(str); g++)
		{
			if (str[i] == str[g])
			{
				str[g] = '*';
				numbl++;
			}
		}
		div *= fuk(numbl);
	}

	cout << "number of different anagramms = " << fuk(strlen(str)) / div;


	return 0;
}

int fuk(int a)
{
	if (a == 1) return 1;
	return a * fuk(a - 1);
}

//oo
// 
//o
// 
// kosovo - 120
//