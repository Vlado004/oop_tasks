#ifndef ACTION_H
#define ACTION_H

#include "Videogame.h"
using namespace std;

class Action : VideoGame {
private:
public:
	string type() {
		return "Action";
	}
};

#endif