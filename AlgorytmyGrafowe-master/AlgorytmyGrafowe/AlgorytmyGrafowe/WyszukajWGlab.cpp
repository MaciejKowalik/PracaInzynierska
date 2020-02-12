#include "WyszukajWGlab.h"
#include <queue>
#include <stack>
#include <fstream>
#include <iostream>

void WyszukajWGlab::wykonajAlgorytm(Graf graf)
{
	fstream przebieg;

	przebieg.open("przebieg.txt", ios::out);

	if (!przebieg.good())
	{
		cout << "Nie udalo sie utworzyc pliku z przebiegiem algorytmu" << endl;
		return;
	}

	queue<int> odwiedzoneWierzcholki, odwiedzoneWierzcholkiKopia;
	
	stack<int> stos, stosKopia;
	
	int liczbaWierzcholkow = graf.getLiczbaWierzcholkow();

	vector<int> odwiedzone;

	odwiedzone.resize(liczbaWierzcholkow+1);

	for (int i = 0; i < liczbaWierzcholkow + 1 ; i++)
		odwiedzone[i] = 0;
	
	int wierzcholek = 1;
	stos.push(wierzcholek);
	
	while (!stos.empty())
	{
		odwiedzoneWierzcholkiKopia = odwiedzoneWierzcholki;
		przebieg << "Odwiedzone wierzcholki: ";
		
		if (odwiedzoneWierzcholkiKopia.empty())
		{
			przebieg << "Nie odwiedzono zadnego wierzcholka\n";
		}
		else
		{
			while (!odwiedzoneWierzcholkiKopia.empty())
			{
				przebieg << odwiedzoneWierzcholkiKopia.front() << " ";
				odwiedzoneWierzcholkiKopia.pop();
			}
			przebieg << "\n";
		}

		stosKopia = stos;

		if (stosKopia.empty())
		{
			przebieg << "Stos jest pusty\n";
		}
		else
		{
			przebieg << "Zawartosc stosu: ";
			
			while (!stosKopia.empty())
			{
				przebieg << stosKopia.top() << " ";
				stosKopia.pop();
			}
		}
		przebieg << "\n";

		wierzcholek = stos.top();
		stos.pop();
	
		przebieg << "Aktualnie odwiedzany wierzcholek: " << wierzcholek <<"\n";

		odwiedzoneWierzcholki.push(wierzcholek);

		odwiedzone[wierzcholek] = 1;

		przebieg << "Sprawdzenie wszystkich nastepnikow: ";
		bool jestNastepnik = false;

		for (int i = liczbaWierzcholkow ; i > 0; i--)
		{
			if (graf.odczytajPolaczenie(i, wierzcholek) != INT_MAX && odwiedzone[i] == 0)
			{
				przebieg << i << " ";
				stos.push(i);
				odwiedzone[i] = 1;
				jestNastepnik = true;
			}
		}
		if (jestNastepnik == false)
		{
			przebieg << "Brak nastepnikow";
		}

		przebieg << "\n\n";

	}

	odwiedzoneWierzcholkiKopia = odwiedzoneWierzcholki;
	przebieg << "Odwiedzone wierzcholki: ";

	if (odwiedzoneWierzcholkiKopia.empty())
	{
		przebieg << "Nie odwiedzono zadnego wierzcholka\n";
	}
	else
	{
		while (!odwiedzoneWierzcholkiKopia.empty())
		{
			przebieg << odwiedzoneWierzcholkiKopia.front() << " ";
			odwiedzoneWierzcholkiKopia.pop();
		}
		przebieg << "\n";
	}
	przebieg.close();

	fstream wynik;

	wynik.open("wynik.txt", ios::out);

	if (!wynik.good())
	{
		cout << "Nie udalo sie utworzyc pliku z wynikiem dzialania algorytmu" << endl;
		return;
	}

	wynik << "Wierzcholki zostaly odwiedzone w kolejnosci:  ";

	odwiedzoneWierzcholkiKopia = odwiedzoneWierzcholki;

	while (!odwiedzoneWierzcholkiKopia.empty())
	{
		wynik << odwiedzoneWierzcholkiKopia.front() << " ";
		odwiedzoneWierzcholkiKopia.pop();
	}

	wynik << "\n";

	wynik.close();
}