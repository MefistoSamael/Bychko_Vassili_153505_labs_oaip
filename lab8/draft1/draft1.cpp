// Task_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <malloc.h>
#include <fstream>
#include <filesystem>
using namespace std;


class database
{
private:

    string surname;
    string name;
    string second_name;
    int nomer;
    int chas_of_mes;
    int tarif;

public:

    string get_sername()
    {
        return surname;
    }
    void set_sername(string Surname)
    {
        surname = Surname;
    }

    string get_name()
    {
        return name;
    }
    void set_name(string Name)
    {
        name = Name;
    }

    string get_secondname()
    {
        return second_name;
    }
    void set_secondname(string Secondname)
    {
        second_name = Secondname;
    }

    int get_nomer()
    {
        return nomer;
    }
    void set_nomer(int Nomer)
    {
        nomer = Nomer;
    }

    int get_chas_of_mes()
    {
        return chas_of_mes;
    }
    void set_chas_of_mes(int Chas_of_mes)
    {
        chas_of_mes = Chas_of_mes;
    }

    int get_tarif()
    {
        return tarif;
    }
    void set_tarif(int Tarif)
    {
        tarif = Tarif;
    }
};

char menu();
void input(database*& dataa, int i);
void enter(database*& dataa, int& size);
void display(database*& dataa, int& size);
void enterpriz(database*& dataa, int& size);
void poisk(database*& dataa, int& size);
void obnov(database*& dataa, int& size);
void delet(database*& dataa, int& size);
void deletee(database*& dataa, int& size);
void swapp(database*& dataa, int i, int j);
void display_plat(database*& dataa, int& size);
void shekerSort(database dataa[], int& size);
void write_fail(database*& dataa, int& size);
void file_enter(database*& dataa, int& size);
int razryad(int n);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ofstream foutt("outputfinish.txt");

    int size = 0;

    database* dataa = new database[0];
    file_enter(dataa, size);

    char choise;

    for (;;)
    {

        choise = menu();

        switch (choise)
        {
        case 'a':
            enter(dataa, size);
            write_fail(dataa, size);
            break;
        case 'b':
            //enterpriz(dataa, size);
            //write_fail(dataa, size);
            break;
        case 'c':
            delet(dataa, size);
            // write_fail(dataa, size);
            break;
        case 'd':
            obnov(dataa, size);
            // write_fail(dataa, size);
            break;
        case 'e':
            display(dataa, size);
            break;
        case'f':
            shekerSort(dataa, size);
            printf("%s", "\nБаза данных отсортирована!)\n");
            write_fail(dataa, size);
            break;
        case 'z':
            system("cls");

            for (int i = 0; i < size; i++)
            {
                foutt << "Фамилия: " << dataa[i].get_sername() << endl;
                foutt << "Имя: " << dataa[i].get_name() << endl;
                foutt << "Отчесвто: " << dataa[i].get_secondname() << endl;
                foutt << "Табельный номер: " << dataa[i].get_nomer() << endl;
                foutt << "количество отработанных часов за месяц: " << dataa[i].get_chas_of_mes() << endl;
                foutt << "почасовой тариф: " << dataa[i].get_tarif() << endl;
            }
            foutt.close();

            delete[] dataa;
            return 0;
            break;
        case 'g':
            poisk(dataa, size);
            break;
        case 'h':
            display_plat(dataa, size);
            break;
        case 'l':
            system("cls");
            break;
        case'j':
            cout << "\nБаза данных очищена\n";
            deletee(dataa, size);
            write_fail(dataa, size);
            break;
        }
    }
}

char menu()
{
    char ch;

    cout << '\n';

    do
    {
        printf("%s", "A-Введите информацию о сотруднике\n");
        printf("%s", "B-Вводите информацию о команде до появления признака////// \n");
        printf("%s", "C- Удалить информацию о сотруднике\n");
        printf("%s", "D-редактировать информацию о сотруднике\n");
        printf("%s", "E-Показать информацию о сотрудниках\n");
        printf("%s", "F-Отсортировать по зарплате сотрудников\n");
        printf("%s", "G-Показать информацию о сотруднике по признаку\n");
        printf("%s", "H- Вывести по возрастанию размер заработной платы  сотрудников\n");
        printf("%s", "J-Удалить базу данных\n");
        printf("%s", "L-очистить экран\n");
        printf("%s", "Z-Выход из программы\n");

        cout << endl;

        cout << "Выбирите команду : ";
        cin >> ch;
    } while (!strchr("abcdefzghjl", tolower(ch)));

    return tolower(ch);
}

