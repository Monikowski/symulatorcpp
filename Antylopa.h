#pragma once
#include "Zwierze.h"

class Swiat;

class Antylopa : public Zwierze {

public:


	Antylopa(int x, int y, Swiat *swiat, int cd, int sila);
	bool kolizja(Organizm *org, bool *alive) override;
	int ruchyDookola(int tab[4][2], int count, int x, int y);
};