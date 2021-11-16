#include <iostream> //стек - облатсь в памяти где выполняется программа
using namespace std;

void search(int* array, int size, int& min, int k);

int main()
{
	srand(time(NULL));
	int z = 0;
	int k = 0;
	int min1 = 0;
	int min2 = 0;
	int size = 0;
	cout << "enter size of array, size must be even ";
	cin >> size;

	int* array = new int[size];

	for (int i = 0; i < size; i++)
	{
		cout << "enter array[" << i << "] ";
		cin >> array[i];
	}
	min1 = array[0];
	min2 = array[0];
	cout << endl;
	for (int i = 0; i < size; i++) //out func
	{
		cout << array[i] << " ";
	}
	cout << endl;
	int temp = 0;
	int j = 0;

	int* array1 = new int[size / 2];
	int* array2 = new int[size / 2];

	search(array1, size/2,min1, size/2 - 1);
	search(array2, size/ 2, min2, size / 2 -1);
	if (min1 < min2) cout << "min = " << min1;
	else cout << "min = " << min2;

	delete[] array;
	delete[] array1;
	delete[] array2;
	return 0;
}

void search(int* array, int size, int& min, int k)
{
	if (min > array[k]) min = array[k];		
	k--;

	if (k == 0)
	{
		return;
	}
	search(array, size, min, k );
}