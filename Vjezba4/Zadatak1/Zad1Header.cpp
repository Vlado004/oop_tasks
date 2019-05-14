#include "Zad1Header.h"
#include <iostream>
#include <math.h>

using namespace std;

void Tocka_3d::postavi_vrijednost(int x, int y, int z) {
	duzina = x;
	sirina = y;
	visina = z;
}

void Tocka_3d::random_vrijednost(int a, int b) {
	if (a > b)
		swap(a, b);
	duzina = a + (rand() % (b - a + 1));
	sirina = a + (rand() % (b - a + 1));
	visina = a + (rand() % (b - a + 1));
}

const double Tocka_3d::udaljenost_2d(Tocka_3d tocka) {
	int x = duzina - tocka.duzina;
	int y = sirina - tocka.sirina;
	return sqrt(x * x + y * y);
}

const double Tocka_3d::udaljenost_3d(Tocka_3d tocka) {
	int x = duzina - tocka.duzina;
	int y = sirina - tocka.sirina;
	int z = visina - tocka.visina;
	return sqrt(x * x + y * y + z * z);
}