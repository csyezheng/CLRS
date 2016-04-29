#include <vector>
#include <iostream>
#include "../src/heap_sort.h"

int main()
{
	std::vector<int> ivec = { 9, 4, 8, 2, 0, 3,7, 1, 5, 6 };
	CLRS::heap_sort(ivec);
	for (const auto &elem : ivec)
		std::cout << elem << std::endl;
	return 0;
}