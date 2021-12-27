#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "Enter repeating numbers ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{

		int numb;
		cout << "Enter number ";
		cin >> numb;
		int answer = 0;
		answer = numb / 10;
		if (numb % 10 == 9) answer++;
		cout << "Numb of interesting numbers = " << answer<< endl;
	}

	return 0;
}
