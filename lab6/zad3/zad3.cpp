//
// В массиве строк найти среднее значение длины строки. Строки, 
// длина которых больше среднего, – обрезать, меньше – добавить
// пробелы.пробелы были заменены на звёзды, для лучшей видимости.
// Полученный массив вывести на экран.Стандартных функций
// работы со строками не использовать.
//


#include <iostream>
using namespace std;

void fill(char** str, int  size);
int average(char** str, int size);
void change(char** str, int size, int avlen);

int main()
{
	int size = 3;
	char** str = new char* [size];
	for (int i = 0; i < size; i++)
	{
		str[i] = new char[40];
	}

	fill(str,size);
	int avlen = average(str, size);
	cout << "avlen = " << avlen << endl;
	change(str, size, avlen);
	for (int i = 0; i < size; i++)
	{
		cout << "str [" << i << "] :" << str[i] << endl;
	}




	for (int i = 0; i < size; i++)
	{
		delete[] str[i];
	}
	delete[] str;

	return 0;
}

void fill(char** str, int  size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter " << i << " string :";
		cin.getline(str[i], 38);
	}
}

int average(char** str, int size)
{
	int a = 0;
	for (int i = 0; i < size; i++)
	{
		a += strlen(str[i]);
	}
	a /= size;
	return a;
}

void change(char** str, int size, int avlen)
{
	for (int i = 0; i < size; i++)
	{
		if (strlen(str[i]) < avlen)
		{
			int len = strlen(str[i]);
			str[i] = (char*)realloc(str[i], avlen+1);
			for (int j = len; j < avlen; j++)
			{
				str[i][j] = '_';
			}
			str[i][avlen] = '\0';
		}
		else if (strlen(str[i]) > avlen)
		{
			str[i] = (char*)realloc(str[i], avlen + 1);
			str[i][avlen] = '\0';
		}
		
	}
}