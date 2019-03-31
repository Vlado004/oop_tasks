#include "Zad2GunHeader.h"
#include <iostream>

using namespace std;

void Gun::reload() {
	bullets = clip_size;
}

void Gun::shoot() {
	if (!bullets)
		bullets--;
	else
		cout << "You do not have enough bullets, reload." << endl;
}

void Gun::move(int a, int b) {
	position.random_vrijednost(a, b);
}

int Gun::current_bullets() {
	return bullets;
}