#include <iostream>
#include <vector>
#include "../src/randomized_quick.h"

int main()
{
	std::vector<int> ivec = { 1, 3, 5, 9, 7, 6, 2, 4, 0 };
	CLRS::randomized_quick_sort(ivec.begin(), ivec.end());
	for (const auto &elem : ivec)
		std::cout << elem << std::endl;
	return 0;
}