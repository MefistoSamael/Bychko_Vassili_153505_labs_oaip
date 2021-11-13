#include <iostream>
using namespace std;

int main()
{ //СДЕЛАТЬ ПРОВЕРКУ НА ВВОД ДО КРАЙНЕЕ ЗНАЧЕНИЕ ИНТА МИНУС ТРИ
	int size;
	size = 0;
	int sum;
	sum = 0;
	int maxnumb;
	maxnumb = 0;
	cout << "enter size of array" << endl;
	cin >> size;


	int** array = new int* [size]; //создание массива
	for (int i = 0; i < size; i++)
	{
		array[i] = new int[size];
	}

	for (int i = 0; i < size; i++)//его заполнение
	{
		for (int j = 0; j < size; j++)
		{
			cin >> array[i][j];
		}
	}

	for (int i = 0; i < size; i++)//вывод массива
	{
		for (int j = 0; j < size; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < size - 1; i++) //поиск наибольшего члена массива
	{
		for (int j = 0; j < size-1; j++)
		{
			if (array[i + 1][j + 1] > array[i][j]) maxnumb = array[i + 1][j + 1];
		}
	}
	cout << "mn = " << maxnumb << endl;
	maxnumb = maxnumb + 1;


	int** arraynew = new int* [size + 2];// создание нового массива
	for (int i = 0; i < size+2; i++)
	{
		arraynew[i] = new int[size+2];
	}

	for (int i = 0; i < size+2; i++)//заполнение краёв нового массива наибольшим числом плюс один
	{
		for (int j = 0; j < size+2; j++)
		{
			arraynew[0][j] = maxnumb;
			arraynew[size +1][j] = maxnumb;//hui
		}
		arraynew[i][0] = maxnumb;
		arraynew[i][size +1] = maxnumb;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arraynew[i+1][j+1] = array[i][j];
		}
	}

	for (int i = 0; i < size; i++)// удаление первого массива
	{
		delete[] array[i];
	}
	delete[] array;

	/*for (int i = 0; i < size + 2; i++)
	{
		for (int j = 0; j < size + 2; j++)
		{
			cout << arraynew[i][j] << " ";
		}
		cout << endl;
	}*/

	for (int i = 1; i < size + 1; i++)//действия над вторым массивом
	{
		for (int j = 1; j < size + 1; j++)
		{
			if (arraynew[i][j]< arraynew[i-1][j-1]&& arraynew[i][j]< arraynew[i][j-1]&& arraynew[i][j]< arraynew[i+1][j-1]&& arraynew[i][j]< arraynew[i-1][j]< arraynew[i+1][j]&& arraynew[i][j] < arraynew[i-1][j+1]&& arraynew[i][j]< arraynew[i][j+1]&& arraynew[i][j] < arraynew[i + 1][j + 1])
			{
				sum++;
				continue;
			}
		}
	}

	for (int i = 0; i < size+2; i++)// удаление второго массива
	{
		delete[] arraynew[i];
	}
	delete[] arraynew;
	

	cout << "numbs of min : " << sum;
	return 0;
}
