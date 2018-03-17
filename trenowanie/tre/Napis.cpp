#include "Napis.h"



Napis::Napis(const char *nap)
{
	m_nD1 = sizeof(nap);
	m_pszNapis =new char[m_nD1];
	strcpy(m_pszNapis, nap);
}

Napis::Napis(const Napis &wzor)
{
	m_nD1 = wzor.m_nD1;
	m_pszNapis = new char[m_nD1];
	strcpy(m_pszNapis, wzor.m_pszNapis);
}

Napis::~Napis()
{
	delete[] m_pszNapis;
}
const char *Napis::Zwroc() const
{
	return m_pszNapis;
}

/*void Napis::Wpisz()
{
	//cin >> m_pszNapis;
	cin.getline(m_pszNapis, sizeof m_pszNapis);
}
*/
void Napis::Wypisz()const
{
	cout << Zwroc();
}
void Napis::Ustaw(const char *nowy_napis)
{
	for (int i = 0; i < sizeof nowy_napis; i++)
	{
		m_pszNapis[i] = *(nowy_napis + i);
	}
}
int Napis::SprawdzNapis(const char *por_napis)const
{
	if (strcmp(m_pszNapis, por_napis) == 0)
		return 0;
	else if (strcmp(m_pszNapis, por_napis) < 0)
		return -1;
	else return 1;
}

Napis & Napis::operator=(const Napis & wzor)
{
	if (this == &wzor)
		return *this;
	m_nD1 = wzor.m_nD1;
	m_pszNapis = new char[m_nD1];
	strcpy(m_pszNapis, wzor.m_pszNapis);
	return *this;
}

bool Napis::operator ==(const Napis & wzor) const
{
	if (this == &wzor)
		return true;
	if (strcmp(m_pszNapis, wzor.m_pszNapis) == 0 && m_nD1 == wzor.m_nD1)
		return true;
	else
		return false;
}

ostream & operator << (ostream& wy, const Napis & p)
{
	wy << p.m_pszNapis;
	return wy;
}

istream &operator >> (istream &we, Napis &p)
{
	string pom;
	getline(we, pom);
	p.m_nD1 = pom.length() + 1;
	p.m_pszNapis = new char[p.m_nD1];
	strcpy(p.m_pszNapis, pom.c_str());
	return we;
}