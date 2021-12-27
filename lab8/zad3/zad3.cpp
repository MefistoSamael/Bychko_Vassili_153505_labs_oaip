#include <iostream>
#include <Windows.h>
#include <string.h>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;
class students {
private:

	string name;//имя

	string Lastname;//фамилия

	string patronymic;//отчество

	int numb;//номер группы

	double avg;//средний балл

	int income;//доход на члена семьи

	

public:
	void set_name(string student_name)
	{
		name = student_name;
	}
	string get_name()
	{
		return name;
	}


	void set_lname(string student_lname)
	{
		Lastname = student_lname;
	}
	string get_lname()
	{
		return Lastname;
	}


	void set_patr(string student_patr)
	{
		patronymic = student_patr;
	}
	string get_patr()
	{
		return patronymic;
	}


	void set_numb(int number)
	{
		numb = number;
	}
	int get_numb()
	{
		return numb;
	}


	void set_avg(double a)
	{
		avg = a;
	}
	double get_avg()
	{
		return avg;
	}


	void set_income(int a)
	{
		income = a;
	}
	int get_income()
	{
		return income;
	}

};
int SIZEOFARR = 3;
students* stud = new students[SIZEOFARR];



int checkinp(int a)
{
	while (true)
	{
		cin >> a;
		if (cin.fail())
		{
			cout << "Ошибка ввода. Вводи только цифры\n";
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else return a;
	}
}

double checkinp(double a)
{
	while (true)
	{
		cin >> a;
		if (cin.fail())
		{
			cout << "Ошибка ввода. Вводи только цифры\n";
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else return a;
	}
}

void input(int i)//ввод
{
	//просто переменные ввода
	string str;
	double d;
	int j;

	cout << "Введите фамилию\n\n";
	getline(cin, str);
	stud[i].set_lname(str);
	cout << "Введите имя\n\n";
	getline(cin, str);
	stud[i].set_name(str);
	cout << "Введите отчество\n\n";
	getline(cin, str);
	stud[i].set_patr(str);
	cout << "Введите номер группы\n\n";
	cin >> j;
	stud[i].set_numb(i);
	cout << "Введите средний балл\n\n";
	cin >> d;
	stud[i].set_avg(d);
	cout << "Введите доход на члена семьи\n\n";
	cin >> j;
	stud[i].set_numb(i);


}

int razryad(int n) {
	int sum = 0;
	while (n) {
		n /= 10;
		++sum;
	}
	return sum;
}

void init()
{
	string str;
	for (int i = 0; i < SIZEOFARR; i++)
	{
		stud[i].set_name(str);
		stud[i].set_lname(str);
		stud[i].set_patr(str);
	}
}

void obnov()
{
	string s;

	cout << "Введите фамилию ученика,информация про которого вы хотите изменить : ";
	cin >> s;
	cin.ignore(1, '\n');

	int i;
	for (i = 0; i < SIZEOFARR; i++)
	{
		if (s == stud[i].get_lname())
			break;
	}

	if (i == SIZEOFARR)
	{
		cout << "\nтакого ученика нет)\n";
		return;
	}

	cout << "Введите новые значения :\n";
	input(i);
	ofstream fout("output.txt", ios::binary | ios::out | ios::in);
	fout.seekp(i * 6 * 52, ios::beg);
	fout << "Фамилия: " << stud[i].get_lname();
	for (int j = 9 + stud[i].get_lname().size(); j < 50; ++j)
	{
		fout << ' ';
	}
	//fout << '\n';
	fout.seekp(i * 6 * 52 + 52, ios::beg);
	fout << "Имя: " << stud[i].get_name();
	for (int j = 5 + stud[i].get_name().size(); j < 50; ++j)
	{
		fout << ' ';
	}
	//fout << '\n';
	fout.seekp(i * 6 * 52 + 52 * 2, ios::beg);
	fout << "Отчесвто: " << stud[i].get_patr();
	for (int j = 10 + stud[i].get_patr().size(); j < 50; ++j)
	{
		fout << ' ';
	}
	//fout << '\n';
	fout.seekp(i * 6 * 52 + 52 * 3, ios::beg);
	fout << "Номер группы: " << stud[i].get_numb();
	int n = razryad(stud[i].get_numb());
	for (int j = 14 + n; j < 50; ++j)
	{
		fout << ' ';
	}
	//fout << '\n';
	fout.seekp(i * 6 * 52 + 52 * 4, ios::beg);
	fout << "Cредний балл: " << stud[i].get_avg();
	n = razryad(stud[i].get_avg());
	for (int j = 14 + n; j < 50; ++j) {
		fout << ' ';
	}
	//fout << '\n';
	fout.seekp(i * 6 * 52 + 52 * 5, ios::beg);
	fout << "Доход на члена семьи: " << stud[i].get_income();
	n = razryad(stud[i].get_income());
	for (int j = 22 + n; j < 50; ++j) {
		fout << ' ';
	}
}


void fileout(int i)
{
	int stop = 0;
	string str;
	for (; stop < SIZEOFARR; stop++) if (stud[stop].get_name() == str) break;
	/*ofstream outf{"output.txt"};
	for (int i = 0; i < stop; i++)
	{
		outf << "Фамилия : " << stud[i].get_lname() << "\n";
		outf << "Имя : " << stud[i].get_name() << "\n";
		outf << "Отчество : "<< stud[i].get_patr() << "\n";
		outf << "Номер группы : " << stud[i].get_numb() << "\n";
		outf << "Средний балл : " << stud[i].get_avg() << "\n";
		outf << "Доход на члена семьи : "<< stud[i].get_income() << "\n";//гыгыгыгыгыгыгыгы ЧЛЕНА гыгыгыгыгыгыгы

	}*/
	ofstream fout("output.txt", ios::binary | ios::out | ios::in);
	fout.seekp(i * 6 * 52, ios::beg);
	fout << "Фамилия: " << stud[i].get_lname();
	for (int j = 9 + stud[i].get_lname().size(); j < 50; ++j)
	{
		fout << ' ';
	}
	//fout << '\n';
	fout.seekp(i * 6 * 52 + 52, ios::beg);
	fout << "Имя: " << stud[i].get_name();
	for (int j = 5 + stud[i].get_name().size(); j < 50; ++j)
	{
		fout << ' ';
	}
	//fout << '\n';
	fout.seekp(i * 6 * 52 + 52 * 2, ios::beg);
	fout << "Отчесвто: " << stud[i].get_patr();
	for (int j = 10 + stud[i].get_patr().size(); j < 50; ++j)
	{
		fout << ' ';
	}
	//fout << '\n';
	fout.seekp(i * 6 * 52 + 52 * 3, ios::beg);
	fout << "Номер группы: " << stud[i].get_numb();
	int n = razryad(stud[i].get_numb());
	for (int j = 14 + n; j < 50; ++j)
	{
		fout << ' ';
	}
	//fout << '\n';
	fout.seekp(i * 6 * 52 + 52 * 4, ios::beg);
	fout << "Cредний балл: " << stud[i].get_avg();
	n = razryad(stud[i].get_avg());
	for (int j = 14 + n; j < 50; ++j) {
		fout << ' ';
	}
	//fout << '\n';
	fout.seekp(i * 6 * 52 + 52 * 5, ios::beg);
	fout << "Доход на члена семьи: " << stud[i].get_income();
	n = razryad(stud[i].get_income());
	for (int j = 22 + n; j < 50; ++j) {
		fout << ' ';
	}
}

void enter()//ввод заранее заданного количества структур
{
	ifstream inf("input.txt");
	string str;
	int numrepeat;
	inf >> numrepeat;
	int newsize = numrepeat + SIZEOFARR;

	int ijk = 0;

	students* newstud = new students[newsize];

	//перенос значений
	for (int i = 0; i < SIZEOFARR; i++)
	{
		newstud[i] = stud[i];
	}

	//инициализация(нужна для дальнейшей проверки)
	/*for (int i = SIZEOFARR; i < newsize; i++)
	{
		stud[i].set_name(str);
		stud[i].set_lname(str);
		stud[i].set_patr(str);
	}*/

	delete[]stud;
	stud = newstud;

	for (ijk = 0; ijk < newsize; ijk++) if (stud[ijk].get_name() == str) break;
	if (ijk == newsize)
	{
		cout << "Массив полон выдели больше места\n";
		return;
	}

	//заполнение новыми
	for (int i = ijk; i < newsize; i++)
	{
		string str;
		int abc;
		double bcd;
		inf >> str;
		stud[i].set_name(str);
		inf >> str;
		stud[i].set_lname(str);
		inf >> str;
		stud[i].set_patr(str);
		inf >> abc;
		stud[i].set_numb(abc);
		inf >> bcd;
		stud[i].set_avg(bcd);
		inf >> abc;
		stud[i].set_income(abc);
	}

	SIZEOFARR = newsize;
	fileout();
}


void display()//просмотр содержимого динамического массива структур
{
	string str;
	int jzk = 0;
	for (; jzk < SIZEOFARR; jzk++)
	{
		if (stud[jzk].get_name() == str) break;
	}
	for (int i = 0; i < 50; i++) printf("%c", '-');
	printf("%c", '\n');
	for (int i = 0; i < jzk; i++)
	{
		for (int i = 0; i < 50; i++) printf("%c", '-');
		printf("%c", '\n');
		cout << "Имя : " << stud[i].get_name() << "\n";
		cout << "Фамилия : " << stud[i].get_lname() << "\n";
		cout << "Отчество : " << stud[i].get_patr() << "\n";
		cout << "Номер группы : " << stud[i].get_numb() << "\n";
		cout << "Средний балл : " << stud[i].get_avg() << "\n";
		cout << "Доход на члена семьи : " << stud[i].get_income() << "\n";//гыгыгыгыгыгыгыгы ЧЛЕНА гыгыгыгыгыгыгы
		for (int i = 0; i < 50; i++) printf("%c", '-');
		printf("%c", '\n');
	}
	for (int i = 0; i < 50; i++) printf("%c", '-');
	printf("%c", '\n');
}

void delet()
{
	int k = 0;
	string s;

	cout << "Введите фамилию ученика,информация про которого вы хотите удалить : ";
	cin >> s;

	if (SIZEOFARR == 0)
	{
		cout << "\nНет элементов для удаления,База данных пуста\n";
		return;
	}

	students* newstud = new students[SIZEOFARR - 1];

	for (int i = 0; i < SIZEOFARR; i++)
	{
		if (stud[i].get_lname() != s)
		{
			k++;
		}
	}

	if (k == SIZEOFARR)
	{
		cout << "\nНевозмождно выполнить!\n";
		return;
	}

	ofstream fout("output.txt", ios_base::app);
	int a;
	for (int i = 0, j = 0; i < SIZEOFARR; i++)
	{
		if (stud[i].get_lname() != s)
		{
			newstud[j] = stud[i];
			j++;
		}
		else
		{
			a = i;
		}
	}
	SIZEOFARR--;
	filesystem::resize_file("output.txt", 52 * 6 * a);
	for (int i = a; i < SIZEOFARR; i++) {
		fout << "Фамилия: " << newstud[i].get_lname();
		for (int j = 9 + newstud[i].get_lname().size(); j < 50; ++j) {
			fout << ' ';
		}
		fout << '\n';
		fout << "Имя: " << newstud[i].get_name();
		for (int j = 5 + newstud[i].get_name().size(); j < 50; ++j) {
			fout << ' ';
		}
		fout << '\n';
		fout << "Отчесвто: " << newstud[i].get_patr();
		for (int j = 10 + newstud[i].get_patr().size(); j < 50; ++j) {
			fout << ' ';
		}
		fout << '\n';
		fout << "Номер группы: " << newstud[i].get_numb();
		int n = razryad(newstud[i].get_numb());
		for (int j = 14 + n; j < 50; ++j) {
			fout << ' ';
		}
		fout << '\n';
		fout << "Средний балл: " << newstud[i].get_avg();
		n = razryad(newstud[i].get_avg());
		for (int j = 14 + n; j < 50; ++j) {
			fout << ' ';
		}
		fout << '\n';
		fout << "Доход на члена семьи: " << newstud[i].get_income();
		n = razryad(newstud[i].get_income());
		for (int j = 22 + n; j < 50; ++j) {
			fout << ' ';
		}
		fout << '\n';
	}

	delete[] stud;

	stud = newstud;
}



void addnewsrtuct()//дополнения уже существующего массива структур новыми структурами
{
	string str;

	printf("%s", "Введите количество структур которые хотите добавить\n");
	int numb = 0;
	checkinp(numb);


	int tempSIZEOFARR = SIZEOFARR + numb;
	students* newstud = new students[tempSIZEOFARR];

	for (int i = 0; i < SIZEOFARR; i++)
	{
		newstud[i] = stud[i];
	}

	/*for (int i = SIZEOFARR; i < tempSIZEOFARR; i++)
	{
		stud[i].set_name(str);
		stud[i].set_lname(str);
		stud[i].set_patr(str);
	}*/
	SIZEOFARR = tempSIZEOFARR;

	delete []stud;
	stud = newstud;
	fileout();
}


void del()//удаление элемента массива структур с заданным значением элемента
{
	printf("%s", "Введите номер структуры которую хотите удалить\n\n");
	int numb = 0;
	while (true)
	{
		checkinp(numb);
		if (numb <= SIZEOFARR - 1) break;
		else printf("%s", "Вы хотите удалить несуществующий элемент массива\n\n");
	}

	int tempSIZEOFARR = SIZEOFARR - 1;
	students* newstud = new students[tempSIZEOFARR];


	for (int i = 0; i < numb; i++)
	{
		newstud[i] = stud[i];
	}

	for (int i = numb, j = numb + 1; i < tempSIZEOFARR; i++, j++)
	{
		newstud[i] = stud[j];
	}

	SIZEOFARR = tempSIZEOFARR;

	delete[]stud;
	stud = newstud;
	fileout();
}

void change()//изменение элемента массива структур с заданным значением элемента
{
	printf("%s", "Введите поле структуры, в котором будет признак прзнак структуры, которую необходимо заменить\n\n");
	printf("%s", "N - имя\nL - фамилия\np - отчество\nn - номер группы\na - среднее\ni - доход на члена семьи\n\n");

	char ch;
	//ввод поля
	while (true)//проверка ввода
	{
		scanf_s("%c", &ch);
		if (ch == 'N' || ch == 'L' || ch == 'p' || ch == 'n' || ch == 'a' || ch == 'i') break;
		else if (ch == '\n');
		else printf("%s", "Введено не то значение, ожидалось: -N- -L- -p- -n- -a- -i- попробуйте заново\n\n");
	}



	printf("%s", "Введите признак структуры,которая будет заменена\n\n");

	string str;
	int izk;
	double jzk;

	//ввод признака
	if (ch == 'N' || ch == 'L' || ch == 'p') cin >> str;
	else if (ch == 'n' || ch == 'i')
	{
		cin >> izk;
		cin.ignore(1, '\n');
	}
	else if (ch == 'a')
	{
		cin >> jzk;
		cin.ignore(1, '\n');
	}

	int i = 0;
	for (; i < SIZEOFARR; i++)
	{
		if (ch == 'N')
		{
			if (stud[i].get_name() == str)
			{
				input(i);
				break;
			}
		}
		if (ch == 'L')
		{
			if (stud[i].get_lname() == str)
			{
				input(i);
				break;
			}
		}
		if (ch == 'p')
		{
			if (stud[i].get_patr() == str)
			{
				input(i);
				break;
			}
		}
		if (ch == 'n')
		{
			if (stud[i].get_numb() == izk)
			{
				input(i);
				break;
			}
		}
		if (ch == 'i')
		{
			if (stud[i].get_income() == izk)
			{
				input(i);
				break;
			}
		}
		if (ch == 'a')
		{
			if (stud[i].get_avg() == jzk)
			{
				input(i);
				break;
			}
		}
	}
	if (i == SIZEOFARR) printf("%s", "Структура с заданным признаком не была встречена\n\n");
	fileout();
}

void sort()//Функция упорядочения массива структур
{
	string str;
	int truesize = 0;
	for (; truesize < SIZEOFARR; truesize++) if (stud[truesize].get_name() == str) break;
	for (int i = 1; i < truesize; i++)
	{
		for (int j = 0; j < truesize - i; j++)
		{
			if (stud[j].get_avg() > stud[j+1].get_avg())
			{
				swap(stud[j], stud[j+1]);
			}
		}
	}
	fileout();
}


void task()
{
	sort();
	const int twominsal = 2*457;
	ofstream outf("taskoutput.txt");

	//
	char str[30];


	for (int i = 0; i < SIZEOFARR; i++)
	{
		if (stud[i].get_income() < twominsal)
		{
			cout << "Фамилия : " << stud[i].get_lname() << "\n";
			outf << "Фамилия : " << stud[i].get_lname() << "\n";
		}
	}
}

int menu()
{
	char ch;

	printf("%s", " E - ввод заранее заданного количества структур\n D - отобразить содержимого динамического массива структур\n c - изменение структуры с заданным признаком\n X - расширить массив структур\n l - удалить эллемент массива структур\n s - сортировка эллементов массива от меньшего к большему\n T - задача\n Q - кончить выполнение программы\n\n");

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
			obnov();
			break;
		case 'X':
			addnewsrtuct();
			break;
		case 'l':
			delet();
			break;
		case 's':
				sort();
				break;
		case 'T':
			task();
			break;
		case 'Q':
			delete[]stud;
			return 0;
		}
	}
}

