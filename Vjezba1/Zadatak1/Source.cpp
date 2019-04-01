#include <iostream>

using namespace std;

int main() {

	int niz[] = {1, 2, 3, 5, 4, 6, 2, 3, 7, 5, 7, 8, 8};
	int provjeri[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int brojac = 0, vel = sizeof(niz) / sizeof(int);

	for (int i = 0; i < vel; i++) {
		for (int j = i; j < vel; j++) {
			if (niz[i] == niz[j])
				brojac++;
		}
		if (provjeri[niz[i] - 1] < brojac)
			provjeri[niz[i] - 1] = brojac;
		brojac = 0;
	}

	for (int i = 0; i < 9; i++) {
		cout << i + 1 << "-" << provjeri[i] << endl;
	}
	system("pause");
}