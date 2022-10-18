#include "stack.h"
#include <iostream>

int main()
{
	Stack<int> stack;
	stack.push(1);

	std::cout << stack.top() <<std::endl;
	stack.push(2);
	stack.push(3);
	std::cout << stack.top() <<std::endl;
	stack.pop();
	std::cout << stack.top() <<std::endl;
	std::cout << "The sise is: " << stack.size() << std::endl;
	std::cout << "The stack is empty?: " << stack.empty() << std::endl;
	stack.pop();
	stack.pop();
	std::cout << "The stack is empty?: " << stack.empty() << std::endl;
	//stack.pop(); -->calls error and end program when uncommented :)
	stack.top(); //call error like above because stack is empty :)
	return 0;
	
}