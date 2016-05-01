#pragma once

#include <vector>
#include <utility>

namespace CLRS
{
	template<typename T, typename C = std::vector<T>>
	class Stack
	{
	public:
		using size_type = typename C::size_type;
		bool empty() const
		{
			return top == 0;
		}
		size_type size() const
		{
			return s.size();
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
			if (top == 0)
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