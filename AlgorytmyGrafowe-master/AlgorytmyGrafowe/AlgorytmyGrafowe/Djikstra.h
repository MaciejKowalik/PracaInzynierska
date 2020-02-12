#pragma once
#include "Algorytm.h"
/*
 * Klasa Djikstra bêd¹ca klas¹ pochodn¹ po klasie Algorytm. Dziedziczy metode wykonajAlgorytm klasy Algorytm i posiada
 * jej w³asn¹ implementacjê, realizuj¹c¹ algorytm Djikstry na zadanym grafie.
 */
class Djikstra :
	public Algorytm
{
public:
	void wykonajAlgorytm(Graf graf);

};

