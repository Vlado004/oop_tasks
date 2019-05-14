#include "Target.h"

using namespace std;

void Target::set_size(int w, int h) {
	width = w;
	height = h;
}

void Target::set_position(int a, int b) {
	position.random_vrijednost(a, b);
}

const int Target::size() {
	return width * height;
}

const Tocka Target::location() {
	return position;
}

void Target::shot() {
	hit = true;
}

const bool Target::status() {
	return hit;
}