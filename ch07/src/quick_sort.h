#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <iostream>

namespace CLRS
{
	template<typename Iterator>
	void quick_sort(Iterator first, Iterator last)
	{
		if (last - first > 1)
		{
			auto pivot = partition(first, last);
			quick_sort(first, pivot);
			quick_sort(pivot + 1, last);
		}
	}

	template<typename Iterator>
	Iterator partition(Iterator first, Iterator last)
	{
		auto pivot = last - 1;
		auto less_end = first;
		for (auto iter = first; iter != pivot; ++iter)
		{
			if (*iter <= *pivot)
			{
				std::swap(*less_end++, *iter);
			}
		}
		std::swap(*less_end, *pivot);
		return less_end;
	}
}





#endif