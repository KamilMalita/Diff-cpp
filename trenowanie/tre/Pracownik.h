#pragma once
#include "Data.h"
#include "Napis.h"
class Pracownik
{
	Napis m_Imie, m_Nazwisko;
	Data m_DataUrodzenia;
	const int m_nIDZatrudnienia;
public:
	Pracownik* m_nastêpny;
	int Porownaj(const Pracownik &wzorzec)const;
	const char *Imie()const;
	const char *Nazwisko()const;
	void Imie(const char *nowe_imie);
	void Nazwisko(const char *nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);
	void Wypisz();
	//void Wpisz();
	int SprawdzImie(const char *por_imie) const;
	int SprawdzNazwisko(const char *por_nazwisko)const;
	Pracownik(const char* imie = "", const char* nazwisko = "", int dzien = 1, int miesiac = 1, int rok = 2000);
	Pracownik(const Pracownik &wzor);
	~Pracownik();
	Pracownik &operator=(const Pracownik &wzor);
	bool operator == (const Pracownik &wzor) const;
	friend ostream &operator<<(ostream& wy, const Pracownik &p);
	friend istream &operator>>(istream& we, Pracownik &p);
};

