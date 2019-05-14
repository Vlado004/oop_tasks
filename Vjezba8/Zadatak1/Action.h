#ifndef ACTION_H
#define ACTION_H

#include "Videogame.h"
using namespace std;

namespace oss {

	class Action : virtual public VideoGame {
	private:

	public:
		string type() { return "Action"; }
	};

}

#endif