#include <iostream>

using namespace std;

int& pronadi(int niz[], int vel) {
	for (int i = 0; i < vel; i++) {
		if (niz[i] % 10 + (niz[i] / 100) % 10 == 5)
			return niz[i];
	}
}

int main() {
	int niz[] = { 1564, 4892, 9849, 1517, 7418, 9876, 3485, 1124 };
	cout<<pronadi(niz, sizeof(niz) / sizeof(int)) + 1<<endl;
	system("pause");
}