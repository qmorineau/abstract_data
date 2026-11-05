#ifndef QUEUE_TPP
#define QUEUE_TPP

namespace ft
{
	template <class T, class Container>
	queue<T, Container>::queue(const Container& container)
		: c(container)
	{
		// Complexity: same as the underlying container
	}

	template <class T, class Container>
	bool
	queue<T, Container>::empty() const
	{
		// Complexity: O(1)
		return c.empty();
	}

	template <class T, class Container>
	typename queue<T, Container>::size_type
	queue<T, Container>::size() const
	{
		// Complexity: O(1)
		return c.size();
	}

	template <class T, class Container>
	typename queue<T, Container>::reference
	queue<T, Container>::front()
	{
		// Complexity: O(1)
		return c.front();
	}

	template <class T, class Container>
	typename queue<T, Container>::const_reference
	queue<T, Container>::front() const
	{
		// Complexity: O(1)
		return c.front();
	}

	template <class T, class Container>
	typename queue<T, Container>::reference
	queue<T, Container>::back()
	{
		// Complexity: O(1)
		return c.back();
	}

	template <class T, class Container>
	typename queue<T, Container>::const_reference
	queue<T, Container>::back() const
	{
		// Complexity: O(1)
		return c.back();
	}

	template <class T, class Container>
	void
	queue<T, Container>::push(const value_type& x)
	{
		// Complexity: same as Container::push_back
		c.push_back(x);
	}

	template <class T, class Container>
	void
	queue<T, Container>::pop()
	{
		// Complexity: same as Container::pop_front
		c.pop_front();
	}

	template <class T, class Container>
	bool
	operator==(const queue<T, Container>& x, const queue<T, Container>& y)
	{
		// Complexity: O(size())
		return x.c == y.c;
	}

	template <class T, class Container>
	bool operator!=(const queue<T, Container>& x, const queue<T, Container>& y)
	{
		// Complexity: O(size())
		return x.c != y.c;
	}

	template <class T, class Container>
	bool
	operator<(const queue<T, Container>& x, const queue<T, Container>& y)
	{
		// Complexity: O(size())
		return x.c < y.c;
	}

	template <class T, class Container>
	bool operator>(const queue<T, Container>& x, const queue<T, Container>& y)
	{
		// Complexity: O(size())
		return x.c > y.c;
	}

	template <class T, class Container>
	bool operator>=(const queue<T, Container>& x, const queue<T, Container>& y)
	{
		// Complexity: O(size())
		return x.c >= y.c;
	}
	
	template <class T, class Container>
	bool operator<=(const queue<T, Container>& x, const queue<T, Container>& y)
	{
		// Complexity: O(size())
		return x.c <= y.c;
	}
}

#endif