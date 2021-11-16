#include <iostream>
using namespace std;

int main()
{
	int size;
	cout << "enter size of array" << endl;
	while (true)
	{
		cin >> size;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "oops smth went wrong, try again" << endl;
		}
		else break;
	}
	int **array = new int*[size];// количество строк size
	for (int i = 0; i < size; i++) //задание столбцов
	{
		array[i] = new int[size];
	}


	for (int i = 0; i < size; i++) //ввод элементов массива
	{
		for (int j = 0; j < size; j++)
		{
			while (true)
			{
				cin >> array[i][j];
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "oops smth went wrong, try again" << endl;
				}
				else if (array[i][j] <0 || array[i][j] > 1) cout << "oops, its not 0 or 1, try again" << endl;
				else break;
			}
		}
	}
	for (int i = 0; i < size; i++) //вывод элементов массива
	{
		for (int j = 0; j < size; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 20; i++) cout << "-"; //черточки)
	cout << endl;
	for (int i = 0; i < size; i++)//движение
	{
		for (int j = size - 1; j >= 0; j--)
		{
			cout << array[j][i] << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < size; i++) //очистка памяти
	{
		delete[] array[i];
	}


	return 0;
}
