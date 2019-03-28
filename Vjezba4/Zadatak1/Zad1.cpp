#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

class Tocka_3d {
private:
	double duzina, visina, sirina;

public:
	void postavi_vrijednost(int x = 0, int y = 0, int z = 0) {
		duzina = x;
		sirina = y;
		visina = z;
	}

	void random_vrijednost(int a, int b) {
		if (a > b)
			swap(a, b);
		duzina = a + (rand() % (b - a + 1));
		sirina = a + (rand() % (b - a + 1));
		visina = a + (rand() % (b - a + 1));
	}

	const double dohvati_duljinu() { return duzina; }

	const double dohvati_visinu() { return visina; }

	const double dohvati_sirinu() { return sirina; }

	const double udaljenost_2d(Tocka_3d tocka) {
		int x = duzina - tocka.duzina;
		int y = sirina - tocka.sirina;
		return sqrt(x * x + y * y);
	}

	const double udaljenost_3d(Tocka_3d tocka) {
		int x = duzina - tocka.duzina;
		int y = sirina - tocka.sirina;
		int z = visina - tocka.visina;
		return sqrt(x * x + y * y + z * z);
	}
};

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