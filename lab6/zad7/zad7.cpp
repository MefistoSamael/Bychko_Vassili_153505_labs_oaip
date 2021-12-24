#include <iostream>
using namespace std;
int main()
{
	char str[106];
	cout << "Enter string " << endl;
	cin.getline(str, 105);
	int length = 0;

	for (int i = 0; i < strlen(str) - 2; i++)
	{
		for (int g = strlen(str) - 1; g != i; g--)
		{
			if (str[i] != str[g])
			{
				if (strlen(str) - 1 - i > length)
				{
					length = strlen(str) - 1 - i;
				}
				break;
			}
		}
	}

	if (length == 0)
	{
		length = -1;
	}
	cout << "Max length of polyndrome =  " << length;

	return 0;
}

//aaaaaaaaaaaaab - 13
//baaaaaaaaaaaaa - 13