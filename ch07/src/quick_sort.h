#ifndef QUICK_SORT_H
#define QUICK_SORT_H

namespace CLRS
{
	/**
	template <typename Iterator>
	void quick_sort(Iterator first, Iterator last) {
		if (first < last - 1)
		{
			auto pivot = partition(first, last);
			quick_sort(first, pivot);
			quick_sort(pivot + 1, last);
		}
	}


	template <typename Iterator>
	Iterator partition(Iterator first, Iterator last)
	{
		auto pivot = last - 1;
		auto less_end = first - 1;
		for (auto iter = first; iter != pivot; ++iter)
		{
			if (*iter < *pivot)
			{
				std::swap(*iter, *++less_end);
			}
		}
		std::swap(*++less_end, *pivot);
		return less_end;
	}
	*/

	template<typename T>
	void quick_sort(T &seq, std::size_t p, std::size_t r)
	{
		if (p < r)
		{
			auto q = partition(seq, p, r);
			quick_sort(seq, p, q - 1);
			quick_sort(seq, q + 1, r);
		}
	}

	template<typename T>
	std::size_t partition(T &seq, std::size_t p, std::size_t r)
	{
		auto x = seq[r];
		auto i = p - 1;
		for (auto j = p; j != r; ++j)
		{
			if (seq[j] <= x)
			{
				std::swap(seq[++i], seq[j]);
			}
		}
		std::swap(seq[i + 1], seq[r]);
		return i + 1;
	}
}



#endif
