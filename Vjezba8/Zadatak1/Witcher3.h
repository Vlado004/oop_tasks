#ifndef WITCHER3_H
#define WITCHER3_H

#include "Rpg.h"
#include "OpenWorld.h"
using namespace std;

class Witcher3 : Rpg, OpenWorld {
private:
	string name = "Witcher3";

public:
	string type() {
		return "Open World RPG";
	}
};

#endif