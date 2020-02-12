#include "BellmanFord.h"
#include <fstream>
#include <iostream>

void BellmanFord::wykonajAlgorytm(Graf graf)
{
	bool znaleziono = false;

	fstream przebieg;

	przebieg.open("przebieg.txt", ios::out);

	if (!przebieg.good())
	{
		cout << "Nie udalo sie utworzyc pliku z przebiegiem algorytmu" << endl;
		return;
	}

	int limit = graf.getLiczbaWierzcholkow() + 1;

	vector <int> odleglosci;
	odleglosci.resize(limit);

	int tmp;

	przebieg << "Iteracja zerowa " << endl;

	for (int i = 1; i < limit; i++)
	{
		odleglosci[i] = graf.odczytajPolaczenie(i, 1); // 1 wierzcho³ek - od którego zaczynamy
	
		if (odleglosci[i] == INT_MAX)
		{
			przebieg << "- ";
		}
		else
		{
			przebieg << odleglosci[i] << " ";
		}
	}
	przebieg << "\n---------------------------------------------\n";
	
	for (int i = 2; i <= limit - 2; i++)
	{
		for (int j = 2; j < limit; j++)
		{
			for (int k = 1; k < limit; k++)
			{
				double sprawdzenie = (double)odleglosci[k] + (double)graf.odczytajPolaczenie(j, k);

				if (sprawdzenie > INT_MAX)
				{
					tmp = INT_MAX;
				}
				else
				{
					tmp = odleglosci[k] + graf.odczytajPolaczenie(j, k);
				}
	
				if (tmp < odleglosci[j])
				{
					odleglosci[j] = tmp;
					przebieg << "Znaleziono polaczenie do wierzcholka nr: " << j << " przez wierzcholek nr: " << k << " wynoszaca: " << tmp << "\n";
					znaleziono = true;
				}
			}
		}
	
		if (!znaleziono)
		{
			przebieg << "Nie znaleziono nowych polaczen\n";
		}

		znaleziono = false;
		przebieg << "---------------------------------------------\n";
		przebieg << "Iteracja nr: " << i - 1 << "\n";
		for (int l = 1; l < limit; l++)
		{
			if (odleglosci[l] == INT_MAX)
			{
				przebieg << "- ";
			}
			else
			{
				przebieg << odleglosci[l] << " ";
			}
		}
		przebieg << "\n";
	
	}

	przebieg.close();

	fstream wynik;

	wynik.open("wynik.txt", ios::out);

	if (!wynik.good())
	{
		cout << "Nie udalo sie utworzyc pliku z wynikiem algorytmu" << endl;
		return;
	}

	wynik << "Odleglosci od pierwszego wierzcho³ka:\n";

	for (int l = 1; l < limit; l++)
	{
		if (odleglosci[l] == INT_MAX)
		{
			wynik << "D[" << l << "] = -\t";
		}
		else
		{
			wynik << "D[" << l << "] = " << odleglosci[l] << "\t";
		}
	}
}
