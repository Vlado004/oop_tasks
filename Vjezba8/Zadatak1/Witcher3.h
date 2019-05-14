#ifndef WITCHER3_H
#define WITCHER3_H

#include "Rpg.h"
#include "OpenWorld.h"
using namespace std;

namespace oss {

	class Witcher3 : public Rpg, public OpenWorld {
	private:

	public:
		string type() { return "Open World RPG"; }

		string name() { return "Witcher3"; }

		~Witcher3() {}
	};

}

#endif