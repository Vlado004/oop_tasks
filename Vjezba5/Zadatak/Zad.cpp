#include <iostream>
#include <string>
#include <vector>
#include "Food.h"
#pragma warning(disable : 4996)
using namespace std;

void funkcija() {

}

int main() {
	vector <Food> Hrana;
	time_t t = time(NULL) + 5259492;
	string string1 = "Meso", string2 = "Piletina";
	Food tmp(string1, string2, 2, 30, 21, 12, &t, 100);
	//for (int i = 0; i < 3; i++)
	//{
		Hrana.push_back(tmp);
		cout << "OMEGALUL" << endl;
	//}

	//for (int i = 0; i < 3; i++) {
		if (Hrana[/*i*/0].dodaj_potrosnju(4, 2019, 50))
			cout << "Dodano" << endl;
		else
			cout << "We tried bois" << endl;
	//}
		

	//for (int i = 0; i < 3; i++)
		Hrana[/*i*/0].ispis();

	system("pause");
}