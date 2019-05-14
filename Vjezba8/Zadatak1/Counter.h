#ifndef COUNTER_H
#define COUNTER_H

#include "VideoGame.h"

namespace oss {

	class Counter {
	private:
		int ps4, pc, xbox;
	public:
		Counter() { ps4 = pc = xbox = 0; }

		void add(VideoGame* game);

		string mostFrequentPlatform();
	};

}

#endif