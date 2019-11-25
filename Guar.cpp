#include "Header.h"


Guarana::Guarana(int x, int y, Swiat *swiat) : Roslina(GEST_GUA, ID_GUA, INIC_GUA, SYMB_GUA, x, y, CD_GUA, SILA_GUA, swiat) {
}

bool Guarana::kolizja(Organizm* org, bool *alive) {
	org->setSila(3);
	return true;
}
