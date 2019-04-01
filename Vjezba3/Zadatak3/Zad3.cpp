#include <iostream>
#include <string>
using namespace std;

void FIX_ME(string &txt) {
	for (int i = 0; i < txt.size(); i++) {
		bool prije = false, nakon = false;
		if (txt[i] == ',' || txt[i] == '.') {
			if (i != 0) {
				if (txt[i - 1] == ' ') {
					prije = true;
				}
			}
			if (i != txt.size() - 1) {
				if (txt[i + 1] != ' ') {
					nakon = true;
				}
			}

			if (prije) {
				if (nakon) {
					swap(txt[i],txt[i-1]);
				}
				else {
					for (int j = i; j < txt.size(); j++) {
						swap(txt[j], txt[j - 1]);
					}
				}
			}
			else {
				if (nakon) {
					txt.insert(txt.begin() + i + 1, ' ');
				}
			}
		}
	}
}

int main() {
	string tekst = "Ja bih,ako ikako mogu , ovu recenicu napisao ispravno .";
	FIX_ME(tekst);
	cout << tekst << endl;
	system("pause");
}