#include "pch.h"

bool func(char* s, char* t)
{
	if (strlen(t) > 2 * strlen(s) - 1)
	{
		return 0;
	}
	else
	{
		bool A = true; //переменная выхода
		bool B = true; //если в цикл не пошло
		bool C = true; //если операций не было

		int lenS = strlen(s);
		int lenT = strlen(t);

		int m = 0;

		for (int i = 0; i < lenS; i++)
		{
			if (s[i] == t[0])
			{
				C = false;
				for (int h = 0; h < lenT; h++) //h сколько идем вправо
				{
					B = false;

					if (i + 2 * h - lenT + 1 >= 0 && i + h < lenS) //МОЖЕМ ЛИ ИДТИ
					{
						B = true;
						for (int d = i; d <= i + h; d++, m++) //идём вправо
						{
							if (s[d] != t[m]) A = false; //выход
						}

						if (!A) break;
						m--;

						for (int g = i + h; g > i + 2 * h - lenT; g--, m++) //идём влево
						{
							if (s[g] != t[m] && m < lenT) A = false; //выход
						}

						if (i + 2 * h - lenT + 1 < 0)A = false; // 2h - lenT + 1 - где закончили
						m = 0;

						if (A)break;

						A = true;
					}
				}
				if (!B) A = false;
				if (A) break;
			}
		}
		if (C) A = false;
		if (A == true) return 1;
		else return 0;
	}
}

TEST(TestCaseName, Test1) {
	bool A = 1;
	char s[501] = { "qwertyuiopasdfghjklzxcvbnm" };
	char t[1000] = { "cvbnmnbvc" };
	A = func(s, t);

  EXPECT_TRUE(A);
}

TEST(TestCaseName, Test2) {
	bool A = 1;
	char s[501] = { "aaaaaa" };
	char t[1000] = { "aaaaaaaaaaaa" };
	A = func(s, t);

	EXPECT_FALSE(A);
}

TEST(TestCaseName, Test3) {
	bool A = 1;
	char s[501] = { "abcdef" };
	char t[1000] = { "cdedcb" };
	A = func(s, t);

	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test4) {
	bool A = 1;
	char s[501] = { "aaa" };
	char t[1000] = { "aaaaa" };
	A = func(s, t);

	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test5) {
	bool A = 1;
	char s[501] = { "aab" };
	char t[1000] = { "baaa" };
	A = func(s, t);

	EXPECT_FALSE(A);
}

TEST(TestCaseName, Test6) {
	bool A = 1;
	char s[501] = { "ab" };
	char t[1000] = { "b" };
	A = func(s, t);

	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test7) {
	bool A = 1;
	char s[501] = { "abcdef" };
	char t[1000] = { "abcdef" };
	A = func(s, t);

	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test8) {
	bool A = 1;
	char s[501] = { "ba" };
	char t[1000] = { "baa" };
	A = func(s, t);

	EXPECT_FALSE(A);
}





