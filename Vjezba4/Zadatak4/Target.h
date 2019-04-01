#ifndef TARGET_H
#define TARGET_H
#include "Point.h"

using namespace std;

class Target {
private:
	Tocka position;
	int height, width;
	bool hit;
public:
	Target() { hit = false; };

	void set_size(int, int);

	void set_position(int, int);

	const int get_width();

	const int get_height();

	const Tocka location();

	void shot();

	const bool status();
};

#endif