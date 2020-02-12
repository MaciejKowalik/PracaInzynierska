#pragma once
#include "Algorytm.h"
/*
 * Klasa WyszukajWGlab bêd¹ca klas¹ pochodn¹ po klasie Algorytm. Dziedziczy metode wykonajAlgorytm klasy Algorytm i posiada
 * jej w³asn¹ implementacjê, realizuj¹c¹ algorytm przeszukiwania grafu w g³¹b na zadanym grafie.
 */
class WyszukajWGlab :
	public Algorytm
{
public:
	void wykonajAlgorytm(Graf graf);
};

