#ifndef QUEUE_TPP
#define QUEUE_TPP

namespace ft
{
	template <class T, class Container>
	ft::queue<T, Container>::queue(const Container& container)
		: c(container)
	{
		// Complexity: same as the underlying container
	}

	template <class T, class Container>
	bool
	ft::queue<T, Container>::empty() const
	{
		// Complexity: O(1)
		return c.empty();
	}

	template <class T, class Container>
	typename ft::queue<T, Container>::size_type
	ft::queue<T, Container>::size() const
	{
		// Complexity: O(1)
		return c.size();
	}

	template <class T, class Container>
	typename ft::queue<T, Container>::reference
	ft::queue<T, Container>::front()
	{
		// Complexity: O(1)
		return c.front();
	}

	template <class T, class Container>
	typename ft::queue<T, Container>::const_reference
	ft::queue<T, Container>::front() const
	{
		// Complexity: O(1)
		return c.front();
	}

	template <class T, class Container>
	typename ft::queue<T, Container>::reference
	ft::queue<T, Container>::back()
	{
		// Complexity: O(1)
		return c.back();
	}

	template <class T, class Container>
	typename ft::queue<T, Container>::const_reference
	ft::queue<T, Container>::back() const
	{
		// Complexity: O(1)
		return c.back();
	}

	template <class T, class Container>
	void
	ft::queue<T, Container>::push(const value_type& x)
	{
		// Complexity: same as Container::push_back
		c.push_back(x);
	}

	template <class T, class Container>
	void
	ft::queue<T, Container>::pop()
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