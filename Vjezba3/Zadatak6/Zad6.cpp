#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> TRANSFORMATE(vector<string> rijeci) {
	bool samo_slova;
	vector <string> NOVO;

	for (int word = 0; word < rijeci.size(); word++) {
		string buffer = "";
		
		samo_slova = true;
		for (int letter = 0; letter < rijeci[word].size(); letter++) {
			if (isdigit(rijeci[word][letter]))
				samo_slova = false;
		}

		if (samo_slova) {
			
			if (rijeci[word].size() == 1) {
				NOVO.push_back(rijeci[word] +'\0');
				continue;
			}
			int brojac = 0, broj_ponavljanja = 1;//1?
			while (brojac < rijeci[word].size()) {

				if (brojac == 0) {
					if (rijeci[word][0] == rijeci[word][1]) {
						broj_ponavljanja++;
					}
				}
				else {
					if (rijeci[word][brojac - 1] == rijeci[word][brojac]) {
						broj_ponavljanja++;
					}
					else {
						if (broj_ponavljanja != 1)
							buffer += broj_ponavljanja + '0';
						buffer += rijeci[word][brojac - 1];
						broj_ponavljanja = 1;
					}
				}
				brojac++;
			}

			if (broj_ponavljanja != 1)
				buffer += broj_ponavljanja + '0';
			buffer += rijeci[word][brojac - 1];

		}
		else {

			for (int i = 0; i < rijeci[word].size(); i++) {
				if (isalpha(rijeci[word][i])) {
					if (i == 0) {
						buffer += rijeci[word][i];
					}
					else {
						if (!isdigit(rijeci[word][i - 1])) {
							buffer += rijeci[word][i];
						}
						else {
							int kolicina = rijeci[word][i - 1] - '0';
							for (int broj_ponavljanja = 0; broj_ponavljanja < kolicina; broj_ponavljanja++) {
								buffer += rijeci[word][i];
							}
						}
					}
				}
			}
		}

		buffer += '\0';
		NOVO.push_back(buffer);
	}
	return NOVO;
}

int main() {
	int broj_rijeci;
	string buffer;
	vector<string> rijeci;
	cout << "Upisite broj zeljenih rijeci: ";
	cin >> broj_rijeci;
	for (int i = 0; i < broj_rijeci; i++) {
		cout << "Upisite string: ";
		cin >> buffer;
		if (buffer.size() >= 20) {
			cout << "Neispravan unos, ";
			i--;
		}
		else {
			for (int j = 0; j < buffer.size(); j++) {
				if (!isdigit(buffer[j])) {
					if (islower(buffer[j])) {
						buffer[j] = toupper(buffer[j]);
					}
				}
			}
		}
		rijeci.push_back(buffer);
	}

	vector<string> trans_rijeci= TRANSFORMATE(rijeci);
	for (int i = 0; i < trans_rijeci.size(); i++) {
		cout << trans_rijeci[i] << endl;
	}

	system("pause");
}