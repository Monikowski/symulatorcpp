#include "Header.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

HANDLE console2 = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

Czlowiek::Czlowiek(int x, int y, Swiat *swiat, int cduz, int cd, int sila) : Zwierze(0, ID_CZL, INIC_CZL, SYMB_CZL, x, y, cd, sila, swiat) {
	this->cooldownUzycie = cduz;
	swiat->setcooldown(cooldown, cooldownUzycie);
	swiat->setsila(sila);
}

void Czlowiek::addWiek() {
	wiek++;

	if (cooldown == 0 && cooldownUzycie > 0) {
		cooldownUzycie--;
	}

	if (cooldown > 0) {
		cooldown--;
		sila--;
	}
}

void Czlowiek::akcja(int seed) {


	this->swiat->rysujSwiat();

	int flag = 0;
	
	int newx = x;
	int newy = y;

	Swiat* zapas = swiat;

	gotoxy(32 + swiat->n, 8);
	SetConsoleTextAttribute(console2, 10);
	cout << "Twoj ruch" << endl;
	SetConsoleTextAttribute(console2, 7);

	while (flag == 0)
	{

		char key = _getch();
		if ((key == static_cast<char>(0xe0)) || (key == static_cast<char>(0x00)))
		{
			key = _getch();
		}

		switch (key) {
		case KEY_UP:
			if (y - 1 > - 1) {
				newy = y - 1;
				flag = 1;
				break;
			}		
			

		case KEY_DOWN:
			if (y + 1 < swiat->m) {
				newy = y + 1;
				flag = 1;
				break;
			}
			

		case KEY_LEFT:
			if (x - 1 > -1) {
				newx = x - 1;
				flag = 1;
				break;
			}
			

		case KEY_RIGHT:
			if (x + 1 < swiat->n) {
				newx = x + 1;
				flag = 1;
				break;
			}
			

		case 'x':
			if (!cooldown && !cooldownUzycie) {
				cooldown = 10;
				cooldownUzycie = 5;
				sila = sila + 10;
				flag = 2;
				gotoxy(2, 6);
				cout << "                                                                                                 ";
				gotoxy(2, 6);
				SetConsoleTextAttribute(console2, 15);
				cout << "Uzyto mikstury sily, nacisnij SPACE aby kontynuowac";
				SetConsoleTextAttribute(console2, 7);
				while(_getch() != 32);
				break;
			}
			

		default:
			gotoxy(32 + swiat->n, 8);
			SetConsoleTextAttribute(console2, 10);
			cout << "Sprobuj ponownie" << endl;
			SetConsoleTextAttribute(console2, 7);
			break;
		}
	}

	bool alive = true;


	if (flag == 1){	
		if (this->swiat->getOrganizmy()[newx][newy].occupied == true) {
			zderzenie(this->swiat->getOrganizmy()[newx][newy], newx, newy, &alive);
	}

		if (alive && this->swiat->getOrganizmy()[newx][newy].occupied == false) {
			this->swiat->getOrganizmy()[x][y].occupied = false;
			this->swiat->getOrganizmy()[newx][newy].occupied = true;
			this->swiat->getOrganizmy()[newx][newy].organizm = this;
			this->x = newx;
			this->y = newy;
	}
	}

	if (alive) {
		swiat->setcooldown(cooldown, cooldownUzycie);
		swiat->setsila(sila);
	}
	gotoxy(0, 7);
	cout << "                                                                                                                 ";

}

Czlowiek::~Czlowiek() {
	swiat->setsila(-1);
}

int Czlowiek::getcdu() {
	return cooldownUzycie;
}
