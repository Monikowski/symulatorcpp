#pragma once
#include "Organizm.h"

class Roslina : public Organizm {
public:

	virtual void akcja(int seed);
	void rozrost(int seed);
	int sprawdz(int tab[4][2], int count, int x, int y);

	Roslina(const double & gestosc, const int & id, const int & inic, const char & symbol, int x, int y, int cooldown, int sila, Swiat* swiat);
};