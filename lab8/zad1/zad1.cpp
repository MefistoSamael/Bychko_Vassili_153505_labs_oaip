#include <iostream>
#include <Windows.h>
#include <string.h>
using namespace std;
struct ats_type {

	char date[30];//дата

	char NameSity[30];//название города

	int code;//код города

	double time;//время разговора в минутах

	double rate;//тариф

	int number;//номер телефона

};
int SIZEOFARR = 3;
ats_type* atsinfo = new ats_type[SIZEOFARR];

void checkinp(int& var)
{
	char answer[256]; // строка для чтения
	answer[255] = 0;
	scanf_s("%s", answer, 253);

	while (sscanf_s(answer, "%d", &var) < 1)
	{
		printf("%s", "Надо вводиь числа, а не буквы\n\n");
		scanf_s("%s", answer, 256);
	}
}

void checkinp(double& var)
{
	char answer[256]; // строка для чтения
	answer[255] = 0;
	scanf_s("%s", answer, 253);

	while (sscanf_s(answer, "%lf", &var) < 1)
	{
		printf("%s", "Надо вводиь числа, а не буквы\n\n");
		scanf_s("%s", answer, 256);
	}
}



void input(int i)//ввод
{
	printf("%s", "Введите дату разговора в формате дд.мм.гггг\n\n");
	scanf_s("%s", atsinfo[i].date, 29);
	printf("%s", "Введите название города\n\n");
	scanf_s("%s", atsinfo[i].NameSity, 29);
	printf("%s", "Введите код города \n\n");
	checkinp(atsinfo[i].code);
	printf("%s", "Введите время разговора в минутах\n\n");
	checkinp(atsinfo[i].time);
	printf("%s", "Введите тариф в рублях в минуту в качетве целого числа\n\n");
	checkinp(atsinfo[i].rate);
	printf("%s", "Введите номер телефона без плюса\n\n");
	checkinp(atsinfo[i].number);


}


void init()
{
	for (int i = 0; i < SIZEOFARR; i++)
	{
		*atsinfo[i].date = '\0';
		*atsinfo[i].NameSity = '\0';
	}
}

void enter()//ввод заранее заданного количества структур
{
	int ijk = 0;
	for (; ijk < SIZEOFARR; ijk++) if (atsinfo[ijk].date[0] == '\0') break;

	if (ijk == SIZEOFARR)
	{
		printf("%s", "У тебя полностью заполнен массив, глупышка\n\n");
		return;
	}

	printf("%s", "Введите количество структур которые хотите ввести\n\n");
	int numb;
	checkinp(numb);
	if (ijk + numb > SIZEOFARR)
	{
		printf("%s", "алярм! ты хочешь ввести структур больше чем есть, сначала расширь массив\n\n");
		return;
	}
	for (int i = ijk; i < ijk + numb; i++)
	{
		printf("%s", "Давай, ввод должен продолжатья, я верю в тебя, ты сможешь!\n\n");
		input(i);
	}

}

