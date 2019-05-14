#ifndef FALLOUT_H
#define FALLOUT_H

#include "Rpg.h"
using namespace std;

namespace oss {

	class Fallout4 : public Rpg {
	private:

	public:
		string name() { return "Fallout4"; }

		~Fallout4() {}
	};

}

#endif