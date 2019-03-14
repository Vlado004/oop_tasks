#include <iostream>
using namespace std;
//SVAKI BROJ SAMO JEDNOM
void pronadi(int* niz, int velicina) {
	int ponavljanja[] = { 0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < velicina; i++) {
		ponavljanja[niz[i] - 1]++;
	}
	for (int i = 0; i < 9; i++) {
		if (ponavljanja[i] == 0) {
			niz[velicina] = i + 1;
			break;
		}
	}
	int min;
	for (int i = 0; i < velicina; i++) {
		min = i;
		for (int j = i + 1; j < velicina; j++) {
			if (niz[j] < niz[min])
				min = j;

		}
		swap(niz[i], niz[min]);
	}
}

int main() {
	int* niz = new int[];
	int index = 0, upis;
	while (true) {
		cout << "Upisi neki broj\n";
		cin >> upis;
		if (upis == 0) {
			break;
		}
		niz[index] = upis;
		index++;
	}
	pronadi(niz, index);
	for (int i = 0; i <= index; i++) {
		cout << niz[i] << " ";
	}
	delete[] niz;
}