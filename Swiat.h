#pragma once
#include "Organizm.h"
class Organizm;

struct Organizmy {
	bool occupied;
	Organizm *organizm;
};

class Swiat {
private: 

	int liczba;
	int silaczlowieka, cooldownczlowieka, cooldownczlowiekaUzycie;
	int liczniksmierci;

	Organizm **org;
	Organizmy **organizmy;

	Swiat* nowyptr;
	
public:
	
	const int n, m; 

	
	Swiat(int n, int m);
	void wykonajTure();
	void rysujSwiat();
	void zniszczono();
	int getLiczba();
	void dodajOrganizm(Organizm *org);
	void przesun(int start);
	void setIndexes();

	void setsila(int x);
	void setcooldown(int x, int y);
	void setLiczba(int x);



	int getliczniksmierci();

	void addliczniksmierci();

	void spawn(Swiat* help);

	void fillHelper(Swiat* help);

	void quickSort(Organizm *arr[], int low, int high);

	int partition(Organizm *arr[], int low, int high);

	void swap(Organizm** arr, int i, int j);

	Organizm** getOrganizm();
	Organizmy** getOrganizmy();

	Swiat* getnowyptr();
};