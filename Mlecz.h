#pragma once
#pragma once


#include "Roslina.h"

using namespace std;

class Mlecz : public Roslina {
public:

	Mlecz(int x, int y, Swiat *swiat);
	void akcja(int seed);
};