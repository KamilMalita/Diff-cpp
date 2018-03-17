#include "Data.h"
#include "Pracownik.h"
#include "Napis.h"
#include "ListaZatrudnionych.h"
void main()
{
	char znak;
	const Pracownik *Szukany = new Pracownik;
	Pracownik kontrolny;
	Napis imie, nazwisko;
	ListaZatrudnionych *head = new ListaZatrudnionych;
	while (1)
	{
		cout << "\n";
		cout << "Co ma siê staæ?" << endl
			<< "Usunac wszystkich?- 0"<< endl
			<< "Dodac pracownika?- d" << endl
			<< "Wyswietlic pracownikow?- w" << endl
			<< "Usunac pracownika?- u" << endl
			<< "Wyszukac pracownika?- s" << endl
			<< "Wyjsc z programu?- q" << endl;
		cin >> znak;
		switch (znak)
		{
		case 'u':
			cout << "Pracownik do usuniecia" << endl;
			cin.ignore(1000, '\n');
			cin >> kontrolny;
			head->Usun(kontrolny);
			break;
		case 'd':
			cin.ignore(1000, '\n');
			cin >> kontrolny;
			head->DodajNaPoczatek(kontrolny);

			break;
		case'w':
			head->WypiszPracownikow();
			break;
		case 's':
			cout << " kogo chcesz wyszukac?\n Wpisz imie: ";
			cin.ignore(1000, '\n');
			cin >> imie;
			cout << "I nazwisko: ";
			cin >> nazwisko;
			Szukany=head->Szukaj(nazwisko.Zwroc() , imie.Zwroc());
			if (Szukany != NULL)
			{
				cout << *Szukany;
			}
			break;
		case '0':
			head->~ListaZatrudnionych();
			break;
		case'q':
			return;
		case '1':
			ofstream plik;
			head->Zapis_do_pliku(plik);
			break;
		}
	}
}
