#pragma once
#include "Zwierze.h"

class Swiat;

class Zolw : public Zwierze {

public:

	Zolw(int x, int y, Swiat *swiat, int cd, int sila);
	void akcja(int seed) override;
	bool kolizja(Organizm *org, bool *alive) override;
};