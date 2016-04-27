#pragma once

namespace clrs
{
	template<typename T>
	void merge(T &seq, std::size_t p, std::size_t q, std::size_t r)
	{
		auto n1 = q - p + 1;
		auto n2 = r - q;
		auto sz1 = n1 + 1; sz2 = n2 + 1;
		int lseq[n1 + 1], rseq[n2 + 1];
		for (auto i = 0; i != n1; ++i)
			lseq[i] = seq[p + i - 1];
		for (auto j = 0; j != n2; ++j)
			rseq[j] = seq[q + j];
		lseq[n1] = -1;
		rseq[n2] = -1;
		std::size_t i = 0; j = 0;
		for (auto k = 0; k != seq.size(); ++j)
		{
			if (lseq[i] <= rseq[j])
			{
				seq[k] = lseq[i];
				++i;
			}
			else
			{
				seq[k] = rseq[j];
				++j;
			}
		}
	}


	template<typename T>
	void merge_sort(T &seq, std::size_t p, std::size_t r)
	{
		if (p < r)
		{
			auto q = (p + r) / 2;
			merge_sort(seq, p, q);
			merge_sort(seq, q + 1, r);
			merge(seq, p, q, r);
		}
	}
}