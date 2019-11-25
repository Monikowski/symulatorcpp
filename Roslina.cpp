#include "Header.h"

int Roslina::sprawdz(int tab[4][2], int count, int x, int y) {
	 {
		int m = this->swiat->m;
		int n = this->swiat->n;
		if ((x + 1) < n && this->swiat->getOrganizmy()[x + 1][y].occupied == false) {
			tab[count][0] = x + 1;
			tab[count][1] = y;
			count++;
		}
		if ((x - 1) > -1 && this->swiat->getOrganizmy()[x - 1][y].occupied == false) {
			tab[count][0] = x - 1;
			tab[count][1] = y;
			count++;
		}
		if ((y - 1) > -1 && this->swiat->getOrganizmy()[x][y - 1].occupied == false) {
			tab[count][0] = x;
			tab[count][1] = y - 1;
			count++;
		}
		if ((y + 1) < m && this->swiat->getOrganizmy()[x][y + 1].occupied == false) {
			tab[count][0] = x;
			tab[count][1] = y + 1;
			count++;
		}
		return count;
	};
}

Roslina::Roslina(const double & gestosc, const int & id, const int & inic, const char & symbol, int x, int y, int cooldown, int sila, Swiat* swiat)
	: Organizm(gestosc, id, inic, symbol, x, y, cooldown, sila, swiat) {};

void Roslina::akcja(int seed) {
	srand(seed);
		
	switch (id) {

	case 7:
		if (rand() % 100 <= ROZ_TRA) {
			rozrost(seed);
		}
		break;
	case 9:
		if (rand() % 100 <= ROZ_GUA) {
			rozrost(seed);
		}
		break;
	case 10:
		if (rand() % 100 <= ROZ_JAG) {
			rozrost(seed);
		}
		break;
	}
}

void Roslina::rozrost(int seed) {
	srand(seed);
	int count = 0;
	int arr[4][2];
	count = sprawdz(arr, count, x, y);
	if (count) {
		count = rand() % count;
		int newx = arr[count][0];
		int newy = arr[count][1];

		switch (id) {
		case 7:
			swiat->dodajOrganizm(new Trawa(newx, newy, swiat));
			break;
		case 8:
			swiat->dodajOrganizm(new Mlecz(newx, newy, swiat));
			break;
		case 9:
			swiat->dodajOrganizm(new Guarana(newx, newy, swiat));
			break;
		case 10:
			swiat->dodajOrganizm(new Jagody(newx, newy, swiat));
			break;
		case 11:
			swiat->dodajOrganizm(new Barszcz(newx, newy, swiat));
			break;
		}
	}
}