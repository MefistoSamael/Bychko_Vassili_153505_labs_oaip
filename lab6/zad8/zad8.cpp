#include <iostream>
using namespace std;
int main()
{
	int N = 0;
	cout << "Enter N :";
	cin >> N;
	cin.ignore(1);

	for (int r = 0; r < N; r++)
	{
		cout << "Enter string s:";
			char s[501];
		cin.getline(s, 500);
		char t[999];
		cout << "Enter string t:";
			cin.getline(t, 999);
		if (strlen(t) > 2 * strlen(s) - 1)
		{
			cout << "No";
			break;
		}
		else
		{
			bool A = true; //���������� ������
			bool B = true; //���� � ���� �� �����
			bool C = true; //���� �������� �� ����
			int lenS = 0;
			int lenT = 0;
			lenS = strlen(s);
			lenT = strlen(t);
			int m = 0;

			for (int i = 0; i < lenS; i++)
			{
				if (s[i] == t[0])
				{
					C = false;
					for (int h = 0; h < lenT; h++) //h ������� ���� ������
					{
						B = false;
						
						if (i + 2 * h - lenT + 1 >= 0 && i + h < lenS) //����� �� ����
						{
							B = true;
							for (int d = i; d <= i + h; d++, m++) //��� ������
							{
								if (s[d] != t[m]) A = false; //�����
							}

							if (!A) break;
							m--;

							for (int g = i + h; g > i + 2 * h - lenT; g--, m++) //��� �����
							{
								if (s[g] != t[m] && m < lenT) A = false; //�����
							}

							if (i + 2 * h - lenT + 1 < 0)A = false; // 2h - lenT + 1 - ��� ���������
							m = 0;

							if (A)break;

							A = true;
						}
					}
					if (!B) A = false;
					if (A) break;
				}
			}
			if (C) A = false;
			if (A == true) cout << "Yes";
			else cout << "No";
			cout << lenT << " " << lenS;
		}
	}

	return 0;
}