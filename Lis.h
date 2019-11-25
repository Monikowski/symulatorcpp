#pragma once
#include "Zwierze.h"

using namespace std;

class Lis : public Zwierze {
public:

	Lis(int x, int y, Swiat *swiat, int cd, int sila);

	void akcja(int seed) override;

	bool czyBezpiecznie(int x, int y);

	bool czyMozliwyRuch(int x, int y);

	int ruchyDookola(int tab[4][2], int count, int x, int y) override;
};