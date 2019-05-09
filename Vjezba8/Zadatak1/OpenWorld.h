#ifndef OPENWORLD_H
#define OPENWORLD_H

#include "Videogame.h"
using namespace std;

class OpenWorld : VideoGame {
public:
	string type() {
		return "Open World";
	}
};

#endif