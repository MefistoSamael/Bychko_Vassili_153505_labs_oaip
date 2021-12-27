#include "pch.h"
using namespace std;

bool change(char** str, int size, int avlen, char** test)
{
	bool A = 1;
	for (int i = 0; i < size; i++)
	{
		if (strlen(str[i]) < avlen)
		{
			int len = strlen(str[i]);
			str[i] = (char*)realloc(str[i], avlen + 1);
			for (int j = len; j < avlen; j++)
			{
				str[i][j] = '_';
			}
			str[i][avlen] = '\0';
		}
		else if (strlen(str[i]) > avlen)
		{
			str[i] = (char*)realloc(str[i], avlen + 1);
			str[i][avlen] = '\0';
		}

	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < avlen; j++)
		{
			if (str[i][j] != test[i][j]) A = 0;
		}
	}
	return A;
}

TEST(TestCaseName, Test1) {
	bool A = 1;
	char** str = new char* [3];
	for (int i = 0; i < 3; i++)
	{
		str[i] = new char[30];
	}
	str[0] = { "a qwertyu\0" };
	str[1] = { "bcdz\0" };
	str[2] = { "ag\0" };
	char** test = new char* [3];
	for (int i = 0; i < 3; i++)
	{
		test[i] = new char[30];
	}
	test[0] = { "a qwe\0" };
	test[1] = { "bcdz_\0" };
	test[2] = { "ag___\0" };
	int avg = 5;
	A = change(str, 3, avg, test);


	EXPECT_TRUE(A);
}