#include "Target.h"
#include <iostream>
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));
	Target meta;
	meta.set_position(-100, 100);
	meta.set_size(10, 3);
	Tocka pozicija = meta.location();
	cout << "Trenutacna lokacija mete je X: " << pozicija.dohvati_duljinu()
		<< ", Y: " << pozicija.dohvati_sirinu()
		<< ", Z: " << pozicija.dohvati_visinu() << "." << endl
		<< "Velicina mete je " << meta.size() << "." << endl;
	cout << "Pogodena? " << meta.status() << endl << "PEW" << endl;
	meta.shot();
	cout << "Pogodena? " << meta.status() << endl;
	system("pause");
}