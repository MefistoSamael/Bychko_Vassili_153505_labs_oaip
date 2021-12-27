#include <string>
#include <iostream>
#include <Windows.h>
#include <malloc.h>
#include <iomanip>
#include <fstream> 
#include <cstdlib>

std::ofstream fout("output.txt");
std::ifstream fin("output.txt");

void _()
{
	std::cout << std::endl;
}

void I()
{
	std::cout << "\t\t\t\t\t";
}

class Rate_list
{
public:

	void set_name(char* _name)
	{
		for (int i = 0; i < 40; i++)
		{
			name[i] = _name[i];
		}
	}
	char* get_name()
	{
		return name;
	}

	void set_surname(char* _surname)
	{
		for (int i = 0; i < 40; i++)
		{
			surname[i] = _surname[i];
		}
	}
	char* get_surname()
	{
		return surname;
	}

	void set_second_name(char* _second_name)
	{
		for (int i = 0; i < 40; i++)
		{
			second_name[i] = _second_name[i];
		}
	}
	char* get_second_name()
	{
		return second_name;
	}

	void set_grup_nomber(int _grup_nomber)
	{
		grup_nomber = _grup_nomber;
	}
	int get_grup_nomber()
	{
		return grup_nomber;
	}

	void set_average(double _average)
	{
		average = _average;
	}
	double get_average()
	{
		return average;
	}

	void set_stonks(int _stonks)
	{
		stonks = _stonks;
	}
	int get_stonks()
	{
		return stonks;
	}

private:

	char name[40];

	char surname[40];

	char second_name[40];

	int grup_nomber;

	double average;

	int stonks;
};

void add(Rate_list*& List, int& size);

void add_check(Rate_list*& List, int& size);

void in(int start, Rate_list*& List, int& size);

void find(Rate_list*& List, int& size);

void delet(Rate_list*& List, int& size);

void display(Rate_list*& List, int& size);

void output(Rate_list*& List, int t);

void update(Rate_list*& List, int& size);

void sort(Rate_list*& List, int& size);

int check_N();

double check_D();

double str_2_dbl(std::string s);

void meta(Rate_list*& List, int& size, int min_salaru);

void file_write(Rate_list*& List, int& size, int S);

int file_find(Rate_list*& List, int& size);

void file_change(Rate_list*& List, int& size, bool kostil);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int min_salaru;

	int size = 0, num;
	char har;

	Rate_list* List = (Rate_list*)calloc(size, sizeof(Rate_list));

	char ch;

	std::cout << " в - ввести и следом число человек" << std::endl;
	std::cout << " В - вводить до появления признака" << std::endl;
	std::cout << " п - показать весь список" << std::endl;
	std::cout << " о - обновить информацию о человеке" << std::endl;
	std::cout << " н - найти по признаку" << std::endl;
	std::cout << " у - удалить" << std::endl;
	std::cout << " с - отсортировать по возрастанию " << std::endl;
	std::cout << " м - вывести фамилии студентов у которых доход на члена семьи мень двух минимальных зарплат" << std::endl;
	std::cout << " з - закончить" << std::endl;
	_();

	std::cout << "  Введите минимальную зарплату: ";
	min_salaru = check_N();

	_();

	do {
		std::cout << " Введите комманду: ";

		std::cin >> ch;
		switch (ch)
		{
		case 'в':
			add(List, size);
			file_change(List, size, 1);
			/*file_write(List, size,0);*/
			break;
		case 'В':
			add_check(List, size);
			file_change(List, size, 0);
			break;
		case 'о':
			update(List, size);
			file_change(List, size, 1);
			break;
		case 'н':
			find(List, size);
			break;
		case 'п':
			display(List, size);
			break;
		case 'с':
			sort(List, size);
			file_change(List, size, 1);
			break;
		case 'м':
			meta(List, size, min_salaru);
			break;
		case 'у':
			delet(List, size);
			file_change(List, size, 0);
			/*file_write(List, size,0);*/
			break;
		case 'з':
			return 0;

		default:
			std::cout << "Такой функции нет" << std::endl;;
			break;
		}

		/*std::cin.clear();
		std::cin.ignore(32767, '\n');*/

	} while (ch != 'з');

	free(List);

	return 0;
}

