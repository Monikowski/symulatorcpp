#include "Header.h"

void Zwierze::akcja(int seed) {
	nowyruch(x, y, seed);
}

Zwierze::Zwierze(const double & gestosc, const int & id, const int & inic, const char & symbol, int x, int y, int cooldown, int sila, Swiat* swiat) 
	: Organizm(gestosc, id, inic, symbol, x, y, cooldown, sila, swiat) {}

void Zwierze::zderzenie(Organizmy organizm, int x2, int y2, bool *alive) {
	int x1 = this->getX();
	int y1 = this->getY();
	if (this->id == organizm.organizm->id) {
		rozmnoz(x1, y1, x2, y2, organizm.organizm);
		return;
	}
	else if (organizm.organizm->kolizja(this, alive)) { // dla zolwia -> kolizja returnuje false dla atakujacego o sile < 5, dla antylopy false jezeli ma gdzie uciec, wtedy przesuwa
												 //atakujacego na stara pozycje, jak nie ma gdzie isc to zwraca true i sie bija (domyslnie zwierzeta sie bija wiec jest true)
		if (this->sila >= organizm.organizm->getSila()) {
			organizm.organizm->setKtozabil(id);
			delete organizm.organizm;
		}
		else {
			this->ktozabil = organizm.organizm->id;
			delete this;
			*alive = false;
		}
	}
};

int Zwierze::sprawdzDookola(int tab[8][2], int count, int x, int y) {
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

int Zwierze::ruchyDookola(int tab[4][2], int count, int x, int y) {
	int m = this->swiat->m;
	int n = this->swiat->n;
	if ((x + 1) < n) {
		tab[count][0] = x + 1;
		tab[count][1] = y;
		count++;
	}
	if ((x - 1) > -1) {
		tab[count][0] = x - 1;
		tab[count][1] = y;
		count++;
	}
	if ((y - 1) > -1) {
		tab[count][0] = x;
		tab[count][1] = y - 1;
		count++;
	}
	if ((y + 1) < m) {
		tab[count][0] = x;
		tab[count][1] = y + 1;
		count++;
	}
	return count;
}

void Zwierze::nowyruch(int x, int y, int seed) {
	int arr[4][2];
	int count = 0;
	srand(seed);
	count = ruchyDookola(arr, count, x, y);
	count = rand() % count;
	int newx = arr[count][0];
	int newy = arr[count][1];
	bool alive = true;

		if (this->swiat->getOrganizmy()[newx][newy].occupied == true) {
			zderzenie(this->swiat->getOrganizmy()[newx][newy], newx, newy, &alive);
		}

		if (alive && this->swiat->getOrganizmy()[newx][newy].occupied == false) {
			this->swiat->getOrganizmy()[x][y].occupied = false;
			this->swiat->getOrganizmy()[newx][newy].occupied = true;
			this->swiat->getOrganizmy()[newx][newy].organizm = this;
			newxy(arr[count]);
		}


}

void Zwierze::ruchX(int ruch) {
	x = x + ruch;
}
void Zwierze::ruchY(int ruch) {
	y = y + ruch;
}

void Zwierze::newxy(int arr[2]) {
	x = arr[0];
	y = arr[1];
}


bool Zwierze::rozmnoz(int x1, int y1, int x2, int y2, Organizm *inne) {
	if (this->getCooldown() == 0 && inne->getCooldown() == 0) {
		this->setCooldown();
		inne->setCooldown();
		int tab[8][2];
		int count = 0;
		count = sprawdzDookola(tab, count, x1, y1);
		count = sprawdzDookola(tab, count, x2, y2);
		if (count > 0) {
			srand(time(0));
			int x = rand() % count;

			switch (id) {
			
			case 1:
				this->swiat->dodajOrganizm(new Wilk(tab[x][0], tab[x][1], swiat, CD_WIL, SILA_WIL));
				break;
			case 2:
				this->swiat->dodajOrganizm(new Owca(tab[x][0], tab[x][1], swiat, CD_OWC, SILA_OWC));
				break;
			case 3:
				this->swiat->dodajOrganizm(new Lis(tab[x][0], tab[x][1], swiat, CD_LIS, SILA_LIS));
				break;
			case 4:
				this->swiat->dodajOrganizm(new Zolw(tab[x][0], tab[x][1], swiat, CD_ZOL, SILA_ZOL));
				break;
			case 5:
				this->swiat->dodajOrganizm(new Antylopa(tab[x][0], tab[x][1], swiat, CD_ANT, SILA_ANT));
				break;

			}
			return true;
		}
		else return false;
	}
	else return false;
}

void Zwierze::setCooldown() {

	switch (id) {

	case 1:	
		cooldown = CD_WIL;
		break;
	case 2:
		cooldown = CD_OWC;
		break;
	case 3:
		cooldown = CD_LIS;
		break;
	case 4:	
		cooldown = CD_ZOL;
		break;
	case 5: 
		cooldown = CD_ANT;
		break;

	default:
		cooldown = CD_ROS;
		break;

	}
}