#pragma once
#include "Data.h"
class Napis
{
private:
	char * m_pszNapis;
	int m_nD1;
public:
	const char *Zwroc()const;
	void Ustaw(const char *nowy_napis);
	//void Wpisz();
	void Wypisz()const;
	int SprawdzNapis(const char *por_napis)const;
	Napis(const char *nap="");
	Napis(const Napis &wzor);
	~Napis();
	Napis & operator=(const Napis & wzor);
	bool operator ==(const Napis & wzor) const;
	friend ostream & operator << (ostream& wy, const Napis & p);
	friend istream &operator >> (istream &we, Napis &p);
};

