#include <iostream>
using namespace std;

typedef struct my_vec{
	int *niz;
	int fiz_vel, log_vel;

	my_vec vector_new(int init) {

		my_vec* vector = new my_vec;
		vector->niz = new int[init];
	}

} my_vec;

int main() {

}