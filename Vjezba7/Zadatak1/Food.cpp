#include "Food.h"
#pragma warning(disable : 4996)


int get_curr_year() {
	time_t t = time(NULL);
	tm *tmp = localtime(&t);
	return tmp->tm_year + 1900;
}

int get_curr_month() {
	time_t t = time(NULL);
	tm *tmp = localtime(&t);
	return tmp->tm_mon + 1;
}

Food::Food(string v, string n, int k_v, int k_p, int k_m, int k_u, string r_t, int d_p)
{
	cout << "CREATED" << endl;
	vrsta = v;
	naziv = n;
	kolicina_vode = k_v;
	kolicina_proteina = k_p;
	kolicina_masti = k_m;
	kolicina_ugljikohidrata = k_u;
	datum_isteka = r_t;
	dnevna_potreba = d_p;
	time_t t = time(NULL);
	tm *tmp = localtime(&t);
	int rok_god = 0;


	rok_god = rok_god + datum_isteka[6] - '0';
	rok_god = rok_god *10 + datum_isteka[7] - '0';
	rok_god = rok_god *10 + datum_isteka[8] - '0';
	rok_god = rok_god *10 + datum_isteka[9] - '0';
	rok = 0;
	rok = rok + datum_isteka[3] - '0';
	rok = rok*10 + datum_isteka[4] - '0';
	rok = rok - tmp->tm_mon;
	if (rok < 0) {
		rok = rok + 12;
	}
	rok = rok + 12 * (rok_god - (tmp->tm_year + 1900));
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
		<< "Rok Trajanja: " << datum_isteka << endl
		<< "Dnevna Potrebna kolicina: " << dnevna_potreba << endl;
	for (int i = 0; i < rok; i++) {
		if (mjesecna_potrsonja[i].jel_prazno())
			break;
		mjesecna_potrsonja[i].ispis();
	}
	cout << endl;
}

int Food::dodaj_potrosnju(int mjesec, int godina, int rez) {
	time_t t = time(NULL);
	tm *tmp = localtime(&t);
	if (tmp->tm_year + 1900 != godina)
		return 0;
	int i;
	for (i = 0; i < rok; i++) {
		if (mjesecna_potrsonja[i].jel_postoji(mjesec, godina)) {
			return 0;
		}
		if (mjesecna_potrsonja[i].jel_prazno()) {
			break;
		}
	}
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
			sad_rez = mjesecna_potrsonja[i-1].vrati_rez();
			break;
		}
	}
	for (int j = 0; j < 12; j++) {
		for (int i = 0; i < rok; i++) {
			if (mjesecna_potrsonja[i].jel_postoji(tmp->tm_mon + 1, tmp->tm_year + 1900)) {
				int rez = mjesecna_potrsonja[i].vrati_rez();
				if (rez + rez / 10 > sad_rez)
					return rez/10;
				if (rez - rez / 10 < sad_rez)
					return -(rez / 10);
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

ostream& operator << (ostream& os, Mlijecni& mp) {
	
	os << mp.naziv << " ";
}

istream& operator >> (istream& is, Mlijecni& mp) {

}

istream& operator >> (istream& is, Mesni& mp) {

}

ostream& operator << (ostream& os, Vege& vp) {

}

istream& operator >> (istream& is, Vege& vp) {

}

ostream& operator << (ostream& os, Kolaci& kp) {

}

istream& operator >> (istream& is, Kolaci& kp) {

}