void enterprop()//ввод до появления структуры с заданным признаком
{

	for (int i = 0; i < SIZEOFARR; i++)
	{
		if (atsinfo[i].date[0] == '\0') break;
		if (i == SIZEOFARR-1)
		{
			printf("%s", "У тебя полностью заполнен массив, глупышка\n");
			return;
		}

	}


	printf("%s", "Введите поле структуры, в котором будет признак прзнак структуры при котором завершить ввод\n\n");
	printf("%s", "d - дата\nN - название города\nc - код города\nt - время разговора в часах\nr - тариф\nn - номер телефона\n\n");
	char ch;
	//ввод поля
	while (true)//проверка ввода
	{
		scanf_s("%c", &ch);
		if (ch == 'd' || ch == 'N' || ch == 'c' || ch == 't' || ch == 'r' || ch == 'n') break;
		else if (ch == '\n');
		else printf("%s", "Введено не то значение, ожидалось: -d- -N- -c- -t- -r- -n- попробуйте заново\n\n");
	}



	printf("%s", "Введите признак структуры при котором будет завершен ввод\n");

	char str[30];
	int izk;
	double jzk;

	//ввод признака
	if (ch == 'd' || ch == 'N') scanf_s("%s", str, 30);
	else if (ch == 't' || ch == 'r') scanf_s("%lf", &jzk);
	else checkinp(izk);


	int i = 0;
	for (; i < SIZEOFARR; i++) if (atsinfo[i].date[0] == '\0') break;

	for (;; i++)
	{
		input(i);
		if (ch == 'd')
		{
			if (!strcmp(atsinfo[i].date, str)) break;
		}
		if (ch == 'N')
		{
			if (!strcmp(atsinfo[i].NameSity, str)) break;
		}
		if (ch == 'r')
		{
			if (atsinfo[i].rate == jzk) break;
		}
		if (ch == 't')
		{
			if (atsinfo[i].time == jzk) break;
		}
		if (ch == 'c')
		{
			if (atsinfo[i].code == izk) break;
		}
		if (ch == 'n')
		{
			if (atsinfo[i].number == izk) break;
		}
		if (i == SIZEOFARR - 1)
		{
			printf("%s", "Ввод закончен по причине конца массива\n\n");
			break;
		}
	}
	return;

}

void display()//просмотр содержимого динамического массива структур
{
	int jzk = 0;
	for (; jzk < SIZEOFARR; jzk++)
	{
		if (atsinfo[jzk].date[0] == '\0') break;
	}
	for (int i = 0; i < 50; i++) printf("%c", '-');
	printf("%c", '\n');
	for (int i = 0; i < jzk; i++)
	{
		for (int i = 0; i < 50; i++) printf("%c", '-');
		printf("%c", '\n');
		printf("%s%s%s", "Дата : ", atsinfo[i].date, "\n");
		printf("%s%s%s", "Название города : ", atsinfo[i].NameSity, "\n");
		printf("%s%i%s", "Код города : ", atsinfo[i].code, "\n");
		printf("%s%lf%s", "Время разговора в минутах : ", atsinfo[i].time, "\n");
		printf("%s%lf%s", "Тариф : ", atsinfo[i].rate, "\n");
		printf("%s%i%s", "Номер телефона : ", atsinfo[i].number, "\n");
		for (int i = 0; i < 50; i++) printf("%c", '-');
		printf("%c", '\n');
	}
	for (int i = 0; i < 50; i++) printf("%c", '-');
	printf("%c", '\n');
}

void displayi(int i)//просмотр содержимого одной структуры динамического массива структур
{
	for (int i = 0; i < 50; i++) printf("%c", '-');
	printf("%c", '\n');
	printf("%s%s%s", "Дата : ", atsinfo[i].date, "\n");
	printf("%s%s%s", "Название города : ", atsinfo[i].NameSity, "\n");
	printf("%s%i%s", "Код города : ", atsinfo[i].code, "\n");
	printf("%s%lf%s", "Время разговора в минутах : ", atsinfo[i].time, "\n");
	printf("%s%lf%s", "Тариф : ", atsinfo[i].rate, "\n");
	printf("%s%i%s", "Номер телефона : ", atsinfo[i].number, "\n");
	printf("%c", '\n');
	for (int i = 0; i < 50; i++) printf("%c", '-');
	printf("%c", '\n');
}


void addnewsrtuct()//дополнения уже существующего массива структур новыми структурами
{
	printf("%s", "Введите количество структур которые хотите добавить\n");
	int numb;
	checkinp(numb);


	int tempSIZEOFARR = SIZEOFARR + numb;
	ats_type* atsinfonew = new ats_type[tempSIZEOFARR];

	for (int i = 0; i < SIZEOFARR; i++)
	{
		atsinfonew[i] = atsinfo[i];
	}

	for (int i = SIZEOFARR; i < tempSIZEOFARR; i++)
	{
		*atsinfonew[i].date = '\0';
		*atsinfonew[i].NameSity = '\0';
	}
	SIZEOFARR = tempSIZEOFARR;

	delete[] atsinfo;
	atsinfo = atsinfonew;

}