void enter(database*& dataa, int& size)
{
    int dop, start = size;

    cout << "Введите колличество сотруднико : ";

    bool good = true;
    while (good)
    {
        good = false;
        cin >> dop;
        if (cin.fail())
        {
            good = true;
            cout << "\nВведены неверные данные,повторите попытку:\n";

            cin.clear();
            cin.ignore(32676, '\n');
        }
    }

    database* newdataa = new database[size + dop];

    for (int i = 0; i < size; i++)
    {
        newdataa[i] = dataa[i];
    }
    size += dop;

    delete[] dataa;

    dataa = newdataa;

    for (start; start < size; start++)
    {
        input(dataa, start);
    }
}

void input(database*& dataa, int i)
{
    bool good = true;
    cout << "Фамилия:	";
    string Sername;
    cin >> Sername;
    dataa[i].set_sername(Sername);

    cout << "Имя:	";
    string Name;
    cin >> Name;
    dataa[i].set_name(Name);

    cout << "Отчество:	";
    string Second_name;
    cin >> Second_name;
    dataa[i].set_secondname(Second_name);

    cout << "Табельный номер: ";
    good = true;
    int Nomer;
    while (good)
    {
        good = false;
        cin >> Nomer;;
        if (cin.fail())
        {
            good = true;
            cout << "\nВведены неверные данные,повторите попытку:\n";

            cin.clear();
            cin.ignore(32676, '\n');
        }
    }
    cout << endl;
    dataa[i].set_nomer(Nomer);

    cout << "количество отработанных часов за месяц: ";
    good = true;
    int chas;
    while (good)
    {
        good = false;
        cin >> chas;;
        if (cin.fail())
        {
            good = true;
            cout << "\nВведены неверные данные,повторите попытку:\n";

            cin.clear();
            cin.ignore(32676, '\n');
        }
    }
    cout << endl;
    dataa[i].set_chas_of_mes(chas);

    cout << "почасовой тариф: ";
    good = true;
    int Tarif;
    while (good)
    {
        good = false;
        cin >> Tarif;
        if (cin.fail())
        {
            good = true;
            cout << "\nВведены неверные данные,повторите попытку:\n";

            cin.clear();
            cin.ignore(32676, '\n');
        }
    }
    cout << endl;
    dataa[i].set_tarif(Tarif);
}

void display(database*& dataa, int& size)
{
    if (size == 0)
        cout << "\nБаза данных пуста\n";
    for (int i = 0; i < size; i++)
    {
        cout << endl;
        cout << endl;
        cout << "Фамилия: " << dataa[i].get_sername() << endl;
        cout << "Имя: " << dataa[i].get_name() << endl;
        cout << "Отчесвто: " << dataa[i].get_secondname() << endl;
        cout << "Табельный номер: " << dataa[i].get_nomer() << endl;
        cout << "количество отработанных часов за месяц: " << dataa[i].get_chas_of_mes() << endl;
        cout << "почасовой тариф: " << dataa[i].get_tarif() << endl;
        cout << "Размер заработной платы сотрудника: " << dataa[i].get_tarif() * dataa[i].get_chas_of_mes();
        cout << endl;
    }
}

void display(database*& dataa, int i, int k)
{
    cout << endl;
    cout << endl;
    cout << "Фамилия: " << dataa[i].get_sername() << endl;
    cout << "Имя: " << dataa[i].get_name() << endl;
    cout << "Отчесвто: " << dataa[i].get_secondname() << endl;
    cout << "Табельный номер: " << dataa[i].get_nomer() << endl;
    cout << "количество отработанных часов за месяц: " << dataa[i].get_chas_of_mes() << endl;
    cout << "почасовой тариф: " << dataa[i].get_tarif() << endl;
    cout << endl;
}

