#pragma once

#include <cstddef>

namespace CLRS
{
	std::size_t left(std::size_t i)
	{
		return 2 * i + 1;
	}

	std::size_t right(std::size_t i)
	{
		return 2 * i + 2;
	}

	template<typename T>
	void max_heapify(T &seq, std::size_t i, std::size_t heap_size)
	{
		auto l = left(i);
		auto r = right(i);
		std::size_t largest;
		if (l <= heap_size && seq[i] < seq[l])
			largest = l;
		else
			largest = i;
		if (r <= heap_size && seq[largest] < seq[r])
			largest = r;
		if (largest != i)
		{
			using std::swap;
			swap(seq[i], seq[largest]);
			max_heapify(seq, largest, heap_size);
		}
	}

	template<typename T>
	void build_heap(T &seq)
	{
		std::size_t heap_size = seq.size() - 1;
		for (auto i = seq.size() / 2 - 1; i != -1; --i)
			max_heapify(seq, i, heap_size);
	}

	template<typename T>
	void heap_sort(T &seq)
	{
		build_heap(seq);
		std::size_t heap_size = seq.size() - 1;
		for (auto i = seq.size() - 1; i != 0; --i)
		{
			using std::swap;
			swap(seq[heap_size--], seq[0]);
			max_heapify(seq, 0, heap_size);
		}
	}

}