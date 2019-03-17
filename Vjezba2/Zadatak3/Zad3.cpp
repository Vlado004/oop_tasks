#include <iostream>
using namespace std;

typedef struct my_vect{
	int *niz;
	int fiz_vel, log_vel;

	my_vect *vector_new(int init) {
		my_vect* vector = new my_vect;
		vector->niz = new int[init];
		vector->fiz_vel = init;
		vector->log_vel = 0;
		return vector;
	}

	void vector_delete() {
		delete[] niz;
	}

} my_vect;

int main() {
	my_vect* vector = vector->vector_new(5);
	vector->vector_delete();
}