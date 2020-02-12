#pragma once
#include "Graf.h"
#include <string>

using namespace std;

/*
 * Klasa WczytajDane zawieraj¹ca metody zapewniaj¹ce ³adowanie danych o grafie z pliku.
 * Dane wczytywane mog¹ byæ w formie macierzy (metoda wczytajMacierzSasiedztwa) lub listy s¹siedztwa (metoda wczytajListeSasiedztwa)
 * z pliku o zadanej nazwie.
 */

class WczytajDane
{
public:
	static Graf wczytajListeSasiedztwa(int &liczbaWierzcholkow, string nazwaPliku);

	static Graf wczytajMacierzSasiedztwa(int &liczbaWierzcholkow, string nazwaPliku);
};

