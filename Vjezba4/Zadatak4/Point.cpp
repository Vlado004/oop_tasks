#include "Point.h"
#include <iostream>
#include <math.h>

using namespace std;

void Tocka::postavi_vrijednost(int x, int y, int z) {
	duzina = x;
	sirina = y;
	visina = z;
}

void Tocka::random_vrijednost(int a, int b) {
	if (a > b)
		swap(a, b);
	duzina = a + (rand() % (b - a + 1));
	sirina = a + (rand() % (b - a + 1));
	visina = a + (rand() % (b - a + 1));
}

const double Tocka::udaljenost_2d(Tocka tocka) {
	int x = duzina - tocka.duzina;
	int y = sirina - tocka.sirina;
	return sqrt(x * x + y * y);
}

const double Tocka::udaljenost_3d(Tocka tocka) {
	int x = duzina - tocka.duzina;
	int y = sirina - tocka.sirina;
	int z = visina - tocka.visina;
	return sqrt(x * x + y * y + z * z);
}