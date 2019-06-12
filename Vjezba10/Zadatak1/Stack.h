#ifndef STACK_H
#define STACK_H
#include <iostream>

template<typename T>
class Stack {
private:
	const int defaultSize = 10;
	const int maxSize = 1000;
	int size, top;
	T* arr;
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
		if (this->full()) {
			std::cout << "Nema dovoljno mjesta." << std::endl;
			return;
		}
		*stackPtr = data;
		top++;
		stackPtr++;
	}

	T pop() {
		if (this->empty()) {
			std::cout << "Stack je prazan." << std::endl;
			return NULL;
		}
		top--;
		stackPtr--;
		return *stackPtr;
	}

	const bool full() {
		if (top >= size)
			return true;
		return false;
	}

	const bool empty() {
		if (top <= 0)
			return true;
		return false;
	}

	const T curr_top() {
		if (this->empty()) {
			std::cout << "Stack je prazan." << std::endl;
			return NULL;
		}
		return arr[top - 1];
	}

	const int curr_size() {
		return size;
	}
};

#endif