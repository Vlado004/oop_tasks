#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <string>
using namespace std;

namespace oss {

	class VideoGame {
	public:
		virtual ~VideoGame() = 0;

		virtual string type() = 0;

		virtual string name() = 0;
	};

}

#endif