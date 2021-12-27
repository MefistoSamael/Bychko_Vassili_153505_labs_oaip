#include "pch.h"


void func(int numb, char* res)
{
	int n = 0;

	for (int i = numb; i > 0; )
	{
		//������� ������
		for (; i >= 1000; i -= 1000)
		{
			res[n] =  'M'; n++;
			
		}

		if (i >= 900)
		{
			res[n] = 'C'; n++;
			res[n] = 'M'; n++;
			i -= 900;
		}

		//������� ���������
		for (; i >= 500; i -= 500)
		{
			res[n] =  'D'; n++;
		}

		//������� ���������
		if (i >= 400)
		{
			res[n] = 'C'; n++;
			res[n] = 'D'; n++;
			i -= 400;
		}


		//������� �����
		for (; i >= 100; i -= 100)
		{
			res[n] =  'C'; n++;
		}

		if (i >= 90)
		{
			res[n] = 'X'; n++;
			res[n] = 'C'; n++;
			i -= 90;
		}

		//������� �����������
		for (; i >= 50; i -= 50)
		{
			res[n] =  'L'; n++;
		}

		//������� 40
		if (i >= 40)
		{
			res[n] = 'X'; n++;
			res[n] = 'L'; n++;
			i -= 40;
		}

		//������� �������
		for (; i >= 10; i -= 10)
		{
			res[n] =  'X'; n++;
		}

		//������� 9
		if (i == 9)
		{
			res[n] = 'I'; n++;
			res[n] = 'X'; n++;
			i -= 9;
		}

		//������� 5
		for (; i >= 5; i -= 5)
		{
			res[n] =  'V'; n++;
		}

		//������� 4
		if (i == 4)
		{
			res[n] = 'I'; n++;
			res[n] = 'V'; n++;
			i -= 4;
		}
		for (; i > 0; i--)
		{
			res[n] =  'I'; n++;
		}
		res[n] = '\0';
	}
}


TEST(TestCaseName, Test1) {
	bool E = true;
	int input = 3449;
	char res[16];
	func(input, res);
	char test[16] = { "MMMCDXLIX" };
	for (int i = 0; i < strlen(res); i++)
	{
		if (res[i] != test[i]) E = 0;
	}

	EXPECT_TRUE(E);
}

TEST(TestCaseName, Test2) {
	bool E = true;
	int input = 3999;
	char res[16];
	func(input, res);
	char test[16] = { "MMMCMXCIX" };
	for (int i = 0; i < strlen(res); i++)
	{
		if (res[i] != test[i]) E = 0;
	}

	EXPECT_TRUE(E);
	}

TEST(TestCaseName, Test3) {
	bool E = true;
	int input = 1;
	char res[16];
	func(input, res);
	char test[16] = { "I" };
	for (int i = 0; i < strlen(res); i++)
	{
		if (res[i] != test[i]) E = 0;
	}

	EXPECT_TRUE(E);
}

TEST(TestCaseName, Test4) {
	bool E = true;
	int input = 3683;
	char res[16];
	func(input, res);
	char test[16] = { "MMMDCLXXXIII" };
	for (int i = 0; i < strlen(res); i++)
	{
		if (res[i] != test[i]) E = 0;
	}

	EXPECT_TRUE(E);
}

TEST(TestCaseName, Test5) {
	bool E = true;
	int input = 357;
	char res[16];
	func(input, res);
	char test[16] = { "CCCLVII" };
	for (int i = 0; i < strlen(res); i++)
	{
		if (res[i] != test[i]) E = 0;
	}

	EXPECT_TRUE(E);
}