void add(Rate_list*& List, int& size)
{
	int dop, start = size;

	bool Л = true;

	while (Л)
	{
		Л = false;
		std::cin >> dop;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "   Ошибка ввода.Введите значение заного" << std::endl;
			_();
			Л = true;
		}
	}

	//Rate_list* newList = new Rate_list[size + dop];

	Rate_list* newList = (Rate_list*)calloc(size + dop, sizeof(Rate_list));

	for (int i = 0; i < size; i++)
	{
		newList[i] = List[i];
	}
	size += dop;

	//delete[]List;

	free(List);

	List = newList;

	for (start; start < size; start++)
	{
		std::cout << "Введите имя: ";
		char _name[40];
		std::cin >> _name;
		List[start].set_name(_name);

		std::cout << "Введите фамилию: ";
		char _surname[40];
		std::cin >> _surname;
		List[start].set_surname(_surname);

		std::cout << "Введите отчество: ";
		char _second_name[40];
		std::cin >> _second_name;
		List[start].set_second_name(_second_name);

		std::cout << "Введите номер группы: ";
		List[start].set_grup_nomber(check_N());

		std::cin.clear();
		std::cin.ignore(32767, '\n');

		std::cout << "Введите средний балл: ";
		List[start].set_average(check_D());

		std::cout << "Введите доход: ";
		List[start].set_stonks(check_N());

		_();
	}
}

void in(Rate_list*& List, int& size)
{
	int start = size;

	//Rate_list* newList = new Rate_list[size + 1];

	Rate_list* newList = (Rate_list*)calloc(size + 1, sizeof(Rate_list));

	for (int i = 0; i < size; i++)
	{
		newList[i] = List[i];
	}
	size++;

	free(List);

	List = newList;

	std::cout << "Введите имя: ";
	char _name[40];
	std::cin >> _name;
	List[start].set_name(_name);

	std::cout << "Введите фамилию: ";
	char _surname[40];
	std::cin >> _surname;
	List[start].set_surname(_surname);

	std::cout << "Введите отчество: ";
	char _second_name[40];
	std::cin >> _second_name;
	List[start].set_second_name(_second_name);

	std::cout << "Введите номер группы: ";
	List[start].set_grup_nomber(check_N());

	std::cin.clear();
	std::cin.ignore(32767, '\n');

	std::cout << "Введите средний балл: ";
	List[start].set_average(check_D());

	std::cout << "Введите доход: ";
	List[start].set_stonks(check_N());

	_();
}

void delet(Rate_list*& List, int& size)
{
	int num;
	std::cin >> num;

	if (num > size || num <= 0)
	{
		std::cout << " Ошибка ввода.";
		return;
	}

	//Rate_list* newList = new Rate_list[size - 1];

	Rate_list* newList = (Rate_list*)calloc(size - 1, sizeof(Rate_list));

	for (int k = 0, j = 0; k < size; k++, j++)
	{
		if (k == num - 1 && num == size) continue;

		if (k == num - 1) k++;

		newList[j] = List[k];
	}

	size--;

	free(List);

	List = newList;
	_();
}

void display(Rate_list*& List, int& size)
{
	int t;
	bool b = true;

	for (t = 0; t < size; t++) {

		output(List, t);
		b = false;
	}
	if (b)
		std::cout << " \t\t\t\t\t Список пуст" << std::endl;
}

