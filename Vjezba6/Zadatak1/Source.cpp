#include "Vec3.h"
#include <iostream>


int main() {
	OOP::Vec3 vector1;
	OOP::Vec3 vector2(1,1,1,7,8,9);
	std::cin >> vector1;
	std::cout << vector1 << std::endl << vector2 << std::endl;
	OOP::Vec3 rezultatni_vektor;

	rezultatni_vektor = vector1 + vector2;
	std::cout << rezultatni_vektor << std::endl;
	rezultatni_vektor = vector1 - vector2;
	std::cout << rezultatni_vektor << std::endl;
	rezultatni_vektor = vector1 * 2;
	std::cout << rezultatni_vektor << std::endl;
	rezultatni_vektor = vector1 / 2;
	std::cout << rezultatni_vektor << std::endl;
	rezultatni_vektor += vector1;
	std::cout << rezultatni_vektor << std::endl;
	rezultatni_vektor -= vector1;
	std::cout << rezultatni_vektor << std::endl;
	rezultatni_vektor *= 2;
	std::cout << rezultatni_vektor << std::endl;
	rezultatni_vektor /= 2;
	std::cout << rezultatni_vektor << std::endl;

	std::cout << vector1 * vector2 << std::endl;
	bool flag = vector1 == vector2;
	std::cout << flag << std::endl;
	flag = vector1 != vector2;
	std::cout << flag << std::endl;

	float broj = vector1["z_poc"];
	std::cout << broj << std::endl;

	vector1.normalize();
	std::cout << vector1 << std::endl;

	system("pause");
}