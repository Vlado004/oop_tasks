#include <iostream>

using namespace std;

typedef struct {
	string ID, ime, spol;
	int kviz1, kviz2, mid_score, final_score, total;
} student;

void dodaj_zapis() {

}

int main() {
	student* niz_studenata = new student[30];
	delete[] niz_studenata;

}