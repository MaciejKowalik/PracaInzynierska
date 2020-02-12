#pragma once
#include "Algorytm.h"
/*
 * Klasa FloydWarshall bêd¹ca klas¹ pochodn¹ po klasie Algorytm. Dziedziczy metode wykonajAlgorytm klasy Algorytm i posiada
 * jej w³asn¹ implementacjê, realizuj¹c¹ algorytm Floyda-Warshalla na zadanym grafie.
 */
class FloydWarshall :
	public Algorytm
{
public:
	void wykonajAlgorytm(Graf graf);
};

