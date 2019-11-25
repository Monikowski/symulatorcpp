#include "Header.h"

Zolw::Zolw(int x, int y, Swiat *swiat, int cd, int sila) : Zwierze(GEST_ZOL, ID_ZOL, INIC_ZOL, SYMB_ZOL, x, y, cd, sila, swiat) {
}

void Zolw::akcja(int seed) {
	srand(time(0));
	if (rand() % 4 == 0) {
		nowyruch(x, y, seed);
	}
}

bool Zolw::kolizja(Organizm* org, bool *alive) {
	if (org->getSila() < 5)
		return false;
	else return true;
}
