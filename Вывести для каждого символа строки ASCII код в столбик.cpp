#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "russian");

	char str[15];
	cout << "¬ведите строку: ";
	cin.getline(str,15);
	const size_t N = sizeof(str);
	int i=0;
	while (str[i] != '\0')
	{
		bool flag = true;
		for (int j = 0; j < i; j++) {
			if (str[j] == str[i]) flag = false;
		}
		if (flag) cout << str[i] << "->" << (int)str[i] << endl;
		i++;
	}
	
	system("pause");

	return 0;
}