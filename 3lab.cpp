#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

void cyclic_shift_r(double **Neo, int line, int column, int n)
{
	for (int k = 0; k < abs(n); k++) {	
		for (int i = 0; i < line; i++) {
			if (n<0)
			for (int j = 0 ; j < column-1; j++) {
				int tmp= Neo[i][j];
				Neo[i][j]=Neo[i][j+1];
				Neo[i][j+1]=tmp;
			}
			
			else
				for (int j = column-1 ; j > 0; j--) {
				int tmp= Neo[i][j];
				Neo[i][j]=Neo[i][j-1];
				Neo[i][j-1]=tmp;
			
			}
		}
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int line, column, n;
	cout << "Введите количество строк: ";
	cin >> line;
	cout << "Введите количество столбцов: ";
	cin >> column;
	double **Neo = new double *[line];
	cout << "\n" << "Ввод матрицы..." << "\n\n";
	for (int i = 0; i < line; i++,cout<<endl)
	{
		Neo[i] = new double[column];
		
		for (int j = 0; j < column; j++)
		{
			Neo[i][j] = rand() % 100;
			cout<<Neo[i][j];
			cout<<"\t";
		}
	}
	
	cout << "Сдвинуть на... " ;
	cin >> n;
 	cyclic_shift_r(Neo, line, column, n);
	cout << "\n" << " Вывод сдвинутой матрицы..." << "\n\n";
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {

			cout << "\t" << Neo[i][j];
		}
		cout << "\n";
	}
	delete[] Neo;
	system("pause");
	return 0;
}