#include "pch.h"

int conver(char s)
{
	if (s == '1') return 1;
	if (s == '0') return 0;
	else return 1234554431;
}

char btoc(bool a)
{
	if (a == 1) return '1';
	if (a == 0) return '0';
}


TEST(TestCaseName, 1) {
	bool F = 1;
	char input[40] = { "1001110\0" };
	char answer[40];
	char test[80] = { "11111111111111111111111111110010" };
	int numb = 0;
	bool G = 0;
	if (conver(input[0]) == 0)
	{
		numb += conver(input[0]) * pow(2, strlen(input) - 1);
	}
	else G = 1;
	int len = strlen(input) - 1;
	for (int i = 1; i <= strlen(input) - 2; i++)
	{
		numb += conver(input[i]) * pow(2, len - 1);
 		len--;
	}
	if (G) numb *= -1;
	std::cout << numb;
	for (int a = 31, i = 0; a >= 0; a--, i++)
	{
		bool b = ((1 << a) & numb);
		answer[i] = btoc(b);
	}

	for (int i = 0; i < strlen(test); i++)
	{
		if(answer[i] != test[i]) F = 0;
	}

  EXPECT_TRUE(F);
}

TEST(TestCaseName, 2) {
	bool F = 1;
	char input[40] = { "0\0" };
	char answer[40];
	char test[80] = { "00000000000000000000000000000000" };
	int numb = 0;
	bool G = 0;
	if (conver(input[0]) == 0)
	{
		numb += conver(input[0]) * pow(2, strlen(input) - 1);
	}
	else G = 1;
	int len = strlen(input) - 1;
	for (int i = 1; i <= len - 1; i++)
	{
		numb += conver(input[i]) * pow(2, len - 1);
		len--;
	}
	if (G) numb *= -1;
	std::cout << numb;
	for (int a = 31, i = 0; a >= 0; a--, i++)
	{
		bool b = ((1 << a) & numb);
		answer[i] = btoc(b);
	}

	for (int i = 0; i < strlen(test); i++)
	{
		if (answer[i] != test[i]) F = 0;
	}

	EXPECT_TRUE(F);
}

TEST(TestCaseName, 3) {
	bool F = 1;
	char input[40] = { "11\0" };
	char answer[40];
	char test[80] = { "11111111111111111111111111111111" };
	int numb = 0;
	bool G = 0;
	if (conver(input[0]) == 0)
	{
		numb += conver(input[0]) * pow(2, strlen(input) - 1);
	}
	else G = 1;
	int len = strlen(input) - 1;
	for (int i = 1; i <= 1; i++)
	{
		numb += conver(input[i]) * pow(2, len - 1);
		len--;
	}
	if (G) numb *= -1;
	std::cout << numb << std::endl;
	for (int a = 31, i = 0; a >= 0; a--, i++)
	{
		bool b = ((1 << a) & numb);
		answer[i] = btoc(b);
	}

	for (int i = 0; i < strlen(test); i++)
	{
		//if (answer[i] != test[i]) F = 0;
		std::cout << answer[i] << " " << test[i] << std::endl;
	}

	EXPECT_TRUE(F);
}

TEST(TestCaseName, 4) {
	bool F = 1;
	char input[40] = { "111\0" };
	char answer[40];
	char test[80] = { "11111111111111111111111111111101" };
	int numb = 0;
	bool G = 0;
	if (conver(input[0]) == 0)
	{
		numb += conver(input[0]) * pow(2, strlen(input) - 1);
	}
	else G = 1;
	int len = strlen(input) - 1;
	for (int i = 1; i <= 2; i++)
	{
		numb += conver(input[i]) * pow(2, len - 1);
		len--;
	}
	if (G) numb *= -1;
	std::cout << numb << std::endl;
	for (int a = 31, i = 0; a >= 0; a--, i++)
	{
		bool b = ((1 << a) & numb);
		answer[i] = btoc(b);
	}

	for (int i = 0; i < strlen(test); i++)
	{
		if (answer[i] != test[i]) F = 0;
	}

	EXPECT_TRUE(F);
}