#include "Stack.h"


int main() 
{
	Stack<int> *stack = new Stack<int>();
	
	for (int i = 0; i < 100; ++i) 
	{
		stack->push(i);
	}

	while (!stack->isEmpty()) {
		std::cout << stack->pop() << std::endl;
	}

	char c;

	std::cin >> c;

	return 0;
}