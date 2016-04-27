#pragma once

namespace clrs
{
	template<typename T>
	void insert_sort(T &seq)
	{
		for (auto i = 1; i != seq.size(); ++i)
		{
			auto key = seq[i];
			auto j = i - 1;
			while (j >= 0 && key < seq[j])
			{
				seq[j + 1] = seq[j];
				--j;
			}
			seq[j + 1] = key;
		}
	}
}