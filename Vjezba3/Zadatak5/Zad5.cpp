#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct {
	string name, movie;
	int year;
} producent;

typedef struct lista {
	string name;
	int count;
	lista* next;
} lista;

void PRONADI(vector <producent> vector) {
	if (vector.size() == 0)
		return;

	lista* pocetak = NULL, *iterator;
	for (int i = 0; i < vector.size(); i++) {
		iterator = pocetak;
		bool unutar = false;
		while (iterator != NULL) {
			if (iterator->name.compare(vector[i].name) == 0) {
				unutar = true;
				iterator->count += 1;
				break;
			}
			iterator = iterator->next;
		}
		if (!unutar) {
			lista* tmp = new lista;
			tmp->name = vector[i].name;
			tmp->count = 1;
			tmp->next = pocetak;
			pocetak = tmp;
		}
	}

	iterator = pocetak;
	int max = iterator->count;
	while (iterator != NULL) {
		if (iterator->count > max) {
			max = iterator->count;
		}
		iterator = iterator->next;
	}
	iterator = pocetak;
	cout << "Najzastupljeniji su: " << endl;
	while (iterator != NULL) {
		if (iterator->count == max) {
			cout << iterator->name << endl;
		}
		iterator = iterator->next;
	}
	cout << "Sa " << max << " filmova." << endl;
	
	while (pocetak != NULL)
	{
		lista* tmp = pocetak;
		pocetak = pocetak->next;
		delete tmp;
	}
}

int main() {
	vector <producent> vector;
	string tmp;
	producent buffer;
	while (1) {
		cout << "KRAJ?";
		cin >> tmp;
		if (tmp.compare("kraj") == 0)
			break;
		cout << "UPISI IME: ";
		cin >> buffer.name;
		cout << "UPISI FILM: ";
		cin >> buffer.movie;
		cout << "UPISI GODINU: ";
		cin >> buffer.year;
		vector.push_back(buffer);
	}
	PRONADI(vector);

	system("pause");
}