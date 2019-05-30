#ifndef XERROR_H
#define XERROR_H
#include <string>

class XError {
public:
	virtual std::string get_time() = 0;
	virtual void make_log() = 0;
	virtual void print() = 0;
};

#endif