#include "pch.h"

int func(int numb)
{
	int answer = 0;
	answer = numb / 10;
	if (numb % 10 == 9) answer++;
	return answer;
}


TEST(TestCaseName, Test1) {
	bool E = 1;
	int input = 1;
	int res = func(input);
	int test = 0;
	if (res != test)E = 0;
	EXPECT_TRUE(E);
}

TEST(TestCaseName, Test2) {
	bool E = 1;
	int input = 9;
	int res = func(input);
	int test = 1;
	if (res != test)E = 0;
	EXPECT_TRUE(E);
}

TEST(TestCaseName, Test3) {
	bool E = 1;
	int input = 10;
	int res = func(input);
	int test = 1;
	if (res != test)E = 0;
	EXPECT_TRUE(E);
}

TEST(TestCaseName, Test4) {
	bool E = 1;
	int input = 34;
	int res = func(input);
	int test = 3;
	if (res != test)E = 0;
	EXPECT_TRUE(E);
}

TEST(TestCaseName, Test5) {
	bool E = 1;
	int input = 880055535;
	int res = func(input);
	int test = 88005553;
	if (res != test)E = 0;
	EXPECT_TRUE(E);
}

TEST(TestCaseName, Test6) {
	bool E = 1;
	int input = 2147483647;
	int res = func(input);
	int test = 214748364;
	if (res != test)E = 0;
	EXPECT_TRUE(E);
}

