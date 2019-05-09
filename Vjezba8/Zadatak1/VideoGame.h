#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <string>
using namespace std;

class VideoGame {
public:
	virtual ~VideoGame();

	virtual string type()=0;
};

VideoGame::~VideoGame() {}

#endif