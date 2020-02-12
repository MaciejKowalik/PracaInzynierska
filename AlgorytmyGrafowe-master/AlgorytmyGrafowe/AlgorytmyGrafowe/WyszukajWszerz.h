#pragma once
#include "Algorytm.h"
/*
 * Klasa WyszukajWszerz bêd¹ca klas¹ pochodn¹ po klasie Algorytm. Dziedziczy metode wykonajAlgorytm klasy Algorytm i posiada
 * jej w³asn¹ implementacjê, realizuj¹c¹ algorytm przeszukiwania grafu wszerz na zadanym grafie.
 */
class WyszukajWszerz :
	public Algorytm
{
public:
	void wykonajAlgorytm(Graf graf);
};
