#include "funkcije.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

void ispis_vectora(vector<int> &vector) {
	for (int i = 0; i < vector.size(); i++) {
		cout << vector[i] << " ";
	}
	cout << endl;
}

vector<int> unos_vectora(vector<int> &vector, bool unos, int donja, int gornja, int br_elem) {
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
		for (int i = 0; i < br_elem; i++) {
			vector.push_back(donja + (rand() % (gornja + 1)));
		}
	}
	return vector;
}

vector<int> pronadi(vector<int> prvi, vector<int> drugi, vector<int> novi) {
	sort(drugi.begin(), drugi.end());
	for (int i = 0; i < prvi.size(); i++) {
		if (binary_search(drugi.begin(), drugi.end(), prvi[i])) {
			novi.push_back(prvi[i]);
		}
	}
	return novi;
}