void output(Rate_list*& List, int t)
{
	I();
	std::cout << "Имя: ";
	std::cout << List[t].get_name();
	_();

	I();
	std::cout << "Фамилия: ";
	std::cout << List[t].get_surname();
	_();

	I();
	std::cout << "Отчество: ";
	std::cout << List[t].get_second_name();
	_();

	I();
	std::cout << "Номер группы: ";
	std::cout << List[t].get_grup_nomber();
	_();

	I();
	std::cout << "Средний балл: ";
	std::cout << std::fixed << std::showpoint << std::setprecision(7) << List[t].get_average();
	_();

	I();
	std::cout << "Доход: ";
	std::cout << List[t].get_stonks();
	_(); _();

}

void find(Rate_list*& List, int& size)
{
	std::cout << "   Введите в каком поле хотите искать" << std::endl;

	std::string abj;

	std::cin.clear();
	std::cin.ignore(32767, '\n');

	while (1)
	{

		getline(std::cin, abj);

		if (abj != "Имя" && abj != "Фамилия" && abj != "Отчество" && abj != "Номер в группе" && abj != "Средний балл" && abj != "Доход")
		{
			std::cout << "  Ошибка ввода.Такого поля не существует.Введите данные заного" << std::endl;
			continue;
		}
		break;
	}

	std::cout << "   Введите, что хотите найти" << std::endl;
	std::string l;

	getline(std::cin, l);

	bool J = true;

	if (abj == "Имя")
	{
		for (int i = 0; i < size; i++)
		{
			if (List[i].get_name() == l)
			{
				J = false;
				output(List, i);
				_();
			}
		}
	}
	else if (abj == "Фамилия")
	{
		for (int i = 0; i < size; i++)
		{
			if (List[i].get_surname() == l)
			{
				output(List, i);
				_();
				J = false;
			}
		}
	}
	else if (abj == "Отчество")
	{
		for (int i = 0; i < size; i++)
		{
			if (List[i].get_second_name() == l)
			{
				output(List, i);
				_();
				J = false;
			}
		}
	}
	else if (abj == "Номер в группе")
	{
		int f = atoi(l.c_str());

		for (int i = 0; i < size; i++)
		{
			if (List[i].get_grup_nomber() == f)
			{
				output(List, i);
				_();
				J = false;
			}
		}
	}
	else if (abj == "Средний балл")
	{
		for (int i = 0; i < size; i++)
		{
			if (str_2_dbl(l) == List[i].get_average())
			{
				output(List, i);
				_();
				J = false;
			}
		}
	}
	else if (abj == "Доход")
	{
		int f = atoi(l.c_str());

		for (int i = 0; i < size; i++)
		{
			if (List[i].get_stonks() == f)
			{
				output(List, i);
				_();
				J = false;
			}
		}
	}

	if (J)
		std::cout << "                                        Ничего не найдено" << std::endl;
}

void add_check(Rate_list*& List, int& size)
{
	std::cout << "   Введите в каком поле хотите искать" << std::endl;

	std::cin.clear();
	std::cin.ignore(32767, '\n');

	int L = size;

	std::string abj;

	while (1)
	{
		getline(std::cin, abj);

		if (abj != "Имя" && abj != "Фамилия" && abj != "Отчество" && abj != "Номер в группе" && abj != "Средний балл" && abj != "Доход")
		{
			std::cout << "  Ошибка ввода.Такого поля не существует.Введите данные заного" << std::endl;
			continue;
		}
		break;
	}

	_();

	bool J = true;

	std::cout << "   Введите, что хотите найти" << std::endl;
	std::string l;
	getline(std::cin, l);

	for (L; L < L + 1; L++)
	{
		in(List, size);
		_();

		if (abj == "Имя" && List[L].get_name() == l)
			break;

		else if (abj == "Фамилия" && List[L].get_surname() == l)
			break;

		else if (abj == "Отчество" && List[L].get_second_name() == l)
			break;

		else if (abj == "Номер в группе")
		{
			int f = atoi(l.c_str());
			if (f == List[L].get_grup_nomber())
				break;
		}

		else if (abj == "Средний балл")
		{
			double f = str_2_dbl(l);
			if (f == List[L].get_average())
				break;
		}

		else if (abj == "Доход")
		{
			int f = atoi(l.c_str());
			if (f == List[L].get_stonks())
				break;
		}
	}
}

