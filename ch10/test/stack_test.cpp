#include <iostream>
#include "../src/stack.h"

int main()
{

	CLRS::Stack<int> s;
	s.push(9);
	std::cout << s.size() << std::endl;
	std::cout << s.pop() << std::endl;
	std::cout << s.size() << std::endl;

	return 0;
}