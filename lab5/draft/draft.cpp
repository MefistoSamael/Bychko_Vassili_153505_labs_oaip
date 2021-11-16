#include <iostream>
using namespace std;

int Foo(int &a)
 {
	if (a < 1) 
		return 0;
	a--;
	cout << a << endl;
	return Foo(a);
	cout << endl << "gigigig";
}


int main()
{
	setlocale(LC_ALL, "rus");
	int a = 5;
	Foo(a);
	cout << "a = " << a;

}

