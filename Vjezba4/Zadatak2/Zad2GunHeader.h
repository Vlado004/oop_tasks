#ifndef ZAD2GUNHEADER_H
#define ZAD2GUNHEADER_H
#include "Zad2PointHeader.h"

class Gun {
private:
	int clip_size, bullets;
	Tocka_3d position;
public:
	Gun() { clip_size = 15; bullets = 15; }

	void reload();

	void shoot();

	void move_rand(int, int);

	const Tocka_3d current_position();

	const int current_bullets();
};

#endif