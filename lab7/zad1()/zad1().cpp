#include <iostream>
#include <iomanip>
using namespace std;

int numb(char symb);//замена символа на число
char numbtochar(int numb)
{
	if (numb == 0) return '0';
	else if (numb == 1) return '1';
	else if (numb == 2) return '2';
	else if (numb == 3) return '3';
	else if (numb == 4) return '4';
	else if (numb == 5) return '5';
	else if (numb == 6) return '6';
	else if(numb == 7) return '7';
	else if(numb == 8) return '8';
	else if(numb == 9) return '9';
}

int main()
{
	char a = 0;
	char b = 0;
	char c = 0;
	long long numb10 = 0;
	char first;
	int stepen = 0;

	cin >> first;
	cout << "numb of symb = " << cin.rdbuf()->in_avail() << endl;

	//перевод в десятичную СС
	numb10 = numb(first) * pow(13, cin.rdbuf()->in_avail() - 1);//посокльку число было введено заранее проделаем один шаг вне цикла
	stepen = (cin.rdbuf()->in_avail()) - 2;
	while (a != '\n' && stepen >=0)
	{
		cin >> a;
		numb10 += numb(a) * pow(13, stepen);
		stepen--;
	}
	cout << "numb10 = " << numb10 << endl;

	
	//перевод в троичную СС

	long long n = 0;
	cout << "numb3 = ";


	int j = 0;
	long long j3 = 0;
	for (j = 0; pow(3, j) < numb10; j++) j3 = pow(3, j);
	for (long long i = numb10; i > 0;)
	{

		n = i / j3;
		i -= j3 * n;
		j3 /= 3;
		cout << n;
	}
	


	return 0;
}

int numb(char symb)//замена символа на число
{
	if (symb >= 48 && symb <= 57) return symb - 48;
	if (symb >= 65 && symb <= 67) return symb - 55;
}


//нормальная реализация кода
	/*long  answer = 0;
		int n = 0;
		for (long long i = numb10; i > 0;)
		{

			int temp = i % 3;
			i /= 3;
			answer += temp * pow(10, n);
			n++;
		}
		cout << "numb3 = " << answer;*/