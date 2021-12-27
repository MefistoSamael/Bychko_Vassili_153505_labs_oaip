#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{

	string str;
	cout << "enter string" << endl;
	getline(cin, str);

	int n;
	n = str.size();

	double generalSum = 0;
	for (int i = 0; i < n; i++)
	{
		if (((int)str[i] >= 48) && ((int)str[i] <= 57))
		{
			int count = 0;
			int j = i;
			int pos1 = 0;
			int pos2 = 0;

			while (((int)str[j] >= 48) && ((int)str[j] <= 57) || str[j] == ',' || str[j] == '.' || str[j] == 'e' || str[j] == 'E' || str[j] == '+' || str[j] == '-')
			{
				if (str[j] == '.' || str[j] == ',')
				{
					pos1 = j;
				}

				if ((str[j] == 'e' || str[j] == 'E') && (str[j + 1] == '+' || str[j + 1] == '-' || ((int)str[j + 1] >= 48 && (int)str[j + 1] <= 57)))
				{
					pos2 = j;
				}

				count++;
				j++;
			}

			double numb = 0;

			if (pos1 == 0 && pos2 != 0)
			{
				if (str[pos2 + 1] == '+')
				{
					int k = 0;
					j -= 1;

					double degree = 0;
					for (j; j > pos2 + 1; j--)
					{
						degree += (str[j] - 48) * pow(10, k);
						k++;
					}

					k = 0;
					j -= 2;
					double mant = 0;
					for (j; j >= i; j--)
					{
						mant += (str[j] - 48) * pow(10, k);
						k++;
					}

					numb = mant * pow(10, degree);
				}
				else if (str[pos2 + 1] == '-')
				{
					int k = 0;
					j -= 1;

					double degree = 0;
					for (j; j > pos2 + 1; j--)
					{
						degree += (str[j] - 48) * pow(10, k);
						k++;
					}

					k = 0;
					j -= 2;
					double mant = 0;
					for (j; j >= i; j--)
					{
						mant += (str[j] - 48) * pow(10, k);
						k++;
					}

					numb = mant * pow(10, -degree);
				}
				else
				{
					int k = 0;
					j -= 1;

					double degree = 0;
					for (j; j > pos2; j--)
					{
						degree += (str[j] - 48) * pow(10, k);
						k++;
					}

					k = 0;
					j -= 1;
					double mant = 0;
					for (j; j >= i; j--)
					{
						mant += (str[j] - 48) * pow(10, k);
						k++;
					}

					numb = mant * pow(10, degree);
				}
			}
			else if (pos1 != 0 && pos2 == 0)
			{
				int k = 0;
				j -= 1;
				for (j; j > pos1; j--)
				{
					numb += (str[j] - 48) * pow(10, k);
					k++;
				}

				double fractionalPart = 0;
				fractionalPart = numb * pow(10, -k);

				numb = 0;
				j -= 1;
				k = 0;
				for (j; j >= i; j--)
				{
					numb += (str[j] - 48) * pow(10, k);
					k++;
				}

				numb += fractionalPart;
			}
			else if (pos1 != 0 && pos2 != 0)
			{
				if (str[pos2 + 1] == '+')
				{
					int k = 0;
					j -= 1;

					double degree = 0;
					for (j; j > pos2 + 1; j--)
					{
						degree += (str[j] - 48) * pow(10, k);
						k++;
					}

					k = 0;
					j -= 2;

					double mant = 0;
					for (j; j > pos1; j--)
					{
						mant += (str[j] - 48) * pow(10, k);
						k++;
					}

					double fractionalPart = 0;
					fractionalPart = mant * pow(10, -k);

					mant = 0;
					j -= 1;
					k = 0;
					for (j; j >= i; j--)
					{
						mant += (str[j] - 48) * pow(10, k);
						k++;
					}

					mant += fractionalPart;

					numb = mant * pow(10, degree);
				}
				else if (str[pos2 + 1] == '-')
				{
					int k = 0;
					j -= 1;

					double degree = 0;
					for (j; j > pos2 + 1; j--)
					{
						degree += (str[j] - 48) * pow(10, k);
						k++;
					}

					k = 0;
					j -= 2;

					double mant = 0;
					for (j; j > pos1; j--)
					{
						mant += (str[j] - 48) * pow(10, k);
						k++;
					}

					double fractionalPart = 0;
					fractionalPart = mant * pow(10, -k);

					mant = 0;
					j -= 1;
					k = 0;
					for (j; j >= i; j--)
					{
						mant += (str[j] - 48) * pow(10, k);
						k++;
					}

					mant += fractionalPart;

					numb = mant * pow(10, -degree);
				}
				else
				{
					int k = 0;
					j -= 1;

					double degree = 0;
					for (j; j > pos2; j--)
					{
						degree += (str[j] - 48) * pow(10, k);
						k++;
					}

					k = 0;
					j -= 1;

					double mant = 0;
					for (j; j > pos1; j--)
					{
						mant += (str[j] - 48) * pow(10, k);
						k++;
					}

					double fractionalPart = 0;
					fractionalPart = mant * pow(10, -k);

					mant = 0;
					j -= 1;
					k = 0;
					for (j; j >= i; j--)
					{
						mant += (str[j] - 48) * pow(10, k);
						k++;
					}

					mant += fractionalPart;

					numb = mant * pow(10, degree);
				}
			}
			else
			{
				int k = 0;
				j -= 1;
				for (j; j >= i; j--)
				{
					numb += (str[j] - 48) * pow(10, k);
					k++;
				}
			}

			if (i != 0 && str[i - 1] == '-')
			{
				numb *= (-1);
			}

			generalSum += numb;
			i += count;
		}
	}

	cout << "the sum of all the numbers = " << generalSum << endl;

	return 0;
}