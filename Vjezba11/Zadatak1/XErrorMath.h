#ifndef XERRORMATH_H
#define XERRORMATH_H
#include "XError.h"

class XErrorMath : public XError {
public:
	std::string get_time() {
		time_t curr_time = time(NULL);
		return ctime(&curr_time);
	}

	void make_log(std::string name) {
		std::ofstream datoteka(name, std::ios_base::out | std::ios_base::app);
		if (!datoteka)
			return;
		datoteka << get_time() + print() << std::endl;
	}

	std::string print() {
		return "Doslo je do matematicke greske\n";
	}
};

#endif