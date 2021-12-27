#include "pch.h"
#define  ull unsigned long long
unsigned long long tonumb(unsigned long long numb, int* ten, int N)
{
    unsigned long long num = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        num++;
        if (numb < 2)
        {
            ten[i] = numb;
            break;
        }
        ten[i] = numb % 2;
        numb /= 2;
    }
    return num;
}
bool to2(int* ten, int* d2, int* pam, int N, int M, unsigned long long n)
{
    int* temp = (int*)calloc(301, sizeof(int));
    bool test = 1;
    int k = 0, j = N - 1, z = n;
    int dv = M - 1;
    while (n != 0)
    {
        if (ten[N - 1] % 2 != 0)
        {
            ten[N - 1]--;
            d2[dv] = 1;
            dv--;
        }
        else
        {
            d2[dv] = 0;
            dv--;
        }
        if (j >= N - z && d2[dv + 1] != pam[j]) test = 0;
        j--;
        for (int i = N - n, p = N - n; i < N; i++)
        {
            k += ten[i];
            if (k < 2)
            {
                if (i == N - 1 && k == 0)
                {
                    if (i == N - n)
                    {
                        ten[i] = 0;
                        n--;
                    }
                    temp[p] = 0;
                    continue;
                }
                if (i == N - n)
                {
                    ten[i] = 0;
                    n--;
                }
                temp[p] = 0;
                p++;
                k *= 10;
                continue;
            }
            int t = k % 2;
            temp[p] = (k - t) / 2;

            if (t) k = 10;
            else k = 0;
            p++;
        }
        for (int u = N - n; u < N; u++)
        {
            ten[u] = temp[u];
        }
    }

    delete[]temp;
    return test;
}
bool func(int p, int* itog)
{
    bool test = 1;
    unsigned long long i;
    int N = 301, M = 501;
    int* ten = (int*)malloc(301 * sizeof(int));
    for (int i = 0; i < 301; i++)
    {
        ten[i] = 0;
    }
    int* memr = (int*)malloc(301 * sizeof(int));
    for (int i = 0; i < 301; i++)
    {
        memr[i] = 0;
    }
    int* d2 = (int*)malloc(501 * sizeof(int));
    for (int i = 0; i < 301; i++)
    {
        d2[i] = 0;
    }
    for (int i = 0, z = 0; z <= 10000; i += 2)
    {
        unsigned long long n = tonumb(i, ten, N);
        for (int m = N - n; m < N; m++)
        {
            memr[m] = ten[m];
        }
        bool o = to2(ten, d2, memr, N, M, n);
        if (o)
        {
            if (z == p || z == p - 1)
            {
                if (z == p - 1) memr[N - 1] = 1;
                for (int m = N - n, v = 0; m < N; m++, v++)
                {
                    if (memr[m] != itog[v]) test = 0;
                }
                break;
            }
            z += 2;
        }
    }
    delete[]ten;
    delete[]d2;
    return test;
}
TEST(TestCaseName, 1) {
    int input = 11;
    int itog[4] = { 1,1,0,1 };
    bool Z = func(input, itog);
    EXPECT_TRUE(Z);
}
TEST(TestCaseName, 2) {
    int input = 1;
    int itog[1] = { 1 };
    bool Z = func(input, itog);
    EXPECT_TRUE(Z);
}
TEST(TestCaseName, 3) {
    int input = 3;
    int itog[2] = { 1,1 };
    bool Z = func(input, itog);
    EXPECT_TRUE(Z);
}
TEST(TestCaseName, 4) {
    int input = 299;
    int itog[19] = { 1,0,1,0,1,1,1,0,1,1,0,1,1,0,0,0,0,0,1 };
    bool Z = func(input, itog);
    EXPECT_TRUE(Z);
}