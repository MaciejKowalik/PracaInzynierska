#include "FloydWarshall.h"
#include <fstream>
#include <iostream>

void FloydWarshall::wykonajAlgorytm(Graf graf)
{

	fstream przebieg;

	przebieg.open("przebieg.txt", ios::out);

	if (!przebieg.good())
	{
		cout << "Nie udalo sie utworzyc pliku z przebiegiem algorytmu" << endl;
		return;
	}

	int limit = graf.getLiczbaWierzcholkow() + 1;

	bool znaleziono = false;

	przebieg << "Poczatkowe wartosci wag: \n";

	for (int i = 1; i < limit; i++)
	{
		for (int j = 1; j < limit; j++)
		{
			if (graf.odczytajPolaczenie(j, i) != INT_MAX)
			{
				przebieg << graf.odczytajPolaczenie(j, i) << "\t";
			}
			else
			{
				przebieg << "-\t";
			}
		}
		przebieg << "\n";
	}
	
	przebieg << "---------------------------------------------\n";

	int odleglosc;

	for (int i = 1; i < limit; i++)
	{
		for (int j = 1; j < limit; j++)
		{
			for (int k = 1; k < limit; k++)
			{
				if (graf.odczytajPolaczenie(k, i) != INT_MAX && graf.odczytajPolaczenie(i, j) != INT_MAX)
				{
					if (graf.odczytajPolaczenie(k, j) == INT_MAX)
					{
						odleglosc = graf.odczytajPolaczenie(k, i) + graf.odczytajPolaczenie(i, j);
						graf.wprowadzPolaczenie(k, j, odleglosc);
						przebieg << "Znaleziono nowe polaczenie, z wierzcholka: " << j << " do: " << k << " przez: " << i << ", rowna " << graf.odczytajPolaczenie(k, j) << "\n";
						znaleziono = true;
					}
					else
					{
						if (graf.odczytajPolaczenie(k, j) > graf.odczytajPolaczenie(i, j) + graf.odczytajPolaczenie(k, i))
						{
							odleglosc = graf.odczytajPolaczenie(k, i) + graf.odczytajPolaczenie(i, j);
							graf.wprowadzPolaczenie(k, j, odleglosc);
							przebieg << "Znaleziono krotsze polaczenie, z wierzcholka: " << j << " do: " << k << " przez: " << i << ", rowna " << graf.odczytajPolaczenie(k, j) << endl;
							znaleziono = true;
						}
					}
				}
			}
		}
	
		if (!znaleziono)
		{
			przebieg << "Nie znaleziono nowych polaczen przez wierzcholek " << i << " w tej iteracji\n";
		}
		else
		{
			znaleziono = false;
		}
		przebieg << "---------------------------------------------\n";
		przebieg << "Iteracja nr: " << i << "\n";

		for (int i = 1; i < limit; i++)
		{
			for (int j = 1; j < limit; j++)
			{
				if (graf.odczytajPolaczenie(j, i) != INT_MAX)
				{
					przebieg << graf.odczytajPolaczenie(j, i) << "\t";
				}
				else
				{
					przebieg << "-\t";
				}
			}
			przebieg << "\n";
		}
	}

	przebieg.close();

	fstream wynik;

	wynik.open("wynik.txt", ios::out);

	if (!wynik.good())
	{
		cout << "Nie udalo sie utworzyc pliku z wynikiem algorytmu" << endl;
		return;
	}

	
	
	for (int i = 0; i < limit; i++)
	{
		if (i == 0)
		{
			wynik << "d\t";
		}
		else
		{
			wynik << i << "\t";
		}
	}
	wynik << "\n";
	for (int i = 1; i < limit; i++)
	{
		for (int j = 0; j < limit; j++)
		{
			if (j == 0)
			{
				wynik << i << "\t";
			}
			else
			{
				if (graf.odczytajPolaczenie(j, i) != INT_MAX)
				{
					wynik << graf.odczytajPolaczenie(j, i) << "\t";
				}
				else
				{
					wynik << "-\t";
				}
			}
		}
		wynik << "\n";
	}

	wynik.close();

}