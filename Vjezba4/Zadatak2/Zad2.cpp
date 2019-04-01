#include "Zad2GunHeader.h"
#include <iostream>

int main() {
	Gun pewpew;
	pewpew.move_rand(-100,100);
	Tocka_3d curr_pos = pewpew.current_position();
	cout << "You handgun is located at the coordinates X: " << curr_pos.dohvati_duljinu()
		<< ", Y" << curr_pos.dohvati_sirinu()
		<< ", Z: " << curr_pos.dohvati_visinu() << ".\n";
	for (int i = 0; i < 16; i++) {
		pewpew.shoot();
		cout << "You have " << pewpew.current_bullets() << " bullets left.\n";
	}
	pewpew.reload();
	cout << "You have " << pewpew.current_bullets() << " bullets left.\n";
	system("pause");
}