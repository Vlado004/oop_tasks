#ifndef ZAD1HEADER_H
#define ZAD1HEADER_H
using namespace std;

class Tocka_3d {
private:
	double duzina, visina, sirina;

public:
	void postavi_vrijednost(int x = 0, int y = 0, int z = 0);

	void random_vrijednost(int a, int b);

	const double dohvati_duljinu() { return duzina; }

	const double dohvati_visinu() { return visina; }

	const double dohvati_sirinu() { return sirina; }

	const double udaljenost_2d(Tocka_3d tocka);

	const double udaljenost_3d(Tocka_3d tocka);
};

#endif