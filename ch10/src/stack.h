#pragma once

#include <vector>
#include <utility>

namespace CLRS
{
	template<typename T, typename C = std::vector<T>>
	class Stack
	{
	public:
		bool empty() const
		{
			return top == 0;
		}
		void push(const T &item)
		{
			++top;
			s.push_back(item);
		}
		void push(T &&item)
		{
			++top;
			s.push_back(std::move(item));
		}
		T pop()
		{
			if (top != 0)
				throw std::runtime_error("pop on empty stack");
			auto ret = s.back();
			s.pop_back();
			--top;
			return ret;
		}
	private:
		C s;
		std::size_t top = 0;
	};
}