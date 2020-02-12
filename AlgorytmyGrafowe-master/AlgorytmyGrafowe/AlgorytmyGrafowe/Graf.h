#pragma once
#include <vector>

using namespace std;
class Graf
{
private:

	vector<vector<int>> macierz;
	int liczbaWierzcholkow;

public:

	Graf();

	Graf(int liczbaWierzcholkow);

	~Graf();

	int getLiczbaWierzcholkow();

	void setLiczbaWierzcholkow(int liczbaWierzcholkow);
	
	void wprowadzPolaczenie(int x, int y, int odleglosc);

	int odczytajPolaczenie(int x, int y);

};

