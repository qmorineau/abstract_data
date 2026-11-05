#ifndef MAP_TPP
#define MAP_TPP

namespace ft
{
	// ======================
	//	Construct / Destruct
	// ======================

	template <class Key, class T, class Compare, class Allocator>
	map<Key,T,Compare,Allocator>::map(const Compare& comp, const Allocator& alloc)
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	template <class InputIterator>
	map<Key,T,Compare,Allocator>::map(InputIterator first, InputIterator last, const Compare& comp, const Allocator& alloc)
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	map<Key,T,Compare,Allocator>::map(const map& x)
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	map<Key,T,Compare,Allocator>::~map()
	{
		// todo
	}

	// =====================
	//	    Assignement
	// =====================

	template <class Key, class T, class Compare, class Allocator>
	map<Key,T,Compare,Allocator>&
	map<Key,T,Compare,Allocator>::operator=(const map<Key,T,Compare,Allocator>& x)
	{
		// todo
		return (*this);
	}
	
	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::allocator_type
	map<Key,T,Compare,Allocator>::get_allocator() const
	{
		// todo
	}

	// =====================
	//	     Iterators
	// =====================

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::iterator
	map<Key,T,Compare,Allocator>::begin()
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::const_iterator
	map<Key,T,Compare,Allocator>::begin() const
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::iterator
	map<Key,T,Compare,Allocator>::end()
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::const_iterator
	map<Key,T,Compare,Allocator>::end() const
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::reverse_iterator
	map<Key,T,Compare,Allocator>::rbegin()
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::const_reverse_iterator
	map<Key,T,Compare,Allocator>::rbegin() const
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::reverse_iterator
	map<Key,T,Compare,Allocator>::rend()
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::const_reverse_iterator
	map<Key,T,Compare,Allocator>::rend() const
	{
		// todo
	}

	// ====================
	//	     Capacity
	// ====================

	template <class Key, class T, class Compare, class Allocator>
	bool
	map<Key,T,Compare,Allocator>::empty() const
	{
		return false;
		// todo
	}
	
	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::size_type
	map<Key,T,Compare,Allocator>::size() const
	{
		// todo
	}
	
	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::size_type
	map<Key,T,Compare,Allocator>::max_size() const
	{
		// todo
	}

	// =====================
	//	   Element Access
	// =====================

	template <class Key, class T, class Compare, class Allocator>
	T&
	map<Key,T,Compare,Allocator>::operator[](const key_type& x)
	{
		// todo
	}

	// =====================
	//	     Modifiers
	// =====================

	template <class Key, class T, class Compare, class Allocator>
	pair<typename map<Key,T,Compare,Allocator>::iterator, bool>
	map<Key,T,Compare,Allocator>::insert(const value_type& x)
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::iterator
	map<Key,T,Compare,Allocator>::insert(iterator position, const value_type& x)
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	template <class InputIterator>
	void
	map<Key,T,Compare,Allocator>::insert(InputIterator first, InputIterator last)
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	void
	map<Key,T,Compare,Allocator>::erase(iterator position)
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::size_type
	map<Key,T,Compare,Allocator>::erase(const key_type& x)
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	void
	map<Key,T,Compare,Allocator>::erase(iterator first, iterator last)
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	void
	map<Key,T,Compare,Allocator>::swap(map<Key,T,Compare,Allocator>& other)
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	void
	map<Key,T,Compare,Allocator>::clear()
	{
		// todo
	}

	// =====================
	//	     Observers
	// =====================

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::key_compare
	map<Key,T,Compare,Allocator>::key_comp() const
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::value_compare
	map<Key,T,Compare,Allocator>::value_comp() const
	{
		// todo
	}

	// =====================
	//	   map Operations
	// =====================

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::iterator
	map<Key,T,Compare,Allocator>::find(const key_type& x)
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::const_iterator
	map<Key,T,Compare,Allocator>::find(const key_type& x) const
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::size_type
	map<Key,T,Compare,Allocator>::count(const key_type& x) const
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::iterator
	map<Key,T,Compare,Allocator>::lower_bound(const key_type& x)
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::const_iterator
	map<Key,T,Compare,Allocator>::lower_bound(const key_type& x) const
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::iterator
	map<Key,T,Compare,Allocator>::upper_bound(const key_type& x)
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::const_iterator
	map<Key,T,Compare,Allocator>::upper_bound(const key_type& x) const
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	pair<typename map<Key,T,Compare,Allocator>::iterator, typename map<Key,T,Compare,Allocator>::iterator>
	map<Key,T,Compare,Allocator>::equal_range(const key_type& x)
	{
		// todo
	}

	template <class Key, class T, class Compare, class Allocator>
	pair<typename map<Key,T,Compare,Allocator>::const_iterator,
		typename map<Key,T,Compare,Allocator>::const_iterator>
	map<Key,T,Compare,Allocator>::equal_range(const key_type& x) const
	{
		// todo
	}

	// =====================
	//	    Non-Members
	// =====================

	template <class Key, class T, class Compare, class Allocator>
	bool operator==(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)
	{
		// todo
		return false;
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator!=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)
	{
		// todo
		return false;
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator<(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)
	{
		// Complexity: O(size())
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator>(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)
	{
		// Complexity: O(size())
		return (y < x);
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator>=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)
	{
		// Complexity: O(size())
		return !(x < y);
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator<=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)
	{
		// Complexity: O(size())
		return !(y < x);
	}

	// ======================
	//	  Specialized Algo
	// ======================

	template <class Key, class T, class Compare, class Allocator>
	void swap(map<Key,T,Compare,Allocator>& x, map<Key,T,Compare,Allocator>& y)
	{
		// Complexity: O(1)
		x.swap(y);
	}
}

#endif