#include "Header.h"

Antylopa::Antylopa(int x, int y, Swiat *swiat, int cd, int sila) : Zwierze(GEST_ANT, ID_ANT, INIC_ANT, SYMB_ANT, x, y, cd, sila, swiat) {
}

int Antylopa::ruchyDookola(int tab[4][2], int count, int x, int y) {
	int m = this->swiat->m;
	int n = this->swiat->n;
	if ((x + 2) < n) {
		tab[count][0] = x + 2;
		tab[count][1] = y;
		count++;
	}
	if ((x - 2) > -1) {
		tab[count][0] = x - 2;
		tab[count][1] = y;
		count++;
	}
	if ((y - 2) > -1) {
		tab[count][0] = x;
		tab[count][1] = y - 2;
		count++;
	}
	if ((y + 2) < m) {
		tab[count][0] = x;
		tab[count][1] = y + 2;
		count++;
	}
	return count;
}


bool Antylopa::kolizja(Organizm* org, bool *alive) {
	srand(time(0));
	if (rand() % 2 == 1) {
		int arr[8][2];
		int count = 0;
		count = sprawdzDookola(arr, count, x, y);
		if (count == 0)
			return true;
		else {
			srand(rand());
			count = rand() % count;
			int newx = arr[count][0];
			int newy = arr[count][1];

			this->swiat->getOrganizmy()[x][y].organizm = org;
			this->swiat->getOrganizmy()[newx][newy].occupied = true;
			this->swiat->getOrganizmy()[newx][newy].organizm = this;
			this->swiat->getOrganizmy()[org->getX()][org->getY()].occupied = false;
			org->setX(x);
			org->setY(y);
			newxy(arr[count]);
			return false;
		}

	}
	else return true;
}