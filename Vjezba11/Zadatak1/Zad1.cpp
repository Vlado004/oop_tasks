#include <iostream>
#include "XErrorOperand.h"
using namespace std;

int upisi_broj() {
	int tmp;
	bool invalid = true;
	cout << "Upisite jedan broj: ";
	cin >> tmp;
	while (invalid) {
		if (cin.fail()) {
			throw XErrorOperand();
			/*cin.clear();
			cin.ignore();
			cout << "Molimo vas upisite broj :)" << endl;*/
		}
		else
			invalid = false;
	}
	return tmp;
}

int main() {
	int operand1, operand2;
	while (1) {
		try {
			operand1 = upisi_broj();

		}
		catch (XErrorOperand e) {

		}
	}
}