#include <iostream>
using namespace std;

int mylen(char* array);//поиск длинны строки

int numb(char symb);//замена символа на число

long long to10(char* numb13);//перевод в десятичную запись

int to3(long long numb10, int* numb3)//перевод в троичную запись
{
	int n = 899;
	for (long long i = numb10; i > 0; )
	{
		numb3[n] = i % 3;
		i /= 3;
		n--;

	}
	return n;
}


//-858993460 мусор которым заполняется массив
int main()
{
	char numb13[300];
	int numb3[900];
	cin.getline(numb13, 299);
	long long numb10 = 0;


	numb10 = to10(numb13);
	cout << numb10 << endl;

	int start = to3(numb10, numb3);
	for (int i = start + 1; i < 900; i++)
	{
		cout << numb3[i];
	}


	return 0;

}

int mylen(char* array)//поиск длинны строки
{
	int len = 0;
	while (array[len]) len++;

	return len;
}

int numb(char symb)//замена символа на число
{
	if (symb >= 48 && symb <= 57) return symb - 48;
	if (symb >= 65 && symb <= 67) return symb - 55;
}

long long to10(char* numb13)
{
	long long numb10 = 0;
	for (int i = mylen(numb13) - 1, n = 0; i >= 0; i--, n++)
	{
		numb10 += numb(numb13[i]) * powl(13, n);
	}
	return numb10;
}

//51B9B636B771
//1012122202010122201000001100