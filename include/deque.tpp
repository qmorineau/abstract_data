#ifndef DEQUE_TPP
#define DEQUE_TPP

namespace ft
{
	// ======================
	//	Construct / Destruct
	// ======================

	template <class T, class Allocator>
	ft::deque<T, Allocator>::deque(const Allocator&)
	{
		// todo
	}

	template <class T, class Allocator>
	ft::deque<T, Allocator>::deque(size_type n, const T& value, const Allocator& alloc)
	{
		// todo
	}

	template <class T, class Allocator>
	template <class InputIterator>
	ft::deque<T, Allocator>::deque(InputIterator first, InputIterator last, const Allocator& alloc)
	{
		// todo
	}

	template <class T, class Allocator>
	ft::deque<T, Allocator>::deque(const deque<T,Allocator>& x)
	{
		// todo
	}

	template <class T, class Allocator>
	ft::deque<T, Allocator>::~deque()
	{
		// todo
	}

	// =====================
	//	    Assignement
	// =====================

	template <class T, class Allocator>
	deque<T,Allocator>&
	ft::deque<T,Allocator>::operator=(const deque<T,Allocator>& x)
	{
		// todo
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void
	ft::deque<T,Allocator>::assign(InputIterator first, InputIterator last)
	{
		// todo
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::assign(size_type n, const T& t)
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::allocator_type
	ft::deque<T,Allocator>::get_allocator() const
	{
		// todo
	}

	// =====================
	//	     Iterators
	// =====================

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::iterator
	ft::deque<T,Allocator>::begin()
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_iterator
	ft::deque<T,Allocator>::begin() const
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::iterator
	ft::deque<T,Allocator>::end()
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_iterator
	ft::deque<T,Allocator>::end() const
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::reverse_iterator
	ft::deque<T,Allocator>::rbegin()
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_reverse_iterator
	ft::deque<T,Allocator>::rbegin() const
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::reverse_iterator
	ft::deque<T,Allocator>::rend()
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_reverse_iterator
	ft::deque<T,Allocator>::rend() const
	{
		// todo
	}

	// ====================
	//	     Capacity
	// ====================

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::size_type
	ft::deque<T,Allocator>::size() const
	{
		return 0;// todo
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::size_type
	ft::deque<T,Allocator>::max_size() const
	{
		return 0;// todo
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::resize(size_type sz, T c)
	{
		// todo
	}

	template <class T, class Allocator>
	bool
	ft::deque<T,Allocator>::empty() const
	{
		return false;// todo
	}

	// ======================
	//	   Element Access
	// ======================

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::reference
	ft::deque<T,Allocator>::operator[](size_type n)
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_reference
	ft::deque<T,Allocator>::operator[](size_type n) const
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::reference
	ft::deque<T,Allocator>::at(size_type n)
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_reference
	ft::deque<T,Allocator>::at(size_type n) const
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::reference
	ft::deque<T,Allocator>::front()
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_reference
	ft::deque<T,Allocator>::front() const
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::reference
	ft::deque<T,Allocator>::back()
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_reference
	ft::deque<T,Allocator>::back() const
	{
		// todo
	}

	// =====================
	//	     Modifiers
	// =====================

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::push_front(const T& x)
	{
		// todo
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::push_back(const T& x)
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::iterator
	ft::deque<T,Allocator>::insert(iterator position, const T& x)
	{
		return begin();// todo
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::insert(iterator position, size_type n, const T& x)
	{
		// todo
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void
	ft::deque<T,Allocator>::insert(iterator position, InputIterator first, InputIterator last)
	{
		// todo
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::pop_front()
	{
		// todo
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::pop_back()
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::iterator
	ft::deque<T,Allocator>::erase(iterator position)
	{
		return begin();// todo
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::iterator
	ft::deque<T,Allocator>::erase(iterator first, iterator last)
	{
		return begin();// todo
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::swap(deque<T,Allocator>&)
	{
		// todo
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::clear()
	{
		// todo
	}

	// =====================
	//	  Private-Members
	// =====================

	// =====================
	//	    Non-Members
	// =====================

	template <class T, class Allocator>
	bool
	operator==(const deque<T,Allocator>& x, const deque<T,Allocator>& y)
	{
		return false; // todo
	}

	template <class T, class Allocator>
	bool
	operator< (const deque<T,Allocator>& x, const deque<T,Allocator>& y)
	{
		return false; // todo
	}
	template <class T, class Allocator>
	bool
	operator!=(const deque<T,Allocator>& x, const deque<T,Allocator>& y)
	{
		 return false;// todo
	}

	template <class T, class Allocator>
	bool
	operator> (const deque<T,Allocator>& x, const deque<T,Allocator>& y)
	{
		return false;// todo
	}

	template <class T, class Allocator>
	bool
	operator>=(const deque<T,Allocator>& x, const deque<T,Allocator>& y)
	{
		return false;// todo
	}

	template <class T, class Allocator>
	bool
	operator<=(const deque<T,Allocator>& x, const deque<T,Allocator>& y)
	{
		return false;// todo
	}

	// ======================
	//	  Specialized Algo
	// ======================

	template <class T, class Allocator>
	void
	swap(deque<T,Allocator>& x, deque<T,Allocator>& y)
	{
		// todo
	}
}

#endif