#include "Counter.h"
#include "GodOfWar.h"
#include "Fallout4.h"
#include "LastOfUs2.h"
#include "DarkSouls.h"
#include "Witcher3.h"
#include <iostream>
using namespace oss;

VideoGame::~VideoGame() {}

int main(void)
{
	Counter c;
	VideoGame* v[] = { new Witcher3, new DarkSouls, new Fallout4, new LastOfUs2, new GodOfWar };
	size_t sz = sizeof v / sizeof v[0];
	for (unsigned i = 0; i < sz; ++i)
		c.add(v[i]);
	std::cout << "Najzastupljenija platforma: " << c.mostFrequentPlatform() << std::endl;
	for (unsigned i = 0; i < sz; ++i)
		delete v[i];
	system("pause");
}