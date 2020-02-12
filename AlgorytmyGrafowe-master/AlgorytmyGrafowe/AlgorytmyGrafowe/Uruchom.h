#pragma once
/*
 * Klasa Uruchom odpowiadaj¹ca za uruchomienie odpowiedniego algorytmu w zale¿noœci od zadanych parametrów z wiersza poleceñ.
 * Metoda uruchom przyjmuje jako argumenty liczbê wprowadzonych parametrów oraz ich wartoœci. Na ich podstawie uruchamia metodê
 * z jednej z klas pochodnych klasy Algorytm lub zwraca odpowiednie komunikaty o niepoprawnie wprowadzonych danych.
 */
class Uruchom
{
public:
	static void uruchom(int argc, char* argv[]);
};

