#ifndef STACK_TPP
#define STACK_TPP

namespace ft
{
	template <class T, class Container>
	stack<T, Container>::stack(const Container& container)
		: c(container)
	{
		// Complexity: same as the underlying container
	}

	template <class T, class Container>
	bool
	stack<T, Container>::empty() const
	{
		// Complexity: O(1)
		return c.empty();
	}

	template <class T, class Container>
	typename stack<T, Container>::size_type 
	stack<T, Container>::size() const
	{
		// Complexity: O(1)
		return c.size();
	}
	
	template <class T, class Container>
	typename stack<T, Container>::reference
	stack<T, Container>::top()
	{
		// Complexity: O(1)
		return c.back();
	}
	
	template <class T, class Container>
	typename stack<T, Container>::const_reference
	stack<T, Container>::top() const
	{
		// Complexity: O(1)
		return c.back();
	}
	
	template <class T, class Container>
	void
	stack<T, Container>::push(const value_type& x)
	{
		// Complexity: same as Container::push_back
		c.push_back(x);
	}
	
	template <class T, class Container>
	void
	stack<T, Container>::pop()
	{
		// Complexity: same as Container::pop_back
		c.pop_back();
	}

	template <class T, class Container>
	bool
	operator==(const stack<T, Container>& x, const stack<T, Container>& y)
	{
		// Complexity: O(size())
		return x.c == y.c;
	}

	template <class T, class Container>
	bool
	operator!=(const stack<T, Container>& x, const stack<T, Container>& y)
	{
		// Complexity: O(size())
		return x.c != y.c;
	}

	template <class T, class Container>
	bool
	operator<(const stack<T, Container>& x, const stack<T, Container>& y)
	{
		// Complexity: O(size())
		return x.c < y.c;
	}

	template <class T, class Container>
	bool
	operator>(const stack<T, Container>& x, const stack<T, Container>& y)
	{
		// Complexity: O(size())
		return x.c > y.c;
	}

	template <class T, class Container>
	bool
	operator>=(const stack<T, Container>& x, const stack<T, Container>& y)
	{
		// Complexity: O(size())
		return x.c >= y.c;
	}

	template <class T, class Container>
	bool
	operator<=(const stack<T, Container>& x, const stack<T, Container>& y)
	{
		// Complexity: O(size())
		return x.c <= y.c;
	}
}

#endif