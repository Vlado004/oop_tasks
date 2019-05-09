#include "Counter.h"

void Counter::add(VideoGame*) {

}

string Counter::most_frequent() {
	if (ps4 > pc) {
		if (ps4 > xbox)
			return "PS4";
		return "XBOX";
	}
	if (pc < xbox)
		return "PC";
	return "XBOX";
}