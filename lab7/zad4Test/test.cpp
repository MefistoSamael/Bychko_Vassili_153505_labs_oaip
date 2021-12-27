#include "pch.h"
using namespace std;

int numb(char symb)//замена символа на число
{
	if (symb >= 48 && symb <= 57) return symb - 48;
	if (symb >= 65 && symb <= 74) return symb - 55;
}

char numbtochar(int numb)
{
	char digit = 0;

	if (numb < 10) digit = '0' + numb;
	else digit = 'A' + numb - 10;

	return digit;
}

void sum(char* numb1, char* numb2, char* answer, bool slf)
{

	if (slf == 0)
	{
		//учитываем переход за 19
		bool B = 0;
		int i = 11;
		for (; numb2[i] != '*'; i--)//пока не встретим символ заполнитель в меньшем числе
		{
			char ans;
			if (numb(numb1[i]) + numb(numb2[i]) > 18) ans = numbtochar(numb(numb1[i]) + numb(numb2[i]) - 19);
			else ans = numbtochar(numb(numb1[i]) + numb(numb2[i]));

			answer[i] = ans;//присвоение результата
			if (B)//учитываем переход
			{
				answer[i]++;

				B = 0;
			}
			if (numb(numb1[i]) + numb(numb2[i]) > 18) B = 1;//учитываем переход
		}
		for (; numb1[i] != '*'; i--)//пока не встретим символ заполнитель в большем числе
		{
			bool C = 0;
			answer[i] = numb1[i];//перенос
			if (B)//учитываем переход
			{

				if (answer[i] == '9') answer[i] = 'A';
				else if (answer[i] == 'I')
				{
					answer[i] = '0';
					answer[i - 1] = '1';
					if (numb1[i - 1] == 'I') C = 1;
				}
				else answer[i]++;
				B = 0;
			}
			if (numb(numb1[i]) > 18 || C == 1) B = 1;
		}
		if (B)
		{
			answer[i] = '1';
		}
	}
	else
	{
		//учитываем переход за 19
		bool B = 0;
		int i = 11;
		for (; numb1[i] != '*'; i--)//пока не встретим символ заполнитель в меньшем числе
		{
			char ans;
			if (numb(numb2[i]) + numb(numb1[i]) > 18) ans = numbtochar(numb(numb2[i]) + numb(numb1[i]) - 19);
			else ans = numbtochar(numb(numb2[i]) + numb(numb1[i]));

			answer[i] = ans;//присвоение результата
			if (B)//учитываем переход
			{
				answer[i]++;

				B = 0;
			}
			if (numb(numb2[i]) + numb(numb1[i]) > 18) B = 1;//учитываем переход
		}
		for (; numb2[i] != '*'; i--)//пока не встретим символ заполнитель в большем числе
		{
			bool C = 0;
			answer[i] = numb2[i];//перенос
			if (B)//учитываем переход
			{

				if (answer[i] == '9' || numb2[i] == '9') answer[i] = 'A';
				else if (answer[i] == 'I' || numb2[i] == 'I')
				{
					answer[i] = '0';
					answer[i - 1] = '1';
					if (numb2[i - 1] == 'I') C = 1;
				}
				else answer[i]++;
				B = 0;
			}
			if (numb(numb2[i]) > 18 || C == 1) B = 1;
		}
		if (B)
		{
			answer[i] = '1';
		}
	}

}

int mylen(char* str)
{
	int res = 0;
	for (int i = strlen(str) - 1; str[i] != '*' && str[i] != '-'; i--, res++);
	return res;
}

