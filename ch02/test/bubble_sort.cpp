#include <vector>
#include <iostream>
#include "../src/bubble_sort.h"

int main()
{
	std::vector<int> ivec = { 1, 3, 2, 4, 0, 9, 5, 8, 6, 7 };
	clrs::bubble_sort(ivec);
	for (const auto &elem : ivec)
		std::cout << elem << std::endl;
}