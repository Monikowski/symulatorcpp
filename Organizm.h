#pragma once
#include "Swiat.h"
#include "conio2.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;


class Swiat;
struct Organizmy;

class Organizm {
protected:

	int x, y, wiek, index, cooldown, sila, ktozabil;
	Swiat *swiat;
	
public:

	const int  id, inic;
	const char symbol;
	const double gestosc;

	virtual void akcja(int seed) = 0;
	virtual bool kolizja(Organizm *org, bool *alive);
	void smierc(int ktozabil);

	int getX();
	int getY();
	void setX(int x);
	void setY(int y);

	int getWiek();
	virtual void addWiek();

	virtual ~Organizm();

	void setIndex(int i);

	virtual void setCooldown();

	int getCooldown();

	const char* zabojca(int kto);

	int getSila();

	virtual int getcdu();

	void setSila(int x);

	void setKtozabil(int x);

	void stworznowy(int x, int y, Swiat* swiat);

	Organizm(const double & gestosc, const int & id, const int & inic, const char & symbol, int x, int y, int cooldown, int sila, Swiat* swiat);
};