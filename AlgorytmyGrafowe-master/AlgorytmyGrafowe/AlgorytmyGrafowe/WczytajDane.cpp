#include "WczytajDane.h"
#include <iostream>
#include <fstream>
#include <exception>
Graf WczytajDane::wczytajMacierzSasiedztwa(int &liczbaWierzcholkow, string nazwaPliku)
{
	fstream plik;

	plik.open(nazwaPliku, ios::in);

	if (!plik.good())
	{
		return Graf(-1);
	}
	else
	{
		string dana;
		string znakBraku = "-";

		try {
			plik >> liczbaWierzcholkow;
		}
		catch (...)
		{
			cout << "Blad w ladowaniu liczby wierzcholkow" << endl;
			return Graf(-1);
		}

		Graf graf = Graf(liczbaWierzcholkow);

		try {
			for (int i = 0; i < liczbaWierzcholkow + 1; i++)
			{
				for (int j = 0; j < liczbaWierzcholkow + 1; j++)
				{
					plik >> dana;

					if (dana.compare(znakBraku) == 0)
					{
						graf.wprowadzPolaczenie(i, j, INT_MAX);
					}
					else
					{
						graf.wprowadzPolaczenie(i, j, stoi(dana));
					}
				}
			}
		}
		catch (...)
		{
			return Graf(-1);
		}
		plik.close();

		cout << "Pomyslnie zaladowano graf, liczba wierzcholkow = " << liczbaWierzcholkow << endl;

		return graf;
	}

}

Graf WczytajDane::wczytajListeSasiedztwa(int &liczbaWierzcholkow, string nazwaPliku)
{
	fstream plik;

	plik.open(nazwaPliku, ios::in);

	if (!plik.good())
	{
		cout << "Blad w ladowaniu pliku" << endl;
		return Graf(-1);
	}
	
	try {
		plik >> liczbaWierzcholkow;
	}
	catch (...)
	{
		return Graf(-1);
	}
	Graf graf = Graf(liczbaWierzcholkow);

	string w1, w2, odleglosc;
	while (!plik.eof())
	{
		try {
			plik >> w1;
			plik >> w2;
			plik >> odleglosc;

		graf.wprowadzPolaczenie(stoi(w2), stoi(w1), stoi(odleglosc));

		}
		catch (...)
		{
			return Graf(-1);
		}
	}

	plik.close();
			
	cout << "Pomyslnie zaladowano graf, liczba wierzcholkow = " << liczbaWierzcholkow << endl;

	return graf;
	

}