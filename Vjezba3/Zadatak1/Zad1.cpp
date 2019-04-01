#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

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

int main() {
	vector<int> vector;

	vector = unos_vectora(vector, false);
	ispis_vectora(vector);
	vector.clear();

	vector = unos_vectora(vector, false, 100, 200);
	ispis_vectora(vector);
	vector.clear();
	
	vector = unos_vectora(vector, false, 0, 100, 15);
	ispis_vectora(vector);
	vector.clear();
	
	vector = unos_vectora(vector, true);
	ispis_vectora(vector);
	vector.clear();

	system("Pause");
}