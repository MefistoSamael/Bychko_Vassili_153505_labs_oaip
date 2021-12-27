#include "pch.h"

int razryad(int a, int i)
{
    return ((a % (int)pow(10, i))) / pow(10, i - 1);
}

int to3(int poisnbarrel)
{
    int stepen = -1;

    for (int i = 0; i < i + 1; i++)
    {
        if (poisnbarrel < pow(3, i))
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
            if (poisnbarrel < j * pow(3, i))
            {
                j--;
                sum += j * pow(10, i);
                poisnbarrel -= j * pow(3, i);
                break;
            }
        }
    }

    return sum;

}

int check(int* array, int a, int b, int c)
{
    for (int i = 0; i < 241; i++)
    {
        int i3 = to3(i);
        int razrish = 4;
        bool iseq = true;


        for (int i = 1; i <= 5; i++, razrish--)
        {
            int l = razryad(i3, i);

            if (array[razrish] == a && array[razrish] != l) //l раз€рд бочки
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
            return i;
        }
    }
}



TEST(TestCaseName, 1) {
    bool V = 1;
    int input = 238;

    int poisnbarrel3 = to3(input);

    int* array = (int*)calloc(5, sizeof(int));



    int j = 4;

    for (int i = 1; i <= 5; i++, j--)
    {
        array[j] = razryad(poisnbarrel3, i);
    }
    int res = check(array, 0, 1, 2);
    int test = 238;
    if (test != res) V = 0;



    EXPECT_TRUE(V);
}

TEST(TestCaseName, 2) {
    bool V = 1;
    int input = 240;

    int poisnbarrel3 = to3(input);

    int* array = (int*)calloc(5, sizeof(int));



    int j = 4;

    for (int i = 1; i <= 5; i++, j--)
    {
        array[j] = razryad(poisnbarrel3, i);
    }
    int res = check(array, 0, 1, 2);
    int test = 240;
    if (test != res) V = 0;



    EXPECT_TRUE(V);
}

TEST(TestCaseName, 3) {
    bool V = 1;
    int input = 15;

    int poisnbarrel3 = to3(input);

    int* array = (int*)calloc(5, sizeof(int));



    int j = 4;

    for (int i = 1; i <= 5; i++, j--)
    {
        array[j] = razryad(poisnbarrel3, i);
    }
    int res = check(array, 0, 1, 2);
    int test = 15;
    if (test != res) V = 0;



    EXPECT_TRUE(V);
}