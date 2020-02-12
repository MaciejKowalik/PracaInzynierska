#include "Graf.h"
#include <climits>

Graf::Graf()
{
}

Graf::Graf(int liczbaWierzcholkow)
{
	this->liczbaWierzcholkow = liczbaWierzcholkow;

	int limit = liczbaWierzcholkow + 1;

	macierz.resize(limit);

	for (int i = 0; i < limit; i++)
	{
		macierz[i].resize(limit);
	}


	for (int i = 0; i < limit; i++)
	{
		for (int j = 0; j < limit; j++)
		{
			if (i == j && i != 0)
			{
				macierz[i][j] = 0;
			}
			else
			{
				macierz[i][j] = INT_MAX;
			}
		}

	}
}

Graf::~Graf()
{
}

int Graf::getLiczbaWierzcholkow()
{
	return liczbaWierzcholkow;
}

void Graf::setLiczbaWierzcholkow(int liczbaWierzcholkow)
{
	this->liczbaWierzcholkow = liczbaWierzcholkow;
}
void Graf::wprowadzPolaczenie(int x, int y, int odleglosc)
{
	macierz[x][y] = odleglosc;
}

int Graf::odczytajPolaczenie(int x, int y)
{
	return macierz[x][y];
}

