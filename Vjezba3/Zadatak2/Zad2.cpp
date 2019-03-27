#include <iostream>
#include <vector>

#include "funkcije.h"
using namespace std;


int main() {
	srand(time(NULL));
	vector<int> vector1, vector2, rez_vector;
	vector1 = unos_vectora(vector1, false, 0, 100, 15);
	vector2 = unos_vectora(vector2, false, 0, 100, 15);
	ispis_vectora(vector1);
	ispis_vectora(vector2);

	rez_vector = pronadi(vector1, vector2, rez_vector);
	ispis_vectora(rez_vector);
	system("pause");
}