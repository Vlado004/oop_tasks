#include <iostream>
#include <time.h>
#include <math.h>
#include "Zad1Header.h"
using namespace std;

int main() {
	srand(time(NULL));
	Tocka_3d tocka1;
	Tocka_3d tocka2;

	tocka1.postavi_vrijednost(2, 4);
	tocka2.random_vrijednost(-5, 5);

	cout << "Duzina prve tocke: " << tocka1.dohvati_duljinu() << endl;
	cout << "Sirina prve tocke: " << tocka1.dohvati_sirinu() << endl;
	cout << "Visina prve tocke: " << tocka1.dohvati_visinu() << endl;

	cout << "Duzina druge tocke: " << tocka2.dohvati_duljinu() << endl;
	cout << "Sirina druge tocke: " << tocka2.dohvati_sirinu() << endl;
	cout << "Visina druge tocke: " << tocka2.dohvati_visinu() << endl;

	cout << "2D Udaljenost izmedu prve i druge tocke je: " << tocka1.udaljenost_2d(tocka2) << endl;
	cout << "3D Udaljenost izmedu prve i druge tocke je: " << tocka1.udaljenost_3d(tocka2) << endl;
	system("pause");
}