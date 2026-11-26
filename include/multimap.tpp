#ifndef MULTIMAP_TPP
#define MULTIMAP_TPP

namespace ft
{
	// ======================
	//	Construct / Destruct
	// ======================

	template <class Key, class T, class Compare, class Allocator>
	multimap<Key,T,Compare,Allocator>::multimap(const Compare& comp, const Allocator& alloc)
		: _tree(comp, alloc)
	{
		// Complexity: O(1);
	}

	template <class Key, class T, class Compare, class Allocator>
	template <class InputIterator>
	multimap<Key,T,Compare,Allocator>::multimap(InputIterator first, InputIterator last, const Compare& comp, const Allocator& alloc)
		: _tree(comp, alloc)
	{
		// N = distance(first, last)
		// Complexity: O(N * log(N));
		for (;first != last; ++first)
			_tree.insert_multi(*first);
	}

	template <class Key, class T, class Compare, class Allocator>
	multimap<Key,T,Compare,Allocator>::multimap(const multimap& x)
		: _tree(x._tree)
	{
		// Complexity: O(x.size());
	}

	template <class Key, class T, class Compare, class Allocator>
	multimap<Key,T,Compare,Allocator>::~multimap()
	{
		// Complexity: O(size());
	}

	// =====================
	//	    Assignement
	// =====================

	template <class Key, class T, class Compare, class Allocator>
	multimap<Key,T,Compare,Allocator>&
	multimap<Key,T,Compare,Allocator>::operator=(const multimap<Key,T,Compare,Allocator>& x)
	{
		// Complexity: O(size() + x.size());
		if (this != &x)
			_tree = x._tree;
		return (*this);
	}
	
	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::allocator_type
	multimap<Key,T,Compare,Allocator>::get_allocator() const
	{
		// Complexity: O(1);
		return _tree.get_allocator();
	}

	// =====================
	//	     Iterators
	// =====================

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::iterator
	multimap<Key,T,Compare,Allocator>::begin()
	{
		// Complexity: O(1);
		return _tree.begin();
	}

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::const_iterator
	multimap<Key,T,Compare,Allocator>::begin() const
	{
		// Complexity: O(1);
		return _tree.begin();
	}

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::iterator
	multimap<Key,T,Compare,Allocator>::end()
	{
		// Complexity: O(1);
		return _tree.end();
	}

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::const_iterator
	multimap<Key,T,Compare,Allocator>::end() const
	{
		// Complexity: O(1);
		return _tree.end();
	}

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::reverse_iterator
	multimap<Key,T,Compare,Allocator>::rbegin()
	{
		// Complexity: O(1);
		return _tree.rbegin();
	}

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::const_reverse_iterator
	multimap<Key,T,Compare,Allocator>::rbegin() const
	{
		// Complexity: O(1);
		return _tree.rbegin();
	}

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::reverse_iterator
	multimap<Key,T,Compare,Allocator>::rend()
	{
		// Complexity: O(1);
		return _tree.rend();
	}

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::const_reverse_iterator
	multimap<Key,T,Compare,Allocator>::rend() const
	{
		// Complexity: O(1);
		return _tree.rend();
	}

	// ====================
	//	     Capacity
	// ====================

	template <class Key, class T, class Compare, class Allocator>
	bool
	multimap<Key,T,Compare,Allocator>::empty() const
	{
		// Complexity: O(1);
		return _tree.empty();
	}
	
	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::size_type
	multimap<Key,T,Compare,Allocator>::size() const
	{
		// Complexity: O(1);
		return _tree.size();
	}
	
	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::size_type
	multimap<Key,T,Compare,Allocator>::max_size() const
	{
		// Complexity: O(1);
		return _tree.max_size();
	}

	// =====================
	//	     Modifiers
	// =====================

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::iterator
	multimap<Key,T,Compare,Allocator>::insert(const value_type& x)
	{
		// Complexity: O(log(size()))
		return _tree.insert_multi(x).first;
	}

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::iterator
	multimap<Key,T,Compare,Allocator>::insert(iterator position, const value_type& x)
	{
		/*
		Complexity: 
			insertion just before pos:	amortized O(1)
			else:						O(log(size()))
		*/
		return _tree.insert_multi(position, x).first;
	}

	template <class Key, class T, class Compare, class Allocator>
	template <class InputIterator>
	void
	multimap<Key,T,Compare,Allocator>::insert(InputIterator first, InputIterator last)
	{
		/*
		N = distance(first, last)
		Complexity: O(N * log(size() + N))
		*/
		for (; first != last; ++first)
			_tree.insert_multi(*first);
	}

	template <class Key, class T, class Compare, class Allocator>
	void
	multimap<Key,T,Compare,Allocator>::erase(iterator position)
	{
		// Complexity: amortized O(1)
		_tree.erase(position);
	}

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::size_type
	multimap<Key,T,Compare,Allocator>::erase(const key_type& x)
	{
		// Complexity: O(size() + count(x))
		_tree.erase(x);
	}

	template <class Key, class T, class Compare, class Allocator>
	void
	multimap<Key,T,Compare,Allocator>::erase(iterator first, iterator last)
	{
		// Complexity: O(size() + distance(first, last))
		_tree.erase(first, last);
	}

