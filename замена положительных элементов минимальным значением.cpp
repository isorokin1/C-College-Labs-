#include "stdafx.h"
#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	int a[10], min;
	int n = 0;
	cout << "Введите  массив: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n - i; ++i)
	{
		for (int j = i + 1; j < n - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	min = a[0];
	for (int i = 0; i < 10; i++)
		if (a[i] < min) min = a[i];
	cout << endl << "Минимальное число = " << min << endl << "Получившийся массив: ";
	for (int i = 0; i < 10; i++) {
		if (a[i] > 0) a[i] = min;
		cout << a[i] << " ";
	}
     system("pause");
	return 0;
}