#include "Header.h"

Jagody::Jagody(int x, int y, Swiat *swiat) : Roslina(GEST_JAG, ID_JAG, INIC_JAG, SYMB_JAG, x, y, CD_JAG, SILA_JAG, swiat) {
}

bool Jagody::kolizja(Organizm* org, bool *alive) {
	this->ktozabil = org->id;
	org->setKtozabil(id);
	delete org;
	delete this;
	*alive = false;
	return false;
}

