#include "ListaZatrudnionych.h"



ListaZatrudnionych::ListaZatrudnionych()
{
	m_pPierwszy= NULL;
	m_nLiczbaPracownik�w = 0;

}


ListaZatrudnionych::~ListaZatrudnionych()
{
	m_pPierwszy = NULL;
	m_nLiczbaPracownik�w = 0;
}

void ListaZatrudnionych::DodajNaPoczatek(const Pracownik &p)
{
	Pracownik *temp=m_pPierwszy;
	Pracownik *nowy=new Pracownik(p);
	if (m_pPierwszy == NULL)
	{
		m_pPierwszy = nowy;
		m_pPierwszy->m_nast�pny = NULL;
		m_nLiczbaPracownik�w++;
	}
	else
	{	
		if (m_pPierwszy->Porownaj(p) > 0)
		{
			nowy->m_nast�pny = m_pPierwszy;
			m_pPierwszy = nowy;
			m_nLiczbaPracownik�w++;
			return;
		}
		*nowy = p;
		while (temp->m_nast�pny!=NULL && temp->Porownaj(p)<0)
		{
			temp = temp->m_nast�pny;
		}
		if (temp->Porownaj(p) == 0) return;
		nowy->m_nast�pny = temp->m_nast�pny;
		temp->m_nast�pny = nowy;
		m_nLiczbaPracownik�w++;
	}
}

void ListaZatrudnionych::Usun(const Pracownik &wzorzec)
{
	Pracownik *temp = new Pracownik, *pierwszy = m_pPierwszy;
	*temp = wzorzec;
	if (pierwszy == NULL)
		cout << "PROBLEM, PUSTO TU";
	else {
		if (pierwszy->Porownaj(wzorzec) == 0)
		{
			m_pPierwszy = m_pPierwszy->m_nast�pny;
			m_nLiczbaPracownik�w--;
			return;
		}
		while (pierwszy != NULL) 
		{
			if (pierwszy->m_nast�pny->Porownaj(wzorzec) == 0)
			{
				pierwszy->m_nast�pny = pierwszy->m_nast�pny->m_nast�pny;
				m_nLiczbaPracownik�w--;
				return;
			}
			pierwszy = pierwszy->m_nast�pny;
		}
		}
}

void ListaZatrudnionych::WypiszPracownikow()const
{
	Pracownik *temp = m_pPierwszy;
	while (temp != NULL)
	{
		temp->Wypisz();
		temp = temp->m_nast�pny;
	}
}


const Pracownik* ListaZatrudnionych::Szukaj(const char* nazwisko, const char* imie)
{
	Pracownik *head = m_pPierwszy;
	while (head != NULL)
	{
		if (head->SprawdzImie(imie) == 0 && head->SprawdzNazwisko(nazwisko)==0) return head;
		head = head->m_nast�pny;
	}
	return nullptr;
}
void ListaZatrudnionych::Zapis_do_pliku(ofstream &plik)
{
	int i = 1;
	Pracownik *head = m_pPierwszy;
	plik.open("../Pracownicy.txt", ios::out | ios::trunc);
	if (!plik.good())
	{
		cout << "\n Blad otwarcia pliku!";
		return;
	}
	while (head)
	{
		//plik << i;
		plik << *head << endl;
		head = head->m_nast�pny;
		i++;
	}
	plik.close();
}