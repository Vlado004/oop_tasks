#ifndef COUNTER_H
#define COUNTER_H

#include <string>
#include "VideoGame.h"

class Counter {
private:
	int ps4, pc, xbox;
public:
	Counter() { ps4 = pc = xbox = 0; }

	void add(VideoGame*);

	string most_frequent();
};

#endif