void update(Rate_list*& List, int& size)
{
	int n;
	std::cin >> n;

	n--;

	if (n + 1 > size || n + 1 <= 0)
	{
		std::cout << " Ошибка ввода.";
		return;
	}

	std::cout << "Введите имя: ";
	std::cin >> List[n].get_name();

	std::cout << "Введите фамилию: ";
	std::cin >> List[n].get_surname();

	std::cout << "Введите отчество: ";
	std::cin >> List[n].get_second_name();

	std::cout << "Введите номер группы: ";
	List[n].set_grup_nomber(check_N());

	std::cin.clear();
	std::cin.ignore(32767, '\n');

	std::cout << "Введите средний балл: ";
	List[n].set_average(check_D());

	std::cout << "Введите доход: ";
	List[n].set_stonks(check_N());

	_();
}

void sort(Rate_list*& List, int& size)
{
	for (int i = 1; i < size; i++)
		for (int j = i; j > 0 && List[j - 1].get_average() > List[j].get_average(); j--)
		{
			//swap(j - 1, j);

			Rate_list buff;

			buff = List[j - 1];
			List[j - 1] = List[j];
			List[j] = buff;
		}
}

int check_N()                                     // Функция проверки стороны матрицы
{
	bool b = false;

	int N;

	while (b == false)
	{
		std::cin >> N;

		if (std::cin.fail() || N <= 0)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "   Ошибка ввода. Введите значения заного" << std::endl;
			_();
		}
		else
		{
			b = true;

			return N;
		}
	}
}

double check_D()                                     // Функция проверки стороны матрицы
{
	bool b = false;

	double N;

	while (b == false)
	{
		std::cin >> N;

		if (std::cin.fail() || N <= 0)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "   Ошибка ввода. Введите значения заного" << std::endl;
			_();
		}
		else
		{
			b = true;

			std::cin.clear();
			std::cin.ignore(32767, '\n');

			return N;
		}
	}
}

double str_2_dbl(std::string s)
{
	int l = s.length();
	int P;

	bool point = false;

	for (int i = 0; i < l; i++)
	{
		if ((s[i] < 48 || s[i]> 57) && s[i] != '.')
		{
			return -1;
		}

		if (s[i] == '.' && point)
		{
			return -1;
		}

		if (s[i] == '.')
		{
			point = true;
			P = i;
		}
	}

	if (!point)
	{
		return atoi(s.c_str());
	}
	else
	{
		int max_pow = P - 1;
		double sum = 0;

		for (int i = 0; i < l; i++)
		{
			if (i == P)i++;

			sum += (s[i] - 48) * pow(10, max_pow);
			max_pow--;
		}

		return sum;

	}
}

void meta(Rate_list*& List, int& size, int min_salaru)
{
	bool a = false;

	I();

	for (int i = 0; i < size; i++)
	{
		if (List[i].get_stonks() < 2 * min_salaru)
		{
			if (!a)
			{

				std::cout << "Студенты с низким доходом в семье: " << std::endl;
				_();
				a = true;
			}

			I();
			std::cout << List[i].get_surname() << std::endl;
			_();
		}
	}

	if (!a)
	{
		std::cout << "Нет студентов с низким доходом в семье";
	}
}