void dif(char* numb1, char* numb2, char* answer2)
{
	bool B = 0;
	int i = 11;
	for (; numb2[i] != '*'; i--)
	{
		int n1 = numb(numb1[i]);
		int n2 = numb(numb2[i]);
		if (B)
		{
			n1--;
		}
		char ans;
		if (n1 - n2 < 0)
		{
			ans = n1 - n2 + 19;
			B = 1;
		}
		else ans = n1 - n2;
		answer2[i] = numbtochar(ans);
	}
	for (; numb1[i] != '*'; i--)
	{
		bool Z = 0;
		if (B)
		{
			if (numb1[i] == '0')
			{
				answer2[i] = 'I';
				B = 1;
			}
			else if (numb1[i] == 'A')
			{
				answer2[i] = '9';
				B = 0;
			}
			else
			{
				Z = 1;
				B = 0;
			}
		}
		answer2[i] = numb1[i];
		if (Z)answer2[i]--;
	}
}

bool Islow0(char* str)
{
	int numbofminus = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '-')
		{
			numbofminus++;
			str[i] = '*';
		}
	}
	if (numbofminus % 2 == 0) return 0;
	else return 1;
}

void func(char *numb1, char *numb2, char *answer, char* answer2)
{
	//блок с получением базовой инфы о числах
	bool sign = 0;
	bool slf = 0;

	//Second Longer than First?
	if (mylen(numb1) > mylen(numb2)) slf = 0;	else slf = 1;

	//Проверка чисел на отрицательность
	bool Fir = Islow0(numb1);
	bool Sec = Islow0(numb2);


	//для учитывания знака
	bool changesignsum = 0;
	bool changesigndif = 0;

	//для cуммы
	if (slf == 0)
	{
		if (Fir && Sec == 0)
		{
			changesignsum = 1;//-III + I
			dif(numb1, numb2, answer);
		}
		if (Fir == 0 && Sec)
		{
			changesignsum = 0;//III-I
			dif(numb1, numb2, answer);
		}
		if (Fir && Sec)
		{
			changesignsum = 1;//-III - I
			sum(numb1, numb2, answer, slf);
		}
		if (Fir == 0 && Sec == 0)
		{
			changesignsum = 0;//III + I
			sum(numb1, numb2, answer, slf);
		}

	}
	else
	{
		if (Sec && Fir == 0)
		{
			changesignsum = 1;//-I + III
			dif(numb2, numb1, answer);
		}
		if (Sec == 0 && Fir)
		{
			changesignsum = 01;//I-III
			dif(numb2, numb1, answer);
		}
		if (Sec && Fir)
		{
			changesignsum = 1;//-I - III
			sum(numb1, numb2, answer, slf);
		}
		if (Sec == 0 && Fir == 0)
		{
			changesignsum = 0;//I + III
			sum(numb1, numb2, answer, slf);
		}
	}

	//для разности
	if (slf == 0)
	{
		if (Fir && Sec == 0)
		{
			changesigndif = 1;//-III - I
			sum(numb1, numb2, answer2, slf);

		}
		if (Fir == 0 && Sec)
		{
			changesigndif = 0;//III + I
			sum(numb1, numb2, answer2, slf);
		}
		if (Fir && Sec)
		{
			changesigndif = 1;//-III + I
			dif(numb1, numb2, answer2);
		}
		if (Fir == 0 && Sec == 0)
		{
			changesigndif = 0;//III - I
			dif(numb1, numb2, answer2);
		}

	}
	else
	{
		if (Sec && Fir == 0)
		{
			changesigndif = 0;//I + III
			sum(numb1, numb2, answer2, slf);
		}
		if (Sec == 0 && Fir)
		{
			changesigndif = 1;//-I-III
			sum(numb1, numb2, answer2, slf);
		}
		if (Sec && Fir)
		{
			changesigndif = 0;//-I + III
			dif(numb2, numb1, answer2);
		}
		if (Sec == 0 && Fir == 0)
		{
			changesigndif = 1;//I - III
			dif(numb2, numb1, answer2);
		}
	}
}

TEST(TestCaseName, 1) {
	bool N = 1;

	char in1[13] = { "**I89C0E45IG" };
	char in2[13] = { "*****IEGFH34" };
	in1[12] = 0;
	in2[12] = 0;
	char ans1[13];
	char ans2[13];
	ans1[12] = 0;
	ans2[12] = 0;
	char test1[13] = { "**I8ABFC1431" };
	char test2[13] = { "**I88C4G77FC" };
	test1[12] = 0;
	test2[12] = 0;

	func(in1, in2, ans1, ans2);
	for (int i = 2; i < 13; i++)
	{
		if (ans1[i] != test1[i]) N = 0;
		if (ans2[i] != test2[i]) N = 0;
	}


  EXPECT_TRUE(N);
}

