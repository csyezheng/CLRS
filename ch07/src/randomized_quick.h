#pragma once

#include <random>

namespace CLRS
{
	template<typename TIterator>
	TIterator partition(TIterator first, TIterator last)
	{
		auto pivot = last - 1;
		auto bigger = first;
		for (auto iter = first; iter != pivot; ++iter)
		{
			if (*iter <= *pivot)
			{
				std::swap(*bigger++, *iter);
			}
		}
		std::swap(*bigger, *pivot);
		return bigger;
	}

	template<typename TIterator>
	TIterator randomized_partition(TIterator first, TIterator last)
	{
		std::random_device rd;
		std::mt19937 e(rd());
		//////////////////////////////////////////////////
		std::uniform_int_distribution<> dist(0, 100);          ///////////////////<>/////////////
		//////////////////////////////////////////////////
		auto range = last - first;
		TIterator pivot = first + dist(e) * range / 100;
		std::swap(*pivot, *(last - 1));
		return partition(first, last);
	}

	template<typename TIterator>
	void randomized_quick_sort(TIterator first, TIterator last)
	{
		if (last - first > 1)
		{
			auto pivot = randomized_partition(first, last);
			randomized_quick_sort(first, pivot);
			randomized_quick_sort(pivot + 1, last);
		}
	}
}