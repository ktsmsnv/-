#ifndef _exception_
#define _exception_
#include  <iostream>
#include  <limits>
#include  <fstream>
#include  <cstdlib>
#include  <string>
#include  <iomanip>
#include  <conio.h>
#include  <Windows.h>
#include  <sstream>
using namespace std;
class Err
{
protected:
	string mes;                             //  ��� �� ������ 
	string mes2;                           //  � ����� ������ ���������

public:

	//     ���������������� �����������
	Err(string mes0, string mes20) : mes(mes0), mes2(mes20) {}

	virtual void ErrOutput()
	{
		cout << "������: " << mes;
		cout << " � �������/������ " << mes2 << endl;
		_getch();
	}

};

class ErrFile : public Err
{
protected:
	string mes1;                             //  ��� ������ � ����� ������
public:

	//     ���������������� �����������
	ErrFile(string mes0, string mes10, string mes20)
		: Err(mes0, mes20), mes1(mes10) {}

	virtual void ErrOutput()
	{
		cout << "������: " << mes << endl;
		cout << "��� ������ � ������: " << mes1 << endl;
		cout << "��������� � ������: " << mes2 << endl;
		_getch();
	}//  ����� ��������� �� ������
};


class ErrMem : public ErrFile
{
protected:
public:

	//    ���������������� �����������
	ErrMem(string mes0, string mes10, string mes20)
		: ErrFile(mes0, mes10, mes20) {}

	virtual void ErrOutput()
	{
		cout << "������: " << mes;
		cout << " ��� ��������� ������ ��� " << mes1;
		cout << " � ������ " << mes2 << endl;
		_getch();
	}
	string getMes() { return mes; }
	string getMes1() { return mes1; }
};
#endif