void poisk(database*& dataa, int& size)
{
    int k = 0;
    string s;
    cout << "Введите по какому признаку будем искать : ";

    while (true)
    {
    a:
        cin >> s;

        if (s == "имя")
        {
            string l;
            cout << "Введите до чего будем искать :\n";
            cin >> l;

            int i;

            for (i = 0; i < size; i++)
            {
                if (l == dataa[i].get_name())
                {
                    display(dataa, i, k);
                    break;
                }

            }

            if (i == size)
                cout << "\nТакого сотрудника нет\n";
        }
        else if (s == "фамилия")
        {
            string l;
            cout << "Введите до чего будем искать :\n";
            cin >> l;

            int i;

            for (i = 0; i < size; i++)
            {
                if (l == dataa[i].get_sername())
                {
                    display(dataa, i, k);
                    break;
                }

            }

            if (i == size)
                cout << "\nТакого сотрудника нет\n";
        }
        else if (s == "отчество")
        {
            string l;
            cout << "Введите до чего будем искать :\n";
            cin >> l;

            int i;

            for (i = 0; i < size; i++)
            {
                if (l == dataa[i].get_secondname())
                {
                    display(dataa, i, k);
                    break;
                }

            }

            if (i == size)
                cout << "\nТакого сотрудника нет\n";
        }
        else if (s == "табельный номер")
        {
            int l;
            cout << "Введите до чего будем искать :\n";
            cin >> l;

            int i;

            for (i = 0; i < size; i++)
            {
                if (l == dataa[i].get_nomer())
                {
                    display(dataa, i, k);
                    break;
                }

            }

            if (i == size)
                cout << "\nТакого сотрудника нет\n";
        }
        else if (s == "количество отработанных часов за месяц")
        {
            int l;
            cout << "Введите до чего будем искать :\n";
            cin >> l;

            int i;

            for (i = 0; i < size; i++)
            {
                if (l == dataa[i].get_chas_of_mes())
                {
                    display(dataa, i, k);
                    break;
                }

            }

            if (i == size)
                cout << "\nТакого сотрудника нет\n";
        }
        else if (s == "тариф")
        {
            int l;
            cout << "Введите до чего будем искать :\n";
            cin >> l;

            int i;

            for (i = 0; i < size; i++)
            {
                if (l == dataa[i].get_tarif())
                {
                    display(dataa, i, k);
                    break;
                }

            }

            if (i == size)
                cout << "\nТакого сотрудника нет\n";
        }
        else
        {

            cout << "Ошибка ввода,повторите попытку : ";
            goto a;
        }
        break;
    }
}

void obnov(database*& dataa, int& size)
{
    string s;

    cout << "Введите фамилию сотрудника,информация про которого вы хотите изменить : ";
    cin >> s;

    int i;
    for (i = 0; i < size; i++)
    {
        if (s == dataa[i].get_sername())
            break;
    }

    if (i == size)
    {
        cout << "\nтакого человека нет)\n";
        return;
    }

    cout << "Введите новые значения :\n";
    input(dataa, i);
    ofstream fout("output.txt"/*, ios_base::app*/, ios::binary | ios::out | ios::in);
    fout.seekp(i * 6 * 52, ios::beg);
    fout << "Фамилия: " << dataa[i].get_sername();
    for (int j = 9 + dataa[i].get_sername().size(); j < 50; ++j)
    {
        fout << ' ';
    }
    //fout << '\n';
    fout.seekp(i * 6 * 52 + 52, ios::beg);
    fout << "Имя: " << dataa[i].get_name();
    for (int j = 5 + dataa[i].get_name().size(); j < 50; ++j)
    {
        fout << ' ';
    }
    //fout << '\n';
    fout.seekp(i * 6 * 52 + 52 * 2, ios::beg);
    fout << "Отчесвто: " << dataa[i].get_secondname();
    for (int j = 10 + dataa[i].get_secondname().size(); j < 50; ++j)
    {
        fout << ' ';
    }
    //fout << '\n';
    fout.seekp(i * 6 * 52 + 52 * 3, ios::beg);
    fout << "Табельный номер: " << dataa[i].get_nomer();
    int n = razryad(dataa[i].get_nomer());
    for (int j = 17 + n; j < 50; ++j)
    {
        fout << ' ';
    }
    //fout << '\n';
    fout.seekp(i * 6 * 52 + 52 * 4, ios::beg);
    fout << "количество отработанных часов за месяц: " << dataa[i].get_chas_of_mes();
    n = razryad(dataa[i].get_chas_of_mes());
    for (int j = 40 + n; j < 50; ++j) {
        fout << ' ';
    }
    //fout << '\n';
    fout.seekp(i * 6 * 52 + 52 * 5, ios::beg);
    fout << "почасовой тариф: " << dataa[i].get_tarif();
    n = razryad(dataa[i].get_tarif());
    for (int j = 17 + n; j < 50; ++j) {
        fout << ' ';
    }
    //fout << '\n';
    //fout << "loh";
    //fout.close();
    //int k;
    //cin >> k;
}

