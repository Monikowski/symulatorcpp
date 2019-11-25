#pragma once

#include "Zwierze.h"


class Czlowiek : public Zwierze {
private: 
	int cooldownUzycie;

public:
	

		void akcja(int seed) override;
		Czlowiek(int x, int y, Swiat *swiat, int cduz, int cd, int sila);
		//void kolizja(Organizmy organizm, int x2, int y2);
		void addWiek() override;
		virtual bool rozmnoz(int x1, int y1, int x2, int y2, Organizm *organizm) { return true; };
		~Czlowiek();
		int getcdu();
	};
	