#include "pch.h"
using namespace std;

bool insert(char* str, char* substr, char symb, char* test)
{
	bool EtoZadanieMenyaZabulilo_MneBolno = 1;
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
	for (int i = 0; i < strlen(newstr); i++)
	{
		if (newstr[i] != test[i]) EtoZadanieMenyaZabulilo_MneBolno = 0;
	}
	free(newstr);

	return EtoZadanieMenyaZabulilo_MneBolno;
}

//puk kapuka huiapuk
//puk apuk huiapuk
//0
//aaaaa aaa
//a a a

TEST(TestCaseName, Test1) {
	bool A = 0;
	char str[25] = {"puk kapuka huiapuk"};
	char substr[20] = {"apuk"};
	char symb = 'd';
	char test[35] = {"puk kapuka huiapukd"};
	A = insert(str,substr,symb,test);
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test2) {
	bool A = 0;
	char str[25] = { "0" };
	char substr[20] = { "0" };
	char symb = 'd';
	char test[35] = { "0d" };
	A = insert(str, substr, symb, test);
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test3) {
	bool A = 0;
	char str[25] = { "puk apuk huiapuk" };
	char substr[20] = { "apuk" };
	char symb = 'd';
	char test[35] = { "puk apukd huiapukd" };
	A = insert(str, substr, symb, test);
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test4) {
	bool A = 0;
	char str[25] = { "aaaaa aaa" };
	char substr[20] = { "aaaaa" };
	char symb = 'd';
	char test[35] = { "aaaaad aaa" };
	A = insert(str, substr, symb, test);
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test5) {
	bool A = 0;
	char str[25] = { "a a a" };
	char substr[20] = { "a" };
	char symb = 'd';
	char test[35] = { "ad ad ad" };
	A = insert(str, substr, symb, test);
	EXPECT_TRUE(A);
}