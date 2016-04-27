#include <vector>
#include "../src/merge_sort.h"

int main()
{
	std::vector<int> ivec = { 1, 3, 1, 4, 6, 2, 6, 7, 9, 5 };
	clrs::merge_sort(ivec, 0, ivec.size());
	return 0;
}