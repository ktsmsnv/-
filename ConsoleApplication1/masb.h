#pragma once
#ifndef _masb_
#define _masb_
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
 ostream& operator<<(ostream& out, PLATAA& z) //����������� ������������� �������� ������ �� ����� ��������� ���� PLATA
{
	out << "|" << setw(8) << std::left << z.plata << "|" << setw(12) << std::left << z.count << "|" << endl;
	return out;
}

class masB : public masA
{
protected:
	PLATAA* mas;
	int k;
public:
	masB() :mas(NULL), k(0) {};
	masB(masB& z);
	virtual ~masB() { if (mas != NULL) delete[]mas; cout << "~masB()\n"; }
	masB& operator=(masB& z);
	virtual masB& operator= (masA& z);

	//���������������� ������ ������ 
	void sort3();
	void sort1();
	//������ ������ � masB
	void makePerech();
	//����������� ������
	virtual void outputMas();
	virtual void outputFile();

	friend ostream& operator<<(ostream& out, masB& z);
};
#include "masb.cpp"
#endif
