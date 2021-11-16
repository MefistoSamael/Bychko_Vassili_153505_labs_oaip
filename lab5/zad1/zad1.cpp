#include <iostream> //стек - облатсь в памяти где выполняется программа
using namespace std;
void InputSize(int* size, char letter);
void Input(int* size, char letter, int* array);
void Fill(int* str, int* clmn, char letter, int** array, int* array1, int* array2);
void Out(int* size, char letter, int* array);
void search(int* max, int* str, int* clmn, int** array);
int main()
{
	int sizeX = 0;
	int sizeY = 0;
	InputSize(&sizeX, 'X');
	InputSize(&sizeY, 'Y');

	int* arrayX = new int[sizeX];
	Input(&sizeX, 'X', arrayX);

	int* arrayY = new int[sizeY]; 
	Input(&sizeY, 'Y', arrayY);

	int** arrayZ = new int* [sizeX];
	for (int i = 0; i<sizeX;i++)
	{
		arrayZ[i] = new int[sizeY];
	}

	Fill(&sizeX, &sizeY, 'Z', arrayZ, arrayX,arrayY);
	cout << "\n";
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			cout << arrayZ[i][j] << " ";
		}
		cout << "\n";
	}

	int max = 0;
	search(&max, &sizeX, &sizeY, arrayZ);



	delete[] arrayX;
	delete[] arrayY;
	for (int i = 0; i < sizeX; i++)
	{
		delete[] arrayZ[i];
	}

	delete[] arrayZ;

	return 0;
}

void Input(int* size, char letter, int* array)
{
	for (int i = 0; i < *size; i++)//input func
	{
		cout << "enter " << i << " array " << letter << " member\n";
		cin >> array[i];
	}
}

void InputSize(int* size, char letter)
{
	cout << "enter size of array " << letter << " ";
	cin >> *size;
}



void Fill(int* str, int* clmn, char letter, int** array, int* array1, int* array2)
{
	for (int i = 0; i < *str; i++)
	{
		for (int j = 0; j < *clmn; j++)
		{
			array[i][j] = array1[i] * array2[j];
		}
	}
}

void Out(int* size, char letter, int* array)
{
	cout << endl;
	for (int i = 0; i < *size; i++)
	{
		cout << array[i];
	}
}
void search(int* max, int* str, int* clmn, int** array)
{
	for (int i = 0; i < *str; i++)//search func
	{
		for (int j = 0; j < *clmn; j++)
		{
			if (array[i][j] > *max) *max = array[i][j];
		}
	}

	cout << " max = " << *max;
}