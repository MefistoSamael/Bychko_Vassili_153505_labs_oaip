#include <iostream>
#include <cassert>
using namespace std;

void insert(char* str, char* substr, char symb)
{
	bool B = 1;
	int index = 0;
	char* newstr = (char*)calloc(100, sizeof(char));
	int k = strlen(substr) - 1;
	for (int i = 0; i < 100; i++)//заполнение нового массива
	{
		for (; str[1] != ' '; i++)
		{
			newstr[i] = str[i];
		}
		if (newstr[i] = substr[k])
		{
			for (; k >= 0; k++)
			{
				if (newstr[i] != substr[k])
				{
					break;
					B = 0;
				}

			}
		}
	}
	free(str);
	str = newstr;

}

int main()
{
	char* str = (char*)malloc(20* sizeof(char));
	cin.getline(str, 10);
	char* substr = (char*)malloc(20* sizeof(char));
	cin.getline(substr, 10);
	cout << "\nstrlen = " << strlen(substr);
	cout <<"str = " << str;
	cout << endl <<"substr = " <<substr << endl;
	cout << "Enter symb = ";
	char symb;
	cin >> symb;
	insert(str, substr, symb);
	cout << "newstr = " << str;

	free(str);
	free(substr);

	return 0;
}
