#include "funkcije.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

int compare(const void* a, const void* b)
{
	const int* x = (int*)a;
	const int* y = (int*)b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}

void ispis_vectora(vector<int> &vector) {
	for (int i = 0; i < vector.size(); i++) {
		cout << vector[i] << " ";
	}
	cout << endl;
}

vector<int> unos_vectora(vector<int> &vector, bool unos, int donja = 0, int gornja = 100, int br_elem = 5) {
	if (gornja < donja) {
		swap(gornja, donja);
	}
	if (unos) {
		int i = 0;
		int buffer;
		while (i < br_elem) {
			cout << "Upisite broj: ";
			cin >> buffer;
			if (donja < buffer && buffer < gornja) {
				vector.push_back(buffer);
				i++;
			}
			else {
				cout << "Neispravan unos.\n";
			}
		}
	}
	else {
		srand(time(NULL));
		for (int i = 0; i < br_elem; i++) {
			vector.push_back(donja + (rand() % (gornja + 1)));
		}
	}
	return vector;
}

vector<int> pronadi(vector<int> prvi, vector<int> drugi, vector<int> novi) {
	qsort(&drugi, drugi.size(), sizeof(int), compare);
	int brojac = 0;
	for (int i = 0; i < prvi.size(); i++) {
		if (binary_search(drugi.begin(), drugi.end(), prvi[i])) {
			novi[brojac] = prvi[i];
			brojac++;
		}
	}
	return novi;
}