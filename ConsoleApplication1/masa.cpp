#include  "masa.h"
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
using namespace std;
masA::masA(masA& z) //����������� ����������� ������ masA
{
	int i;
	n = z.n;
	if (n == 0) px = NULL;
	else {
		try {
			px = new abonent[n];
			//throw bad_alloc();
		}
		catch (bad_alloc)                     //   ���������� ��� �������� ������
		{
			px = NULL; n = 0;
			throw ErrMem("��� ������", "���. ������� (px)", "masA(masA &z)");
		}
		if (px == NULL) {
			cout << "��� ������.\n";
			cout << "����������� �����������.\n";
			system("pause"); exit(1);
		}
		for (i = 0; i < n; i++)
			px[i] = z.px[i];
	}
} // ����� ������������ �����������
masA& masA :: operator=(masA& z) //����������� ������������� �������� ������������ ������ masA
{
	int i;
	if (this == &z) return *this;
	if (px != NULL) delete[]px;
	n = z.n;
	if (z.px == NULL) px = NULL;
	else {
		try {
			px = new abonent[n];
			//throw bad_alloc();
		}
		catch (bad_alloc)                     //   ���������� ��� �������� ������
		{
			px = NULL; n = 0;
			throw ErrMem("��� ������", "���. ������� (px)", "masA::operator=(masA &z)");
		}
		if (px == NULL) {
			cout << "��� ������.\n";
			cout << "�������� ������������.\n";
			system("pause"); return z;
		}
		for (i = 0; i < n; i++)
			px[i] = z.px[i];
	}
	return *this;
}

