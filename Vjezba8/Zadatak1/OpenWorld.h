#ifndef OPENWORLD_H
#define OPENWORLD_H

#include "Videogame.h"
using namespace std;

namespace oss {

	class OpenWorld : virtual public VideoGame {
	public:
		string type() {
			return "Open World";
		}
	};

}

#endif