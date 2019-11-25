#pragma once

#include "Roslina.h"

using namespace std;

class Guarana : public Roslina {
public:

	Guarana(int x, int y, Swiat *swiat);
	bool kolizja(Organizm* org, bool *alive);
};