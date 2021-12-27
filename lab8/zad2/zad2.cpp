#include <iostream>
#include <Windows.h>
#include <string.h>
#include <fstream>

using namespace std;

struct inf_type {
	int number;//номер рейса

	char type[30];//тип самолета

	char destination[30];//пункт назначения

	char time[30];//время вылета
};
int SIZEOFARR = 3;
inf_type* infdesk = (inf_type*)calloc (SIZEOFARR, sizeof(inf_type));


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

	while (sscanf_s(answer, "%i", &var) < 1)
	{
		printf("%s", "Надо вводиь числа, а не буквы\n\n");
		scanf_s("%s", answer, 256);
	}
}

void fileinput(int i)
{
	ifstream inf("input.txt");
	inf >> infdesk[i].number;
	inf >> infdesk[i].type;
	inf >> infdesk[i].destination;
	inf >> infdesk[i].time;
}

void input(int i)//ввод
{
	printf("%s", "Введите номер рейса\n\n");
	scanf_s("%d", &infdesk[i].number);
	printf("%s", "Введите тип самолёта\n\n");
	scanf_s("%s", infdesk[i].type, 29);
	printf("%s", "Введите пункт назначения\n\n");
	scanf_s("%s", infdesk[i].destination, 29);
	printf("%s", "Введите время вылета\n\n");
	scanf_s("%s", infdesk[i].time, 29);


}

void fileout()
{
	int stop = 0;

	for (; stop < SIZEOFARR; stop++) if (infdesk[stop].type == 0) break;
	ofstream outf("output.txt");
	for (int i = 0; i < stop; i++)
	{
		outf << "\nНомер рейса : " << infdesk[i].number << "\n";
		outf << "Тип самолёта : " << infdesk[i].type << "\n";
		outf << "Пункт назначения : " << infdesk[i].destination << "\n";
		outf << "Время вылета : " << infdesk[i].time << "\n";
	}

}

void init()
{
	for (int i = 0; i < SIZEOFARR; i++)
	{
		*infdesk[i].type = '\0';
		*infdesk[i].destination = '\0';
		*infdesk[i].time = '\0';
	}
}

void enter()//ввод заранее заданного количества структур
{
	ifstream inf("input.txt");

	int numrepeat;
	inf >> numrepeat;
	int newsize = numrepeat + SIZEOFARR;

	int ijk = 0;

	inf_type* newinfdesk = (inf_type*)calloc(newsize, sizeof(inf_type));

	//перенос значений
	for (int i = 0; i < SIZEOFARR; i++)
	{
		newinfdesk[i] = infdesk[i];
	}

	//инициализация(нужна для дальнейшей проверки)
	for (int i = SIZEOFARR; i < newsize; i++)
	{
		*infdesk[i].type = '\0';
		*infdesk[i].destination = '\0';
		*infdesk[i].time = '\0';
	}

	free(infdesk);
	infdesk = newinfdesk;

	for (ijk = 0; ijk < newsize; ijk++) if (infdesk[ijk].type[0] == '\0') break;
	if (ijk == newsize)
	{
		cout << "Массив полон выдели больше места\n";
		return;
	}

	//заполнение новыми
	for (int i = ijk; i < newsize; i++)
	{
		inf >> infdesk[i].number;
		inf >> infdesk[i].type;
		inf >> infdesk[i].destination;
		inf >> infdesk[i].time;
	}

	SIZEOFARR = newsize;
	fileout();
}


void display()//просмотр содержимого динамического массива структур
{
	int jzk = 0;
	for (; jzk < SIZEOFARR; jzk++)
	{
		if (infdesk[jzk].type[0] == '\0') break;
	}
	for (int i = 0; i < 50; i++) printf("%c", '-');
	printf("%c", '\n');
	for (int i = 0; i < jzk; i++)
	{
		for (int i = 0; i < 50; i++) printf("%c", '-');
		printf("%c", '\n');
		printf("%s%i%s", "Номер рейса : ", infdesk[i].number, "\n");
		printf("%s%s%s", "Тип самолёта : ", infdesk[i].type, "\n");
		printf("%s%s%s", "Пункт назначения : ", infdesk[i].destination, "\n");
		printf("%s%s%s", "Время вылета : ", infdesk[i].time, "\n");
		for (int i = 0; i < 50; i++) printf("%c", '-');
		printf("%c", '\n');
	}
	for (int i = 0; i < 50; i++) printf("%c", '-');
	printf("%c", '\n');
}


