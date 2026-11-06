#ifndef MAP_TPP
#define MAP_TPP

namespace ft
{
	// ======================
	//	Construct / Destruct
	// ======================

	template <class Key, class T, class Compare, class Allocator>
	map<Key,T,Compare,Allocator>::map(const Compare& comp, const Allocator& alloc)
		:	_key_comp(comp),
			_value_comp(comp),
			_tree(alloc, _value_comp)
	{
		// Complexity: O(1);
	}

	template <class Key, class T, class Compare, class Allocator>
	template <class InputIterator>
	map<Key,T,Compare,Allocator>::map(InputIterator first, InputIterator last, const Compare& comp, const Allocator& alloc)
		:	_key_comp(comp),
			_value_comp(comp),
			_tree(alloc, _value_comp)
	{
		// N = distance(first, last)
		// Complexity: O(N * log(N));
		_tree.insert(first, last);
	}

	template <class Key, class T, class Compare, class Allocator>
	map<Key,T,Compare,Allocator>::map(const map& x)
		:	_key_comp(x._key_comp),
			_value_comp(x._value_comp),
			_tree(x._tree)
	{
		// Complexity: O(x.size());
	}

	template <class Key, class T, class Compare, class Allocator>
	map<Key,T,Compare,Allocator>::~map()
	{
		// Complexity: O(size());
	}

	// =====================
	//	    Assignement
	// =====================

	template <class Key, class T, class Compare, class Allocator>
	map<Key,T,Compare,Allocator>&
	map<Key,T,Compare,Allocator>::operator=(const map<Key,T,Compare,Allocator>& x)
	{
		// Complexity: O(size() + x.size());
		if (this != &x)
			_tree = x._tree;
		return (*this);
	}
	
	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::allocator_type
	map<Key,T,Compare,Allocator>::get_allocator() const
	{
		// Complexity: O(1);
		return _tree.get_allocator();
	}

