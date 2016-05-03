#include <iostream>
#include "../src/queue.h"

int main()
{
	CLRS::Queue<int> q;
	q.enqueue(32);
	std::cout << q.size() << std::endl;
	std::cout << q.dequeue() << " " <<  q.front() << " " << q.back() << std::endl;
	std::cout << q.size() << std::endl;
	return 0;
}
