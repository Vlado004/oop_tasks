#include <iostream>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	int broj_sibica = 21, izbor_korisnika, izbor_racunala;
	bool krug_pca = true;
	while (broj_sibica > 0) {
		cout << "Ostalo je " << broj_sibica << " sibica(e). " << endl;
		if (krug_pca) {
			if (broj_sibica == 1) {
				cout << "CONGRATULATIONS, pobijedili ste. GG" << endl;
				broj_sibica = 0;
			}
			else {
				if (broj_sibica < 5) {
					cout << "Racunalo je uzelo " << broj_sibica - 1 << " sibica(e)." << endl;
					broj_sibica = 1;
				}
				else {
					izbor_racunala = (rand() % 3) + 1;
					cout << "Racunalo je uzelo " << izbor_racunala << " sibica(e)." << endl;
					broj_sibica -= izbor_racunala;
				}
				krug_pca = false;
			}
		}
		else {
			cout << "Upisite broj sibica koji zelite uzeti: ";
			cin >> izbor_korisnika;
			if (0 < izbor_korisnika && izbor_korisnika < 4) {
				if (izbor_korisnika > broj_sibica) {
					cout << "Neispravan unos. ";
				}
				else {
					broj_sibica -= izbor_korisnika;
					krug_pca = true;
					if (!broj_sibica) {
						cout << "Zao mi je but you suck." << endl;
					}
				}
			}
			else {
				cout << "Neispravan unos. ";
			}
		}
	}
	system("pause");
}