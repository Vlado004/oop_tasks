#ifndef RPG_H
#define RPG_H

#include "Videogame.h"
using namespace std;

namespace oss {

	class Rpg : virtual public VideoGame {
	public:
		string type() {
			return "Rpg";
		}
	};

}

#endif