	// =====================
	//	     Iterators
	// =====================

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::iterator
	map<Key,T,Compare,Allocator>::begin()
	{
		// Complexity: O(1);
		return _tree.begin();
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::const_iterator
	map<Key,T,Compare,Allocator>::begin() const
	{
		// Complexity: O(1);
		return _tree.begin();
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::iterator
	map<Key,T,Compare,Allocator>::end()
	{
		// Complexity: O(1);
		return _tree.end();
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::const_iterator
	map<Key,T,Compare,Allocator>::end() const
	{
		// Complexity: O(1);
		return _tree.end();
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::reverse_iterator
	map<Key,T,Compare,Allocator>::rbegin()
	{
		// Complexity: O(1);
		return _tree.rbegin();
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::const_reverse_iterator
	map<Key,T,Compare,Allocator>::rbegin() const
	{
		// Complexity: O(1);
		return _tree.rbegin();
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::reverse_iterator
	map<Key,T,Compare,Allocator>::rend()
	{
		// Complexity: O(1);
		return _tree.rend();
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::const_reverse_iterator
	map<Key,T,Compare,Allocator>::rend() const
	{
		// Complexity: O(1);
		return _tree.rend();
	}

	// ====================
	//	     Capacity
	// ====================

	template <class Key, class T, class Compare, class Allocator>
	bool
	map<Key,T,Compare,Allocator>::empty() const
	{
		// Complexity: O(1);
		return _tree.empty();
	}
	
	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::size_type
	map<Key,T,Compare,Allocator>::size() const
	{
		// Complexity: O(1);
		return _tree.size();
	}
	
	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::size_type
	map<Key,T,Compare,Allocator>::max_size() const
	{
		// Complexity: O(1);
		return _tree.max_size();
	}

	// =====================
	//	   Element Access
	// =====================

	template <class Key, class T, class Compare, class Allocator>
	T&
	map<Key,T,Compare,Allocator>::at(const Key& key)
	{
		// Complexity: O(log(size()))
	}

	template <class Key, class T, class Compare, class Allocator>
	const T&
	map<Key,T,Compare,Allocator>::at(const Key& key) const
	{
		// Complexity: O(log(size()))
	}

	template <class Key, class T, class Compare, class Allocator>
	T&
	map<Key,T,Compare,Allocator>::operator[](const key_type& x)
	{
		// Complexity: O(log(size()))
	}

	// =====================
	//	     Modifiers
	// =====================

	template <class Key, class T, class Compare, class Allocator>
	pair<typename map<Key,T,Compare,Allocator>::iterator, bool>
	map<Key,T,Compare,Allocator>::insert(const value_type& x)
	{
		// Complexity: O(log(size()))
		return _tree.insert(x);
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::iterator
	map<Key,T,Compare,Allocator>::insert(iterator position, const value_type& x)
	{
		/*
		Complexity: 
			insertion in position:	amortized O(1)
			else:					O(log(size()))
		*/
		return _tree.insert(position, x);
	}

	template <class Key, class T, class Compare, class Allocator>
	template <class InputIterator>
	void
	map<Key,T,Compare,Allocator>::insert(InputIterator first, InputIterator last)
	{
		/*
		N = distance(first, last)
		Complexity: O(N * log(size() + N))
		*/
		_tree.insert(first, last);
	}

	template <class Key, class T, class Compare, class Allocator>
	void
	map<Key,T,Compare,Allocator>::erase(iterator position)
	{
		// Complexity: amortized O(1)
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::size_type
	map<Key,T,Compare,Allocator>::erase(const key_type& x)
	{
		// Complexity: O(size() + count(x))
	}

	template <class Key, class T, class Compare, class Allocator>
	void
	map<Key,T,Compare,Allocator>::erase(iterator first, iterator last)
	{
		// Complexity: O(size() + distance(first, last))
	}

	template <class Key, class T, class Compare, class Allocator>
	void
	map<Key,T,Compare,Allocator>::swap(map<Key,T,Compare,Allocator>& other)
	{
		// Complexity: O(1)
		if (this != &other)
			ft::swap(_tree, other._tree);
	}

	template <class Key, class T, class Compare, class Allocator>
	void
	map<Key,T,Compare,Allocator>::clear()
	{
		// Complexity: O(size())
		_tree.clear();
	}

	// =====================
	//	     Observers
	// =====================

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::key_compare
	map<Key,T,Compare,Allocator>::key_comp() const
	{
		// Complexity: O(1);
		return _key_comp;
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::value_compare
	map<Key,T,Compare,Allocator>::value_comp() const
	{
		// Complexity: O(1);
		return _value_comp;
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
		// N = elements found
		// Complexity: O(log(size()) + N)
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::iterator
	map<Key,T,Compare,Allocator>::lower_bound(const key_type& x)
	{
		// Complexity: O(log(size())
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::const_iterator
	map<Key,T,Compare,Allocator>::lower_bound(const key_type& x) const
	{
		// Complexity: O(log(size())
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::iterator
	map<Key,T,Compare,Allocator>::upper_bound(const key_type& x)
	{
		// Complexity: O(log(size())
	}

	template <class Key, class T, class Compare, class Allocator>
	typename map<Key,T,Compare,Allocator>::const_iterator
	map<Key,T,Compare,Allocator>::upper_bound(const key_type& x) const
	{
		// Complexity: O(log(size())
	}

	template <class Key, class T, class Compare, class Allocator>
	pair<typename map<Key,T,Compare,Allocator>::iterator, typename map<Key,T,Compare,Allocator>::iterator>
	map<Key,T,Compare,Allocator>::equal_range(const key_type& x)
	{
		// Complexity: O(log(size())
	}

	template <class Key, class T, class Compare, class Allocator>
	pair<typename map<Key,T,Compare,Allocator>::const_iterator,
		typename map<Key,T,Compare,Allocator>::const_iterator>
	map<Key,T,Compare,Allocator>::equal_range(const key_type& x) const
	{
		// Complexity: O(log(size())
	}

	// =====================
	//	    Non-Members
	// =====================

	template <class Key, class T, class Compare, class Allocator>
	bool operator==(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)
	{
		/*
		Complexity:
			if x.size() != y.size():	O(1)
			else:						O(size())
		*/
		return false;
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator!=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)
	{
		/*
		Complexity:
			if x.size() != y.size():	O(1)
			else:						O(size())
		*/
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