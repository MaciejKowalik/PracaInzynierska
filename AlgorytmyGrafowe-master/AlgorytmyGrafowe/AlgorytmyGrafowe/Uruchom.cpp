#include "Uruchom.h"
#include "Algorytm.h"
#include "WczytajDane.h"
#include "BellmanFord.h"
#include "Djikstra.h"
#include "FloydWarshall.h"
#include "WyszukajWGlab.h"
#include "WyszukajWszerz.h"
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

void Uruchom::uruchom(int argc, char* argv[])
{

	if (argc == 6)
	{
		string algorytm(argv[1]);
		string przelacznik1(argv[2]);
		string danePrzelacznik1(argv[3]);
		string przelacznik2(argv[4]);
		string danePrzelacznik2(argv[5]);

		string daneWejsciowe;
		string sposobWczytywania;
		int liczbaWierzcholkow;
		Graf graf;

		if (przelacznik1.compare("-i") == 0 && przelacznik2.compare("-s") == 0)
		{
			daneWejsciowe = danePrzelacznik1;
			sposobWczytywania = danePrzelacznik2;
		}
		else if (przelacznik2.compare("-i") == 0 && przelacznik1.compare("-s") == 0)
		{
			daneWejsciowe = danePrzelacznik2;
			sposobWczytywania = danePrzelacznik1;
		}
		else
		{
			cout << "Niepoprawnie wprowadzone nazwy przelacznikow" << endl;
			return;
		}


		if (sposobWczytywania.compare("lista") == 0)
		{
			graf = WczytajDane::wczytajListeSasiedztwa(liczbaWierzcholkow, daneWejsciowe);
		}
		else if (sposobWczytywania.compare("macierz") == 0)
		{
			graf = WczytajDane::wczytajMacierzSasiedztwa(liczbaWierzcholkow, daneWejsciowe);
		}
		else
		{
			cout << "Niepoprawna nazwa parametru: sposob wczytywania" << endl;
			return;
		}

		if (graf.getLiczbaWierzcholkow() == -1)
		{
			cout << "Niepomysle zaladowanie danych, sprawdz wprowadzone pliki" << endl;
			return;
		}
		enum nazwyAlgorytmow { Brak, BellF, Djik, FloyW, B, D };

		map<string, nazwyAlgorytmow> algorytmy;

		algorytmy["BellmanFord"] = BellF;
		algorytmy["Djikstra"] = Djik;
		algorytmy["FloydWarshall"] = FloyW;
		algorytmy["BFS"] = B;
		algorytmy["DFS"] = D;

		Algorytm* wsk = nullptr;

		switch (algorytmy[algorytm])
		{
		case BellF:
		{
			wsk = new BellmanFord();
			break;
		}
		case Djik:
		{
			wsk = new Djikstra();
			break;
		}
		case FloyW:
		{
			wsk = new FloydWarshall();
			break;
		}
		case B:
		{
			wsk = new WyszukajWszerz();
			break;
		}
		case D:
		{
			wsk = new WyszukajWGlab();
			break;
		}

		case Brak:
		{
			cout << "Niepoprawna nazwa algorytmu" << endl;
			return;
		}
		}
		wsk->wykonajAlgorytm(graf);

		cout << "WYKONYWANIE ALGORYTMU ZAKONCZONE" << endl;
	}
	else
	{
		cout << "Niepoprawna liczba argumentow" << endl;
		return;
	}

	
}