void addnewsrtuct()//дополнения уже существующего массива структур новыми структурами
{
	printf("%s", "Введите количество структур которые хотите добавить\n");
	int numb;
	checkinp(numb);


	int tempSIZEOFARR = SIZEOFARR + numb;
	inf_type* infdesknew = (inf_type*)calloc(tempSIZEOFARR, sizeof(inf_type));

	for (int i = 0; i < SIZEOFARR; i++)
	{
		infdesknew[i] = infdesk[i];
	}

	for (int i = SIZEOFARR; i < tempSIZEOFARR; i++)
	{
		*infdesknew[i].type = '\0';
		*infdesknew[i].destination = '\0';
		*infdesknew[i].time = '\0';
	}
	SIZEOFARR = tempSIZEOFARR;

	free( infdesk);
	infdesk = infdesknew;

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

	int tempSIZEOFARR = SIZEOFARR - 1;
	inf_type* infdesknew = (inf_type*)calloc(tempSIZEOFARR, sizeof(inf_type));


	for (int i = 0; i < numb; i++)
	{
		infdesknew[i] = infdesk[i];
	}

	for (int i = numb, j = numb + 1; i < tempSIZEOFARR; i++, j++)
	{
		infdesknew[i] = infdesk[j];
	}

	SIZEOFARR = tempSIZEOFARR;

	free( infdesk);
	infdesk = infdesknew;

	fileout();
}

void change()//изменение элемента массива структур с заданным значением элемента
{
	printf("%s", "Введите поле структуры, в котором будет признак прзнак структуры, которую необходимо заменить\n\n");
	printf("%s", "n - номер рейса\nT - тип самолёта\nd - пункт назначения\nt - время вылета\n\n\n");
	char ch;
	//ввод поля
	while (true)//проверка ввода
	{
		scanf_s("%c", &ch);
		if (ch == 'n' || ch == 'T' || ch == 'd' || ch == 't') break;
		else if (ch == '\n');
		else printf("%s", "Введено не то значение, ожидалось: -n- -T- -d- -t- попробуйте заново\n\n");
	}



	printf("%s", "Введите признак структуры,которая будет заменена\n\n");

	char str[30];
	int izk;
	double jzk;

	//ввод признака
	if (ch == 'T' || ch == 'd' || ch == 't') scanf_s("%s", str, 30);
	else if (ch == 'n') scanf_s("%i", &izk);

	int i = 0;
	for (; i < SIZEOFARR; i++)
	{
		if (ch == 'n')
		{
			if (infdesk[i].number == izk)
			{
				input(i);
				break;
			}
		}
		if (ch == 'T')
		{
			if (!strcmp(infdesk[i].type, str))
			{
				input(i);
				break;
			}
		}
		if (ch == 't')
		{
			if (!strcmp(infdesk[i].time, str))
			{
				input(i);
				break;
			}
		}
		if (ch == 'd')
		{
			if (!strcmp(infdesk[i].destination, str))
			{
				input(i);
				break;
			}
		}
	}
	if (i == SIZEOFARR) printf("%s", "Структура с заданным признаком не была встречена\n\n");

	fileout();
}

bool compareAbB(char* a, char* b)
{
	int lena = strlen(a);
	int lenb = strlen(b);

	if (lena > lenb) return 1;
	if (lenb > lena) return 0;

	if (lena == lenb)
	{
		for (int i = 0; i < lena; i++)
		{
			if (a[i] > b[i]) return 1;
		}
	}

	return 0;
}

