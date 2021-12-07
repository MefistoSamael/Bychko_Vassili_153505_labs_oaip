#include "pch.h"


bool vowel(char symb)
{
	if ((symb != 65 || symb != 69 || symb != 73 || symb != 79 || symb != 85 || symb != 89 || symb != 97 || symb != 101 || symb != 105 || symb != 111 || symb != 117 || symb != 121) && ((symb >= 66 && symb <= 90) || (symb >= 98 && symb <= 122)))
	{
		return 1;
	}
	else return 0;
}

bool isequal(char symb, char symb1)
{
	if (symb == symb1 || symb + 32 == symb1 || symb == symb1 + 32) return 1;
	else return 0;
}

bool change(char* str, char* newstr, char* test)
{
	bool BB = 1;
	int numeq = 0;
	char* temp = new char[strlen(newstr)];
	//копируем значения с заменой
	for (int i = 0, j = 0; i < 99; i++)
	{
		if (str[i] == 'c')
		{
			if (str[i + 1] == 'e' || str[i + 1] == 'E' || str[i + 1] == 'i' || str[i + 1] == 'I' || str[i + 1] == 'y' || str[i + 1] == 'Y')
			{
				newstr[j] = 's';
				j++;
				continue;
			}
			newstr[j] = 'k';
			j++;
			continue;
		}
		if (str[i] == 'C')
		{
			if (str[i + 1] == 'e' || str[i + 1] == 'E' || str[i + 1] == 'i' || str[i + 1] == 'I' || str[i + 1] == 'y' || str[i + 1] == 'Y')
			{
				newstr[j] = 'S';
				j++;
				continue;
			}
			newstr[j] = 'K';
			j++;
			continue;
		}

		if (str[i] == 'q')
		{
			if (str[i + 1] == 'u')
			{
				newstr[j] = 'k';
				newstr[j + 1] = 'v';
				j += 2;
				i++;
				continue;
			}
			newstr[j] = 'k';
			j++;
			continue;
		}
		if (str[i] == 'Q')
		{
			if (str[i + 1] == 'u')
			{
				newstr[j] = 'K';
				newstr[j + 1] = 'v';
				j += 2;
				i++;
				continue;
			}
			newstr[j] = 'K';
			j++;
			continue;
		}

		if (str[i] == 'x')
		{
			newstr[j] = 'k';
			newstr[j + 1] = 's';
			j += 2;
			continue;
		}
		if (str[i] == 'X')
		{
			newstr[j] = 'K';
			newstr[j + 1] = 's';
			j += 2;
			continue;
		}

		if (str[i] == 'w')
		{
			newstr[j] = 'v';
			j++;
			continue;
		}
		if (str[i] == 'W')
		{
			newstr[j] = 'V';
			j++;
			continue;
		}

		if (str[i] == 'p' && str[i + 1] == 'h')
		{
			newstr[j] = 'f';
			j++;
			i++;
			continue;
		}
		if (str[i] == 'P' && str[i + 1] == 'h')
		{
			newstr[j] = 'F';
			j++;
			i++;
			continue;
		}

		if (str[i] == 'y' && str[i + 1] == 'o' && str[i + 2] == 'u')
		{
			newstr[j] = 'u';
			j++;
			i += 2;
			continue;
		}
		if (str[i] == 'Y' && str[i + 1] == 'o' && str[i + 2] == 'u')
		{
			newstr[j] = 'U';
			j++;
			i += 2;
			continue;
		}

		if (str[i] == 'o' && str[i + 1] == 'o')
		{
			newstr[j] = 'u';
			j++;
			i++;
			continue;
		}
		if (str[i] == 'O' && str[i + 1] == 'o')
		{
			newstr[j] = 'U';
			j++;
			i++;
			continue;
		}

		if (str[i] == 'e' && str[i + 1] == 'e')
		{
			newstr[j] = 'i';
			j++;
			i++;
			continue;
		}
		if (str[i] == 'E' && str[i + 1] == 'e')
		{
			newstr[j] = 'I';
			j++;
			i++;
			continue;
		}

		if (str[i] == 't' && str[i + 1] == 'h')
		{
			newstr[j] = 'z';
			j++;
			i++;
			continue;
		}
		if (str[i] == 'T' && str[i + 1] == 'h')
		{
			newstr[j] = 'Z';
			j++;
			i++;
			continue;
		}
		newstr[j] = str[i];
		j++;



	}
	for (int i = 0; i < strlen(newstr); i++)
	{
		temp[i] = newstr[i];
		newstr[i] = ' ';
	}
	for (int i = 0, j = 0; i < strlen(newstr); i++)
	{
		if (isequal(temp[i], temp[i + 1]) && vowel(temp[i]))
		{
			numeq++;
			continue;
		}
		newstr[j] = temp[i];
		j++;
	}
	newstr[strlen(newstr) - numeq] = '\0';

	for (int i = 0; i < strlen(newstr); i++)
	{
		if (newstr[i] != test[i]) BB = 0;
	}
	return BB;
}


TEST(TestCaseName, Test1) {
	bool A = 1;
	char str[] = { "Too swift for Theex, too quick for Gallow" };
	char newstr[300];
	char test[] = { "Tu svift for Ziks, tu kvik for Galov" };

	A = change(str, newstr, test);
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test2) {
	bool A = 1;
	char str[] = { "Too strong for young Prince Joseph to follow" };
	char newstr[300];
	char test[] = { "Tu strong for ung Prinse Josef to folov" };

	A = change(str, newstr, test);
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test3) {
	bool A = 1;
	char str[] = { "kxssaaa pph" };
	char newstr[300];
	char test[] = { "ksaaa pf" };

	A = change(str, newstr, test);
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test4) {
	bool A = 1;
	char str[] = { "kkkkkkkkkk" };
	char newstr[300];
	char test[] = { "k" };

	A = change(str, newstr, test);
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test5) {
	bool A = 1;
	char str[] = { "aaaa" };
	char newstr[300];
	char test[] = { "aaaa" };

	A = change(str, newstr, test);
	EXPECT_TRUE(A);
}

TEST(TestCaseName, Test6) {
	bool A = 1;
	char str[] = { "aaaakkk***" };
	char newstr[300];
	char test[] = { "aaaak***" };

	A = change(str, newstr, test);
	EXPECT_TRUE(A);
}


