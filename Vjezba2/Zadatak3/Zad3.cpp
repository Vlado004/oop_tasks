#include <iostream>
using namespace std;

typedef struct {
	int *niz;
	int fiz_vel, log_vel;

	void vector_new() {
		niz = new int[10];
		fiz_vel = 10;
		log_vel = 0;
	}

	void vector_delete() {
		delete[] niz;
	}

	void vector_push_back(int broj) {
		if (log_vel == fiz_vel) {
			niz = (int*)realloc(niz, fiz_vel*2*sizeof(int));
		}
		niz[log_vel] = broj;
		log_vel++;
	}

	int vector_pop_back() {
		if (!log_vel)
			return NULL;
		log_vel = log_vel - 1;
		return niz[log_vel];
	}

	int vector_size() {
		return log_vel;
	}

	int& vector_front() {
		return niz[0];
	}

	int& vector_back() {
		return niz[log_vel - 1];
	}

} vector;

int main() {
	vector* v = new vector;
	v->vector_new();

	for (int i = 0; i < 15; i++) {
		v->vector_push_back(i);
		cout << v->vector_size() << endl;
	}

	v->vector_front() = 21;
	v->vector_back() = 56;

	for (int i = 0; i < 15; i++) {
		cout << v->vector_pop_back() << endl;
	}

	v->vector_delete();
	delete v;
	system("Pause");
}