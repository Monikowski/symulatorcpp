#include "Header.h"

using namespace std;

HANDLE console1 = GetStdHandle(STD_OUTPUT_HANDLE);

void wypiszSrodek(int szer) {

	cout << '|';
	for (int i = 0; i < szer; i++) {
		cout << ' ';
	}
	cout << '|' << endl;
}

void wypiszGore(int szer) {

	cout << '*';
	for (int i = 0; i < szer; i++)
		cout << '-';
	cout << '*' << endl;
}

void wypiszDol(int szer) {
	cout << '*';
	for (int i = 0; i < szer; i++)
		cout << '-';
	cout << '*' << endl;
}

Swiat::Swiat(int szer, int wys) : n(szer), m(wys){
	liczba = 0;
	organizmy = new Organizmy*[n];
	for (int i = 0; i < n; i++) {
		organizmy[i] = new Organizmy[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			organizmy[i][j].occupied = false;
		}
	}
	org = new Organizm*[n*m];
	nowyptr = this;
}

void Swiat::wykonajTure() {

	liczniksmierci = 0;
	srand(time(0));
	setIndexes();
	for (int i = 0; i < liczba; i++) {
		if (org[i]->getWiek() != 0) {
			srand(rand());
			org[i]->akcja(rand());
		}
	}
	for (int i = 0; i < liczba; i++) {
		org[i]->addWiek();
	}
	setIndexes();
	rysujSwiat();

	gotoxy(32 + n, 8);
	SetConsoleTextAttribute(console1, 15);
	cout << "Nacisnij SPACE aby przejsc do nastepnej tury, s aby zapisac, l aby wczytac";
	SetConsoleTextAttribute(console1, 7);
	char zn = 0;
	char che = 0;
	int czyczlowiek = 0;
	int indexczlowiek = -1;
	while (zn != 32) {
		zn = _getch();
		switch (zn) {

		case 's':
			do {
				FILE *save;
				char filename[50];
				int namectr = 0;
				gotoxy(32 + n, 8);
				cout << "                                                                                                          ";
				gotoxy(32 + n, 8);
				SetConsoleTextAttribute(console1, 15);
				cout << "Podaj nazwe pliku: ";
				while (true) {
					che = _getch();
					if (che > 96 && che < 123) {
						gotoxy(32 + n + namectr, 9);
						cout << che;
						filename[namectr] = che;
						namectr++;

					}
					else if (che == 8 && namectr > 0) {
						filename[namectr - 1] = '\0';
						gotoxy(32 + n - 1 + namectr, 9);
						cout << ' ';
						namectr--;

					}
					else if (che == 13) {
						filename[namectr] = '.';
						filename[namectr + 1] = 't';
						filename[namectr + 2] = 'x';
						filename[namectr + 3] = 't';
						filename[namectr + 4] = '\0';
						break;

					}
					else if (che == 27) {
						che = 27;
						break;

					}

				}
				if (che != 27) {
					save = fopen(filename, "w");
					if (save == NULL) {
						gotoxy(32 + n, 9);
						cout << "                                                                    ";
						gotoxy(32 + n, 9);
						cout << "Nie mozna otworzyc pliku.";
						che = _getch();
						break;

					}
					fprintf(save, "%d\n", n);
					fprintf(save, "%d\n", m);
					fprintf(save, "%d\n", liczba);
					for (int i = 0; i < liczba; i++) {
						if (org[i]->id == 0) {
							indexczlowiek = i;
							czyczlowiek = 1;
							break;
						}
					}
					fprintf(save, "%d\n", czyczlowiek);
					fprintf(save, "%d\n", indexczlowiek);
					for (int i = 0; i < liczba; i++) {
						if (org[i]->id != 0) {
							fprintf(save, "%d\n", org[i]->id);
							fprintf(save, "%d\n", org[i]->getX());
							fprintf(save, "%d\n", org[i]->getY());
							fprintf(save, "%d\n", i);
							fprintf(save, "%d\n", org[i]->getCooldown());
							fprintf(save, "%d\n", org[i]->getSila());										
						}						
					}
					if (czyczlowiek) {
						fprintf(save, "%d\n", org[indexczlowiek]->getX());
						fprintf(save, "%d\n", org[indexczlowiek]->getY());
						fprintf(save, "%d\n", org[indexczlowiek]->getCooldown());
						fprintf(save, "%d\n", org[indexczlowiek]->getSila());
						fprintf(save, "%d\n", org[indexczlowiek]->getcdu());
					}

					fclose(save);
					break;

				}
			} while (che != 27);
			break;
			case 'l':
				do {
					int idtest, xtemp, ytemp, indextemp, cdtemp, silatemp, cdutemp, ntemp, mtemp;
					FILE *save;
					char filename[50];
					int namectr = 0;
					gotoxy(32 + n, 9);
					cout << "                                                                    ";
					gotoxy(32 + n, 9);
					cout << "Nazwa pliku do wczytania: ";
					while (true) {
						che = _getch();
						if (che > 96 && che < 123) {
							gotoxy(32 + n + 1 + namectr, 9);
							cout << che;
							filename[namectr] = che;
							namectr++;

						}
						else if (che == 8 && namectr > 0) {
							filename[namectr - 1] = '\0';
							gotoxy(32 + n + namectr, 9);
							cout << ' ';
							namectr--;

						}
						else if (che == 13) {
							filename[namectr] = '.';
							filename[namectr + 1] = 't';
							filename[namectr + 2] = 'x';
							filename[namectr + 3] = 't';
							filename[namectr + 4] = '\0';
							break;

						}
						else if (che == 27) {
							che = 27;
							break;

						}

					}
					if (che != 27) {
						save = fopen(filename, "r");
						fscanf(save, "%d\n%d\n", &ntemp, &mtemp);
						Swiat *nowy = new Swiat(ntemp, mtemp);
						fscanf(save, "%d\n%d\n%d\n", &liczba, &czyczlowiek, &indexczlowiek);
						nowy->setLiczba(liczba);
						if (czyczlowiek) {
							for (int i = 0; i < liczba - 1; i++) {
								fscanf(save, "%d\n", &idtest);
								fscanf(save, "%d\n", &xtemp);
								fscanf(save, "%d\n", &ytemp);
								fscanf(save, "%d\n", &indextemp);
								fscanf(save, "%d\n", &cdtemp);
								fscanf(save, "%d\n", &silatemp);

								switch (idtest) {

									case 1:
										nowy->getOrganizm()[indextemp] = new Wilk(xtemp, ytemp, nowy, cdtemp, silatemp);
										break;
									case 2:
										nowy->getOrganizm()[indextemp] = new Owca(xtemp, ytemp, nowy, cdtemp, silatemp);
										break;
									case 3:
										nowy->getOrganizm()[indextemp] = new Lis(xtemp, ytemp, nowy, cdtemp, silatemp);
										break;
									case 4:
										nowy->getOrganizm()[indextemp] = new Zolw(xtemp, ytemp, nowy, cdtemp, silatemp);
										break;
									case 5:
										nowy->getOrganizm()[indextemp] = new Antylopa(xtemp, ytemp, nowy, cdtemp, silatemp);
										break;

									case 7:
										nowy->getOrganizm()[indextemp] = new Trawa(xtemp, ytemp, nowy);
										break;
									case 8:
										nowy->getOrganizm()[indextemp] = new Mlecz(xtemp, ytemp, nowy);
										break;
									case 9:
										nowy->getOrganizm()[indextemp] = new Guarana(xtemp, ytemp, nowy);
										break;
									case 10:
										nowy->getOrganizm()[indextemp] = new Jagody(xtemp, ytemp, nowy);
										break;
									case 11:
										nowy->getOrganizm()[indextemp] = new Barszcz(xtemp, ytemp, nowy);
										break;
									default:
										break;
								}
							}
							fscanf(save, "%d\n", &xtemp);
							fscanf(save, "%d\n", &ytemp);
							fscanf(save, "%d\n", &cdtemp);
							fscanf(save, "%d\n", &silatemp);
							fscanf(save, "%d\n", &cdutemp);
							nowy->getOrganizm()[indexczlowiek] = new Czlowiek(xtemp, ytemp, nowy, cdutemp, cdtemp, silatemp);
						}
						else for (int i = 0; i < liczba; i++) {
							fscanf(save, "%d\n", &idtest);
							fscanf(save, "%d\n", &xtemp);
							fscanf(save, "%d\n", &ytemp);
							fscanf(save, "%d\n", &indextemp);
							fscanf(save, "%d\n", &cdtemp);
							fscanf(save, "%d\n", &silatemp);

							switch (idtest) {

							case 1:
								nowy->getOrganizm()[indextemp] = new Wilk(xtemp, ytemp, nowy, cdtemp, silatemp);
								break;
							case 2:
								nowy->getOrganizm()[indextemp] = new Owca(xtemp, ytemp, nowy, cdtemp, silatemp);
								break;
							case 3:
								nowy->getOrganizm()[indextemp] = new Lis(xtemp, ytemp, nowy, cdtemp, silatemp);
								break;
							case 4:
								nowy->getOrganizm()[indextemp] = new Zolw(xtemp, ytemp, nowy, cdtemp, silatemp);
								break;
							case 5:
								nowy->getOrganizm()[indextemp] = new Antylopa(xtemp, ytemp, nowy, cdtemp, silatemp);
								break;

							case 7:
								nowy->getOrganizm()[indextemp] = new Trawa(xtemp, ytemp, nowy);
								break;
							case 8:
								nowy->getOrganizm()[indextemp] = new Mlecz(xtemp, ytemp, nowy);
								break;
							case 9:
								nowy->getOrganizm()[indextemp] = new Guarana(xtemp, ytemp, nowy);
								break;
							case 10:
								nowy->getOrganizm()[indextemp] = new Jagody(xtemp, ytemp, nowy);
								break;
							case 11:
								nowy->getOrganizm()[indextemp] = new Barszcz(xtemp, ytemp, nowy);
								break;
							}
						}

						for (int i = 0; i < liczba; i++) {
							nowy->getOrganizmy()[nowy->getOrganizm()[i]->getX()][nowy->getOrganizm()[i]->getY()].occupied = true;
							nowy->getOrganizmy()[nowy->getOrganizm()[i]->getX()][nowy->getOrganizm()[i]->getY()].organizm = nowy->getOrganizm()[i];
						}
						nowyptr = nowy;
						fclose(save);
						break;

					}

				} while (che != 27);
				break;
		}
	}
}

