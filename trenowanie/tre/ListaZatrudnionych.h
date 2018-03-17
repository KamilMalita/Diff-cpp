#pragma once
#include "Pracownik.h"
class ListaZatrudnionych
{
	Pracownik* m_pPierwszy;
	int m_nLiczbaPracowników;
public:
	ListaZatrudnionych();
	~ListaZatrudnionych();
	void WypiszPracownikow()const;
	void DodajNaPoczatek(const Pracownik &p);
	void Usun(const Pracownik &wzorzec);
	const Pracownik* Szukaj(const char* nazwisko, const char* imie);
	void Zapis_do_pliku(ofstream &plik);
};

