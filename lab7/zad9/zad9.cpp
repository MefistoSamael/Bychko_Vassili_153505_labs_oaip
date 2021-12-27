#include <iostream>
using namespace std;


int main()
{
	int numb;
	cin >> numb;
	int sum = 0;
	int stepen = 0;
	for (int i = 0; sum < numb; i++)
	{
		sum += pow(3, i);
		if (sum > numb)
		{
			stepen = i - 1;
			sum -= pow(3, i);
			break;
		}
	}
	cout << sum << endl;
	int size = 0;//количество разраядов числа в 3 системе

	int dif = numb - sum;

	for (int i = dif; i > 0;i/=3)
	{
		size++;
	}



	int* array =new int [size];//массив для разности


	int size2 = 0;
	for (int i = sum; i > 0; i /= 3)
	{
		size2++;
	}


	int* array2 = new int[size2];//массив для суммы
	for (int i = size2-1, j = sum; i >= 0; i--, j/=3)
	{
		array2[i] = j % 3;
	}
	for (int i = 0; i < size2; i++)
	{
		cout << array2[i];
	}
	cout << endl;
	for (int i = dif, j = size-1; j>=0;i/=3, j--)
	{
		array[j] = i % 3;
	}
	for (int i = 0; i < size; i++)
	{
		cout << array[i];
	}
	int* answer = new int[size2];
	for (int i = 0; i < size2; i++)
	{
		answer[i] = array2[i];
	}
	for (int i = size - 1, j = size2 - 1; i >= 0; i--, j--)
	{
		answer[j] = array[i] + array2[j];
	}
	cout << endl;
	for (int i = 0; i < size2; i++)
	{
		cout << answer[i];
	}


	delete[] array;
	delete[] array2;
	delete[] answer;
	




	return 0;
}