	template <class Key, class T, class Compare, class Allocator>
	void
	multimap<Key,T,Compare,Allocator>::swap(multimap<Key,T,Compare,Allocator>& other)
	{
		// Complexity: O(1)
		if (this != &other)
			_tree.swap(other._tree);
	}

	template <class Key, class T, class Compare, class Allocator>
	void
	multimap<Key,T,Compare,Allocator>::clear()
	{
		// Complexity: O(size())
		_tree.clear();
	}

	// =====================
	//	     Observers
	// =====================

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::key_compare
	multimap<Key,T,Compare,Allocator>::key_comp() const
	{
		// Complexity: O(1);
		return _tree.key_comp();
	}

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::value_compare
	multimap<Key,T,Compare,Allocator>::value_comp() const
	{
		// Complexity: O(1);
		return value_comp(_tree.key_comp());
	}

	// =====================
	//	   multimap Operations
	// =====================

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::iterator
	multimap<Key,T,Compare,Allocator>::find(const key_type& x)
	{
		// Complexity: O(log(size()))
		return _tree.find(x);
	}

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::const_iterator
	multimap<Key,T,Compare,Allocator>::find(const key_type& x) const
	{
		// Complexity: O(log(size()))
		return _tree.find(x);
	}

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::size_type
	multimap<Key,T,Compare,Allocator>::count(const key_type& x) const
	{
		// N = elements found
		// Complexity: O(log(size()) + N)
		return _tree.count(x);
	}

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::iterator
	multimap<Key,T,Compare,Allocator>::lower_bound(const key_type& x)
	{
		// Complexity: O(log(size())
		return _tree.lower_bound(x);
	}

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::const_iterator
	multimap<Key,T,Compare,Allocator>::lower_bound(const key_type& x) const
	{
		// Complexity: O(log(size())
		return _tree.lower_bound(x);
	}

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::iterator
	multimap<Key,T,Compare,Allocator>::upper_bound(const key_type& x)
	{
		// Complexity: O(log(size())
		return _tree.upper_bound(x);
	}

	template <class Key, class T, class Compare, class Allocator>
	typename multimap<Key,T,Compare,Allocator>::const_iterator
	multimap<Key,T,Compare,Allocator>::upper_bound(const key_type& x) const
	{
		// Complexity: O(log(size())
		return _tree.upper_bound(x);
	}

	template <class Key, class T, class Compare, class Allocator>
	pair<typename multimap<Key,T,Compare,Allocator>::iterator, typename multimap<Key,T,Compare,Allocator>::iterator>
	multimap<Key,T,Compare,Allocator>::equal_range(const key_type& x)
	{
		// Complexity: O(log(size())
		return _tree.equal_range(x);
	}

	template <class Key, class T, class Compare, class Allocator>
	pair<typename multimap<Key,T,Compare,Allocator>::const_iterator,
		typename multimap<Key,T,Compare,Allocator>::const_iterator>
	multimap<Key,T,Compare,Allocator>::equal_range(const key_type& x) const
	{
		// Complexity: O(log(size())
		return _tree.equal_range(x);
	}

	// =====================
	//	    Non-Members
	// =====================

	template <class Key, class T, class Compare, class Allocator>
	bool operator==(const multimap<Key,T,Compare,Allocator>& x, const multimap<Key,T,Compare,Allocator>& y)
	{
		/*
		Complexity:
			if x.size() != y.size():	O(1)
			else:						O(size())
		*/
		if (x.size() != y.size())
			return false;
		typedef typename map<Key,T,Compare,Allocator>::const_iterator const_iterator;
		const_iterator itx = x.begin();
		const_iterator ity = y.begin();
		const_iterator x_end = x.end();
		const_iterator y_end = y.end();
		for (; itx != x_end && ity != y_end; ++itx, ++ity)
		{
			if (!(*itx == *ity))
				return false;
		}
		return true;
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator!=(const multimap<Key,T,Compare,Allocator>& x, const multimap<Key,T,Compare,Allocator>& y)
	{
		/*
		Complexity:
			if x.size() != y.size():	O(1)
			else:						O(size())
		*/
		return !(x == y);
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator<(const multimap<Key,T,Compare,Allocator>& x, const multimap<Key,T,Compare,Allocator>& y)
	{
		// Complexity: O(size())
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator>(const multimap<Key,T,Compare,Allocator>& x, const multimap<Key,T,Compare,Allocator>& y)
	{
		// Complexity: O(size())
		return (y < x);
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator>=(const multimap<Key,T,Compare,Allocator>& x, const multimap<Key,T,Compare,Allocator>& y)
	{
		// Complexity: O(size())
		return !(x < y);
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator<=(const multimap<Key,T,Compare,Allocator>& x, const multimap<Key,T,Compare,Allocator>& y)
	{
		// Complexity: O(size())
		return !(y < x);
	}

	// ======================
	//	  Specialized Algo
	// ======================

	template <class Key, class T, class Compare, class Allocator>
	void swap(multimap<Key,T,Compare,Allocator>& x, multimap<Key,T,Compare,Allocator>& y)
	{
		// Complexity: O(1)
		x.swap(y);
	}
}

#endif