void sort()//Функция упорядочения массива структур
{
	for (int i = 1; i < SIZEOFARR; i++)
	{
		for (int j = 0; j < SIZEOFARR - i; j++)
		{
			if (compareAbB(infdesk[j].time, infdesk[j+1].time))
			{
				swap(infdesk[j], infdesk[j + 1]);
			}
		}
	}
}


void task()
{
	sort();
	ofstream outf("taskoutput.txt");
	char str[30];

	cout << "Введите пункт назначения, для которого Вывести все номера рейсов, типы самолетов и времена вылета\n";
	cin >> str;

	for (int i = 0; i < SIZEOFARR; i++)
	{
		if (!strcmp(infdesk[i].destination, str))
		{
			outf << "\nНомер рейса : " << infdesk[i].number << "\n";
			outf << "Тип самолёта : " << infdesk[i].type << "\n";
			outf << "Время вылета : " << infdesk[i].time << "\n";
		}
	}
}

int menu()
{
	char ch;

	printf("%s", " E - ввод заранее заданного количества структур\n D - отобразить содержимого динамического массива структур\n c - изменение структуры с заданным признаком\n X - расширить массив структур\n l - удалить эллемент массива структур\n s - сортировка эллементов массива От большего к меньшему\n T - задача\n Q - кончить выполнение программы\n\n");

	while (true)
	{
		scanf_s("%c", &ch);
		if (ch == 'E' || ch == 'P' || ch == 'D' || ch == 'd' || ch == 'c' || ch == 'X' || ch == 'l' || ch == 's' || ch == 'T' || ch == 'Q') break;
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
		case 'D':
			display();
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
		/*case 's':
			sort();
			break;*/
		case 'T':
			task();
			break;
		case 'Q':
			free( infdesk);
			return 0;
		}
	}
}


/*
void displayi(int i)//просмотр содержимого одной структуры динамического массива структур
{
	for (int i = 0; i < 50; i++) printf("%c", '-');
	printf("%c", '\n');
	printf("%s%i%s", "Номер рейса : ", infdesk[i].number, "\n");
	printf("%s%s%s", "Тип самолёта : ", infdesk[i].type, "\n");
	printf("%s%s%s", "Пункт назначения : ", infdesk[i].destination, "\n");
	printf("%s%s%s", "Время вылета : ", infdesk[i].time, "\n");
	printf("%c", '\n');
	for (int i = 0; i < 50; i++) printf("%c", '-');
	printf("%c", '\n');
}
*/

/*
void displayprop()//поиск и вывод на экран структуры(структур) с заданным значением элемента
{
	printf("%s", " Введите поле структуры в котором будет заданный признак\n");
	printf("%s", "n - номер рейса\nT - тип самолёта\nd - пункт назначения\nt - время вылета\n\n\n");


	char ch;
	//ввод поля
	while (true)//проверка ввода
	{
		scanf_s("%c", &ch);
		if (ch == 'n' || ch == 'T' || ch == 'd' || ch == 't') break;
		else if (ch == '\n');
		else printf("%s", "Введено не то значение, ожидалось: -n- -T- -d- -t- попробуйте заново\n\n");
	}

	printf("%s", "Введите признак структуры, которую надо отобразить\n");

	char str[30];
	int izk;
	double jzk;

	//ввод признака
	if (ch == 'T' || ch == 'd' || ch == 't') scanf_s("%s", str, 30);
	else if (ch == 'n') scanf_s("%i", &izk);

	int i = 0;
	for (int i = 0; i < 50; i++) printf("%c", '-');
	printf("%c", '\n');
	bool B = 0;//был ли вывод?
	for (; i < SIZEOFARR; i++)
	{
		if (ch == 'n')
		{
			if (infdesk[i].number == izk)
			{
				displayi(i);
				B = 1;
			}
		}
		if (ch == 'T')
		{
			if (!strcmp(infdesk[i].type, str))
			{
				displayi(i);
				B = 1;
			}
		}
		if (ch == 't')
		{
			if (!strcmp(infdesk[i].time, str))
			{
				displayi(i);
				B = 1;
			}
		}
		if (ch == 'd')
		{
			if (!strcmp(infdesk[i].destination, str))
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
*/

