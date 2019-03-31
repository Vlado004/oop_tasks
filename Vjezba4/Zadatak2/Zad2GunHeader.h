#ifndef ZAD2GUNHEADER_H
#define ZAD2GUNHEADER_H
#include "Zad2PointHeader.h"

class Gun {
private:
	int clip_size, bullets;
	Tocka_3d position;
public:
	Gun() { clip_size = 9; bullets = 9; }

	void reload();

	void shoot();

	void move(int, int);

	int current_bullets();
};

#endif