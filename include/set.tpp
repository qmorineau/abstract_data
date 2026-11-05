#ifndef SET_TPP
#define SET_TPP

namespace ft
{
	// ======================
	//	Construct / Destruct
	// ======================

	template <class Key, class Compare, class Allocator>
	set<Key, Compare, Allocator>::set(const Compare& comp, const Allocator& alloc)
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	template <class InputIterator>
	set<Key, Compare, Allocator>::set(InputIterator first, InputIterator last, const Compare& comp, const Allocator& alloc)
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	set<Key, Compare, Allocator>::set(const set& x)
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	set<Key, Compare, Allocator>::~set()
	{
		// todo
	}

	// =====================
	//	    Assignement
	// =====================

	template <class Key, class Compare, class Allocator>
	set<Key,Compare,Allocator>&
	set<Key, Compare, Allocator>::operator=(const set<Key,Compare,Allocator>& x)
	{
		// todo
		return (*this);
	}
	
	template <class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::allocator_type
	set<Key, Compare, Allocator>::get_allocator() const
	{
		// todo
	}

	// =====================
	//	     Iterators
	// =====================

	template <class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::iterator
	set<Key, Compare, Allocator>::begin()
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::const_iterator
	set<Key, Compare, Allocator>::begin() const
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::iterator
	set<Key, Compare, Allocator>::end()
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::const_iterator
	set<Key, Compare, Allocator>::end() const
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::reverse_iterator
	set<Key, Compare, Allocator>::rbegin()
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::const_reverse_iterator
	set<Key, Compare, Allocator>::rbegin() const
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::reverse_iterator
	set<Key, Compare, Allocator>::rend()
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::const_reverse_iterator
	set<Key, Compare, Allocator>::rend() const
	{
		// todo
	}

	// ====================
	//	     Capacity
	// ====================

	template <class Key, class Compare, class Allocator>
	bool
	set<Key, Compare, Allocator>::empty() const
	{
		return false;
		// todo
	}
	
	template <class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::size_type
	set<Key, Compare, Allocator>::size() const
	{
		// todo
	}
	
	template <class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::size_type
	set<Key, Compare, Allocator>::max_size() const
	{
		// todo
	}

	// =====================
	//	     Modifiers
	// =====================

	template <class Key, class Compare, class Allocator>
	pair<typename set<Key, Compare, Allocator>::iterator, bool>
	set<Key, Compare, Allocator>::insert(const value_type& x)
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::iterator
	set<Key, Compare, Allocator>::insert(iterator position, const value_type& x)
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	template <class InputIterator>
	void
	set<Key, Compare, Allocator>::insert(InputIterator first, InputIterator last)
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	void
	set<Key, Compare, Allocator>::erase(iterator position)
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::size_type
	set<Key, Compare, Allocator>::erase(const key_type& x)
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	void
	set<Key, Compare, Allocator>::erase(iterator first, iterator last)
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	void
	set<Key, Compare, Allocator>::swap(set<Key,Compare,Allocator>&)
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	void
	set<Key, Compare, Allocator>::clear()
	{
		// todo
	}

	// =====================
	//	     Observers
	// =====================

	template <class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::key_compare
	set<Key, Compare, Allocator>::key_comp() const
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::value_compare
	set<Key, Compare, Allocator>::value_comp() const
	{
		// todo
	}

	// =====================
	//	   Set Operations
	// =====================

	template <class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::iterator
	set<Key, Compare, Allocator>::find(const key_type& x) const
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::size_type
	set<Key, Compare, Allocator>::count(const key_type& x) const
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::iterator
	set<Key, Compare, Allocator>::lower_bound(const key_type& x) const
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::iterator
	set<Key, Compare, Allocator>::upper_bound(const key_type& x) const
	{
		// todo
	}

	template <class Key, class Compare, class Allocator>
	pair<typename set<Key, Compare, Allocator>::iterator, typename set<Key, Compare, Allocator>::iterator>
	set<Key, Compare, Allocator>::equal_range(const key_type& x) const
	{
		// todo
	}

	// =====================
	//	    Non-Members
	// =====================

	template <class Key, class Compare, class Allocator>
	bool operator==(const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y)
	{
		// todo
		return false;
	}

	template <class Key, class Compare, class Allocator>
	bool operator!=(const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y)
	{
		// todo
		return false;
	}

	template <class Key, class Compare, class Allocator>
	bool operator<(const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y)
	{
		// Complexity: O(size())
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class Key, class Compare, class Allocator>
	bool operator>(const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y)
	{
		// Complexity: O(size())
		return (y < x);
	}

	template <class Key, class Compare, class Allocator>
	bool operator>=(const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y)
	{
		// Complexity: O(size())
		return !(x < y);
	}

	template <class Key, class Compare, class Allocator>
	bool operator<=(const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y)
	{
		// Complexity: O(size())
		return !(y < x);
	}

	// ======================
	//	  Specialized Algo
	// ======================

	template <class Key, class Compare, class Allocator>
	void swap(set<Key,Compare,Allocator>& x, set<Key,Compare,Allocator>& y)
	{
		// Complexity: O(1)
		x.swap(y);
	}
}

#endif