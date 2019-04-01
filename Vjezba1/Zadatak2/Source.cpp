#include <iostream>
#include <string>
using namespace std;

typedef struct {
	string ID, ime, prezime, spol;
	int kviz1, kviz2, mid_score, final_score, total;
} student;

void help() {
	cout << "Lista naredbi: " << endl
		<< "-help" << endl
		<< "-dodaj" << endl
		<< "-ukloni" << endl
		<< "-update" << endl
		<< "-ispis" << endl
		<< "-prosjek" << endl
		<< "-sortiraj" << endl
		<< "-max" << endl
		<< "-min" << endl
		<< "-pronadi" << endl
		<< "-izlaz" << endl << endl;
}

void ispisi_sve_studente(student niz_studenata[]) {
	int brojac = 0;
	for (int i = 0; i <= 20; i++) {
		if (niz_studenata[i].ID.compare("0") != 0) {
			cout << niz_studenata[i].ID << " - " << niz_studenata[i].ime << " " << niz_studenata[i].prezime << endl
				<< "Kviz 1: " << niz_studenata[i].kviz1 << endl
				<< "Kviz 2: " << niz_studenata[i].kviz2 << endl
				<< "Mid Score: " << niz_studenata[i].mid_score << endl
				<< "Final Score: " << niz_studenata[i].final_score << endl
				<< "Total: " << niz_studenata[i].total << endl << endl;
			brojac++;
		}
	}
	if (!brojac)
		cout << "Nije pronaden niti jedan student\n";
}

void ispis_jednog(student niz_studenata[], int mjesto) {
	cout << niz_studenata[mjesto].ime << " " << niz_studenata[mjesto].prezime << endl
		<< "Kviz 1: " << niz_studenata[mjesto].kviz1 << endl
		<< "Kviz 2: " << niz_studenata[mjesto].kviz2 << endl
		<< "Mid Score: " << niz_studenata[mjesto].mid_score << endl
		<< "Final Score: " << niz_studenata[mjesto].final_score << endl
		<< "Total: " << niz_studenata[mjesto].total << endl << endl;
}

int jel_postoji(student niz_studenata[], string ID) {
	for (int i = 0; i < 20; i++) {
		if (niz_studenata[i].ID.compare(ID) == 0) {
			return i;
		}
	}
	return -1;
}

void dodaj_zapis(student niz_studenata[], int& kapacitet) {
	if (kapacitet >= 20) {
		cout << "Prekoracen je limit studenata\n\n";
		return;
	}
	string tmp_id;
	cout << "Upisite ID studenta: ";
	cin >> tmp_id;

	for (int i = 0; i < 20; i++) {
		if (niz_studenata[i].ID.compare(tmp_id) == 0) {
			cout << "ID vec postoji\n\n";
			return;
		}
	}
	kapacitet++;
	int counter = 0;
	while (niz_studenata[counter].ID.compare("0")) {
		counter++;
	}
	niz_studenata[counter].ID = tmp_id;
	cout << "Upisite ime: ";
	cin >> niz_studenata[counter].ime;
	cout << "Upisite prezime: ";
	cin >> niz_studenata[counter].prezime;
	niz_studenata[counter].kviz1 = niz_studenata[counter].kviz2 = 0;
	niz_studenata[counter].mid_score = niz_studenata[counter].final_score = niz_studenata[counter].total = 0;
	cout << "Student uspijesno dodan\n\n";
}

void ukloni_studenta(student niz_studenata[], int& kapacitet) {
	string tmp_id;
	cout << "Upisite ID studenta: ";
	cin >> tmp_id;
	for (int i = 0; i <= 20; i++) {
		if (niz_studenata[i].ID.compare(tmp_id) == 0) {
			kapacitet--;
			niz_studenata[i].ID = "0";
			niz_studenata[i].total = -1;
			cout << "Student uspijesno izbrisan\n\n";
			return;
		}
	}
	cout << "Student ne postoji\n\n";
}

void update_zapis(student niz_studenata[]) {
	string buffer;
	cout << "Upisi ID studenta za azurirati: ";
	cin >> buffer;
	int counter = jel_postoji(niz_studenata, buffer);
	if (counter == -1) {
		cout << "Student ne postoji\n\n";
		return;
	}

	cout << "Upisi stavku za azurirati: ";
	cin >> buffer;
	
	if (buffer.compare("ime") == 0) {
		string tmp;
		cout << "Upisite Ime: ";
		cin >> tmp;
		niz_studenata[counter].ime = tmp;
	} else if (buffer.compare("prezime") == 0) {
		string tmp;
		cout << "Upisite Prezime: ";
		cin >> tmp;
		niz_studenata[counter].prezime = tmp;
	} else if (buffer.compare("kviz1") == 0) {
		int tmp;
		cout << "Upisite broj bodova za kviz 1: ";
		cin >> tmp;
		if (tmp < 0) {
			cout << "Broj bodova treba biti veci od 0\n\n";
			return;
		} else if (tmp > 100) {
			cout << "Broj bodova treba biti manji od 100\n\n";
			return;
		}
		niz_studenata[counter].total -= niz_studenata[counter].kviz1;
		niz_studenata[counter].kviz1 = tmp;
		niz_studenata[counter].total += tmp;
	} else if (buffer.compare("kviz2") == 0) {
		int tmp;
		cout << "Upisite broj bodova za kviz 2: ";
		cin >> tmp;
		if (tmp < 0) {
			cout << "Broj bodova treba biti veci od 0\n\n";
			return;
		}
		else if (tmp > 100) {
			cout << "Broj bodova treba biti manji od 100\n\n";
			return;
		}
		niz_studenata[counter].total -= niz_studenata[counter].kviz2;
		niz_studenata[counter].kviz2 = tmp;
		niz_studenata[counter].total += tmp;
	} else if (buffer.compare("mid") == 0) {
		int tmp;
		cout << "Upisite broj bodova za mid-term: ";
		cin >> tmp;
		if (tmp < 0) {
			cout << "Broj bodova treba biti veci od 0\n\n";
			return;
		}
		else if (tmp > 100) {
			cout << "Broj bodova treba biti manji od 100\n\n";
			return;
		}
		niz_studenata[counter].total -= niz_studenata[counter].mid_score;
		niz_studenata[counter].mid_score = tmp;
		niz_studenata[counter].total += tmp;
	} else if (buffer.compare("final") == 0) {
		int tmp;
		cout << "Upisite broj bodova za zavrsnu ocjenu: ";
		cin >> tmp;
		if (tmp < 0) {
			cout << "Broj bodova treba biti veci od 0\n\n";
			return;
		}
		else if (tmp > 100) {
			cout << "Broj bodova treba biti manji od 100\n\n";
			return;
		}
		niz_studenata[counter].total -= niz_studenata[counter].final_score;
		niz_studenata[counter].final_score = tmp;
		niz_studenata[counter].total += tmp;
	}
	else {
		cout << "Nepoznata stavka za azuriranje\n\n";
	}
	cout << "Stavka uspijesno azurirana\n\n";
}