void Swiat::przesun(int start) {
	for (start; start < liczba - 1; start++) {
		org[start] = org[start + 1];
		org[start]->setIndex(start);
	}
	liczba--;
}

void Swiat::rysujSwiat() {


	if (silaczlowieka > 0) {
		gotoxy(2, 4);
		SetConsoleTextAttribute(console1, 6);
		cout << "sila czlowieka: " << silaczlowieka << ", bazowo: " << silaczlowieka - cooldownczlowieka << "             ";
		SetConsoleTextAttribute(console1, 7);
		gotoxy(2, 6);
		if (cooldownczlowieka + cooldownczlowiekaUzycie)
			cout << "Pozostalo " << cooldownczlowieka + cooldownczlowiekaUzycie << " tur do odnowienia misktury sily                  ";
		else {
			SetConsoleTextAttribute(console1, 12);
			cout << "***Mikstura + 10 sily gotowa do uzycia klawiszem 'x' podczas twojej tury***";
			SetConsoleTextAttribute(console1, 7);
		}
	}

	gotoxy(2, 11);
	cout << "W - Wilk";
	gotoxy(2, 12);
	cout << "O - Owca";
	gotoxy(2, 13);
	cout << "L - Lis";
	gotoxy(2, 14);
	cout << "Z - Zolw";
	gotoxy(2, 15);
	cout << "A - Antylopa";
	
	gotoxy(2, 17);
	cout << "# - Trawa";
	gotoxy(2, 18);
	cout << "^ - Mlecz";
	gotoxy(2, 19);
	cout << "+ - Guarana";
	gotoxy(2, 20);
	cout << "$ - Wilcze jagody";
	gotoxy(2, 21);
	cout << "% - Barszcz Sosnowskiego";

	gotoxy(2, 25);
	SetConsoleTextAttribute(console1, 10);
	cout << "Strzalki - sterowanie";
	gotoxy(2, 26);
	cout << "x - uzycie umiejetnosci";
	gotoxy(2, 10);
	cout << "@ - Czlowiek";
	SetConsoleTextAttribute(console1, 7);

	for (int i = 0; i < m + 2; i++) {

		gotoxy(28, 10 + i);
		if ((i > 0) && (i < m +1)) {			
			wypiszSrodek(n);			
		}
		else if (i == 0) {
			wypiszGore(n);
		}
		else if (i == (m + 1)) {		
			wypiszDol(n);
		}
	}

	
	for (int i = 0; i < liczba; i++){
				gotoxy(29 + org[i]->getX(), 11 + org[i]->getY());
				if (org[i]->symbol == '@')
					SetConsoleTextAttribute(console1, 10);
				cout << org[i]->symbol;	
				SetConsoleTextAttribute(console1, 7);
			}	



}

