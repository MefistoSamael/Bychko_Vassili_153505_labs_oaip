#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cout << "Enter size of array: ";
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


	int** array1 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		array1[i] = (int*)malloc(n * sizeof(int));
	}

	cout << "we have magis square of " << n << "size" << endl;

	if (n == 1 || n == 2)
	{
		cout << "magic square of " << n << "size dont exist" << endl;
	}
	else if (n % 2 == 1) //нечётный порядок индийским методом
	{
		int posfirst;
		posfirst = n / 2;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				array1[i][j] = 0;
			}
		}

		for (int i = 0, j = posfirst, number = 1; number <= n * n; number++)
		{
			if (number == 1)
			{
				array1[i][j] = number;
				j++;
				i = n - 1;
			}
			else if (number == n * n)
			{
				array1[i][j] = number;
				break;
			}
			else if (j < n - 1 && i >= 1 && array1[i - 1][j + 1] == 0)
			{
				array1[i][j] = number;
				i--;
				j++;
			}
			else if (i != 0 && j == n - 1)
			{
				array1[i][j] = number;
				j = 0;
				i--;
			}
			else if (j < n - 1 && i >= 1 && array1[i - 1][j + 1] > 0)
			{
				array1[i][j] = number;
				i++;
			}
			else if (i == 0 && j < n - 1)
			{
				array1[i][j] = number;
				i = n - 1;
				j++;
			}
			else if (i == 0 && j == n - 1)
			{
				array1[i][j] = number;
				i++;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << array1[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	else if (n % 4 == 0) //чётно-чётный порядок методом порядка 2^n
	{
		int consnumb = 1;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				array1[i][j] = consnumb;
				consnumb++;
			}
		}

		int** helparray = new int* [n];
		for (int i = 0; i < n; i++)
		{
			helparray[i] = new int[n];
		}

		consnumb = n * n;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				helparray[i][j] = consnumb;
				consnumb--;
			}
		}

		int count;
		count = n * n / 16;

		int i = 0;
		int j = 0;
		int i0, j0;

		for (int k = 0; k < count; k++)
		{
			i0 = i;
			j0 = j;

			while (i0 < i + 4)
			{
				array1[i0][j0] = helparray[i0][j0];
				i0++;
				j0++;
			}

			i0 = i + 3;
			j0 = j;

			while (j0 < i + 4)
			{
				array1[i0][j0] = helparray[i0][j0];
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
			delete[] helparray[i];
		}
		delete[]helparray;
		helparray = NULL;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << array1[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	else //чётно-нечётный порядок диагональным методом
	{
		

		int length;
		length = n / 2;

		int** helparray2 = new int* [length];
		for (int i = 0; i < length; i++)
		{
			helparray2[i] = new int[length];
		}

		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				helparray2[i][j] = 0;
			}
		}

		int** helparray3 = new int* [length];
		for (int i = 0; i < length; i++)
		{
			helparray3[i] = new int[length];
		}

		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				helparray3[i][j] = 0;
			}
		}

		int** helparray4 = new int* [length];
		for (int i = 0; i < length; i++)
		{
			helparray4[i] = new int[length];
		}

		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				helparray4[i][j] = 0;
			}
		}

		int** helparray5 = new int* [length];
		for (int i = 0; i < length; i++)
		{
			helparray5[i] = new int[length];
		}

		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				helparray5[i][j] = 0;
			}
		}

		int lim1 = n * n / 4;
		int k = 1;
		int i = 0;
		int j = (length / 2);
		helparray2[i][j] = 1;
		k++;

		while (k < lim1 + 1)
		{
			if (i - 1 > -1 && j - 1 > -1 && helparray2[i - 1][j - 1] == 0)
			{
				helparray2[i - 1][j - 1] = k;

				i--;
				j--;
			}
			else if (i - 1 > -1 && j - 1 > -1 && helparray2[i - 1][j - 1] != 0 && i + 1 < length)
			{
				helparray2[i + 1][j] = k;

				i++;
			}
			else if (i - 1 < 0 && j - 1 >= 0)
			{
				helparray2[length - 1][j - 1] = k;

				i = length - 1;
				j--;
			}
			else if (i - 1 >= 0 && j - 1 < 0)
			{
				helparray2[i - 1][length - 1] = k;

				i--;
				j = length - 1;
			}
			else if (i - 1 < 0 && j - 1 < 0 && helparray2[length - 1][length - 1] != 0 && i + 1 < length)
			{
				helparray2[i + 1][j] = k;

				i++;
			}
			k++;
		}

		int lim2 = n * n / 2;
		i = 0;
		j = (length / 2);
		helparray3[i][j] = k;
		k++;

		while (k < lim2 + 1)
		{
			if (i - 1 > -1 && j - 1 >= 0 && helparray3[i - 1][j - 1] == 0)
			{
				helparray3[i - 1][j - 1] = k;

				i--;
				j--;
			}
			else if (i - 1 >= 0 && j - 1 >= 0 && helparray3[i - 1][j - 1] != 0 && i + 1 < length)
			{
				helparray3[i + 1][j] = k;

				i++;
			}
			else if (i - 1 < 0 && j - 1 >= 0)
			{
				helparray3[length - 1][j - 1] = k;

				i = length - 1;
				j--;
			}
			else if (i - 1 >= 0 && j - 1 < 0)
			{
				helparray3[i - 1][length - 1] = k;

				i--;
				j = length - 1;
			}
			else if (i - 1 < 0 && j - 1 < 0 && helparray3[length - 1][length - 1] != 0 && i + 1 < length)
			{
				helparray3[i + 1][j] = k;

				i++;
			}
			k++;
		}

		int lim3 = n * n / 4 * 3;
		i = 0;
		j = (length / 2);
		helparray4[i][j] = k;
		k++;

		while (k < lim3 + 1)
		{
			if (i - 1 >= 0 && j - 1 >= 0 && helparray4[i - 1][j - 1] == 0)
			{
				helparray4[i - 1][j - 1] = k;

				i--;
				j--;
			}
			else if (i - 1 >= 0 && j - 1 >= 0 && helparray4[i - 1][j - 1] != 0 && i + 1 < length)
			{
				helparray4[i + 1][j] = k;

				i++;
			}
			else if (i - 1 < 0 && j - 1 >= 0)
			{
				helparray4[length - 1][j - 1] = k;

				i = length - 1;
				j--;
			}
			else if (i - 1 >= 0 && j - 1 < 0)
			{
				helparray4[i - 1][length - 1] = k;

				i--;
				j = length - 1;
			}
			else if (i - 1 < 0 && j - 1 < 0 && helparray4[length - 1][length - 1] != 0 && i + 1 < length)
			{
				helparray4[i + 1][j] = k;

				i++;
			}
			k++;
		}

		int lim4 = n * n;
		i = 0;
		j = (length / 2);
		helparray5[i][j] = k;
		k++;

		while (k < lim4 + 1)
		{
			if (i - 1 >= 0 && j - 1 >= 0 && helparray5[i - 1][j - 1] == 0)
			{
				helparray5[i - 1][j - 1] = k;

				i--;
				j--;
			}
			else if (i - 1 >= 0 && j - 1 >= 0 && helparray5[i - 1][j - 1] != 0 && i + 1 < length)
			{
				helparray5[i + 1][j] = k;

				i++;
			}
			else if (i - 1 < 0 && j - 1 >= 0)
			{
				helparray5[length - 1][j - 1] = k;

				i = length - 1;
				j--;
			}
			else if (i - 1 >= 0 && j - 1 < 0)
			{
				helparray5[i - 1][length - 1] = k;

				i--;
				j = length - 1;
			}
			else if (i - 1 < 0 && j - 1 < 0 && helparray5[length - 1][length - 1] != 0 && i + 1 < length)
			{
				helparray5[i + 1][j] = k;

				i++;
			}
			k++;
		}

		int temp;
		temp = helparray2[0][0];
		helparray2[0][0] = helparray5[0][0];
		helparray5[0][0] = temp;

		for (int a = 1; a < length - 1; a++)
		{
			temp = helparray2[a][1];

			helparray2[a][1] = helparray5[a][1];
			helparray5[a][1] = temp;
		}

		k = (n - 2) / 4 - 1;
		if (k > 0)
		{
			while (k > 0)
			{
				for (int i = 0; i < length; i++)
				{
					temp = helparray2[i][length - k];

					helparray2[i][length - k] = helparray5[i][length - k];
					helparray5[i][length - k] = temp;

					temp = helparray4[i][k - 1];

					helparray4[i][k - 1] = helparray3[i][k - 1];
					helparray3[i][k - 1] = temp;
				}
				k--;
			}
		}

		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				array1[i][j] = helparray2[i][j];
				array1[i + length][j + length] = helparray3[i][j];
				array1[i][j + length] = helparray4[i][j];
				array1[i + length][j] = helparray5[i][j];
			}
		}

		for (int i = 0; i < length; i++)
		{
			delete[] helparray2[i];
		}
		delete[]helparray2;
		helparray2 = NULL;

		for (int i = 0; i < length; i++)
		{
			delete[] helparray3[i];
		}
		delete[]helparray3;
		helparray3 = NULL;

		for (int i = 0; i < length; i++)
		{
			delete[] helparray4[i];
		}
		delete[]helparray4;
		helparray4 = NULL;

		for (int i = 0; i < length; i++)
		{
			delete[] helparray5[i];
		}
		delete[]helparray5;
		helparray5 = NULL;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << array1[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}


	for (int i = 0; i < n; i++)
	{
		free(array1[i]);
	}
	free(array1);
	array1 = NULL;

	return 0;
}