#ifndef FOOD_H
#define FOOD_H
using namespace std;
#include "Potrosnja.h"
#include <string>
#include <time.h>
#include <iostream>

class Food {
private:
	string vrsta, naziv, datum_isteka;
	int kolicina_vode, kolicina_proteina, kolicina_masti, kolicina_ugljikohidrata, dnevna_potreba, rok;
	Potrosnja* mjesecna_potrsonja;
public:
	Food(string v, string n, int k_v, int k_p, int k_m, int k_u, string r_t, int d_p);

	Food(const Food& drugi);

	~Food() { delete[] mjesecna_potrsonja; cout << "DELETED" << endl;}

	void povecaj_dnevnu_potrebu();

	void smanji_dnevnu_potrebu();

	const void ispis();

	int dodaj_potrosnju(int mjesec, int godina, int rez);

	const int detektiraj();
};

class Mlijecni :public Food {
private:
	bool samostalno;
	float samostalna_potrosnja, potrosnja_kao_dio;
public:
	Mlijecni(string v, string n, int k_v, int k_p, int k_m, int k_u, string r_t, int d_p, bool sa_stalno, float s_pot, float dio_pot)
		:Food(v, n, k_v, k_p, k_m, k_u, r_t, d_p) {
		samostalno = sa_stalno;
		samostalna_potrosnja = s_pot;
		potrosnja_kao_dio = dio_pot;
	}
};

class Mesni :public Food {
private:
	bool samostalno;
	float samostalna_potrosnja, potrosnja_kao_dio;
public:
	Mesni(string v, string n, int k_v, int k_p, int k_m, int k_u, string r_t, int d_p, bool sa_stalno, float s_pot, float dio_pot)
		:Food(v, n, k_v, k_p, k_m, k_u, r_t, d_p) {
		samostalno = sa_stalno;
		samostalna_potrosnja = s_pot;
		potrosnja_kao_dio = dio_pot;
	}
};

class Vege :public Food {
private:
	bool samostalno;
	float samostalna_potrosnja, potrosnja_kao_prilog;
public:
	Vege(string v, string n, int k_v, int k_p, int k_m, int k_u, string r_t, int d_p, bool sa_stalno, float s_pot, float dio_pri)
		:Food(v, n, k_v, k_p, k_m, k_u, r_t, d_p) {
		samostalno = sa_stalno;
		samostalna_potrosnja = s_pot;
		potrosnja_kao_prilog = dio_pri;
	}
};

class Kolaci :public Food {
private:
	float potrosnja;
public:
	Kolaci(string v, string n, int k_v, int k_p, int k_m, int k_u, string r_t, int d_p, float pot)
		:Food(v, n, k_v, k_p, k_m, k_u, r_t, d_p) {
		potrosnja = pot;
	}
};

class Sir :public Mlijecni {
public:
	Sir(string v, string n, int k_v, int k_p, int k_m, int k_u, string r_t, int d_p, bool sa_stalno, float s_pot, float dio_pot) :
		Mlijecni(v, n, k_v, k_p, k_m, k_u, r_t, d_p, sa_stalno, s_pot, dio_pot) {}
};

class Mlijeko :public Mlijecni {
public:
	Mlijeko(string v, string n, int k_v, int k_p, int k_m, int k_u, string r_t, int d_p, bool sa_stalno, float s_pot, float dio_pot) :
		Mlijecni(v, n, k_v, k_p, k_m, k_u, r_t, d_p, sa_stalno, s_pot, dio_pot) {}
};

class Jogurt :public Mlijecni {
public:
	Jogurt(string v, string n, int k_v, int k_p, int k_m, int k_u, string r_t, int d_p, bool sa_stalno, float s_pot, float dio_pot) :
		Mlijecni(v, n, k_v, k_p, k_m, k_u, r_t, d_p, sa_stalno, s_pot, dio_pot) {}
};


class Meso :public Mesni {
public:
	Meso(string v, string n, int k_v, int k_p, int k_m, int k_u, string r_t, int d_p, bool sa_stalno, float s_pot, float dio_pot) :
		Mesni(v, n, k_v, k_p, k_m, k_u, r_t, d_p, sa_stalno, s_pot, dio_pot) {}
};
	
class Sunka :public Mesni {
public:
	Sunka(string v, string n, int k_v, int k_p, int k_m, int k_u, string r_t, int d_p, bool sa_stalno, float s_pot, float dio_pot) :
		Mesni(v, n, k_v, k_p, k_m, k_u, r_t, d_p, sa_stalno, s_pot, dio_pot) {}
};
	
class Prsut :public Mesni {
public:
	Prsut(string v, string n, int k_v, int k_p, int k_m, int k_u, string r_t, int d_p, bool sa_stalno, float s_pot, float dio_pot) :
		Mesni(v, n, k_v, k_p, k_m, k_u, r_t, d_p, sa_stalno, s_pot, dio_pot) {}
};


class Riza :public Vege {
public:
	Riza(string v, string n, int k_v, int k_p, int k_m, int k_u, string r_t, int d_p, bool sa_stalno, float s_pot, float dio_pri) :
		Vege(v, n, k_v, k_p, k_m, k_u, r_t, d_p, sa_stalno, s_pot, dio_pri) {}
};

class Tofu :public Vege {
public:
	Tofu(string v, string n, int k_v, int k_p, int k_m, int k_u, string r_t, int d_p, bool sa_stalno, float s_pot, float dio_pri) :
		Vege(v, n, k_v, k_p, k_m, k_u, r_t, d_p, sa_stalno, s_pot, dio_pri) {}
};
	
class Hummus :public Vege {
public:
	Hummus(string v, string n, int k_v, int k_p, int k_m, int k_u, string r_t, int d_p, bool sa_stalno, float s_pot, float dio_pri) :
		Vege(v, n, k_v, k_p, k_m, k_u, r_t, d_p, sa_stalno, s_pot, dio_pri) {}
};


class Madjarica :public Kolaci {
public:
	Madjarica(string v, string n, int k_v, int k_p, int k_m, int k_u, string r_t, int d_p, float pot) :
		Kolaci(v, n, k_v, k_p, k_m, k_u, r_t, d_p, pot) {}
};

class Krempita :public Kolaci {
public:
	Krempita(string v, string n, int k_v, int k_p, int k_m, int k_u, string r_t, int d_p, float pot) :
		Kolaci(v, n, k_v, k_p, k_m, k_u, r_t, d_p, pot) {}
};

class Torta :public Kolaci {
public:
	Torta(string v, string n, int k_v, int k_p, int k_m, int k_u, string r_t, int d_p, float pot) :
		Kolaci(v, n, k_v, k_p, k_m, k_u, r_t, d_p, pot) {}
};
#endif