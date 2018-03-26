#include "stdafx.h"
#include <iostream>
#include <locale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int a = 8;
	const int path = a; //���������� ���������1
	cout << "path = " << path << endl;
	const int path_1 = a + 3; //���������� ���������2
	cout << "path_1 = " << path_1 << endl;
	float f = 2 * a + 1; //���������� ����������1 ������������� ����
	cout << "f = " << f << endl;
	float f_1 = a / 2; //���������� ����������2 ������������� ����
	cout << "f_1 = " << f_1 << endl;

	float *pr_f = &f;  //��������� �� ����������1
	int const *pr_n = &path; //��������� �� ���������1

	float *const fl_1 = &f_1; //����������� ��������� �� ����������2
	const int *const pr_n_n = &path; //����������� ��������� �� ���������


										  //1.��������� �� ������� ��������, �� ������� ��������� ��������� (��� ������� �������� ������ �������� � ������).
	(*pr_f)--; //��������, �.�. ��������� ��������� �� ����������
			   //(*ptr_con)--; //����������, �.�. ��������� ��������� �� ���������
	(*fl_1)--; //�������� �.�. ��������� ��������� �� ����������
			   //(*ptr_con_con)--; //����������, �.�. ��������� ��������� �� ���������
	cout << endl;

	//2.������� �� ����� ��������, �� ������� ��������� ������ ���������
	cout << "��������� �� ����������1 = " << *pr_f << endl;
	cout << "��������� �� ���������1 = " << *pr_n << endl;
	cout << "����������� ��������� �� ����������2 = " << *fl_1 << endl;
	cout << "����������� ��������� �� ���������1 = " << *pr_n_n;
	cout << endl;
	cout << endl;

	//3.�������� ����� ���������� (��� ������� ��� �������� � ������) �� ����� ���������2.
	//ptr_fl = &con_1; //����������, �.�. ��� const int* ����� ��������� ���� float*
	//ptr_fl_1 = &con_1; //����������, �.�. ��� ����������� ���������, ����� �������� �������� ������
	pr_n = &path; //��������, �.� ��������� �� �����������, �.�. ��� ����� ����� ��������
	cout << "pr_n = &path_1 = " << *pr_n << endl;
	//ptr_con_�on = &con_1; //����������, �.�. ��������� �������� ��� �����������, �.�. ����� �������� ������
	cout << endl;

	//4. �������� ����� ���������� (��� ������� ��� �������� � ������), 
	//�� ����� ����������� ���������� ������� ������ ��� ������ ������������ ���������� ������� ������ ��������
	//�� ��������� �� ���������.
	pr_f = new float[*pr_n]; //��������, �.�. ��������� ���� float* ����� ��������� �������� ���� float*
							 //ptr_fl_1 = new float[*ptr_con]; //����������, �.�. ��� ����������� ���������
							 //ptr_con = new float[*ptr_con];//����������, �.�. ��������� ���� const int* ���������� ���-������ �������� ���� float*
							 //ptr_con_�on = new float[*ptr_con]; //����������, �.�. ��� ����������� ��������� ���� const int*
	cout << endl;

	//5. ������������������ �������� ������� � ������� �������� ���������� ��������� (����������-���) 
	//���������, �� ������� ��������� ����������� ��������� �� ���������� ���� i / 2,
	//��� i ���������� ����� �������� �������.
	for (int i = 0; i < *pr_n; i++)
	{
		*(pr_f + i) = (float)(*pr_n) + (float)(i / 2);
	}
	cout << endl;

	//6. � ����� ��� �� � ������� ������������� ������� �������� ��������� ����������� ������� �� �����.
	for (int i = 0; i < *pr_n; i++)
	{
		cout << " " << *(pr_f + i);
	}
	cout << endl;

	//7. �������� ����� ��������� (��� �������� ��� ��������) �� ����� ��������� ���������� � �������.
	pr_f = &(*(pr_f + (*pr_n - 1)));
	cout << "pr_f = " << *pr_f << endl;
	//ptr_fl_1 = &(*(ptr_fl + (*ptr_con))); //����������, �.�. ��� ����������� ���������
	//ptr_con = &(*(ptr_fl + (*ptr_con))); //����������, �.�. �������� ���� const int* ������ ��������� �������� ���� float*
	//ptr_con_�on = &(*(ptr_fl + (*ptr_con))); //����������, �.�. ��� ����������� ���������
	cout << endl;

	//8. �������� ��������� ������� �������, � �������� � ���� ����� ���������, �� ������ ������-�� 
	//��������� ���������� ��������.
	float **ptr_max = &pr_f;
	cout << endl;

	//9. ������� �� ����� ��������, ������� ��������� �� ��������� ������� �������.
	cout << **ptr_max;
	cout << endl;
	system("pause");
	return 0;
}