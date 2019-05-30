#ifndef XERROROPERAND_H
#define XERROROPERAND_H
#include "XError.h"

class XErrorOperand : XError {
public:
	XErrorOperand() {
		this->print();
		this->make_log();
	}

	std::string get_time() {

	}

	void make_log() {

	}

	void print() {
		std::cout << "Doslo je do greske pri unosu s operandom" << std::endl;
	}
};

#endif