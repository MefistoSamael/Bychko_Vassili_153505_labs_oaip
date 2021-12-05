//В строке, состоящей из групп нулей и единиц, подсчитать 
//количество единиц в группах с нечетным количеством символов.(вариант 5)
#include <iostream>
using namespace std;

int main()
{
	char str1[80];
	cout << "strlen = " << strlen(str1) << endl;
	int array[80];
	int numbel = 0;
	cout << "Enter string\n!WARNING! numb of symbols < 80\n";
	cin.getline(str1, 80);
	cout << "str -" << str1 << endl;

	// и поиск индекса первого "непробельного" эллемента
	int i = 0;
	for (; i < strlen(str1); i++)
	{
		if (str1[i] != ' ') break;
	}


	int numb = 0;
	for (; str1[i] != '\0'; )
	{
		int numb1 = 0;
		int numbel = 0;
		int j = i;
		for (; str1[j] != ' ' && str1[j] != '\0'; j++)
		{
			if (str1[j] == '1') numb1++;
			numbel++;
		}
		if (numbel % 2) numb += numb1;
		i = j + 1;
	}

	cout << "number of 1 = " << numb;

	return 0;
}
