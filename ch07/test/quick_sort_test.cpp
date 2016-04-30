#include <iostream>
#include <vector>
#include "../src/quick_sort.h"

int main()
{
	std::vector<int> ivec = { 1, 3, 5, 6, 9, 4, 0, 8 };
	CLRS::quick_sort(ivec, 0, ivec.size() - 1);
	for (const auto &elem : ivec)
		std::cout << elem << std::endl;
	return 0;
}