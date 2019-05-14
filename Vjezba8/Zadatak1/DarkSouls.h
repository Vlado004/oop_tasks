#ifndef DARKSOULS_H
#define DARKSOULS_H

#include "Rpg.h"
using namespace std;

namespace oss {

	class DarkSouls : public Rpg {
	private:

	public:
		string name() { return "DarkSouls3"; }

		~DarkSouls() {}
	};

}
#endif