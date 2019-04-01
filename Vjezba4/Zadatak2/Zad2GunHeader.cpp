#include "Zad2GunHeader.h"
#include <iostream>

using namespace std;

void Gun::reload() {
	bullets = clip_size;
}

void Gun::shoot() {
	if (bullets)
		bullets--;
	else
		cout << "You do not have enough bullets, reload." << endl;
}

void Gun::move_rand(int a, int b) {
	position.random_vrijednost(a, b);
}

const Tocka_3d Gun::current_position() {
	return position;
}

const int Gun::current_bullets() {
	return bullets;
}