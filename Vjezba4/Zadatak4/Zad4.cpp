#include "Gun.h"
#include "Target.h"
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));

	int broj_meta;
	cout << "Upisite koliko meta zelite: " << endl;
	cin >> broj_meta;

	vector <Target> vector_meta;
	for (int i = 0; i < broj_meta; i++) {
		Target tmp_meta;
		tmp_meta.set_position(-100, 100);
		tmp_meta.set_size(10, 20);
		vector_meta.push_back(tmp_meta);
	}

	Gun oruzje;
	oruzje.move_rand(-100, 100);
	Tocka lokacija_oruzja = oruzje.current_position();
	int visina_oruzja = lokacija_oruzja.dohvati_visinu();
	for (int i = 0; i < broj_meta; i++) {
		Tocka lokacija_mete = vector_meta[i].location();
		int pocetak_mete = lokacija_mete.dohvati_visinu();
		int visina = vector_meta[i].get_height();
		if (pocetak_mete < visina_oruzja && visina_oruzja < pocetak_mete + visina) {
			if (!oruzje.current_bullets())
				break;
			oruzje.shoot();
			vector_meta[i].shot();
		}
	}

	int broj_pogodenih = 0;
	for (int i = 0; i < broj_meta; i++) {
		if (vector_meta[i].status()) {
			broj_pogodenih++;
		}
	}
	cout << "Pogodeno je " << broj_pogodenih << " meta." << endl;
	system("pause");
}