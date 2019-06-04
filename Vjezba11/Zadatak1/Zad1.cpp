#include <iostream>
#include <vector>
#include "XErrorOperand.h"
#include "XErrorOperator.h"
#include "XErrorMath.h"
using namespace std;

int upisi_broj() {
	int tmp;
	cout << "Upisite jedan broj: ";
	cin >> tmp;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		throw XErrorOperand();
	}
	return tmp;
}

char upisi_operator() {
	char op;
	cout << "Upisi operator: ";
	cin >> op;
	if (op != '+' && op != '-' && op != '*' && op != '/')
		throw XErrorOperator();
	return op;
}

float izracunaj(int broj1, int broj2, char op) {
	switch (op) {
	case '+' :
		return broj1 + broj2;
	case '-':
		return broj1 - broj2;
	case '*':
		return broj1 * broj2;
	case '/':
		if (broj2 == 0)
			throw XErrorMath();
		return broj1 / (float)broj2;
	}
}

int main() {
	int operand1, operand2;
	char op;
	vector <float> rezultati;
	while (1) {
		try {
			operand1 = upisi_broj();
			operand2 = upisi_broj();

			op = upisi_operator();

			rezultati.push_back(izracunaj(operand1, operand2, op));
		}
		catch (XError &e) {
			cout << e.print();
			e.make_log("errors.log");
		}
	}
}