#pragma once

#include <memory>

namespace clrs
{
	template<typename T>
	T merge(T lseq, T rseq)
	{
		T seq;
		auto l = lseq.cbegin();
		auto r = rseq.cbegin();
		while (l != lseq.cend() && r != rseq.cend())
		{
			if (*l <= *r)
				seq.push_back(*l++);
			else
				seq.push_back(*r++);
		}
		if (r == rseq.cend())
			while (l != lseq.cend())
				seq.push_back(*l++);
		else
			while (r != rseq.cend())
				seq.push_back(*r++);
		return seq;
	}


	template<typename T>
	T merge_sort(const T &seq)
	{
		if (seq.size() > 1)
		{
			auto mid = seq.cbegin() + seq.size() / 2;
			auto lseq = merge_sort(T(seq.cbegin(), mid));
			auto rseq = merge_sort(T(mid, seq.cend()));
			return merge(lseq, rseq);
		}
		return seq;
	}
}