TEST(TestCaseName, 2) {
	bool N = 1;

	char in1[13] = { "*-I89C0E45IG" };
	char in2[13] = { "*****IEGFH34" };
	in1[12] = 0;
	in2[12] = 0;
	char ans1[13];
	char ans2[13];
	ans1[12] = 0;
	ans2[12] = 0;
	char test1[13] = { "**I88C4G77FC" };
	char test2[13] = { "**I8ABFC1431" };
	test1[12] = 0;
	test2[12] = 0;

	func(in1, in2, ans1, ans2);
	for (int i = 2; i < 13; i++)
	{
		if (ans1[i] != test1[i]) N = 0;
		if (ans2[i] != test2[i]) N = 0;
	}


	EXPECT_TRUE(N);
}

TEST(TestCaseName, 3) {
	bool N = 1;

	char in1[13] = { "**I89C0E45IG" };
	char in2[13] = { "****-IEGFH34" };
	in1[12] = 0;
	in2[12] = 0;
	char ans1[13];
	char ans2[13];
	ans1[12] = 0;
	ans2[12] = 0;
	char test1[13] = { "**I88C4G77FC" };
	char test2[13] = { "**I8ABFC1431" };
	test1[12] = 0;
	test2[12] = 0;

	func(in1, in2, ans1, ans2);
	for (int i = 2; i < 13; i++)
	{
		if (ans1[i] != test1[i]) N = 0;
		if (ans2[i] != test2[i]) N = 0;
	}


	EXPECT_TRUE(N);
}

TEST(TestCaseName, 4) {
	bool N = 1;

	char in1[13] = { "*-I89C0E45IG" };
	char in2[13] = { "****-IEGFH34" };
	in1[12] = 0;
	in2[12] = 0;
	char ans1[13];
	char ans2[13];
	ans1[12] = 0;
	ans2[12] = 0;
	char test1[13] = { "**I8ABFC1431" };
	char test2[13] = { "**I88C4G77FC" };
	test1[12] = 0;
	test2[12] = 0;

	func(in1, in2, ans1, ans2);
	for (int i = 2; i < 13; i++)
	{
		if (ans1[i] != test1[i]) N = 0;
		if (ans2[i] != test2[i]) N = 0;
	}


	EXPECT_TRUE(N);
}

TEST(TestCaseName, 5) {
	bool N = 1;

	char in1[13] = { "*******III8I" };
	char in2[13] = { "***********I" };
	in1[12] = 0;
	in2[12] = 0;
	char ans1[13];
	char ans2[13];
	ans1[12] = 0;
	ans2[12] = 0;
	char test1[13] = { "*******III9H" };
	char test2[13] = { "*******III80" };
	test1[12] = 0;
	test2[12] = 0;

	func(in1, in2, ans1, ans2);
	for (int i = 7; i < 13; i++)
	{
		if (ans1[i] != test1[i]) N = 0;
		if (ans2[i] != test2[i]) N = 0;
	}


	EXPECT_TRUE(N);
}

TEST(TestCaseName, 6) {
	bool N = 1;

	char in1[13] = { "********5301" };
	char in2[13] = { "*********434" };
	in1[12] = 0;
	in2[12] = 0;
	char ans1[13];
	char ans2[13];
	ans1[12] = 0;
	ans2[12] = 0;
	char test1[13] = { "********5735" };
	char test2[13] = { "********4HFG" };
	test1[12] = 0;
	test2[12] = 0;

	func(in1, in2, ans1, ans2);
	for (int i = 8; i < 13; i++)
	{
		if (ans1[i] != test1[i]) N = 0;
		if (ans2[i] != test2[i]) N = 0;
	}


	EXPECT_TRUE(N);
}