void displayprop()//поиск и вывод на экран структуры(структур) с заданным значением элемента
{
	printf("%s", " Введите поле структуры в котором будет заданный признак\n");
	printf("%s", "d - дата\nN - название города\nc - код города\nt - время разговора в часах\nr - тариф\nn - номер телефона\n");


	char ch;
	//ввод поля
	while (true)//проверка ввода
	{
		scanf_s("%c", &ch);
		if (ch == 'd' || ch == 'N' || ch == 'c' || ch == 't' || ch == 'r' || ch == 'n') break;
		else if (ch == '\n');
		else printf("%s", "Введено не то значение, ожидалось: -d- -N- -c- -t- -r- -n- попробуйте заново\n\n");
	}

	printf("%s", "Введите признак структуры, которую надо отобразить\n");

	char str[30];
	int izk;
	double jzk;

	//ввод признака
	if (ch == 'd' || ch == 'N' ) scanf_s("%s", str, 30);
	else if (ch == 't' || ch == 'r') scanf_s("%lf", &jzk);
	else scanf_s("%i", &izk);

	
	for (int i = 0; i < 50; i++) printf("%c", '-');
	printf("%c", '\n');
	int i = 0;
	//был ли вывод?
	bool B = 0;
	for (; i < SIZEOFARR; i++)
	{
		if (ch == 'd')
		{
			if (!strcmp(atsinfo[i].date, str))
			{
				displayi(i);
				B = 1;
			}
		}
		if (ch == 'N')
		{
			if (!strcmp(atsinfo[i].NameSity, str))
			{
				displayi(i);
				B = 1;
			}
		}
		if (ch == 'r')
		{
			if (atsinfo[i].rate == jzk)
			{
				displayi(i);
				B = 1;
			}
		}
		if (ch == 't')
		{
			if (atsinfo[i].time == jzk)
			{
				displayi(i);
				B = 1;
			}
		}
		if (ch == 'c')
		{
			if (atsinfo[i].code == izk)
			{
				displayi(i);
				B = 1;
			}
		}
		if (ch == 'n')
		{
			if (atsinfo[i].number == izk)
			{
				displayi(i);
				B = 1;
			}
		}
	}
	if (i == SIZEOFARR && B == 0) {
		printf("%s", "Структура не была найдена\n");
		return;
	}
	for (int i = 0; i < 50; i++) printf("%c", '-');
	printf("%c", '\n');

	
}

void del()//удаление элемента массива структур с заданным значением элемента
{
	printf("%s", "Введите номер структуры которую хотите удалить\n\n");
	int numb;
	while (true)
	{
	checkinp(numb);
	if (numb <= SIZEOFARR - 1) break;
	else printf("%s", "Вы хотите удалить несуществующий элемент массива\n\n");
	}

	int tempSIZEOFARR = SIZEOFARR-1;
	ats_type* atsinfonew = new ats_type[tempSIZEOFARR];

	for (int i = 0; i < numb; i++)
	{
		atsinfonew[i] = atsinfo[i];
	}

	for (int i = numb, j = numb + 1; i < tempSIZEOFARR; i++, j++)
	{
		atsinfonew[i] = atsinfo[j];
	}

	SIZEOFARR = tempSIZEOFARR;

	delete[] atsinfo;
	atsinfo = atsinfonew;
}

