#ifndef PRIORITY_QUEUE_TPP
#define PRIORITY_QUEUE_TPP

namespace ft
{
	template <class T, class Container, class Compare>
	ft::priority_queue<T,Container,Compare>::priority_queue(const Compare& x, const Container& y)
		: c(y), comp(x)
	{
		/*
		N = size()
		Complexity: 
			comparaison; O(N)
			value type constructor: O(N)
		*/
		ft::make_heap(c.begin(), c.end(), comp);
	}

	template <class T, class Container, class Compare>
	template <class InputIterator>
	ft::priority_queue<T,Container,Compare>::priority_queue(InputIterator first,
		InputIterator last,
		const Compare& x,
		const Container& y,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
			: c(y), comp(x)
	{
		/*
		N = size()
		M = distance(first, last)
		Complexity: 
			comparaison; O(N + M)
			value type constructor: O(N)
		*/
		c.insert(c.end(), first, last);
		ft::make_heap(c.begin(), c.end(), comp);
	}

	template <class T, class Container, class Compare>
	bool
	ft::priority_queue<T,Container,Compare>::empty() const
	{
		// Complexity: O(1)
		return c.empty();
	}

	template <class T, class Container, class Compare>
	typename ft::priority_queue<T,Container,Compare>::size_type
	ft::priority_queue<T,Container,Compare>::size() const
	{
		// Complexity: O(1)
		return c.size();
	}

	template <class T, class Container, class Compare>
	typename ft::priority_queue<T,Container,Compare>::const_reference
	ft::priority_queue<T,Container,Compare>::top() const
	{
		// Complexity: O(1)
		return c.front();
	}

	template <class T, class Container, class Compare>
	void
	ft::priority_queue<T,Container,Compare>::push(const value_type& x)
	{
		// Complexity: O(log(size()) + Container::push_back complexity
		c.push_back(x);
		ft::push_heap(c.begin(), c.end(), comp);
	}

	template <class T, class Container, class Compare>
	void
	ft::priority_queue<T,Container,Compare>::pop()
	{
		// Complexity: O(log(size()) + Container::pop_back complexity
		if (empty())
			return;
		ft::pop_heap(c.begin(), c.end(), comp);
		c.pop_back();
	}
}

#endif