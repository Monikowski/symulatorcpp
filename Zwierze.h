#pragma once
#include "Organizm.h"

class Zwierze : public Organizm {
public:

	virtual void akcja(int seed);
	 
	bool rozmnoz(int x1, int y1, int x2, int y2, Organizm *organizm);

	virtual void setCooldown() override;

	virtual void zderzenie(Organizmy organizm, int x2, int y2, bool* alive);

	int sprawdzDookola(int tab[8][2], int count, int x, int y);

	virtual int ruchyDookola(int arr[4][2], int count, int x, int y);

	void nowyruch(int x, int y, int seed);

	void ruchX(int ruch);
	void ruchY(int ruch);

	void newxy(int arr[2]);

	Zwierze(const double & gestosc, const int & id, const int & inic, const char & symbol, int x, int y, int cooldown, int sila, Swiat* swiat);
};