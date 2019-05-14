#include "Counter.h"
#include <fstream>

using namespace oss;

void Counter::add(VideoGame* game) {
	//otvorit datoteku
	ifstream dat;
	dat.open("videogames.txt");
	if (dat.fail()) {
		std::cout << "Doslo je do pogreske pri otvaranju datoteke." << std::endl;
		return;
	}
	//Glavni dio
	bool pronadeno = false;
	while (!dat.eof()) {
		string tmp;
		getline(dat, tmp);
		for (int i = 0; i < game->name().size(); i++) {
			if (tmp[i] == game->name()[i])
				pronadeno = true;
			else
			{
				pronadeno = false;
				break;
			}
		}
		if (pronadeno) {
			for (int i = game->name().size() + 1; i < tmp.size() - 1; i++) {
				if (tmp[i] == 'P' && tmp[i+1] == 'C')
					pc += 1;
			}
			for (int i = game->name().size() + 1; i < tmp.size() - 2; i++) {
				if (tmp[i] == 'P' && tmp[i+1] == 'S' && tmp[i+2] == '4')
					ps4 += 1;
			}
			for (int i = game->name().size() + 1; i < tmp.size() - 3; i++) {
				if (tmp[i] == 'X' && tmp[i+1] == 'B' && tmp[i+2] == 'O' && tmp[i+3] == 'X')
				 xbox += 1;
			}
		}
	}
	//zatvorit datoteku
	dat.close();
}

string Counter::mostFrequentPlatform() {
	if (ps4 > pc) {
		if (ps4 > xbox)
			return "PS4";
		return "XBOX";
	}
	if (pc < xbox)
		return "PC";
	return "XBOX";
}