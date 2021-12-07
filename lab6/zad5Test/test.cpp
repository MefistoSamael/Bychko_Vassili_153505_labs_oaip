#include "pch.h"

int mypow(int k, int n, int prec)
{
	long long x = k;
	long long g = 1;
	long long cln = n;
	long long prod = 1;
	while (true)
	{
		g = 1;
		x = k;

		while (g < cln)
		{
			g *= 2;
			if (g > cln)
			{
				g /= 2;
				break;
			}
			x = (x * x) % prec;
		}

		cln -= g;
		prod = (prod * x) % prec;
		if (cln <= 0)
		{
			return prod % prec;
		}
	}
}

int search(char* str1, char* str2, int mainlen, int prec)
{
	long long answer = 0;
	bool CheckEq = 0;
	if (strlen(str1) == strlen(str2))
	{
		CheckEq = 1;
		for (int i = 0; i < strlen(str1); i++)
		{
			if (str1[i] != str2[i])
			{
				CheckEq = 0;
				break;
			}
		}
	}
	if (strlen(str2) + strlen(str1) < mainlen)
	{
		answer = mypow(26, mainlen - strlen(str2) - strlen(str1), prec);
		if (!CheckEq) answer *= 2;
		return answer;
	}
	if (strlen(str2) + strlen(str1) == mainlen)
	{
		answer = 2;
		return answer;
	}
	if (strlen(str2) + strlen(str1) > mainlen)
	{
		bool A = 1;
		int n = 0;
		n = strlen(str2) + strlen(str1) - mainlen;
		//первое сравнение
		for (int i = strlen(str1) - n, j = 0; j < n; i++, j++)
		{
			if (str1[i] != str2[j]) A = 0;
		}
		if (A)
		{
			answer++;
			if (CheckEq) return answer;
		}
		//если первое сравнение не прошло меняем местами строки


		A = 1;
		for (int i = strlen(str1) - 1, j = 0; j < n; i--, j++)
		{
			if (str2[i] != str1[j]) A = 0;
		}
		if (A)
		{
			answer++;
			return answer;
		}
		return answer;


		return 0;

	}
}


TEST(TestCaseName, Test1) {
	bool A = 1;
	int test = 1;
	int res = 0;
	int mainlen =1 ;
	int prec = 1000;
	char str1[] = { "a" };
	char str2[] = { "a" };
	res = search(str1, str2, mainlen, prec);
	if (test != res) A = 0;

	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test2) {
	bool A = 1;
	int test = 0;
	int res = 0;
	int mainlen = 1;
	int prec = 1000;
	char str1[] = { "a" };
	char str2[] = { "b" };
	res = search(str1, str2, mainlen, prec);
	std::cout << "res = " << res;
	if (test != res) A = 0;

	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test3) {
	bool A = 1;
	int test = 1;
	int res = 0;
	int mainlen = 5;
	int prec = 1000;
	char str1[] = { "aaa" };
	char str2[] = { "aaa" };
	res = search(str1, str2, mainlen, prec);
	if (test != res) A = 0;

	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test4) {
	bool A = 1;
	int test = 2;
	int res = 0;
	int mainlen = 5;
	int prec = 1000;
	char str1[] = { "aab" };
	char str2[] = { "baa" };
	res = search(str1, str2, mainlen, prec);
	if (test != res) A = 0;

	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test5) {
	bool A = 1;
	int test = 1;
	int res = 0;
	int mainlen = 3;
	int prec = 1000;
	char str1[] = { "aaa" };
	char str2[] = { "aaa" };
	res = search(str1, str2, mainlen, prec);
	if (test != res) A = 0;

	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test6) {
	bool A = 1;
	int test = 1552;
	int res = 0;
	int mainlen = 999999998;
	int prec = 1000;
	char str1[] = { "a" };
	char str2[] = { "b" };
	res = search(str1, str2, mainlen, prec);
	if (test != res) A = 0;

	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test7) {
	bool A = 1;
	int test = 1;
	int res = 0;
	int mainlen = 5;
	int prec = 1000;
	char str1[] = { "codec" };
	char str2[] = { "codec" };
	res = search(str1, str2, mainlen, prec);
	if (test != res) A = 0;

	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test8) {
	bool A = 1;
	int test = 752;
	int res = 0;
	int mainlen = 14;
	int prec = 1000;
	char str1[] = { "cup" };
	char str2[] = { "russia" };
	res = search(str1, str2, mainlen, prec);
	if (test != res) A = 0;

	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test9) {
	bool A = 1;
	int test = 0;
	int res = 0;
	int mainlen = 7;
	int prec = 123;
	char str1[] = { "russian" };
	char str2[] = { "codecup" };
	res = search(str1, str2, mainlen, prec);
	if (test != res) A = 0;

	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test10) {
	bool A = 1;
	int test = 1;
	int res = 0;
	int mainlen = 7;
	int prec = 15;
	char str1[] = { "codec" };
	char str2[] = { "decup" };
	res = search(str1, str2, mainlen, prec);
	if (test != res) A = 0;

	EXPECT_TRUE(A);
}