void Swiat::zniszczono() {
	liczba--;
}


int Swiat::getLiczba() {
	return liczba;
}

void Swiat::dodajOrganizm(Organizm *o) {

	org[liczba] = o;
	o->setIndex(liczba);
	liczba++;
}

void Swiat::setIndexes() {
	for (int i = 0; i < liczba; i++) {
		org[i]->setIndex(i);
	}
}

void Swiat::setsila(int x) {
	silaczlowieka = x;
}


void Swiat::setcooldown(int x, int y) {
	cooldownczlowieka = x;
	cooldownczlowiekaUzycie = y;
}

int Swiat::getliczniksmierci() {
	return liczniksmierci;
}

void Swiat::addliczniksmierci() {
	liczniksmierci++;
}

Organizm** Swiat::getOrganizm() {
	return org;
}

Organizmy** Swiat::getOrganizmy() {
	return organizmy;
}

void Swiat::fillHelper(Swiat* help) {
	help->dodajOrganizm(new Antylopa(0, 0, help, 0, 0));
	help->dodajOrganizm(new Barszcz(1, 0, help));
	help->dodajOrganizm(new Guarana(2, 0, help));
	help->dodajOrganizm(new Jagody(3, 0, help));
	help->dodajOrganizm(new Lis(4, 0, help, 0, 0));
	help->dodajOrganizm(new Mlecz(5, 0, help));
	help->dodajOrganizm(new Owca(6, 0, help, 0, 0));
	help->dodajOrganizm(new Trawa(7, 0, help));
	help->dodajOrganizm(new Wilk(8, 0, help, 0, 0));
	help->dodajOrganizm(new Zolw(9, 0, help, 0, 0));
}

