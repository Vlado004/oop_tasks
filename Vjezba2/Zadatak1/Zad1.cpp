#include <iostream>
using namespace std;

void pronadi(int* niz) {
	for (int i = 1; i <= 9; i++) {
		bool pronaden = false;
		for (int j = 0; j < 8; j++) {
			if (i == niz[j])
				pronaden = true;
		}
		if (!pronaden) {
			niz[8] = i;
		}
	}
	int min;
	for (int i = 0; i < 9; i++) {
		min = i;
		for (int j = i + 1; j < 9; j++) {
			if (niz[j] < niz[min])
				min = j;

		}
		swap(niz[i], niz[min]);
	}
}

int main() {
	int* niz = new int[9];
	for (int i = 0; i < 9; i++) {
		niz[i] = ((i + 1) * 7) % 10;
	}
	for (int i = 0; i < 8; i++) {
		cout << niz[i] << " ";
	}
	cout << endl;
	pronadi(niz);
	for (int i = 0; i < 9; i++) {
		cout << niz[i] << " ";
	}
	delete[] niz;
	system("Pause");
}