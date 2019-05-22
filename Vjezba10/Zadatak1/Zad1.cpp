#include "Stack.h"

int main() {
	Stack<int> mem(3);

	std::cout << "Stack je prazan -> " << mem.empty() << std::endl;
	std::cout << "Stack je pun -> " << mem.full() << std::endl;
	std::cout << "Velicina Stacka -> " << mem.curr_size() << std::endl;
	std::cout << "Top element -> " << mem.curr_top() << std::endl << std::endl;
	mem.push(3);
	mem.push(4);
	mem.push(5);
	mem.push(6);
	std::cout << "Stack je prazan -> " << mem.empty() << std::endl;
	std::cout << "Stack je pun -> " << mem.full() << std::endl;
	std::cout << "Velicina Stacka -> " << mem.curr_size() << std::endl;
	std::cout << "Top element -> " << mem.curr_top() << std::endl << std::endl;
	std::cout << mem.pop() << std::endl;
	std::cout << mem.pop() << std::endl;
	std::cout << mem.pop() << std::endl;
	std::cout << mem.pop() << std::endl;

	system("pause");
}