int file_find(Rate_list*& List, int& size)
{
	fin.open("output.txt");
	std::string* miakot = new std::string[6];
	std::string* miaso = new std::string[8];

	int N = size + 1;

	for (int i = 0; i < size; i++)
	{
		fin >> miaso[0];
		fin >> miakot[0];

		fin >> miaso[1];
		fin >> miakot[1];

		fin >> miaso[2];
		fin >> miakot[2];

		fin >> miaso[3];
		fin >> miaso[4];
		fin >> miakot[3];

		fin >> miaso[5];
		fin >> miaso[6];
		fin >> miakot[4];

		fin >> miaso[7];
		fin >> miakot[5];

		Rate_list Bufer;

		char name[40];

		for (int i = 0; i < 40; i++)
		{
			name[i] = '\0';
		}
		int Lname = miakot[0].length();
		for (int i = 0; i < Lname; i++)
		{
			name[i] = miakot[0][i];
		}

		char surname[40];
		for (int i = 0; i < 40; i++)
		{
			surname[i] = '\0';
		}
		int Lsurname = miakot[1].length();
		for (int i = 0; i < Lsurname; i++)
		{
			surname[i] = miakot[1][i];
		}

		char s_name[40];
		for (int i = 0; i < 40; i++)
		{
			s_name[i] = '\0';
		}
		int Lsname = miakot[2].length();
		for (int i = 0; i < Lsname; i++)
		{
			s_name[i] = miakot[2][i];
		}

		Bufer.set_name(name);
		Bufer.set_surname(surname);
		Bufer.set_second_name(s_name);

		int f = atoi(miakot[3].c_str());
		Bufer.set_grup_nomber(f);

		double g = str_2_dbl(miakot[4]);
		Bufer.set_average(g);

		int h = atoi(miakot[5].c_str());
		Bufer.set_stonks(h);

		_();

		if (Bufer.get_grup_nomber() != List[i].get_grup_nomber() || Bufer.get_average() != List[i].get_average() || Bufer.get_stonks() != List[i].get_stonks())
		{
			N = i + 1;
			break;
		}
	}

	std::cout << N;

	fin.close();

	return N;
}

void file_change(Rate_list*& List, int& size, bool kostil)
{
	int N = file_find(List, size) - 1;
	int n = 0;

	for (int i = 0; i < N; i++)
	{
		int a = strlen(List[i].get_name());

		n += a;

		a = strlen(List[i].get_surname());

		n += a;

		a = strlen(List[i].get_second_name());

		n += a;

		int b = List[i].get_grup_nomber();
		int f;

		for (f = 0; f == f; f++)
		{
			if (b % (int)pow(10, f) == b)
			{
				break;
			}
		}

		n += f;

		int g = List[i].get_stonks();
		int h;

		for (h = 0; h == h; h++)
		{
			if (g % (int)pow(10, h) == g)
			{
				break;
			}
		}

		n += h;

		double k = List[i].get_stonks();
		int y = k;
		int l;

		for (l = 0; l == l; l++)
		{
			if (y % (int)pow(10, l) == y)
			{
				break;
			}
		}
		n += l;

		n += 73;
	}

	int Length = n;

	std::fstream iofile("output.txt", std::ios::in | std::ios::out);

	iofile.seekg(Length, std::ios::beg);

	if (!kostil)
	{
		for (int i = 0; i < 7; i++)
		{
			iofile << "                                                  \n";
		}

		iofile.seekg(-364, std::ios::cur);
	}

	for (int t = N; t < size; t++)
	{
		if (t != N)
			iofile << std::endl;
		iofile << "Имя: ";
		iofile << List[t].get_name();
		iofile << std::endl;

		iofile << "Фамилия: ";
		iofile << List[t].get_surname();
		iofile << std::endl;

		iofile << "Отчество: ";
		iofile << List[t].get_second_name();
		iofile << std::endl;

		iofile << "Номер группы: ";
		iofile << List[t].get_grup_nomber();
		iofile << std::endl;

		iofile << "Средний балл: ";
		iofile << List[t].get_average();
		iofile << std::endl;

		iofile << "Доход: ";
		iofile << List[t].get_stonks();
		iofile << std::endl;
	}
}

