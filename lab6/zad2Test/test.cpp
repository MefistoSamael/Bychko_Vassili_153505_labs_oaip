#include "pch.h"
using namespace std;

bool insert(char* str, char* substr, char symb, char* test)
{
	bool EtoZadanieMenyaZabulilo_MneBolno = 1;
	//переменна€ дл€ индикации, что конец строки достигнут и нужно двигать нуль“≈–ћ»Ќј“ќ–
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
		//переменна€ дл€ индикации было ли заполнение массива
		bool A = 0;
		int k = strlen(substr) - 1;
		//заполнение нового массива


		for (; str[j] != ' ' && str[j] != '\0'; i++)
		{
			newstr[i] = str[j];
			j++;
			A = 1;
			numbel++;
		}
		//индикации, что конец строки достигнут и нужно двигать нуль“≈–ћ»Ќј“ќ–
		if (str[j] == '\0') C = 1;


		//проверка на первое совпадение с подстрокой
		if (newstr[i - 1] == substr[k] && numbel >= strlen(substr))
		{
			for (; k >= 0; k--)
			{
				B = 1;//чтобы при лишних проходах не входил в иф
				if (newstr[i - 1] != substr[k])
				{
					B = 0;
					break;
				}
				i--;
			}
		}


		//если подстрока совпала
		if (B)
		{
			i += strlen(substr);
			newstr[i] = symb;
			i++;
		}
		//двигаем нуль“≈–ћ»Ќј“ќ–
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