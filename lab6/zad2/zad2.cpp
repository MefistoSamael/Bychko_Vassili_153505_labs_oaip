#include <iostream>
using namespace std;

void insert(char* str,int lens,int leni, char* ins,int index)
{
	char*
}

int main()
{
	char* substr = new char[81];
	cout << "enter substring. Number of elements <80 ";
	cin.getline(substr, 81); 
	cout << "enter string. Number of elements <80 ";
	char* str = new char[80];
	cin.getline(str, 81);
	int array[80];
	cout << "enter insert element ";
	char* ins = new char[80];
	cin.getline(ins, 80);
	for (int i = 0,j = 0,z = 0; i < strlen(str); i++)//����� ������ ������ ��� ���������
	{
		if (str[i] == substr[j])//��� ����������� ������� ��������� � �������������� ��������
		{
			for (; j < strlen(substr); j++)//�����������
			{
				if (str[i + j] != substr[j])//���� �� ��������� ������
				{
					j = 0;
					break;
				}

			}
			if (j)
			{
				array[z] = j;
				z++;
			}
			j == 0;
		}
	}



	return 0;
}