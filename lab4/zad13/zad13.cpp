#include <iostream>
using namespace std;

void FillArrayR(const int& size, int array[]);
void OutArray(const int& size, int array[]);

int main()
{
	int numb = 0;
	cout << "enter numb of udlinnitelei\n";
	cin >> numb;
	//srand(time(NULL));


	int* array = new int [numb]; //создание массива
	

	FillArrayR(numb, array);
	OutArray(numb, array);

	int sum = 0;

	for (int i = 0; i < numb; i++)
	{
		sum += array[i];
	}
	sum -= numb;

	cout << "\nnumb of rozetok = " << sum;
	delete[] array;

}


void FillArrayR(const int& size, int array[])
{
	for (int i = 0; i < size; i++)
	{
			array[i] = rand() % 10 + 2;
	}
}
void OutArray(const int& size, int array[])
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}
