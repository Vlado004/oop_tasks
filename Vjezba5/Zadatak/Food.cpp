#include "Food.h"
#pragma warning(disable : 4996)

Food::Food(string v, string n, int k_v, int k_p, int k_m, int k_u, time_t* r_t, int d_p)
{
	cout << "CREATED" << endl;
	vrsta = v;
	naziv = n;
	kolicina_vode = k_v;
	kolicina_proteina = k_p;
	kolicina_masti = k_m;
	kolicina_ugljikohidrata = k_u;
	datum_isteka = localtime(r_t);
	cout << "PogU" << endl;
	dnevna_potreba = d_p;
	time_t t = time(NULL);
	tm *tmp = localtime(&t);
	rok = datum_isteka->tm_mon - tmp->tm_mon;
	cout << rok << " " << datum_isteka->tm_mon << " " << tmp->tm_mon << endl;
	if (rok < 0) {
		rok = rok + 12;
	}
	rok = rok + 12 * (datum_isteka->tm_year - tmp->tm_year);
	cout << rok << endl;
	mjesecna_potrsonja = new Potrosnja[rok*2];
	for (int i = 0; i < rok; i++)
		mjesecna_potrsonja[i].dodaj_element(0, 0, 0);
}

Food::Food(const Food& drugi) {
	cout << "COPIED" << endl;
	vrsta = drugi.vrsta;
	naziv = drugi.naziv;
	kolicina_vode = drugi.kolicina_vode;
	kolicina_proteina = drugi.kolicina_proteina;
	kolicina_masti = drugi.kolicina_masti;
	kolicina_ugljikohidrata = drugi.kolicina_ugljikohidrata;
	datum_isteka = drugi.datum_isteka;
	dnevna_potreba = drugi.dnevna_potreba;
	rok = drugi.rok;
	mjesecna_potrsonja = new Potrosnja[rok*2];
	for (int i = 0; i < rok; i++) {
		mjesecna_potrsonja[i] = drugi.mjesecna_potrsonja[i];
	}
}

void Food::povecaj_dnevnu_potrebu() {
	dnevna_potreba++;
}

void Food::smanji_dnevnu_potrebu() {
	dnevna_potreba--;
}

const void Food::ispis() {
	cout << "Vrsta: " << vrsta << endl
		<< "Naziv: " << naziv << endl
		<< "Kolicina Vode:" << kolicina_vode << endl
		<< "Kolicina Proteina: " << kolicina_proteina << endl
		<< "Kolicina Masti: " << kolicina_masti << endl
		<< "kolicina Ugljikohidrata: " << kolicina_ugljikohidrata << endl
		<< "Rok Trajanja: " << datum_isteka->tm_mday << "-" << datum_isteka->tm_mon + 1 << "-" << datum_isteka->tm_year + 1900 << endl
		<< "Dnevna Potrebna kolicina: " << dnevna_potreba << endl;
	for (int i = 0; i < rok; i++) {
		if (mjesecna_potrsonja[i].jel_prazno())
			break;
		mjesecna_potrsonja[i].ispis();
	}
	cout << endl;
}

int Food::dodaj_potrosnju(int mjesec, int godina, int rez) {
	cout << "Uslo" << endl;
	time_t t = time(NULL);
	tm *tmp = localtime(&t);
	if (tmp->tm_year + 1900 != godina)
		cout << "Year is not this one" << endl;
		//return 0;
	int i;
	cout << rok << endl;
	for (i = 0; i < rok; i++) {
		cout << "Uslo u for" << endl;
		mjesecna_potrsonja[i].ispis();
		if (mjesecna_potrsonja[i].jel_postoji(mjesec, godina)) {
			cout << "Ovo vec postoji" << endl;
			return 0;
		}
		if (mjesecna_potrsonja[i].jel_prazno()) {
			cout << "Pronaslo prvo prazno na " << i << endl;
			break;
		}
	}
	cout << "Izaslo iz for" << endl;
	mjesecna_potrsonja[i].dodaj_element(mjesec, godina, rez);
	return 1;
}

const int Food::detektiraj() {
	time_t t = time(NULL);
	tm *tmp = localtime(&t);
	tmp->tm_year -= 1;
	int sad_rez;
	for (int i = 0; i < rok; i++) {
		if (mjesecna_potrsonja[i].jel_prazno()) {
			sad_rez = mjesecna_potrsonja[i].vrati_rez();
			break;
		}
	}
	for (int j = 0; j < 12; j++) {
		for (int i = 0; i < rok; i++) {
			if (mjesecna_potrsonja[i].jel_postoji(tmp->tm_mon + 1, tmp->tm_year + 1900)) {
				int rez = mjesecna_potrsonja[i].vrati_rez();
				if (rez + rez / 10 > sad_rez)
					return 1;
				if (rez - rez / 10 < sad_rez)
					return -1;
				return 0;
			}
		}
		tmp->tm_mon += 1;
		if (tmp->tm_mon > 12) {
			tmp->tm_mon -= 12;
			tmp->tm_year += 1;
		}
	}
	return 0;
}