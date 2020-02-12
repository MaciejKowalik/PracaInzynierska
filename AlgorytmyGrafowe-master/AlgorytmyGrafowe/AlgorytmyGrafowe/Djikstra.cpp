#include "Djikstra.h"
#include <iostream>
#include <algorithm>

bool sortujWierzcholki(const pair<int, int>& a,
	const pair<int, int>& b)
{
	return (a.second > b.second);
}

void Djikstra::wykonajAlgorytm(Graf graf)
{

	int limit = graf.getLiczbaWierzcholkow() + 1;
	vector< pair <int,int> > Q;
	vector<int> odleglosci(limit);

	pair <int, int> wierzcholek;
	vector<int> nastepnikiWierzcholka;
	double sprawdzenie;
	for (int i = 1; i < limit; i++)
	{
		odleglosci[i] = graf.odczytajPolaczenie(i, 1);

		Q.push_back(make_pair(i, odleglosci[i]));
	}
	
	make_heap(Q.begin(), Q.end(), sortujWierzcholki);
	pop_heap(Q.begin(), Q.end());
	Q.pop_back();

	while (!Q.empty())
	{
		make_heap(Q.begin(), Q.end(), sortujWierzcholki);

		wierzcholek.first = Q[0].first;
		wierzcholek.second = Q[0].second;

		pop_heap(Q.begin(), Q.end());
		Q.pop_back();

		for (int i = 1; i < limit; i++)
		{
			if (graf.odczytajPolaczenie(i, wierzcholek.first) != INT_MAX && graf.odczytajPolaczenie(i, wierzcholek.first) != 0)
			{
				nastepnikiWierzcholka.push_back(i);
			}
		}

		for (int i = 0; i < nastepnikiWierzcholka.size(); i++)
		{
			double sprawdzenie = (double)odleglosci[wierzcholek.first] + (double)graf.odczytajPolaczenie(nastepnikiWierzcholka[i], wierzcholek.first);
			if (sprawdzenie < odleglosci[nastepnikiWierzcholka[i]])
			{
				odleglosci[nastepnikiWierzcholka[i]] = odleglosci[wierzcholek.first] + graf.odczytajPolaczenie(nastepnikiWierzcholka[i], wierzcholek.first);
			}
		}

		int tmp;

		for (int i = 0; i < Q.size(); i++)
		{
			tmp = Q[i].first;

			if (Q[i].second != odleglosci[tmp])
			{
				Q[i].second = odleglosci[tmp];
			}
		}
	}


	for (int i = 1; i < limit; i++)
	{
		if (odleglosci[i] != INT_MAX)
		{
			cout << "D[" << i << "] = " << odleglosci[i] << "\t";
		}
		else
		{
			cout << "D[" << i << "] = -\t";
		}
	}


}