#pragma once

#include "Roslina.h"

using namespace std;

class Jagody : public Roslina {
public:

	Jagody(int x, int y, Swiat *swiat);
	bool kolizja(Organizm* org, bool *alive);
};