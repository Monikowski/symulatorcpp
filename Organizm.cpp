#include "Header.h"

using namespace std;

HANDLE console3 = GetStdHandle(STD_OUTPUT_HANDLE);


Organizm::~Organizm() {
	smierc(ktozabil);
	swiat->przesun(index);
	swiat->getOrganizmy()[x][y].occupied = false;
}
 
Organizm::Organizm(const double & gestosc, const int & id, const int & inic, const char & symbol, int x, int y, int cooldown, int sila, Swiat*swiat)
	: gestosc(gestosc), id(id), inic(inic),	symbol(symbol), x(x), y(y), cooldown(cooldown), sila(sila), swiat(swiat) {
	this->swiat->getOrganizmy()[x][y].occupied = true;
	this->swiat->getOrganizmy()[x][y].organizm = this;
	this->wiek = 0;
}

bool Organizm::kolizja(Organizm *org, bool *alive) { // domyslnie kolizja nic nie robi, czyli dajac true-> pozwala na atak (gdzie nastepuje porownanie sil)
	return true;
}

void Organizm::smierc(int ktozabil) {
	gotoxy(32 + swiat->n, 10 + swiat->getliczniksmierci());

	if (ktozabil == 0)
		SetConsoleTextAttribute(console3, 10);

	switch (id) {

		case 0:
			SetConsoleTextAttribute(console3, 4);
			cout << "Czlowiek x: " << x << " y: " << y << " umiera zabity przez " << zabojca(ktozabil);
			break;
		case 1:
			cout << "Wilk x: " << x << " y: " << y << " umiera zabity przez " << zabojca(ktozabil);
			break;	
		case 2:
			cout << "Owca x: " << x << " y: " << y << " umiera zabita przez " << zabojca(ktozabil);
			break;	
		case 3:
			cout << "Lis x: " << x << " y: " << y << " umiera zabity przez " << zabojca(ktozabil);
			break;
		case 4:
			cout << "Zolw x: " << x << " y: " << y << " umiera zabity przez " << zabojca(ktozabil);
			break;
		case 5:
			cout << "Antylopa x: " << x << " y: " << y << " umiera zabita przez " << zabojca(ktozabil);
			break;

		case 7:
			cout << "Trawa x: " << x << " y: " << y << " zostaje zjedzona przez " << zabojca(ktozabil);
			break;
		case 8:
			cout << "Mlecz x: " << x << " y: " << y << " zostaje zjedzony przez " << zabojca(ktozabil);
			break;
		case 9:
			cout << "Guarana x: " << x << " y: " << y << " zostaje zjedzona przez " << zabojca(ktozabil);
			break;
		case 10:
			cout << "Wilcze jagody x: " << x << " y: " << y << " zostaja zjedzone przez " << zabojca(ktozabil);
			break;
		case 11:
			cout << "Barszcz sosnowskiego x: " << x << " y: " << y << " zostaje zjedzony przez " << zabojca(ktozabil);
			break;

	}
	SetConsoleTextAttribute(console3, 7);
	swiat->addliczniksmierci();
}


int Organizm::getX() {
	return x;
};

int Organizm::getY() {
	return y;
}
void Organizm::setX(int x) {
	this->x = x;
}
void Organizm::setY(int y) {
	this->y = y;
}

int Organizm::getWiek() {
	return wiek;
}
 void Organizm::addWiek() {
	wiek++;
	if (cooldown > 0)
		cooldown--;
}


void Organizm::setIndex(int i) {
	index = i;
}

 void Organizm::setCooldown() {
	cooldown = 5;
}

int Organizm::getCooldown() {
	return cooldown;
}

const char* Organizm::zabojca(int kto) {

	switch (kto) {

		case 0:
			return "Czlowieka";
			break;
		case 1:
			return "Wilka";
			break;
		case 2:
			return "Owce";
			break;
		case 3:
			return "Lisa";
			break;
		case 4:
			return "Zolwia";
			break;
		case 5:
			return "Antylope";
			break;
		case 10:
			return "Wilcze jagody";
			break;
		case 11:
			return "Barszcz sosnowskiego";
			break;

	}
}


int Organizm::getSila() {
	return sila;
}

void Organizm::setSila(int x) {
	sila = sila + x;
}



void Organizm::setKtozabil(int x) {
	ktozabil = x;
}

void Organizm::stworznowy(int x, int y, Swiat* swiat) {
	
	switch (id) {

	case 1: 
		swiat->dodajOrganizm(new Wilk(x, y, swiat, 0, SILA_WIL));
		break;
	case 2:
		swiat->dodajOrganizm(new Owca(x, y, swiat, 0, SILA_OWC));
		break;
	case 3:
		swiat->dodajOrganizm(new Lis(x, y, swiat, 0, SILA_LIS));
		break;
	case 4:
		swiat->dodajOrganizm(new Zolw(x, y, swiat, 0, SILA_ZOL));
		break;
	case 5:
		swiat->dodajOrganizm(new Antylopa(x, y, swiat, 0, SILA_ANT));
		break;

	case 7:
		swiat->dodajOrganizm(new Trawa(x, y, swiat));
		break;
	case 8:
		swiat->dodajOrganizm(new Mlecz(x, y, swiat));
		break;
	case 9:
		swiat->dodajOrganizm(new Guarana(x, y, swiat));
		break;
	case 10:
		swiat->dodajOrganizm(new Jagody(x, y, swiat));
		break;
	case 11:
		swiat->dodajOrganizm(new Barszcz(x, y, swiat));
		break;

	}

}

int Organizm::getcdu() {
	return 0;
}