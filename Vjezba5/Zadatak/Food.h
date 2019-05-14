#ifndef FOOD_H
#define FOOD_H
using namespace std;
#include "Potrosnja.h"
#include <string>
#include <time.h>
#include <iostream>

class Food {
private:
	string vrsta, naziv, datum_isteka;
	int kolicina_vode, kolicina_proteina, kolicina_masti, kolicina_ugljikohidrata, dnevna_potreba, rok;
	Potrosnja* mjesecna_potrsonja;
public:
	Food(string v, string n, int k_v, int k_p, int k_m, int k_u, string r_t, int d_p);

	Food(const Food& drugi);

	~Food() { delete[] mjesecna_potrsonja; cout << "DELETED" << endl;}

	void povecaj_dnevnu_potrebu();

	void smanji_dnevnu_potrebu();

	const void ispis();

	int dodaj_potrosnju(int mjesec, int godina, int rez);

	const int detektiraj();
};
#endif