void delet(database*& dataa, int& size)
{
    int k = 0;
    string s;

    cout << "Введите фамилию сотрудника,информация про которого вы хотите удалить : ";
    cin >> s;

    if (size == 0)
    {
        cout << "\nНет элементов для удаления,База данных пуста\n";
        return;
    }

    database* newdata = new database[size - 1];

    for (int i = 0; i < size; i++)
    {
        if (dataa[i].get_sername() != s)
        {
            k++;
        }
    }

    if (k == size)
    {
        cout << "\nТакой команды нет!\n";
        return;
    }

    ofstream fout("output.txt", ios_base::app);
    int a;
    for (int i = 0, j = 0; i < size; i++)
    {
        if (dataa[i].get_sername() != s)
        {
            newdata[j] = dataa[i];
            j++;
        }
        else
        {
            a = i;
        }
    }
    size--;
    filesystem::resize_file("output.txt", 52 * 6 * a);
    for (int i = a; i < size; i++) {
        fout << "Фамилия: " << newdata[i].get_sername();
        for (int j = 9 + newdata[i].get_sername().size(); j < 50; ++j) {
            fout << ' ';
        }
        fout << '\n';
        fout << "Имя: " << newdata[i].get_name();
        for (int j = 5 + newdata[i].get_name().size(); j < 50; ++j) {
            fout << ' ';
        }
        fout << '\n';
        fout << "Отчесвто: " << newdata[i].get_secondname();
        for (int j = 10 + newdata[i].get_secondname().size(); j < 50; ++j) {
            fout << ' ';
        }
        fout << '\n';
        fout << "Табельный номер: " << newdata[i].get_nomer();
        int n = razryad(newdata[i].get_nomer());
        for (int j = 17 + n; j < 50; ++j) {
            fout << ' ';
        }
        fout << '\n';
        fout << "количество отработанных часов за месяц: " << newdata[i].get_chas_of_mes();
        n = razryad(newdata[i].get_chas_of_mes());
        for (int j = 40 + n; j < 50; ++j) {
            fout << ' ';
        }
        fout << '\n';
        fout << "почасовой тариф: " << newdata[i].get_tarif();
        n = razryad(newdata[i].get_tarif());
        for (int j = 17 + n; j < 50; ++j) {
            fout << ' ';
        }
        fout << '\n';
    }

    delete[] dataa;

    dataa = newdata;
}

void deletee(database*& dataa, int& size)
{
    delete[] dataa; //free(dataa);
    size = 0;
    dataa = {};
}

void shekerSort(database dataa[], int& size)
{

    int left = 0, right = size - 1;
    int flag = 1;
    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i < right; i++)
        {
            if (dataa[i].get_tarif() * dataa[i].get_chas_of_mes() > dataa[i + 1].get_tarif() * dataa[i + 1].get_chas_of_mes())
            {
                swapp(dataa, i, i + 1);
                flag = 1;
            }
        }
        right--;
        for (int i = right; i > left; i--)
        {
            if (dataa[i - 1].get_tarif() * dataa[i - 1].get_chas_of_mes() > dataa[i].get_tarif() * dataa[i].get_chas_of_mes())
            {
                swapp(dataa, i - 1, i);
                flag = 1;
            }
        }
        left++;
    }
}

