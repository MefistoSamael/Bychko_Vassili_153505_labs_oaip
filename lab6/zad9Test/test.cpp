#include "pch.h"
#include <string>
using namespace std;

int func(string str)
{
	string newstr, numb;
	newstr = "";
	numb = "";
	int i, newlen = 0;


	int length = str.size();

	for (i = 0; i < length; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')//смотрим на цифры
		{
			if (str[i - 1] == '-' && i > 0)//учитываем минус
			{
				newstr += str[i - 1];
			}
			newstr += str[i];//записываем в новый массив
			if (str[i + 1] < '0' || str[i + 1] > '9')
			{
				newstr += '*';
			}
		}
	}

	newlen = newstr.size();

	int* arr = new int[newlen / 2];

	int j = 0;

	for (i = 0; i < newlen; i++)
	{
		if (newstr[i] != '*')
		{
			numb += newstr[i];
		}
		else
		{
			arr[j] = atoi(numb.c_str());//перевод из символа в число
			j++;
			numb = "";
		}
	}

	int sum = 0;

	for (i = 0; i < j; i++)
	{
		sum += arr[i];
	}
	return sum;
}


TEST(TestCaseName, Test1) {
	bool A = 1;
	int test = 534;
	int res = 0;
	string str;
	str = { "fuhbnijfbvshdbr534dfhb;2;dgdy* -2" };
	res = func(str);
	if (test != res) A = 0;
  EXPECT_TRUE(A);
}

TEST(TestCaseName, Test2) {
	bool A = 1;
	int test = 46;
	int res = 0;
	string str;
	str = { "fsduyvbnij   br54dfhb;2;dgdy* -10" };
	res = func(str);

	if (test != res) A = 0;
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test3) {
	bool A = 1;
	int test = 66;
	int res = 0;
	string str;
	str = { "fsduyvbnij   br54dfhb;2;dgdy* 10" };
	res = func(str);

	if (test != res) A = 0;
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test4) {
	bool A = 1;
	int test = 94;
	int res = 0;
	string str;
	str = { "fsduyvbnij 25.3   br54dfhb;2;dgdy* 10" };
	res = func(str);

	if (test != res) A = 0;
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test5) {
	bool A = 1;
	int test = 10;
	int res = 0;
	string str;
	str = { "-0.5fhbvs-0.5" };
	res = func(str);

	if (test != res) A = 0;
	EXPECT_TRUE(A);
}



