#include <iostream>
using namespace std;

int razryad(int a, int i)
{
    return ((a % (int)pow(10, i))) / pow(10, i - 1);
}

int to3(int a)
{
    int stepen = -1;

    for (int i = 0; ; i++)
    {
        if (a < pow(3, i))
        {
            stepen = i - 1;
            break;
        }
    }

    int sum = 0;

    for (int i = stepen; i >= 0; i--)
    {
        for (int j = 0; j <= 3; j++)
        {
            if (a < j * pow(3, i))
            {
                j--;
                sum += j * pow(10, i);
                a -= j * pow(3, i);
                break;
            }
        }
    }

    return sum;

}

void check(int* array, int a, int b, int c)
{
    for (int i = 0; i < 241; i++)
    {
        int i3 = to3(i);
        int razrish = 4;
        bool iseq = true;


        for (int i = 1; i <= 5; i++, razrish--)
        {
            int l = razryad(i3, i);

            if (array[razrish] == a && array[razrish] != l) //l разярд бочки
            {
                iseq = false;
                break;
            }
            if (array[razrish] == b && array[razrish] != l)
            {
                iseq = false;
                break;
            }
            if (array[razrish] == c && array[razrish] != l)
            {
                iseq = false;
                break;
            }
        }
        if (iseq)
        {
            cout << i << " ";
        }
    }
}


int main()
{
    int poisnbarrel;
    cout << "Enter numb of poisned barrel ";
    cin >> poisnbarrel;

    int poisnbarrel3 = to3(poisnbarrel);

    int* array = (int*)calloc(5, sizeof(int));



    int j = 4;

    for (int i = 1; i <= 5; i++, j--)
    {
        array[j] = razryad(poisnbarrel3, i);
    }


    cout << "Probably poisned barrels after 24h: " << std::endl;
    check(array, 0, 0, 0);
    cout << endl;

    cout << "Probably poisned barrels after 48h: " << std::endl;
    check(array, 0, 0, 1);
    cout << endl;

    cout << "Poisned barrel: " << std::endl;
    check(array, 0, 1, 2);


    free(array);

    return 0;
}