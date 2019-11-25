#include "Header.h"


Mlecz::Mlecz(int x, int y, Swiat *swiat) : Roslina(GEST_MLE, ID_MLE, INIC_MLE, SYMB_MLE, x, y, CD_MLE, SILA_MLE, swiat) {
}

void Mlecz::akcja(int seed) {
	for (int i = 0; i < 3; i++) {
		srand(rand()*rand());
		seed = rand();
		if (rand() % 100 <= ROZ_MLE) {
			rozrost(seed);
		}
	}
}

