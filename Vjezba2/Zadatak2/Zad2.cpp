#include <iostream>
using namespace std;

int* poredaj(int* stari, int velicina) {
	int* novi = new int[velicina];
	int parni_index = 0, neparni_index = velicina - 1;

	for (int i = 0; i < velicina; i++) {
		if (stari[i] % 2) {
			novi[neparni_index] = stari[i];
			neparni_index--;
		}
		else {
			novi[parni_index] = stari[i];
			parni_index++;
		}
	}

	return novi;
}

int main() {
	int niz[] = { 15, 45, 98, 7, 146, 32, 159, 548, 18925, 21, 62 };
	
	int* novi = poredaj(niz, sizeof(niz) / sizeof(int));
	for (int i = 0; i < sizeof(niz) / sizeof(int); i++) {
		cout << novi[i] << endl;
	}
	system("pause");
}