#pragma once

#include <deque>
#include <string>
#include <assert.h>

namespace CLRS
{
	template<typename T, typename Container = std::deque<T>>
	class Queue
	{
	public:
		using size_type = typename Container::size_type;
		using iterator = typename Container::iterator;
		using container_type = Container;
		using value_type = typename Container::value_type;
		using reference = typename Container::reference;
		using const_reference = typename Container::const_reference;
		Queue() : q() { }
		Queue(std::size_t sz) : q(sz) { }
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
			assert(!check_full_and_increment() && "overflow");
			q.push_back(item);
		}
		void enqueue(T &&item)
		{
			assert(!check_full_and_increment() && "overflow");
			q.push_back(std::move(item));
		}
		T dequeue()
		{
			assert(!empty() && "underflow");
			auto ret = q.front();
			q.pop_front();
			++head;
			return ret;
		}
		reference front()
		{
			assert(!empty() && "front on empty queue");
			return q.front();
		}
		const_reference front() const
		{
			assert(!empty() && "front on empty queue");
			return q.front();
		}
		reference back()
		{
			assert(!empty() && "back on empty queue");
			return q.back();
		}
		const_reference back() const
		{
			assert(!empty() && "back on empty queue");
			return q.back();
		}
	private:
		Container q;
		size_type head = 0;
		size_type tail = 0;
		bool check_full_and_increment() 
		{
			if (++tail == q.size() && head == 0)
				return true;
			else if (tail == head)
				return true;
			else
				return false;
		}
	};
}