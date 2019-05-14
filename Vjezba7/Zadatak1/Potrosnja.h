#ifndef POTROSNJA_H
#define POTROSNJA_H
#include <iostream>

class Potrosnja {
private:
	int mjesec, godina, mjerenje;
public:
	Potrosnja() { mjesec = 0; godina = 0; mjerenje = 0; }
	Potrosnja(const Potrosnja &drugi) { mjesec = drugi.mjesec; godina = drugi.godina; mjerenje = drugi.mjerenje; }

	void dodaj_element(int, int, int);

	const int jel_postoji(int, int);

	const int jel_prazno();

	const void ispis();

	const int vrati_rez();
};

#endif