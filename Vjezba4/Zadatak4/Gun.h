#ifndef GUN_H
#define GUN_H
#include "Point.h"

class Gun {
private:
	int clip_size, bullets;
	Tocka position;
public:
	Gun() { clip_size = 15; bullets = 15; }

	void reload();

	void shoot();

	void move_rand(int, int);

	const Tocka current_position();

	const int current_bullets();
};

#endif