#include "Zbroj.h"

int main() {
	Zbroj<int> broj1(5), broj2(7);
	Zbroj<char> slovo1('f'), slovo2('e');
	Zbroj<char> slovo3('2'), slovo4('4');

	broj1.zbroji(broj2);
	slovo1.zbroji(slovo2);
	slovo3.zbroji(slovo4);

	broj1.ispis();
	slovo1.ispis();
	slovo3.ispis();

	system("pause");
}