void swapp(database*& dataa, int i, int j)
{
    string bufer_name;
    string bufer_sername;
    string bufer_secondname;
    int bufer_nomer;
    int bufer_chas;
    int bufer_tarif;


    bufer_name = dataa[i].get_name();
    dataa[i].set_name(dataa[j].get_name());
    dataa[j].set_name(bufer_name);

    bufer_sername = dataa[i].get_sername();
    dataa[i].set_sername(dataa[j].get_sername());
    dataa[j].set_sername(bufer_sername);

    bufer_secondname = dataa[i].get_secondname();
    dataa[i].set_secondname(dataa[j].get_secondname());
    dataa[j].set_secondname(bufer_secondname);


    bufer_nomer = dataa[i].get_nomer();
    dataa[i].set_nomer(dataa[j].get_nomer());
    dataa[i].set_nomer(bufer_nomer);

    bufer_chas = dataa[i].get_chas_of_mes();
    dataa[i].set_chas_of_mes(dataa[j].get_chas_of_mes());
    dataa[j].set_chas_of_mes(bufer_chas);

    bufer_tarif = dataa[i].get_tarif();
    dataa[i].set_tarif(dataa[j].get_tarif());
    dataa[j].set_tarif(bufer_tarif);
}

void display_molod(database*& dataa, int& size)
{
    int k = 0;
    if (size == 0)
    {
        cout << "\nБаза данных пуста\n";
        return;
    }
    else if (size >= 2)
        shekerSort(dataa, size);

    display(dataa, 0, k);
}

void display_plat(database*& dataa, int& size)
{
    if (size == 0)
    {
        cout << "Список пуст";
        return;
    }
    shekerSort(dataa, size);
    int i, k = 0;
    for (i = 0; i < size; i++)
    {

        cout << endl;
        cout << "Фамилия: " << dataa[i].get_sername() << endl;
        cout << "Размер заработной платы сотрудника: " << dataa[i].get_tarif() * dataa[i].get_chas_of_mes() << endl;
        cout << endl;
    }
}

void write_fail(database*& dataa, int& size)
{
    ofstream fout("output.txt");

    for (int i = 0; i < size; i++)
    {
        fout << "Фамилия: " << dataa[i].get_sername();
        for (int j = 9 + dataa[i].get_sername().size(); j < 50; ++j) {
            fout << ' ';
        }
        fout << '\n';
        fout << "Имя: " << dataa[i].get_name();
        for (int j = 5 + dataa[i].get_name().size(); j < 50; ++j) {
            fout << ' ';
        }
        fout << '\n';
        fout << "Отчесвто: " << dataa[i].get_secondname();
        for (int j = 10 + dataa[i].get_secondname().size(); j < 50; ++j) {
            fout << ' ';
        }
        fout << '\n';
        fout << "Табельный номер: " << dataa[i].get_nomer();
        int n = razryad(dataa[i].get_nomer());
        for (int j = 17 + n; j < 50; ++j) {
            fout << ' ';
        }
        fout << '\n';
        fout << "количество отработанных часов за месяц: " << dataa[i].get_chas_of_mes();
        n = razryad(dataa[i].get_chas_of_mes());
        for (int j = 40 + n; j < 50; ++j) {
            fout << ' ';
        }
        fout << '\n';
        fout << "почасовой тариф: " << dataa[i].get_tarif();
        n = razryad(dataa[i].get_tarif());
        for (int j = 17 + n; j < 50; ++j) {
            fout << ' ';
        }
        fout << '\n';
    }
    fout.close();
}

int razryad(int n) {
    int sum = 0;
    while (n) {
        n /= 10;
        ++sum;
    }
    return sum;
}

void file_enter(database*& dataa, int& size)
{
    ifstream fin("input.txt");

    int dop = 0, start = size;

    fin >> dop;

    database* newdata = new database[size + dop];

    for (int i = 0; i < size; i++)
    {
        newdata[i] = dataa[i];
    }

    size += dop;

    //delete[]List;

    delete[] dataa;

    dataa = newdata;

    string s;
    for (start; start < size; start++)
    {

        fin >> s;
        dataa[start].set_sername(s);

        //fin >> dataa[start].get_name();

       // fin >> dataa[start].get_secondname();

        //fin >> dataa[start].get_nomer();

       // fin >> dataa[start].get_chas_of_mes();

       // fin >> dataa[start].get_tarif();
    }
}