void prosjek_bodova(student niz_studenata[]) {
	string buffer;
	cout << "Upisite ID studenta: ";
	cin >> buffer;
	int mjesto = jel_postoji(niz_studenata, buffer);
	if (mjesto == -1) {
		cout << "Student ne postoji\n\n";
		return;
	}
	float broj_ispita = 0;
	if (niz_studenata[mjesto].kviz1)
		broj_ispita++;
	if (niz_studenata[mjesto].kviz2)
		broj_ispita++;
	if (niz_studenata[mjesto].mid_score)
		broj_ispita++;
	if (niz_studenata[mjesto].final_score)
		broj_ispita++;
	if (broj_ispita == 0) {
		cout << "Student nije pisao niti jedan ispit\n\n";
		return;
	}
	cout << "Prosjek bodova za " << niz_studenata[mjesto].ime << " " << niz_studenata[mjesto].prezime
		<< " iznosi " << niz_studenata[mjesto].total / broj_ispita << endl << endl;
}

void sortiraj(student niz_studenata[], bool usercall = true ) {
	int max;
	for (int i = 0; i <= 20; i++) {
		max = i;
		for (int j = i + 1; j <= 20; j++) {
			if (niz_studenata[j].total > niz_studenata[max].total) {
				max = j;
			}
		}
		swap(niz_studenata[i], niz_studenata[max]);
	}
	if (usercall)
		cout << "Uspijesno sortirano\n\n";
}

void max(student niz_studenata[]) {
	sortiraj(niz_studenata, false);
	if (niz_studenata[0].ID.compare("0") == 0) {
		cout << "Nema studenata\n\n";
		return;
	}
	ispis_jednog(niz_studenata, 0);
}

void min(student niz_studenata[]) {
	sortiraj(niz_studenata, false);
	int counter = -1;
	for (int i = 0; i <= 20; i++) {
		if (niz_studenata[i].ID.compare("0") == 0) {
			break;
		}
		counter = i;
	}
	if (counter == -1) {
		cout << "Nema studenata\n\n";
		return;
	}
	ispis_jednog(niz_studenata, counter);
}

void pronadi(student niz_studenata[]) {
	string buffer;
	cout << "Upisite ID studenta: ";
	cin >> buffer;
	for (int i = 0; i <= 20; i++) {
		if (niz_studenata[i].ID.compare(buffer) == 0) {
			ispis_jednog(niz_studenata, i);
			return;
		}
	}
	cout << "Student ne postoji\n\n";
}

int main() {
	student* niz_studenata = new student[30];
	for (int i = 0; i < 30; i++) {
		niz_studenata[i].ID = "0";
		niz_studenata[i].total = -1;
	}
	int zauzeto = 0;

	cout << "Upisite 'help' za listu naredbi\n";
	while (true) {
		cout << "Upisite naredbu: ";
		string Buffer;
		cin >> Buffer;

		if (Buffer.compare("izlaz") == 0) {
			break;
		}
		else if (Buffer.compare("help") == 0) {
			help();
		}
		else if (Buffer.compare("dodaj") == 0) {
			dodaj_zapis(niz_studenata, zauzeto);
		}
		else if (Buffer.compare("ukloni") == 0) {
			ukloni_studenta(niz_studenata, zauzeto);
		}
		else if (Buffer.compare("update") == 0) {
			update_zapis(niz_studenata);
		}
		else if (Buffer.compare("ispis") == 0) {
			ispisi_sve_studente(niz_studenata);
		}
		else if (Buffer.compare("prosjek") == 0) {
			prosjek_bodova(niz_studenata);
		}
		else if (Buffer.compare("sortiraj") == 0) {
			sortiraj(niz_studenata);
		}
		else if (Buffer.compare("max") == 0) {
			max(niz_studenata);
		}
		else if (Buffer.compare("min") == 0) {
			min(niz_studenata);
		}
		else if (Buffer.compare("pronadi") == 0) {
			pronadi(niz_studenata);
		}
		else {
			cout << "Nepoznata naredba, pokusajte ponovno (koristite mala slova)\n";
		}
	}
	cout << "Dovidenja\n";
	delete[] niz_studenata;
	//system("pause");
}