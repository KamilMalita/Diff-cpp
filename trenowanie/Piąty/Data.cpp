#include "Data.h"



Data::Data(int d ,int m, int r)
{
	m_nDzien = d;
	m_nMiesiac = m;
	m_nRok = r;
}


Data::~Data()
{
}

void Data::Ustaw(int d, int m, int r)
{
	m_nDzien = d;
	m_nMiesiac = m;
	m_nRok = r;
	Koryguj();
}
int Data::Dzien() const
{
	return m_nDzien;
}
int Data::Miesiac() const
{
	return m_nMiesiac;
}
int Data::Rok() const
{
	return m_nRok;
}
void Data::Wypisz()
{
	cout << Data::Dzien() <<"-"
		 << Data::Miesiac() <<"-"
		 << Data::Rok()<<endl;
}
void Data::Wpisz()
{
	cout << "Podaj dzien: ";
	cin >> m_nDzien;
	cout << "Podaj miesiac: ";
	cin >> m_nMiesiac;
	cout << "Podaj rok: ";
	cin >> m_nRok;
	cin.ignore(1000, '\n');
}
void Data::Koryguj()
{
	if (m_nRok < 0)
		(m_nRok = abs(m_nRok));
	if (m_nDzien < 1)
		(m_nDzien = 1);
	if (m_nMiesiac < 1)
		(m_nMiesiac = 1);
	if (m_nMiesiac > 12)
		(m_nMiesiac = 12);
	if (m_nDzien > 30 && (m_nMiesiac == 4 || m_nMiesiac == 6 || m_nMiesiac == 9 || m_nMiesiac == 11))
	{
		m_nDzien = 30;
		return;
	};
	if (m_nDzien > 31 && (m_nMiesiac == 1 || m_nMiesiac == 3 || m_nMiesiac == 5 || m_nMiesiac == 7 || m_nMiesiac == 8 || m_nMiesiac == 10 || m_nMiesiac == 12))
	{
		m_nDzien = 31;
		return;
	};
	if (m_nDzien > 28 && m_nMiesiac == 2 && m_nRok % 4 == 0)
		(m_nDzien = 29);
	else if (m_nDzien>27 && m_nMiesiac == 2)
		(m_nDzien=28);
}
int Data::Porownaj(const Data &wzor) const
{
	if (this->m_nDzien == wzor.m_nDzien && this->m_nMiesiac == wzor.m_nMiesiac && this->m_nRok == wzor.m_nRok)
		return 0;
	else if (this->m_nRok > wzor.m_nRok || (this->m_nRok == wzor.m_nRok && this->m_nMiesiac > wzor.m_nMiesiac) 
		|| (this->m_nRok == wzor.m_nRok && this->m_nMiesiac == wzor.m_nMiesiac && this->m_nDzien > wzor.m_nDzien))
		return 1;
	else return -1;
}

istream & operator >> (istream & we, Data & d)
{
	cout << "Wprowadz dzien: ";
	we >> d.m_nDzien;
	cout << "Wprowadz miesiac: ";
	we >> d.m_nMiesiac;
	cout << "Wprowadz rok: ";
	we >> d.m_nRok;
	d.Koryguj();
	return we;
}

ostream & operator<<(ostream & wy, const Data & d)
{
	wy << d.m_nDzien <<"-"<< d.m_nMiesiac <<"-" << d.m_nRok;
	return wy;
}
