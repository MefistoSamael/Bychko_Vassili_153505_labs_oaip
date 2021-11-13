#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	int prod = 1;
	const int N = 4;
	const int M = 4;
	int array[N][M];
	int i = 0;
	int j = 0;

	cout << "Enter numbs in array" << endl;
	for (int i = 0; i < N; i++)// ввод
	{
		for (int j = 0; j < M; j++)
		{
			cin >> array[i][j];
		}
	}

	for (i = 0; i < N; i++) //вывод
	{
		for (j = 0; j < M; j++)
		{
			cout << array[i][j]<< " ";
		}
		cout << endl;

	}


	j = 0;
	for (i = 0; i < N; i++) //сумма
	{
		j = i;
		sum += array[i][j];
	}

	j = N - 1;
	for (i = 0; i < N; i++) //произведение
	{
		prod *= array[i][j];
		j--;
	}


	cout << "sum = " << sum << endl;
	cout << "production = " << prod;
	return 0;
}

