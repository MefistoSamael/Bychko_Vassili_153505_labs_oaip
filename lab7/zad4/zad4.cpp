//
// I89C0E45IG
// +
// IEGFH34
// =
// I8ABFC1431
//
//
#include <iostream>
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

void sum(char* numb1, char* numb2,char* answer, bool slf)
{

	if (slf == 0)
	{
		//учитываем переход за 19
		bool B = 0;
		int i = 11;
		for (; numb2[i] != '*';i--)//пока не встретим символ заполнитель в меньшем числе
		{
			char ans;
			if (numb(numb1[i]) + numb(numb2[i]) > 18) ans = numbtochar(numb(numb1[i]) + numb(numb2[i]) - 19);
			else ans =numbtochar (numb(numb1[i]) + numb(numb2[i]));
			
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
			else ans =n1 - n2;
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

int main()
{
	char numb1[13];
	for (int i = 0; i < 12; i++)
	{
		numb1[i] = '*';
	}
	char numb2[13];
	for (int i = 0; i < 12; i++)
	{
		numb2[i] = '*';
	}
	numb1[12] = 0;
	numb2[12] = 0;
	char answer[13];
	char answer2[13];
	


	//заполнение символами заполнителями
	for (int i = 0; i < 13; i++)answer[i] = '*';
	for (int i = 0; i < 13; i++)answer2[i] = '*';
	answer[12] = 0;
	answer2[12] = 0;	
	char symb;
	int numbsymb = 0;



	cout << "Enter numb1 ";
	cin >> symb;
	numbsymb = cin.rdbuf()->in_avail();
	numb1[12 - numbsymb] = symb;
	for (int i = 12 - numbsymb + 1; i < 12; i++)
	{
		cin >> numb1[i];
	}

	cout << "Enter numb2 ";
	cin >> symb;
	numbsymb = cin.rdbuf()->in_avail();
	numb2[12 - numbsymb] = symb;
	for (int i = 12 - numbsymb + 1; i < 12; i++)
	{
		cin >> numb2[i];
	}



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
			changesignsum= 1;//-III + I
			dif(numb1, numb2, answer);
		}
		if (Fir == 0 && Sec) 
		{
			changesignsum= 0;//III-I
			dif(numb1, numb2, answer);
		}
		if (Fir && Sec) 
		{
			changesignsum= 1;//-III - I
			sum(numb1, numb2, answer, slf);
		}
		if (Fir == 0 && Sec == 0)
		{
			changesignsum= 0;//III + I
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





	//блок вывода
	int i = 0;
	for (i = 0; answer[i] == '*'; i++);//поиск начала числа
	cout << "res of sum = ";
	if (changesignsum == 1) cout << "-";

	for (; i < strlen(answer); i++)
	{
		cout << answer[i];
	}
	cout << endl;

	i = 0;
	for (i = 0; answer2[i] == '*'; i++);//поиск начала числа
	cout << "res of dif = ";
	if (changesigndif == 1) cout << "-";

	for (; i < strlen(answer2); i++)
	{
		cout << answer2[i];
	}

	return 0;
}

//
// I89C0E45IG + IEGFH34 = I8ABFC1431
//
// III8I + I = III9H
//
// 5301 - 434 = 4HFG
//
