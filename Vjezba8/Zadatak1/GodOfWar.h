#ifndef GODOFWAR_H
#define GODOFWAR_H

#include "Action.h"
using namespace std;

namespace oss {

	class GodOfWar : public Action {
	private:

	public:
		string name() { return "GodOfWar"; }

		~GodOfWar() {}
	};

}

#endif