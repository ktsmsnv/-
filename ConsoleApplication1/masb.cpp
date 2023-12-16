#include  "masb.h"
#define NOMINMAX
#include  <iostream>
#include  <limits>
#include  <fstream>
#include  <cstdlib>
#include  <string>
#include  <iomanip>
#include  <conio.h>
#include  <Windows.h>
#include  <sstream>

#include  "struct.h"
#include  "exception.h"
#include  "masa.h"
using namespace std;
masB::masB(masB& z)
try : masA(z) //����������� ����������� ������ masB
{
	int i;
	k = z.k;
	if (z.mas == NULL) mas = NULL;
	else {
		try {
			mas = new PLATAA[k];
			throw bad_alloc();
		}
		catch (bad_alloc)                     //   ���������� ��� �������� ������
		{
			mas = NULL; n = 0;
			throw ErrMem("��� ������", "���. ������� (mas)", "����������� ����������� masB");
		}

		if (mas == NULL) {
			cout << "��� ������.\n";
			cout << "����������� �����������.\n";
			system("pause"); exit(1);
		}
		for (i = 0; i < k; i++)
			mas[i] = z.mas[i];
	}
}
catch (ErrMem& ex) { throw ErrMem(ex.getMes(), ex.getMes1(), "masB(masB &z)"); }

masB& masB :: operator= (masA& z) //������������� �������� �����������
{
	int i;
	masB  r;
	if (this == &z) return *this;
	// ����� ������������� �������� ������������ ������ mas� ��� 
	masA :: operator=(z);  // ������������ ������������ ����� ������� z
	r = (masB&)z;                 //  ���������� ������������
	if (mas != NULL) delete[] mas;
	k = r.k;
	if (r.mas == NULL) mas = NULL;
	else {
		try {
			mas = new PLATAA[k];
			//throw bad_alloc();
		}
		catch (bad_alloc)
		{
			throw ErrMem("��� ������", "������� (py)",
				"masB::operator=( masB &z))");
		}

		for (i = 0; i < k; i++)
			mas[i] = r.mas[i];
	}
	return *this;
}

masB& masB :: operator=(masB& z) //������������� �������� ������������ ������ masB
{
	int i;
	if (this == &z) return *this;
	// ����� ������������� �������� ������������ ������ mas� ��� 
	masA :: operator= (z);  // ������������ ������������ ����� ������� z
	if (mas != NULL) delete[] mas;
	k = z.k;
	if (z.mas == NULL) mas = NULL;
	else {
		try {
			mas = new PLATAA[k];
			//throw bad_alloc();
		}
		catch (bad_alloc)                     //   ���������� ��� �������� ������
		{
			mas = NULL; n = 0;
			throw ErrMem("��� ������", "���. ������� (mas)", "������������� �������� ������������ masB");
		}
		if (mas == NULL) {
			cout << "��� ������ ��� ������������. \n";
			system("pause"); return z;
		}
		for (i = 0; i < k; i++)
			mas[i] = z.mas[i];
	}
	return *this;
	
}

//���������� ������� �� ����������� �����
void masB::sort1()
{
	int fl, i, kk;
	PLATAA t;

	kk = k;
	do {
		fl = 0; kk--;
		for (i = 0; i < kk; i++)
			if (mas[i].plata > mas[i + 1].plata)
			{
				fl = 1; t = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = t;
			}
	} while (fl == 1);
	cout << "�������� ���������� �� ����������� �����.\n";
	system("pause");
}
//  ���������� ������� �� �����������
void masB::sort3()
{
	int i, fl, kk;
	PLATAA t;
	kk = k;
	do {
		fl = 0; kk--;
		for (i = 0; i < kk; i++)
			if (mas[i].count > mas[i + 1].count)
			{
				fl = 1; t = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = t;
			}
	} while (fl == 1);
	cout << "�������� ���������� �� ���������� ��������� �� ������� ���� �������. \n";
	system("pause");
}
//����� ������� � ��������� ���� 
void masB::outputFile()
{
	ofstream fout;
	string file;
	int i;
	cout << "��� ��������� �����\n"; cin >> file;
	fout.open(file.c_str());
	//  ������ �� ������������� ����� ����� �����

	if (fout.fail()) throw ErrFile("�� ��������� ����", file,
		"mas�::outputFile");
	//��������� ���������� "���� �� ���������"

	fout << "______________________\n";
	fout << "| �����  | ���������� | \n";
	fout << "______________________\n";
	for (i = 0; i < k; i++)
		fout << setw(6) << mas[i].plata << " | " << setw(11) << mas[i].count << " | \n";
	fout << "_______________________\n";
	fout.close();
	cout << "�������� �������� � �����.\n";
	system("pause");
}
//����� ������� �� ����� 
void masB::outputMas()
{
	int i;

	// ����� ��������� ������� (������� ��������) 
	cout << "��������: " << endl;
	cout << "______________________\n";
	cout << "| �����  | ���������� | \n";
	cout << "______________________\n";
	cout << left;
	// ����� ����� �������
	for (i = 0; i < k; i++)
		cout << setw(6) << "|" << mas[i].plata << "|" << setw(11) << mas[i].count << " | \n";
	cout << "_______________________\n";
	system("pause");

}
//����������� ������ makePerech (�) ������ masB
void masB::makePerech()
{
	int i, j, fl;
	PLATAA* y;
	try {
		y = new PLATAA[n];
		//throw bad_alloc();
	}
	catch (bad_alloc)   //  ���������� ��� �������� ������
	{
		throw ErrMem("��� ������", "�������� ������� (�������)", "makePerech()");
	}


	if (y == NULL) {
		cout << "��� ������.\n";
		system("pause");
		return;
	}
	k = 0;

	if (mas != NULL) delete[] mas;
	for (i = 0; i < n; i++)
	{
		fl = 0;
		for (j = 0; j < k; j++)
			if (px[i].plata == y[j].plata)
			{
				fl = 1; y[j].count++;
			}
		if (fl == 0) {
			y[k].plata = px[i].plata;
			y[k].count = 1;
			k++;
		}
	}
	try {
		mas = new PLATAA[k];
		//throw bad_alloc();
	}
	catch (bad_alloc)   //  ���������� ��� �������� ������
	{
		mas == NULL;
		k = 0;
		delete[] mas;
		throw ErrMem("��� ������", " �������(py)", "makePerech()");
	}

	for (j = 0; j < k; j++)
		mas[j] = y[j];
	delete[] y;
	cout << "�������� �����������.\n";
	system("pause");
}
ostream& operator<<(ostream& out, masB& z)
{
	int i;
	out << "��������: " << endl;
	out << "______________________\n";
	out << "| �����  | ���������� | \n";
	out << "______________________\n";

	for (i = 0; i < z.k; i++)
		out << z.mas[i];
	out << "______________________\n";
	system("pause");
	return out;
}
