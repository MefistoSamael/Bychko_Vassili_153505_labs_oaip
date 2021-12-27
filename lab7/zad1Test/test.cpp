#include "pch.h"
using namespace std;
int mylen(char* array)//поиск длинны строки
{
	int len = 0;
	while (array[len]) len++;

	return len;
}

int numb(char symb)//замена символа на число
{
	if (symb >= 48 && symb <= 57) return symb - 48;
	if (symb >= 65 && symb <= 67) return symb - 55;
}

long long to10(char* numb13)
{
	long long numb10 = 0;
	for (int i = mylen(numb13) - 1, n = 0; i >= 0; i--, n++)
	{
		numb10 += numb(numb13[i]) * powl(13, n);
	}
	return numb10;
}

int to3(long long numb10, int* numb3)//перевод в троичную запись
{
	int n = 899;
	for (long long i = numb10; i > 0; )
	{
		numb3[n] = i % 3;
		i /= 3;
		n--;

	}
	return n;
}



TEST(TestCaseName, 1) {
	bool B = 1;
	char numb13[300] = {"51B9B636B77"};
	int numb3[900];
	//1012122202010122201000001100
	int answer[900] = { 2,1,1,1,2,1,1,0,2,2,1,2,0,2,2,0,0,2,2,0,2,2,1,0,2 };
	long long numb10 = 0;
	numb10 = to10(numb13);
	int start = to3(numb10, numb3);
	cout << endl;
	

	for (int i = start + 1, j = 0; i < 900; i++, j++)
	{
		if (numb3[i] != answer[j]) B = 0;
	}

	EXPECT_TRUE(B);
}

//282BA4AAA
//это предел инта
TEST(TestCaseName, 2) {
	bool B = 1;
	char numb13[300] = { "282BA4AAA" };
	int numb3[900];
	//12112122212110202101
	int answer[900] = { 1,2,1,1,2,1,2,2,2,1,2,1,1,0,2,0,2,1,0,1 };
	long long numb10 = 0;
	numb10 = to10(numb13);
	int start = to3(numb10, numb3);
	cout << endl;


	for (int i = start + 1, j = 0; i < 900; i++, j++)
	{
		if (numb3[i] != answer[j]) B = 0;
	}

	EXPECT_TRUE(B);
}

TEST(TestCaseName, 3) {
	bool B = 1;
	char numb13[300] = { "749003" };
	int numb3[900];
	//12010212001212
	int answer[900] = { 1,2,0,1,0,2,1,2,0,0,1,2,1,2 };
	long long numb10 = 0;
	numb10 = to10(numb13);
	int start = to3(numb10, numb3);
	cout << endl;


	for (int i = start + 1, j = 0; i < 900; i++, j++)
	{
		if (numb3[i] != answer[j]) B = 0;
	}

	EXPECT_TRUE(B);
}

TEST(TestCaseName, 4) {
	bool B = 1;
	char numb13[300] = { "08670" };
	int numb3[900];
	//12010212001212
	int answer[900] = { 2,2,1,1,2,1,2,2,0 };
	long long numb10 = 0;
	numb10 = to10(numb13);
	int start = to3(numb10, numb3);
	cout << endl;


	for (int i = start + 1, j = 0; i < 900; i++, j++)
	{
		if (numb3[i] != answer[j]) B = 0;
	}

	EXPECT_TRUE(B);
}

TEST(TestCaseName, 5) {
	bool B = 1;
	char numb13[300] = { "B0A736344" };
	int numb3[900];
	//12010212001212
	int answer[900] = {2,1,2,0,2,1,2,2,0,0,2,0,2,2,0,2,2,2,2,2,0};
	long long numb10 = 0;
	numb10 = to10(numb13);
	int start = to3(numb10, numb3);
	cout << endl;


	for (int i = start + 1, j = 0; i < 900; i++, j++)
	{
		if (numb3[i] != answer[j]) B = 0;
	}

	EXPECT_TRUE(B);
}