//���� ��������� ������� �������� �� �����
void masA::inputFile()
{
	ifstream fin;
	string file;
	string iniz;
	abonent t;
	cout << "��� �������� �����:";
	cin >> file;
	fin.open(file.c_str());
	//������ �� ������������� ����� ����� �����
	if (fin.fail()) throw ErrFile("�� �����������", file, "inputFile()"); //��������� ���������� "���� �� ����-��"

	n = 0;
	if (px != NULL) { delete[] px; px = NULL; }  // ������� �������

	while (1)
	{
		fin >> t.number >> t.datzakl.d >> t.datzakl.m >> t.datzakl.y >> t.plata >> t.pers.name >> iniz >> t.pers.region >> t.pers.adress >> t.pers.phone;
		if (fin.fail()) break;	n++;
	}

	//  ������ ���������� �������� �����
	fin.clear();
	fin.seekg(0, ios::beg);   //  ����������� ������� � ������ �����

	try {
		px = new abonent[n];
		//throw bad_alloc();
	}
	catch (bad_alloc)      //   ���������� ��� �������� ������
	{
		px = NULL; n = 0;
		throw ErrMem("��� ������", "���. ������� (px)", "inputFile()");
	}

	if (px == NULL) {
		cout << "��� ������.\n"; fin.close();
		cout << "������ ���� �� �������.\n";
		system("pause"); n = 0; return;
	}
	for (int i = 0; i < n; i++)
	{
		fin >> px[i].number >> px[i].datzakl.d >> px[i].datzakl.m >> px[i].datzakl.y >> px[i].plata >> px[i].pers.name >> iniz >> px[i].pers.region >> px[i].pers.adress >> px[i].pers.phone;
		px[i].pers.name = px[i].pers.name + " " + iniz;
		if (fin.fail())   throw Err("��� �����", "inputFile()");
	}

	fin.close();
	cout << "���� ������ " << endl;
	system("pause");
}
//���������� ������ � ������������ ������ ��������
void masA::addAbonent()
{
	int i;
	abonent t, * p;
	string iniz;

	try {      //   ������   try - �����
		p = new abonent[n + 1];  // ��������� ������ ��� ������ �������
		//throw bad_alloc();
	}
	catch (bad_alloc)     //   ���������� ��� �������� ������
	{
		p = NULL; n = 0;
		throw ErrMem("��� ������", "���. ������� (p)", "adddan()");
	}
	if (p == NULL) {
		cout << "��� ������.\n";
		cout << "�������� �� �������.\n";
		system("pause"); return;
	}
	try
	{
		cout << "����� ��������:"; cin >> t.number;
		if (cin.fail())
		{
			throw Err("��� �����", "adddan()");
		}
		cout << "���� ����������.\n";
		cout << "����:";   cin >> t.datzakl.d;
		if (cin.fail())
		{
			throw Err("��� �����", "adddan()");
		}
		cout << "�����:"; cin >> t.datzakl.m;
		if (cin.fail())
		{
			throw Err("��� �����", "adddan()");
		}
		cout << "���:";      cin >> t.datzakl.y;
		if (cin.fail())
		{
			throw Err("��� �����", "adddan()");
		}
		cout << "����������� �����:"; cin >> t.plata;
		if (cin.fail())
		{
			throw Err("��� �����", "adddan()");
		}
		cout << "�.�.�.:"; cin >> t.pers.name >> iniz;
		t.pers.name = t.pers.name + " " + iniz;
		if (cin.fail())
		{
			throw Err("��� �����", "adddan()");
		}
		cout << "������:"; cin >> t.pers.region;
		if (cin.fail())
		{
			throw Err("��� �����", "adddan()");
		}
		cout << "�����:"; cin >> t.pers.adress;
		if (cin.fail())
		{
			throw Err("��� �����", "adddan()");
		}
		cout << "�������:"; cin >> t.pers.phone;
		if (cin.fail())
		{
			throw Err("��� �����", "adddan()");
		}

		for (i = 0; i < n; i++)
			p[i] = px[i];   // ����������� ������� ������� � �����
		p[n] = t; // ���������� ����� ������ � ������ ��������
		n++;   // ���������� �������� ���������� �������

		if (px != NULL) delete[] px; // �������� ������� �������
		px = p;    // ����� ������ ������� ��������� � px

		cout << "������ ���������.\n";
		system("pause");
	}       //   �����   try - �����

	catch (bad_alloc)     //   ���������� ��� �������� ������
	{
		throw ErrMem("��� ������", "��� �������", "addStudent()");
	}

}
//�������� ������ �� ������������� ������� ��������
void masA::deleteAbonent()
{
	int j, i;
	abonent* p = NULL;
	string iniz;
	char ch;

	masA::outputMas(); //  ����� �� ����� ������� ��������

	//  ������ �� ������������� ����� ������ ������
	cout << "����� �������� �������:";
	try
	{
		cin >> j;
		if (cin.fail())
		{
			throw Err("��� �� ����� ������", "deleteStudent()");
		}
	}
	catch (char ex[])
	{
		throw Err("��� �� ����� ������", "deletedan()");
	}


	if (j<1 || j>n)  throw Err("��� ����� ������", "deleteStudent()");//��������� ���������� "��� ����� ������"

	j--; //  ������� �� ������ ��������� ������ � �� �������
	cout << j + 1 << "-� ������:\n";
	cout << px[j].number << " " << px[j].datzakl.d << "." << px[j].datzakl.m << "." << px[j].datzakl.y << " " << px[j].plata << " " << px[j].pers.name << " " << iniz << " " << px[j].pers.region << " " << px[j].pers.adress << " " << px[j].pers.phone << endl;

	cout << "�������?(y/n):"; cin >> ch;
	if (char(cin.peek()) != '\n')
	{
		cin.ignore();
		cin.clear();
		cin.ignore(32767, '\n');
	}
	if (ch == 'n')
	{
		throw Err("��� �� �� ������", "deleteStudent()");
	}
	if (ch != 'y')
	{
		throw Err("����� �� �� �� ��� ", "deleteStudent()");
	}

	//  ���������� �������� ������     
	if (n == 1) { delete[] px; px = NULL; n = 0; }
	else
	{
		try {
			p = new abonent[n - 1];
			//throw bad_alloc();
		}
		catch (bad_alloc)    //  ���������� ��� �������� ������
		{
			throw ErrMem("��� ������", "���. ������� (px)", "deleteStudent()");
		}

		if (p == NULL)
		{
			cout << "��� ������.\n ";
			cout << "������� �� �������.\n";
			system("pause"); return;
		}
		for (i = 0; i < j; i++)
			p[i] = px[i];
		for (i = j + 1; i < n; i++)
			p[i - 1] = px[i];
		delete[] px; // �������� ������� �������
		px = p;    // ����� ������ ������� ��������� � ���� px
		n--;//  ���������� �������� ���������� �������
	}
	cout << "������ �������.\n";
	system("pause");
}
//���������� ������� �������� �� ��� (���������� �� ���������� ���� � ���-�� �������)
void masA::sort1()
{
	int i, fl, nn;
	abonent t;
	nn = n;
	do {
		fl = 0; nn--;
		for (i = 0; i < nn; i++)
			if (px[i].pers.name > px[i + 1].pers.name)
			{
				fl = 1;  t = px[i];
				px[i] = px[i + 1];
				px[i + 1] = t;
			}
	} while (fl == 1);
	cout << "������ �������� ���������� �� ��� � ���������� �������\n";
	system("pause");
}
//���������� ������� �������� �� ���� ����������(���������� �� ���������� �����)
void masA::sort2() // ���������� �� ���� ����������
{
	int fl, i, nn;
	abonent t;

	nn = n;
	do {
		fl = 0; nn--;
		for (i = 0; i < nn; i++)
			if (px[i].datzakl > px[i + 1].datzakl) // ��� ������������� ��������  �>�, ���������� ����������� �-��
			{
				fl = 1; t = px[i];
				px[i] = px[i + 1];
				px[i + 1] = t;
			}
	} while (fl == 1);
	cout << "������ �������� ���������� �� ���� ���������� ��������\n";
	system("pause");
}
//���������� ������� �������� �� ��������� ����
void masA::sort3()  //�� ������ ��������
{
	int i, fl, nn;
	abonent t;
	nn = n;  // ������ ����� ������� �������
	do {
		fl = 0; nn--;
		for (i = 0; i < nn; i++)
			if (px[i].number > px[i + 1].number)
			{
				fl = 1;  t = px[i];
				px[i] = px[i + 1];
				px[i + 1] = t;
			}
	} while (fl == 1);
	cout << "������ �������� ���������� �� ������ ��������\n";
	system("pause");
}
//����� ������� �������� �� �����
void masA::outputMas()
{
	int i;

	// ����� ��������� ������� (������� ��������) 
	cout << "_____________________________________________________________________________________________________________________________________\n";
	cout << "|   |                | ���� ���������� |                   |                    |          |                             |           |\n";
	cout << "| � | ����� �������� | ����| �����| ���| ����������� ����� | ������� � �������� | �����    | �����                       | �������   |\n";
	cout << "|" << "___________________________________________________________________________________________________________________________________" << " | " << "\n";
	cout << left;
	// ����� ����� �������
	for (i = 0; i < n; i++)
		cout << "|" << setw(3) << i + 1 << "|" << setw(16) << px[i].number << "|" << setw(5) << px[i].datzakl.d << "|" << setw(6) << px[i].datzakl.m << "|" << setw(4) << px[i].datzakl.y << "|" << setw(19) << px[i].plata << "|" << setw(20) << px[i].pers.name << "|" << setw(10) << px[i].pers.region << "|" << setw(29) << px[i].pers.adress << "|" << setw(11) << px[i].pers.phone << "| \n";
	cout << "|" << "___________________________________________________________________________________________________________________________________" << " | \n";
	system("pause");

}
//����� ������� �������� � ��������� ����
void masA::outputFile()
{
	ofstream fout;
	string file;
	int i;
	cout << "��� ��������� �����:";   cin >> file;
	fout.open(file.c_str());

	//  ������ �� ������������� ����� ����� �����
	if (fout.fail()) throw ErrFile("�� ��������� ����", file, "masA::outputFile");
	//    ��������� ���������� (8)

	// ����� ��������� 
	fout << "_____________________________________________________________________________________________________________________________________\n";
	fout << "|   |                | ���� ���������� |                   |                    |          |                             |           |\n";
	fout << "| � | ����� �������� | ����| �����| ���| ����������� ����� | ������� � �������� | �����    | �����                       | �������   |\n";
	fout << "|" << "_________________________________________________________________________________________________________________________________" << " | " << "\n";

	// ����� ��������� ����� �������
	for (i = 0; i < n; i++)
		fout << "|" << setw(3) << i + 1 << "|" << setw(16) << px[i].number << "|" << setw(5) << px[i].datzakl.d << "|" << setw(6) << px[i].datzakl.m << "|" << setw(4) << px[i].datzakl.y << "|" << setw(19) << px[i].plata << "|" << setw(20) << px[i].pers.name << "|" << setw(10) << px[i].pers.region << "|" << setw(29) << px[i].pers.adress << "|" << setw(12) << px[i].pers.phone << "| \n";
	fout << "_________________________________________________________________________________________________________________________\n";

	fout.close();
	cout << "������ �������� �������� � ����\n";
	system("pause");
}

//����������� ������������� �������� ������ �� ����� ������� ������ masA
ostream& operator<<(ostream& out, masA& z)
{
	int i;
	out << "_________________________________________________________________________________________________________________________\n";
	out << "|   |                | ���� ���������� |                   |                    |          |                |           |\n";
	out << "| � | ����� �������� | ����| �����| ���| ����������� ����� | ������� � �������� | �����    | �����          | �������   |\n";
	out << "_________________________________________________________________________________________________________________________\n";
	for (i = 0; i < z.n; i++)
		out << "|" << setw(3) << i + 1 << z.px[i];
	out << "_________________________________________________________________________________________________________________________\n";
	system("pause");
	return out;
}

