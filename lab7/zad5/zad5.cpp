#include <iostream>
using namespace std;

int main()
{
	cout << "Entern integer number, numb < 4000 && numb > 0\n";
	int numb;
	cin >> numb;


	for (int i = numb; i >= 0; )
	{
		//считаем тысячи
		for (; i >= 1000; i -= 1000) cout << "M";

		if (i >= 900)
		{
			cout << "CM";
			i -= 900;
		}

		//считаем пятисотни
		for (; i >= 500; i -= 500) cout << "D";

		//выводим четыреста
		if (i >= 400)
		{
			cout << "CD";
			i -= 400;
		}


		//считаем сотни
		for (;i >= 100; i-=100) cout << "C";
		
		if (i >= 90)
		{
			cout << "XC";
			i -= 90;
		}

		//считаем пятидесятки
		for (; i >= 50; i -= 50) cout << "L";

		//выводим 40
		if (i >= 40)
		{
			cout << "XL";
			i -= 40;
		}

		//считаем десятки
		for (;i>= 10; i-=10) cout << "X";

		//выводим 9
		if (i == 9)
		{
			cout << "IX";
			i -= 9;
		}

		//выводим 5
		for (; i >= 5; i -= 5) cout << "V";

		//выводим 4
		if (i == 4)
		{
			cout << "IV";
			i -= 4;
		}
		for (; i > 0; i--) cout << "I";
	}

	return 0;
}

//3449 MMMCDXLIX
//3999 MMMCMXCIX
//1 I
//3683 MMMDCLXXXIII
//357 CCCLVII