#pragma once
#include "Algorytm.h"
/*
 * Klasa BellmanFord bêd¹ca klas¹ pochodn¹ po klasie Algorytm. Dziedziczy metode wykonajAlgorytm klasy Algorytm i posiada
 * jej w³asn¹ implementacjê, realizuj¹c¹ algorytm Bellmana-Forda na zadanym grafie.
 */
class BellmanFord :
	public Algorytm
{
public:
	void wykonajAlgorytm(Graf graf);
};

