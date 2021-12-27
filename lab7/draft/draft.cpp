#include <iostream>
#include <string>

using namespace std;

int main() {
	string mas;

	int x;
	cin >> x;

	if (x > 10) {
		x += 2;
	}

	while (x > 0) {
		mas = char((x % 2) + 48) + mas;
		x /= 2;
	}

	cout << mas << endl;

}