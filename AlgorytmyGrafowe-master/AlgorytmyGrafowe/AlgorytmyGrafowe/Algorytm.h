#pragma once
#include "Graf.h"
/*
 * Klasa Algorytm zawieraj¹ca metodê wirtualn¹ wykonajAlgorytm zdefiniowan¹ w klasach pochodnych,
 * odpowiedzialna za wykonanie na grafie (przekazanym jako argument) wprowadzonego przez u¿ytkownika algorytmu
 */
class Algorytm
{
public:
	virtual void wykonajAlgorytm(Graf graf) = 0;
};
