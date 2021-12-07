#include <iostream>
using namespace std;
int main()
{
	int t = 0;
	cout << "Enter numb of data ";
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		long long answer = 0;
		cout << "Enter length of main string ";
		int mainlen = 0;
		cin >> mainlen;
		cout << "Enter precision of calculations ";
		int prec = 0;
		cin >> prec;
		char* suf = (char*)calloc(200, sizeof(char));
		cout << "Enter string with suf ";
		cin.getline(suf, 199);
		cout << "Enter string with pref ";
		char* pref = (char*)calloc(200, sizeof(char));
		cin.getline(pref, 199);
		if (strlen(pref) + strlen(suf) < mainlen)
		{
			answer = pow(26, mainlen - strlen(pref) - strlen(suf));
			answer %= prec;
		}
		if (strlen(pref) + strlen(suf) == mainlen)
		{
			answer = 2;
		}

	}               

	return 0;
}