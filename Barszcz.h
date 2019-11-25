#pragma once

#include "Roslina.h"

using namespace std;

class Barszcz : public Roslina {
public:

	Barszcz(int x, int y, Swiat *swiat);
	bool kolizja(Organizm* org, bool *alive);
	void akcja(int seed) override;
	int cele(int tab[4][2], int count, int x, int y);
}; 
