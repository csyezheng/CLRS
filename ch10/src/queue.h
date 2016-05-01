#pragma once

#include <deque>

namespace CLRS
{
	template<typename T, typename Container = std::deque<T>>
	class Queue
	{
	public:
		using size_type = typename Container::size_type;
		using iterator = typename Container::iterator;
		Queue(std::size_t sz) : q(sz)
		{
			head = tail = q.begin();
		}
		size_type size() const
		{
			return q.size();
		}
		bool empty() const
		{
			return size() ? false : true;
		}
		void enqueue(const T &item)
		{
			q.push_back(item);
			++tail;
		}
		void enqueue(T &&item)
		{
			q.push_back(std::move(item));
			++tail;
		}
		T dequeue()
		{
			if (empty())
				throw std::runtime_error("dequeue on empty queue");
			auto ret = q.front();
			q.pop_front();
			++head;
			return ret;
		}
	private:
		Container q;
		iterator head;
		iterator tail;
	};
}