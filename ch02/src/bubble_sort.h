#pragma once

namespace clrs
{
	template<typename T>
	void bubble_sort(T &seq)
	{
		for (auto i = 0; i != seq.size(); ++i)
		{
			for (auto j = seq.size() - 1; j != i; --j)
			{
				if (seq[j] < seq[j - 1])
				{
					using std::swap;
					swap(seq[j], seq[j - 1]);
				}
			}
		}
	}
}