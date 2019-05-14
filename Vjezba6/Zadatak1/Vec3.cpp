#include "Vec3.h"
#include <math.h>
using namespace OOP;

int Vec3::counter = 0;

Vec3::Vec3(float x1, float y1, float z1, float x2, float y2, float z2) {
	x_poc = x1;
	y_poc = y1;
	z_poc = z1;
	x_kraj = x2;
	y_kraj = y2;
	z_kraj = z2;
	counter++;
}

std::istream& OOP::operator>>(std::istream& is, Vec3& vect) {
	std::cout << "Unesi pocetni x: ";
	is >> vect.x_poc;
	std::cout << "Unesi pocetni y: ";
	is >> vect.y_poc;
	std::cout << "Unesi pocetni z: ";
	is >> vect.z_poc;
	std::cout << "Unesi krajnji x: ";
	is >> vect.x_kraj;
	std::cout << "Unesi krajnji y: ";
	is >> vect.y_kraj;
	std::cout << "Unesi krajnji z: ";
	is >> vect.z_kraj;
	return is;
}

std::ostream& OOP::operator<<(std::ostream& os, const Vec3& vect) {
	os << "Pocetni x: " << vect.x_poc << std::endl
		<< "Pocetni y: " << vect.y_poc << std::endl
		<< "Pocetni z: " << vect.z_poc << std::endl
		<< "Krajnji x: " << vect.x_kraj << std::endl
		<< "Krajnji y: " << vect.y_kraj << std::endl
		<< "Krajnji z: " << vect.z_kraj << std::endl;
	return os;
}

Vec3& Vec3::operator=(const Vec3& drugi) {
	x_poc = drugi.x_poc;
	y_poc = drugi.y_poc;
	z_poc = drugi.z_poc;
	x_kraj = drugi.x_kraj;
	y_kraj = drugi.y_kraj;
	z_kraj = drugi.z_kraj;
	return *this;
}

Vec3 Vec3::operator+(Vec3& drugi) {
	Vec3 novi(x_poc, y_poc, z_poc, drugi.x_kraj, drugi.y_kraj, drugi.z_kraj);
	return novi;
}

Vec3 Vec3::operator-(Vec3& drugi) {
	Vec3 novi(x_poc, y_poc, z_poc, drugi.x_poc, drugi.y_poc, drugi.z_poc);
	return novi;
}

Vec3 Vec3::operator*(int skalar) {
	Vec3 novi(x_poc, y_poc, z_poc, x_kraj * skalar, y_kraj * skalar, z_kraj * skalar);
	return novi;
}

Vec3 Vec3::operator/(int skalar) {
	Vec3 novi(x_poc, y_poc, z_poc, x_kraj / skalar, y_kraj / skalar, z_kraj / skalar);
	return novi;
}

Vec3& Vec3::operator+=(Vec3& drugi) {
	x_kraj = drugi.x_kraj;
	y_kraj = drugi.y_kraj;
	z_kraj = drugi.z_kraj;
	return *this;
}

Vec3& Vec3::operator-=(Vec3& drugi) {
	x_kraj = drugi.x_poc;
	y_kraj = drugi.y_poc;
	z_kraj = drugi.z_poc;
	return *this;
}

Vec3& Vec3::operator*=(int skalar) {
	x_kraj = x_kraj * skalar;
	y_kraj = y_kraj * skalar;
	z_kraj = z_kraj * skalar;
	return *this;
}

Vec3& Vec3::operator/=(int skalar) {
	x_kraj = x_kraj / skalar;
	y_kraj = y_kraj / skalar;
	z_kraj = z_kraj / skalar;
	return *this;
}

bool Vec3::operator==(Vec3& drugi) {
	if (x_poc == drugi.x_poc && y_poc == drugi.y_poc && z_poc == drugi.z_poc) {
		if (x_kraj == drugi.x_kraj && y_kraj == drugi.y_kraj && z_kraj == drugi.z_kraj)
			return true;
	}
	return false;
}

bool Vec3::operator!=(Vec3& drugi) {
	if (x_poc == drugi.x_poc && y_poc == drugi.y_poc && z_poc == drugi.z_poc) {
		if (x_kraj == drugi.x_kraj && y_kraj == drugi.y_kraj && z_kraj == drugi.z_kraj)
			return false;
	}
	return true;
}

float Vec3::operator*(Vec3& drugi) {
	return (x_kraj - x_poc) * (drugi.x_kraj - drugi.x_poc) + (y_kraj - y_poc) * (drugi.y_kraj - drugi.y_poc) + (z_kraj - z_poc) * (drugi.z_kraj - drugi.z_poc);
}

float Vec3::operator[](std::string s) {
	if (s.compare("x_poc") == 0)
		return x_poc;
	if (s.compare("y_poc") == 0)
		return y_poc;
	if (s.compare("z_poc") == 0)
		return z_poc;
	if (s.compare("x_kraj") == 0)
		return x_kraj;
	if (s.compare("y_kraj") == 0)
		return y_kraj;
	if (s.compare("z_kraj") == 0)
		return z_kraj;
	return 0;
}

Vec3& Vec3::normalize() {
	float l = sqrt((x_kraj - x_poc) * (x_kraj - x_poc) + (y_kraj - y_poc) * (y_kraj - y_poc) + (z_kraj - z_poc) * (z_kraj - z_poc));
	x_kraj = x_poc + ((x_kraj - x_poc) / l);
	y_kraj = y_poc + ((y_kraj - y_poc) / l);
	z_kraj = z_poc + ((z_kraj - z_poc) / l);
	return *this;
}