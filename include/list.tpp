#ifndef LIST_TPP
#define LIST_TPP

namespace ft
{
	// ======================
	//	Construct / Destruct
	// ======================

	template <class T, class Allocator>
	ft::list<T, Allocator>::list(const Allocator& alloc)
	{
		// todo
	}

	template <class T, class Allocator>
	ft::list<T, Allocator>::list(size_type n, const T& value, const Allocator& alloc)
	{
		// todo
	}
	
	template <class T, class Allocator>
	template <class InputIterator>
	ft::list<T, Allocator>::list(InputIterator first, InputIterator last, const Allocator& alloc)
	{
		// todo
	}

	template <class T, class Allocator>
	ft::list<T, Allocator>::list(const list<T,Allocator>& x)
	{
		// todo
	}

	template <class T, class Allocator>
	ft::list<T, Allocator>::~list()
	{
		// todo
	}

	// =====================
	//	    Assignement
	// =====================

	template <class T, class Allocator>
	list<T,Allocator>&
	ft::list<T, Allocator>::operator=(const list<T,Allocator>& x)
	{
		// todo
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void
	ft::list<T, Allocator>::assign(InputIterator first, InputIterator last)
	{
		// todo
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::assign(size_type n, const T& t)
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::allocator_type
	ft::list<T, Allocator>::get_allocator() const
	{
		// todo
	}

	// =====================
	//	     Iterators
	// =====================
	
	template <class T, class Allocator>
	typename ft::list<T, Allocator>::iterator
	ft::list<T, Allocator>::begin()
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::const_iterator
	ft::list<T, Allocator>::begin() const
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::iterator
	ft::list<T, Allocator>::end()
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::const_iterator
	ft::list<T, Allocator>::end() const
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::reverse_iterator
	ft::list<T, Allocator>::rbegin()
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::const_reverse_iterator
	ft::list<T, Allocator>::rbegin() const
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::reverse_iterator
	ft::list<T, Allocator>::rend()
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::const_reverse_iterator
	ft::list<T, Allocator>::rend() const
	{
		// todo
	}

	// ====================
	//	     Capacity
	// ====================

	template <class T, class Allocator>
	bool
	ft::list<T, Allocator>::empty() const
	{
		return false;// todo
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::size_type
	ft::list<T, Allocator>::size() const
	{
		return 0;// todo
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::size_type
	ft::list<T, Allocator>::max_size() const
	{
		return 0;// todo
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::resize(size_type sz, T c)
	{
		// todo
	}

	// ======================
	//	   Element Access
	// ======================

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::reference
	ft::list<T, Allocator>::front()
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::const_reference
	ft::list<T, Allocator>::front() const
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::reference
	ft::list<T, Allocator>::back()
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::const_reference
	ft::list<T, Allocator>::back() const
	{
		// todo
	}

	// =====================
	//	     Modifiers
	// =====================

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::push_front(const T& x)
	{
		// todo
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::pop_front()
	{
		// todo
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::push_back(const T& x)
	{
		// todo
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::pop_back()
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::iterator
	ft::list<T, Allocator>::insert(iterator position, const T& x)
	{
		// todo
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::insert(iterator position, size_type n, const T& x)
	{
		// todo
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void
	ft::list<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last)
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::iterator
	ft::list<T, Allocator>::erase(iterator position)
	{
		// todo
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::iterator
	ft::list<T, Allocator>::erase(iterator position, iterator last)
	{
		// todo
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::swap(list<T,Allocator>&)
	{
		// todo
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::clear()
	{
		// todo
	}

	// =====================
	//	  List Operation
	// =====================	

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::splice(iterator position, list<T,Allocator>& x)
	{
		// todo
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::splice(iterator position, list<T,Allocator>& x, iterator i)
	{
		// todo
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::splice(iterator position, list<T,Allocator>& x, iterator first, iterator last)
	{
		// todo
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::remove(const T& value)
	{
		// todo
	}

	template <class T, class Allocator>
	template <class Predicate>
	void
	ft::list<T, Allocator>::remove_if(Predicate pred)
	{
		// todo
	}

	template <class T, class Allocator>
	void ft::list<T, Allocator>::unique()
	{
		// todo
	}

	template <class T, class Allocator>
	template <class BinaryPredicate>
	void ft::list<T, Allocator>::unique(BinaryPredicate binary_pred)
	{
		// todo
	}

	template <class T, class Allocator>
	void ft::list<T, Allocator>::merge(list<T,Allocator>& x)
	{
		// todo
	}

	template <class T, class Allocator>
	template <class Compare>
	void
	ft::list<T, Allocator>::merge(list<T,Allocator>& x, Compare comp)
	{
		// todo
	}
	
	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::sort()
	{
		// todo
	}

	template <class T, class Allocator>
	template <class Compare>
	void
	ft::list<T, Allocator>::sort(Compare comp)
	{
		// todo
	}

	template <class T, class Allocator>
	void ft::list<T, Allocator>::reverse()
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
	operator==(const list<T,Allocator>& x, const list<T,Allocator>& y)
	{
		return false;// todo
	}

	template <class T, class Allocator>
	bool
	operator< (const list<T,Allocator>& x, const list<T,Allocator>& y)
	{
		return false;// todo
	}

	template <class T, class Allocator>
	bool
	operator!=(const list<T,Allocator>& x, const list<T,Allocator>& y)
	{
		return false;// todo
	}

	template <class T, class Allocator>
	bool
	operator> (const list<T,Allocator>& x, const list<T,Allocator>& y)
	{
		return false;// todo
	}

	template <class T, class Allocator>
	bool
	operator>=(const list<T,Allocator>& x, const list<T,Allocator>& y)
	{
		return false;// todo
	}

	template <class T, class Allocator>
	bool
	operator<=(const list<T,Allocator>& x, const list<T,Allocator>& y)
	{
		return false;// todo
	}

	// ======================
	//	  Specialized Algo
	// ======================

	template <class T, class Allocator>
	void
	swap(list<T,Allocator>& x, list<T,Allocator>& y)
	{
		// todo
	}
}

#endif