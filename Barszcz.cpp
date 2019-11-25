#include "Header.h"

bool Barszcz::kolizja(Organizm* org, bool *alive) {
	this->ktozabil = org->id;
	org->setKtozabil(id);
	delete org;
	delete this;
	*alive = false;
	return false;
}


Barszcz::Barszcz(int x, int y, Swiat *swiat) : Roslina(GEST_BAR, ID_BAR, INIC_BAR, SYMB_BAR, x, y, CD_BAR, SILA_BAR, swiat) {
}

int Barszcz::cele(int tab[4][2], int count, int x, int y) {
	int m = this->swiat->m;
	int n = this->swiat->n;
	if ((x + 1) < n && this->swiat->getOrganizmy()[x + 1][y].occupied == true && this->swiat->getOrganizmy()[x + 1][y].organizm->id < 6) {
		tab[count][0] = x + 1;
		tab[count][1] = y;
		count++;
	}
	if ((x - 1) > -1 && this->swiat->getOrganizmy()[x - 1][y].occupied == true && this->swiat->getOrganizmy()[x - 1][y].organizm->id < 6) {
		tab[count][0] = x - 1;
		tab[count][1] = y;
		count++;
	}
	if ((y - 1) > -1 && this->swiat->getOrganizmy()[x][y - 1].occupied == true && this->swiat->getOrganizmy()[x][y - 1].organizm->id < 6) {
		tab[count][0] = x;
		tab[count][1] = y - 1;
		count++;
	}
	if ((y + 1) < m && this->swiat->getOrganizmy()[x][y + 1].occupied == true && this->swiat->getOrganizmy()[x][y + 1].organizm->id < 6) {
		tab[count][0] = x;
		tab[count][1] = y + 1;
		count++;
	}
	return count;
}

void Barszcz::akcja(int seed) {
	srand(seed);
	if (rand() % 4 == 0) {
		int count = 0;
		int arr[4][2];
		count = cele(arr, count, x, y);
		for (int i = 0; i < count; i++) {
			swiat->getOrganizmy()[arr[i][0]][arr[i][1]].organizm->setKtozabil(id);
			delete swiat->getOrganizmy()[arr[i][0]][arr[i][1]].organizm;
		}
	}

	srand(seed);
	if (rand() % 100 <= ROZ_BAR) {
		seed = rand();
		rozrost(seed);
	}
}

