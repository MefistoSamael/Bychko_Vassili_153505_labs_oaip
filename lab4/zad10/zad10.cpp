#include <iostream>

using namespace std;


int main()
{


	int n;
	cout << "enter size of magic square ";
	while (true)
	{
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "oops smth went wrong, try again" << endl;
		}
		else break;
	}
	cout << endl;


	int** magic_square = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		magic_square[i] = (int*)malloc(n * sizeof(int));
	}

	cout << "Полученный магический квадрат " << n << "-го порядка:" << endl;

	if (n == 1 || n == 2)
	{
		cout << "Магический квадрат " << n << "-го порядка НЕ существует. :(" << endl;
	}
	else if (n % 2 == 1) //нечётный порядок индийским методом
	{
		int positionOfOne;
		positionOfOne = n / 2;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				magic_square[i][j] = 0;
			}
		}

		for (int i = 0, j = positionOfOne, number = 1; number <= n * n; number++)
		{
			if (number == 1)
			{
				magic_square[i][j] = number;
				j++;
				i = n - 1;
			}
			else if (number == n * n)
			{
				magic_square[i][j] = number;
				break;
			}
			else if (j < n - 1 && i >= 1 && magic_square[i - 1][j + 1] == 0)
			{
				magic_square[i][j] = number;
				i--;
				j++;
			}
			else if (i != 0 && j == n - 1)
			{
				magic_square[i][j] = number;
				j = 0;
				i--;
			}
			else if (j < n - 1 && i >= 1 && magic_square[i - 1][j + 1] > 0)
			{
				magic_square[i][j] = number;
				i++;
			}
			else if (i == 0 && j < n - 1)
			{
				magic_square[i][j] = number;
				i = n - 1;
				j++;
			}
			else if (i == 0 && j == n - 1)
			{
				magic_square[i][j] = number;
				i++;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << magic_square[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	else if (n % 4 == 0) //чётно-чётный порядок методом порядка 2^n
	{
		int consecutiveNumber = 1;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				magic_square[i][j] = consecutiveNumber;
				consecutiveNumber++;
			}
		}

		int** helping_square = new int* [n];
		for (int i = 0; i < n; i++)
		{
			helping_square[i] = new int[n];
		}

		consecutiveNumber = n * n;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				helping_square[i][j] = consecutiveNumber;
				consecutiveNumber--;
			}
		}

		int countOfSmallSquare;
		countOfSmallSquare = n * n / 16;

		int i = 0;
		int j = 0;
		int i0, j0;

		for (int k = 0; k < countOfSmallSquare; k++)
		{
			i0 = i;
			j0 = j;

			while (i0 < i + 4)
			{
				magic_square[i0][j0] = helping_square[i0][j0];
				i0++;
				j0++;
			}

			i0 = i + 3;
			j0 = j;

			while (j0 < i + 4)
			{
				magic_square[i0][j0] = helping_square[i0][j0];
				i0--;
				j0++;
			}

			if (j + 4 < n)
			{
				j += 4;
			}
			else if (j + 4 >= n)
			{
				j = 0;
				i += 4;
			}
		}

		for (int i = 0; i < n; i++)
		{
			delete[] helping_square[i];
		}
		delete[]helping_square;
		helping_square = NULL;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << magic_square[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	else //чётно-нечётный порядок диагональным методом
	{
		

		int lengthOfSmallSquare;
		lengthOfSmallSquare = n / 2;

		int** helping_square1 = new int* [lengthOfSmallSquare];
		for (int i = 0; i < lengthOfSmallSquare; i++)
		{
			helping_square1[i] = new int[lengthOfSmallSquare];
		}

		for (int i = 0; i < lengthOfSmallSquare; i++)
		{
			for (int j = 0; j < lengthOfSmallSquare; j++)
			{
				helping_square1[i][j] = 0;
			}
		}

		int** helping_square2 = new int* [lengthOfSmallSquare];
		for (int i = 0; i < lengthOfSmallSquare; i++)
		{
			helping_square2[i] = new int[lengthOfSmallSquare];
		}

		for (int i = 0; i < lengthOfSmallSquare; i++)
		{
			for (int j = 0; j < lengthOfSmallSquare; j++)
			{
				helping_square2[i][j] = 0;
			}
		}

		int** helping_square3 = new int* [lengthOfSmallSquare];
		for (int i = 0; i < lengthOfSmallSquare; i++)
		{
			helping_square3[i] = new int[lengthOfSmallSquare];
		}

		for (int i = 0; i < lengthOfSmallSquare; i++)
		{
			for (int j = 0; j < lengthOfSmallSquare; j++)
			{
				helping_square3[i][j] = 0;
			}
		}

		int** helping_square4 = new int* [lengthOfSmallSquare];
		for (int i = 0; i < lengthOfSmallSquare; i++)
		{
			helping_square4[i] = new int[lengthOfSmallSquare];
		}

		for (int i = 0; i < lengthOfSmallSquare; i++)
		{
			for (int j = 0; j < lengthOfSmallSquare; j++)
			{
				helping_square4[i][j] = 0;
			}
		}

		int lim1 = n * n / 4;
		int k = 1;
		int i = 0;
		int j = (lengthOfSmallSquare / 2);
		helping_square1[i][j] = 1;
		k++;

		while (k < lim1 + 1)
		{
			if (i - 1 > -1 && j - 1 > -1 && helping_square1[i - 1][j - 1] == 0)
			{
				helping_square1[i - 1][j - 1] = k;

				i--;
				j--;
			}
			else if (i - 1 > -1 && j - 1 > -1 && helping_square1[i - 1][j - 1] != 0 && i + 1 < lengthOfSmallSquare)
			{
				helping_square1[i + 1][j] = k;

				i++;
			}
			else if (i - 1 < 0 && j - 1 >= 0)
			{
				helping_square1[lengthOfSmallSquare - 1][j - 1] = k;

				i = lengthOfSmallSquare - 1;
				j--;
			}
			else if (i - 1 >= 0 && j - 1 < 0)
			{
				helping_square1[i - 1][lengthOfSmallSquare - 1] = k;

				i--;
				j = lengthOfSmallSquare - 1;
			}
			else if (i - 1 < 0 && j - 1 < 0 && helping_square1[lengthOfSmallSquare - 1][lengthOfSmallSquare - 1] != 0 && i + 1 < lengthOfSmallSquare)
			{
				helping_square1[i + 1][j] = k;

				i++;
			}
			k++;
		}

		int lim2 = n * n / 2;
		i = 0;
		j = (lengthOfSmallSquare / 2);
		helping_square2[i][j] = k;
		k++;

		while (k < lim2 + 1)
		{
			if (i - 1 > -1 && j - 1 >= 0 && helping_square2[i - 1][j - 1] == 0)
			{
				helping_square2[i - 1][j - 1] = k;

				i--;
				j--;
			}
			else if (i - 1 >= 0 && j - 1 >= 0 && helping_square2[i - 1][j - 1] != 0 && i + 1 < lengthOfSmallSquare)
			{
				helping_square2[i + 1][j] = k;

				i++;
			}
			else if (i - 1 < 0 && j - 1 >= 0)
			{
				helping_square2[lengthOfSmallSquare - 1][j - 1] = k;

				i = lengthOfSmallSquare - 1;
				j--;
			}
			else if (i - 1 >= 0 && j - 1 < 0)
			{
				helping_square2[i - 1][lengthOfSmallSquare - 1] = k;

				i--;
				j = lengthOfSmallSquare - 1;
			}
			else if (i - 1 < 0 && j - 1 < 0 && helping_square2[lengthOfSmallSquare - 1][lengthOfSmallSquare - 1] != 0 && i + 1 < lengthOfSmallSquare)
			{
				helping_square2[i + 1][j] = k;

				i++;
			}
			k++;
		}

		int lim3 = n * n / 4 * 3;
		i = 0;
		j = (lengthOfSmallSquare / 2);
		helping_square3[i][j] = k;
		k++;

		while (k < lim3 + 1)
		{
			if (i - 1 >= 0 && j - 1 >= 0 && helping_square3[i - 1][j - 1] == 0)
			{
				helping_square3[i - 1][j - 1] = k;

				i--;
				j--;
			}
			else if (i - 1 >= 0 && j - 1 >= 0 && helping_square3[i - 1][j - 1] != 0 && i + 1 < lengthOfSmallSquare)
			{
				helping_square3[i + 1][j] = k;

				i++;
			}
			else if (i - 1 < 0 && j - 1 >= 0)
			{
				helping_square3[lengthOfSmallSquare - 1][j - 1] = k;

				i = lengthOfSmallSquare - 1;
				j--;
			}
			else if (i - 1 >= 0 && j - 1 < 0)
			{
				helping_square3[i - 1][lengthOfSmallSquare - 1] = k;

				i--;
				j = lengthOfSmallSquare - 1;
			}
			else if (i - 1 < 0 && j - 1 < 0 && helping_square3[lengthOfSmallSquare - 1][lengthOfSmallSquare - 1] != 0 && i + 1 < lengthOfSmallSquare)
			{
				helping_square3[i + 1][j] = k;

				i++;
			}
			k++;
		}

		int lim4 = n * n;
		i = 0;
		j = (lengthOfSmallSquare / 2);
		helping_square4[i][j] = k;
		k++;

		while (k < lim4 + 1)
		{
			if (i - 1 >= 0 && j - 1 >= 0 && helping_square4[i - 1][j - 1] == 0)
			{
				helping_square4[i - 1][j - 1] = k;

				i--;
				j--;
			}
			else if (i - 1 >= 0 && j - 1 >= 0 && helping_square4[i - 1][j - 1] != 0 && i + 1 < lengthOfSmallSquare)
			{
				helping_square4[i + 1][j] = k;

				i++;
			}
			else if (i - 1 < 0 && j - 1 >= 0)
			{
				helping_square4[lengthOfSmallSquare - 1][j - 1] = k;

				i = lengthOfSmallSquare - 1;
				j--;
			}
			else if (i - 1 >= 0 && j - 1 < 0)
			{
				helping_square4[i - 1][lengthOfSmallSquare - 1] = k;

				i--;
				j = lengthOfSmallSquare - 1;
			}
			else if (i - 1 < 0 && j - 1 < 0 && helping_square4[lengthOfSmallSquare - 1][lengthOfSmallSquare - 1] != 0 && i + 1 < lengthOfSmallSquare)
			{
				helping_square4[i + 1][j] = k;

				i++;
			}
			k++;
		}

		int temporary;
		temporary = helping_square1[0][0];
		helping_square1[0][0] = helping_square4[0][0];
		helping_square4[0][0] = temporary;

		for (int a = 1; a < lengthOfSmallSquare - 1; a++)
		{
			temporary = helping_square1[a][1];

			helping_square1[a][1] = helping_square4[a][1];
			helping_square4[a][1] = temporary;
		}

		k = (n - 2) / 4 - 1;
		if (k > 0)
		{
			while (k > 0)
			{
				for (int i = 0; i < lengthOfSmallSquare; i++)
				{
					temporary = helping_square1[i][lengthOfSmallSquare - k];

					helping_square1[i][lengthOfSmallSquare - k] = helping_square4[i][lengthOfSmallSquare - k];
					helping_square4[i][lengthOfSmallSquare - k] = temporary;

					temporary = helping_square3[i][k - 1];

					helping_square3[i][k - 1] = helping_square2[i][k - 1];
					helping_square2[i][k - 1] = temporary;
				}
				k--;
			}
		}

		for (int i = 0; i < lengthOfSmallSquare; i++)
		{
			for (int j = 0; j < lengthOfSmallSquare; j++)
			{
				magic_square[i][j] = helping_square1[i][j];
				magic_square[i + lengthOfSmallSquare][j + lengthOfSmallSquare] = helping_square2[i][j];
				magic_square[i][j + lengthOfSmallSquare] = helping_square3[i][j];
				magic_square[i + lengthOfSmallSquare][j] = helping_square4[i][j];
			}
		}

		for (int i = 0; i < lengthOfSmallSquare; i++)
		{
			delete[] helping_square1[i];
		}
		delete[]helping_square1;
		helping_square1 = NULL;

		for (int i = 0; i < lengthOfSmallSquare; i++)
		{
			delete[] helping_square2[i];
		}
		delete[]helping_square2;
		helping_square2 = NULL;

		for (int i = 0; i < lengthOfSmallSquare; i++)
		{
			delete[] helping_square3[i];
		}
		delete[]helping_square3;
		helping_square3 = NULL;

		for (int i = 0; i < lengthOfSmallSquare; i++)
		{
			delete[] helping_square4[i];
		}
		delete[]helping_square4;
		helping_square4 = NULL;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << magic_square[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}

	

	for (int i = 0; i < n; i++)
	{
		free(magic_square[i]);
	}
	free(magic_square);
	magic_square = NULL;

	return 0;
}