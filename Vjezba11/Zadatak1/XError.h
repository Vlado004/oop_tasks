#ifndef XERROR_H
#define XERROR_H
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>

class XError {
public:
	virtual std::string get_time() = 0;
	virtual void make_log(std::string) = 0;
	virtual std::string print() = 0;
};

#endif