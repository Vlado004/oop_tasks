#ifndef ZBROJ_H
#define ZBROJ_H
#include <iostream>

template<typename TYPE>
class Zbroj {
private:
	TYPE podatak;
public:
	Zbroj() { std::cout << "Normalni template." << std::endl; }
	Zbroj(TYPE pod) { 
		podatak = pod;
		std::cout << "Normalni template." << std::endl;
	}
	void zbroji(Zbroj drugi) { podatak += drugi.podatak; }
	void ispis() { std::cout << podatak << std::endl; }
};

template<>
class Zbroj<char> {
private:
	char podatak;
public:
	Zbroj() { std::cout << "Specijalni template." << std::endl; }
	Zbroj(char pod) {
		podatak = pod;
		std::cout << "Specijalni template." << std::endl;
	}
	void zbroji(Zbroj drugi) { 
		if (isdigit(podatak)) {
			podatak = podatak + (drugi.podatak - '0');
		}
		else {
			podatak = podatak + (drugi.podatak - 'a' + 1);
		}
	}
	void ispis() { std::cout << podatak << std::endl; }
};

#endif