void Swiat::spawn(Swiat *help) {
	srand(time(0));
	int pola = m * n;
	int x;
	int y;
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < help->getOrganizmy()[j][0].organizm->gestosc*pola; i++) {
			while (true) {
				srand(rand()*rand());
				x = (rand() + n) % n;
				srand(rand()*rand()*rand());
				y = (rand() + m) % m;
				if (organizmy[x][y].occupied == false) {
					help->getOrganizmy()[j][0].organizm->stworznowy(x, y, this);
					break;
				}
			}
		}
	}
	while (true) {
		srand(rand());
		x = rand() % n;
		srand(rand());
		y = rand() % m;
		if (organizmy[x][y].occupied == false) {
			dodajOrganizm(new Czlowiek(x, y, this, 0, 0, SILA_CZL));
			break;
		}
	}

}

void Swiat::swap(Organizm** arr, int i, int j)
{
	Organizm *t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

int Swiat::partition(Organizm *arr[], int low, int high)
{
	int pivot = arr[high]->inic;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j]->inic > pivot)
		{
			i++;
			swap(arr, i, j);
		}
		else if (arr[j]->inic == pivot) {
			if (arr[j]->getWiek() < arr[high]->getWiek()) {
				i++;
				swap(arr, i, j);
			}
			else if (arr[j]->getWiek() == arr[high]->getWiek()) {
				if (arr[j]->id < arr[high]->id) {
					i++;
					swap(arr, i, j);
				}
			}
		}
	}
	swap(arr, i + 1, high);
	return (i + 1);
}

void Swiat::quickSort(Organizm *arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void Swiat::setLiczba(int x) {
	liczba = x;
}

Swiat* Swiat::getnowyptr() {
	return nowyptr;
}