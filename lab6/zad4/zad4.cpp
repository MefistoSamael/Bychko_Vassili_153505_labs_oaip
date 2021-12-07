#include <iostream>
using namespace std;

void change(char* str, char* newstr);

int main()
{
	char* str = new char[100];
	cout << "Enter text :";
	cin.getline(str, 99);
	char* newstr = new char[300];
	newstr[299] = '\0';
	change(str,newstr);
	cout << "newstr :" << newstr;

	return 0;
}

void change(char* str, char* newstr)
{
	int numeq = 0;
	char* temp = new char[strlen(newstr)];
	//копируем значения с заменой
	for (int i = 0, j =0; i < 99; i++)
	{
		if (str[i] == 'c')
		{
			if (str[i + 1] == 'e' || str[i + 1] == 'E' || str[i + 1] == 'i' || str[i + 1] == 'I' || str[i + 1] == 'y' || str[i + 1] == 'Y')
			{
				newstr[j] = 's';
				j++;
				continue;
			}
			newstr[j] = 'k';
			j++;
			continue;
		}
		if (str[i] == 'C' )
		{
			if (str[i + 1] == 'e' || str[i + 1] == 'E' || str[i + 1] == 'i' || str[i + 1] == 'I' || str[i + 1] == 'y' || str[i + 1] == 'Y')
			{
				newstr[j] = 'S';
				j++;
				continue;
			}
			newstr[j] = 'K';
			j++;
			continue;
		}

		if (str[i] == 'q')
		{
			if (str[i + 1] == 'u')
			{
				newstr[j] = 'k';
				newstr[j + 1] = 'v';
				j += 2;
				i++;
				continue;
			}
			newstr[j] = 'k';
			j++;
			continue;
		}
		if (str[i] == 'Q')
		{
			if (str[i + 1] == 'u')
			{
				newstr[j] = 'K';
				newstr[j + 1] = 'v';
				j += 2;
				i++;
				continue;
			}
			newstr[j] = 'K';
			j++;
			continue;
		}

		if (str[i] == 'x')
		{
			newstr[j] = 'k';
			newstr[j + 1] = 's';
			j += 2;
			continue;
		}
		if (str[i] == 'X')
		{
			newstr[j] = 'K';
			newstr[j + 1] = 's';
			j += 2;
			continue;
		}

		if (str[i] == 'w')
		{
			newstr[j] = 'v';
			j++;
			continue;
		}
		if (str[i] == 'W')
		{
			newstr[j] = 'V';
			j++;
			continue;
		}

		if (str[i] == 'p' && str[i+1] == 'h')
		{
			newstr[j] = 'f';
			j++;
			i++;
			continue;
		}
		if (str[i] == 'P' && str[i+1] == 'h')
		{
			newstr[j] = 'F';
			j++;
			i++;
			continue;
		}

		if (str[i] == 'y' && str[i + 1] == 'o' && str[i + 2] == 'u') 
		{
			newstr[j] = 'u';
			j++;
			i+=2;
			continue;
		}
		if (str[i] == 'Y' && str[i + 1] == 'o' && str[i + 2] == 'u')
		{
			newstr[j] = 'U';
			j++;
			i += 2;
			continue;
		}

		if (str[i] == 'o' && str[i + 1] == 'o')
		{
			newstr[j] = 'u';
			j++;
			i++;
			continue;
		}
		if (str[i] == 'O' && str[i + 1] == 'o')
		{
			newstr[j] = 'U';
			j++;
			i++;
			continue;
		}

		if (str[i] == 'e' && str[i + 1] == 'e')
		{
			newstr[j] = 'i';
			j++;
			i++;
			continue;
		}
		if (str[i] == 'E' && str[i + 1] == 'e')
		{
			newstr[j] = 'I';
			j++;
			i++;
			continue;
		}

		if (str[i] == 't' && str[i + 1] == 'h')
		{
			newstr[j] = 'z';
			j++;
			i++;
			continue;
		}
		if (str[i] == 'T' && str[i + 1] == 'h')
		{
			newstr[j] = 'Z';
			j++;
			i++;
			continue;
		}
		newstr[j] = str[i];
		j++;



	}
	//копируем значения в допмассив
	for (int i = 0; i <strlen(newstr) ; i++)
	{
		temp[i] = newstr[i];
		newstr[i] = ' ';
	}
	for (int i = 0, j =0; i < strlen(newstr); i++)
	{
		if (temp[i] == temp[i + 1])
		{
			numeq++;
			continue;
		}
		newstr[j] = temp[i];
		j++;
	}
	newstr[strlen(newstr) - numeq] = '\0';
}

//kxssaaa pph 1999