#include <iostream>
#include <string>
#include <vector>
#include "Food.h"
using namespace std;

void popravi_potrosnju(Food &hrana) {
	int rezultat = hrana.detektiraj();
	cout << rezultat << endl << endl;
	if (rezultat < 0) {
		for (int i = 0; i < -(rezultat); i++) {
			hrana.smanji_dnevnu_potrebu();
		}
	}
	else if (rezultat > 0) {
		for (int i = 0; i < rezultat; i++) {
			hrana.povecaj_dnevnu_potrebu();
		}
	}
}

int main() {
	vector <Food> hrana;
	string string1 = "Meso", string2 = "Piletina", datum = "04-08-2020";
	Food tmp(string1, string2, 2, 30, 21, 12, datum, 50);
	hrana.push_back(tmp);

	hrana[hrana.size() - 1].dodaj_potrosnju(2, 2019, 50);
	hrana[hrana.size() - 1].dodaj_potrosnju(3, 2019, 49);
	hrana[hrana.size() - 1].dodaj_potrosnju(4, 2019, 69);

	string1 = "Riba", string2 = "Losos", datum = "04-08-2019";
	Food tmp2(string1, string2, 2, 30, 21, 12, datum, 50);
	hrana.push_back(tmp2);

	hrana[hrana.size() - 1].dodaj_potrosnju(2, 2019, 50);
	hrana[hrana.size() - 1].dodaj_potrosnju(3, 2019, 49);
	hrana[hrana.size() - 1].dodaj_potrosnju(4, 2019, 40);

	for (int i = 0; i < hrana.size(); i++) {
		hrana[i].ispis();
		popravi_potrosnju(hrana[i]);
		hrana[i].ispis();
	}

	system("pause");
}