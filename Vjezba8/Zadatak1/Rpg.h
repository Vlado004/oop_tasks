#ifndef RPG_H
#define RPG_H

#include "Videogame.h"
using namespace std;

class Rpg : VideoGame {
public:
	string type() {
		return "Rpg";
	}
};

#endif