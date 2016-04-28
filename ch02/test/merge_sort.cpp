#include <vector>
#include <iostream>
#include <algorithm>
#include "../src/merge_sort.h"

int main()
{
	std::vector<int> ivec = { 1, 3, 1, 4, 6, 2, 6, 7, 9, 5 };
	auto ret = clrs::merge_sort(ivec);
	std::for_each(ret.cbegin(), ret.cend(),
		[](const auto &elem) { std::cout << elem << std::endl; });
	return 0;
}