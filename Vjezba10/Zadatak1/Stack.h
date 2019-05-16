#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack {
private:
	const int defaultSize = 10;
	const int maxSize = 1000;
	int size, top;
	T arr;
	T* stackPtr;
public:
	Stack() {
		size = defaultSize;
		top = 0;
		arr = new T[size];
		stackPtr = arr;
	}
	Stack(int userSize) {
		if (userSize <= 0 || userSize > maxSize)
			size = defaultSize;
		else
			size = userSize;
		top = 0;
		arr = new T[size];
		stackPtr = arr;
	}
	~Stack() { delete[] arr; }

	void push(T data) {
		if (top >= size) //pomocna
			return;
		stackPtr* = data;
		top++;
		stackPtr++;
	}
	T pop() {
		if (top == 0) //pomocna i poruka
			return NULL;

	}
};

#endif