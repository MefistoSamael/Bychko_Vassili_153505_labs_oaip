//
// ����� ������� ����� ������, ��������������� �������� 
// ����������, �������� ��������� ������.
//
#include <iostream>
#include <cassert>
#include <stdlib.h>
using namespace std;

void insert(char* str, char* substr, char symb)
{

	//���������� ��� ���������, ��� ����� ������ ��������� � ����� ������� ��������������
	bool C = 0;
	int index = 0;
	char* newstr = (char*)malloc(100 * sizeof(char));
	newstr[99] = '\0';
	//cout << "newstrlen = " << strlen(newstr) << endl;
	int i = 0;
	int j = 0;
	for (int z = 0; newstr[z] != '\0'; z++)
	{
		bool B = 0;
		int numbel = 0;
		//���������� ��� ��������� ���� �� ���������� �������
		bool A = 0;
		int k = strlen(substr) - 1;
		//���������� ������ �������


		for (; str[j] != ' ' && str[j] != '\0'; i++)
		{
			newstr[i] = str[j];
			j++;
			A = 1;
			numbel++;
		}
		//���������, ��� ����� ������ ��������� � ����� ������� ��������������
		if (str[j] == '\0') C = 1;


		//�������� �� ������ ���������� � ����������
		if (newstr[i - 1] == substr[k] && numbel >= strlen(substr))
		{
			for (; k >= 0; k--)
			{
				B = 1;//����� ��� ������ �������� �� ������ � ��
				if (newstr[i - 1] != substr[k])
				{
					B = 0;
					break;
				}
				i--;
			}
		}


		//���� ��������� �������
		if (B)
		{
			i += strlen(substr);
			newstr[i] = symb;
			i++;
		}
		//������� ��������������
		if (C)
		{
			newstr[i] = '\0';
			break;
		}
		newstr[i] = ' ';
		j++;
		i++;


	}
	cout << "\nnewstr = " << newstr << endl;
	free(substr);
	free(newstr);
}

int main()
{
	char* str = (char*)calloc(25, sizeof(char));
	cout << "ENTER main string :";
	cin.getline(str, 24);
	char* substr = (char*)calloc(25, sizeof(char));
	cout << "Enter substring :";
	cin.getline(substr, 24);
	//cout << "\nstrlen = " << strlen(substr) << endl;
	//cout << "str = " << str;
	//cout << endl << "substr = " << substr << endl;
	cout << "Enter symb = ";
	char symb;
	cin >> symb;
	insert(str, substr, symb);


	free(str);

	return 0;
}
//puk kapuka huiapuk
//puk apuk huiapuk
//0
//aaaaa aaa
//a a a