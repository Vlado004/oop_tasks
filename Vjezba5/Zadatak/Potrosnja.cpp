#include "Potrosnja.h"

void Potrosnja::dodaj_element(int m, int g, int r) {
	mjesec = m;
	godina = g;
	mjerenje = r;
}

const int Potrosnja::jel_postoji(int mj, int god) {
	if (mjesec == mj && godina == god)
		return 1;
	return 0;
}

const int Potrosnja::jel_prazno() {
	if (mjesec == 0 && godina == 0)
		return 1;
	return 0;
}

const void Potrosnja::ispis() {
	std::cout << mjerenje << " za " << mjesec << " mjesec " << godina << " godine" << std::endl;
}

const int Potrosnja::vrati_rez() {
	return mjerenje;
}