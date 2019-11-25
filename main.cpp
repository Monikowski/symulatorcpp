#include "Header.h"




int main() {

	int n, m;

	cout << "Wys, szer" << endl;
	cin >> n;
	cin >> m;

	Swiat* help;
	help = new Swiat(50, 50);

	help->fillHelper(help);

	Swiat *swiat;
	swiat = new Swiat(n, m);

	swiat->spawn(help);

	system("cls");

	int pierwszy = 0;

	while (true) {
		swiat->quickSort(swiat->getOrganizm(), 0, swiat->getLiczba() - 1);
		system("cls");
		
		swiat->rysujSwiat();
		swiat->wykonajTure();
		swiat = swiat->getnowyptr();
	}
	system("pause");
	return 0;
}