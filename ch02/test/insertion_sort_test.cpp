#include <iostream>
#include <vector>
#include "../src/insertion_sort.h"

int main()
{
	std::vector<int> ivec = { 9, 2, 1, 4, 2, 8, 3, 9, 3 };
	clrs::insert_sort(ivec);
	for (const auto &elem : ivec)
		std::cout << elem << std::endl;
	return 0;
}