void change()//изменение элемента массива структур с заданным значением элемента
{
	printf("%s", "Введите поле структуры, в котором будет признак прзнак структуры, которую необходимо заменить\n\n");
	printf("%s", "d - дата\nN - название города\nc - код города\nt - время разговора в часах\nr - тариф\nn - номер телефона\n");
	char ch;
	//ввод поля
	while (true)//проверка ввода
	{
		scanf_s("%c", &ch);
		if (ch == 'd' || ch == 'N' || ch == 'c' || ch == 't' || ch == 'r' || ch == 'n') break;
		else if (ch == '\n');
		else printf("%s", "Введено не то значение, ожидалось: -d- -N- -c- -t- -r- -n- попробуйте заново\n\n");
	}



	printf("%s", "Введите признак структуры,которая будет заменена\n\n");

	char str[30];
	int izk;
	double jzk;

	//ввод признака
	if (ch == 'd' || ch == 'N' ) scanf_s("%s", str, 30);
	else if (ch == 't' || ch == 'r') scanf_s("%lf", &jzk);
	else scanf_s("%i", &izk);

	int i = 0;
	for (; i < SIZEOFARR; i++)
	{
		if (ch == 'd')
		{
			if (!strcmp(atsinfo[i].date, str))
			{
				input(i);
				break;
			}
		}
		if (ch == 'N')
		{
			if (!strcmp(atsinfo[i].NameSity, str))
			{
				input(i);
				break;
			}
		}
		if (ch == 'r')
		{
			if (atsinfo[i].rate== jzk)
			{
				input(i);
				break;
			}
		}
		if (ch == 't')
		{
			if (atsinfo[i].time == jzk)
			{
				input(i);
				break;
			}
		}
		if (ch ==
			'c')
		{
			if (atsinfo[i].code == izk)
			{
				input(i);
				break;
			}
		}
		if (ch == 'n')
		{
			if (atsinfo[i].number == izk)
			{
				input(i);
				break;
			}
		}

	}
	if (i == SIZEOFARR) printf("%s", "Структура с заданным признаком не была встречена\n\n");
}

void sort()//Функция упорядочения массива структур
{
	for (int i = 1; i < SIZEOFARR;i++)
	{
		for (int j = 0; j < SIZEOFARR - i; j++)
		{
			if (atsinfo[j].code < atsinfo[j+1].code)
			{
				swap(atsinfo[j], atsinfo[j+1]);
			}
		}
	}
}

void task()
{
	double time = 0;
	double sum = 0;
	printf("%s", "Введите город\n");
	char str[30];
	scanf_s("%s", str, 30);

	int i = 0;
	for (; i < SIZEOFARR; i++)
	{
		if (!strcmp(atsinfo[i].NameSity, str))
		{
			time += atsinfo[i].time;
			sum += atsinfo[i].time* atsinfo[i].rate;
		}
	}

	printf("%s", "Время разговора с данным городом : ");
	printf("%lf", time);
	printf("%s", " Cумма разговора с данным городом : ");
	printf("%lf", sum);
}

int menu()
{
	char ch;

	printf("%s", " E - ввод заранее заданного количества структур\n P - ввод до встречи структуры с заданным свойством\n D - отобразить содержимого динамического массива структур\n d - отбразить на экран структуру (структуры) с заданным значением элемента\n c - изменение структуры с заданным признаком\n X - расширить массив структур\n l - удалить эллемент массива структур\n s - сортировка эллементов массива От большего к меньшему\n T - вывести для заданного города общее время разговоров с ним и сумму\n Q - кончить выполнение программы\n\n");

	while (true)
	{
		scanf_s("%c", &ch);
		if (ch == 'E' || ch == 'P' || ch == 'D' || ch == 'd' || ch == 'c' || ch == 'X' || ch == 'l' || ch == 's'|| ch == 'T' || ch == 'Q') break;
		else
			if (ch == '\n')
			{
				continue;
			}
		else printf("%s", "Ошибка ввода\n");
	}

	return ch;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("%s", "Внимание размер изначального массива структур равен 3, поэтому в случае необходимости ввести большее количество структур, расширьте массив через функцию\n\n");

	init();
	char choice;
	for (;;)
	{
		choice = menu();
		switch (choice) {
		case 'E':
			enter();
			break;
		case 'P':
			enterprop();
			break;
		case 'D':
			display();
			break;
		case 'd':
			displayprop();
			break;
		case 'c':
			change();
			break;
		case 'X':
			addnewsrtuct();
			break;
		case 'l':
			del();
			break;
		case 's':
			sort();
			break;
		case 'T':
			task();
			break;
		case 'Q':
			delete[] atsinfo;
			return 0;
		}
	}
}