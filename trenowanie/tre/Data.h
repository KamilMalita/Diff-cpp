#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
using namespace std;
class Data
{
	int m_nDzien, m_nMiesiac, m_nRok;
public:
	void Ustaw(int d, int m, int r);
	int Dzien() const;
	int Rok() const;
	int Miesiac() const;
	void Wypisz();
	void Wpisz();
	void Koryguj();
	int Porownaj(const Data &wzor) const;
	Data(int d ,int m, int r);
	~Data();
	friend istream &operator >> (istream &we, Data &d);
	friend ostream& operator<<(ostream &wy, const Data &d);
};




