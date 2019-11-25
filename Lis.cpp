#include "Header.h"

Lis::Lis(int x, int y, Swiat *swiat, int cd, int sila) : Zwierze(GEST_LIS, ID_LIS, INIC_LIS, SYMB_LIS, x, y, cd, sila, swiat) {
}

bool Lis::czyBezpiecznie(int x, int y) {
	if (swiat->getOrganizmy()[x][y].occupied == false)
		return true;
	else if (swiat->getOrganizmy()[x][y].organizm->getSila() <= sila)
		return true;
	else if (swiat->getOrganizmy()[x][y].organizm->id == this->id)
		return true;
	else return false;
}

bool Lis::czyMozliwyRuch(int x, int y) {
	if (((x + 1) < swiat->n) && czyBezpiecznie(x + 1, y)) 
		return true;	
	else if (((x - 1) > -1) && czyBezpiecznie(x - 1, y))
		return true;
	else if (((y + 1) < swiat->m) && czyBezpiecznie(x, y + 1))
		return true;
	else if (((y - 1) > -1) && czyBezpiecznie(x, y - 1))
		return true;
	else return false;
}

int Lis::ruchyDookola(int tab[4][2], int count, int x, int y) {
	int m = this->swiat->m;
	int n = this->swiat->n;
	if ((x + 1) < n  && czyBezpiecznie(x + 1, y)) {
		tab[count][0] = x + 1;
		tab[count][1] = y;
		count++;
	}
	if ((x - 1) > -1 && czyBezpiecznie(x - 1, y)) {
		tab[count][0] = x - 1;
		tab[count][1] = y;
		count++;
	}
	if ((y - 1) > -1 && czyBezpiecznie(x, y - 1)) {
		tab[count][0] = x;
		tab[count][1] = y - 1;
		count++;
	}
	if ((y + 1) < m && czyBezpiecznie(x, y + 1)) {
		tab[count][0] = x;
		tab[count][1] = y + 1;
		count++;
	}
	return count;
}

void Lis::akcja(int seed) {
	if (czyMozliwyRuch(x, y)) {
		nowyruch(x, y, seed);
	}
}
