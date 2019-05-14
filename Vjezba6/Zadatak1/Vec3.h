#ifndef VEC3_H
#define VEC3_H
#include <iostream>
#include <string>

namespace OOP {

	class Vec3 {
	private:
		float x_poc, y_poc, z_poc, x_kraj, y_kraj, z_kraj;
		static int counter;
	public:
		Vec3() { x_poc = y_poc = z_poc = x_kraj = y_kraj = z_kraj = 0; counter++; }

		Vec3(float, float, float, float, float, float);

		friend std::istream& operator>>(std::istream& is, Vec3& vect);

		friend std::ostream& operator<<(std::ostream& os, const Vec3& vect);

		Vec3& operator=(const Vec3& drugi);

		Vec3 operator+(Vec3& drugi);

		Vec3 operator-(Vec3& drugi);

		Vec3 operator*(int skalar);

		Vec3 operator/(int skalar);

		Vec3& operator+=(Vec3& drugi);

		Vec3& operator-=(Vec3& drugi);

		Vec3& operator*=(int skalar);

		Vec3& operator/=(int skalar);

		bool operator==(Vec3& drugi);

		bool operator!=(Vec3& drugi);

		float operator*(Vec3& drugi);

		float operator[](std::string s);

		Vec3& normalize();
	};

}
#endif