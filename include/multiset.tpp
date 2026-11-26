#ifndef MULTISET_TPP
#define MULTISET_TPP

namespace ft
{
	// ======================
	//	Construct / Destruct
	// ======================

	template <class Key, class Compare, class Allocator>
	multiset<Key, Compare, Allocator>::multiset(const Compare& comp, const Allocator& alloc)
		: _tree(comp, alloc)
	{
		// Complexity: O(1);
	}

	template <class Key, class Compare, class Allocator>
	template <class InputIterator>
	multiset<Key, Compare, Allocator>::multiset(InputIterator first, InputIterator last, const Compare& comp, const Allocator& alloc)
		: _tree(comp, alloc)
	{
		// N = distance(first, last)
		// Complexity: O(N * log(N));
		for (;first != last; ++first)
			_tree.insert_multi(*first);
	}

	template <class Key, class Compare, class Allocator>
	multiset<Key, Compare, Allocator>::multiset(const multiset& x)
		: _tree(x._tree)
	{
		// Complexity: O(x.size());
	}

	template <class Key, class Compare, class Allocator>
	multiset<Key, Compare, Allocator>::~multiset()
	{
		// Complexity: O(size());
	}

	// =====================
	//	    Assignement
	// =====================

	template <class Key, class Compare, class Allocator>
	multiset<Key,Compare,Allocator>&
	multiset<Key, Compare, Allocator>::operator=(const multiset<Key,Compare,Allocator>& x)
	{
		// Complexity: O(size() + x.size());
		if (this != &x)
			_tree = x._tree;
		return (*this);
	}
	
	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::allocator_type
	multiset<Key, Compare, Allocator>::get_allocator() const
	{
		// Complexity: O(1);
		return _tree.get_allocator();
	}

	// =====================
	//	     Iterators
	// =====================

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::iterator
	multiset<Key, Compare, Allocator>::begin()
	{
		// Complexity: O(1);
		return _tree.begin();
	}

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::const_iterator
	multiset<Key, Compare, Allocator>::begin() const
	{
		// Complexity: O(1);
		return _tree.begin();
	}

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::iterator
	multiset<Key, Compare, Allocator>::end()
	{
		// Complexity: O(1);
		return _tree.end();
	}

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::const_iterator
	multiset<Key, Compare, Allocator>::end() const
	{
		// Complexity: O(1);
		return _tree.end();
	}

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::reverse_iterator
	multiset<Key, Compare, Allocator>::rbegin()
	{
		// Complexity: O(1);
		return _tree.rbegin();
	}

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::const_reverse_iterator
	multiset<Key, Compare, Allocator>::rbegin() const
	{
		// Complexity: O(1);
		return _tree.rbegin();
	}

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::reverse_iterator
	multiset<Key, Compare, Allocator>::rend()
	{
		// Complexity: O(1);
		return _tree.rend();
	}

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::const_reverse_iterator
	multiset<Key, Compare, Allocator>::rend() const
	{
		// Complexity: O(1);
		return _tree.rend();
	}

	// ====================
	//	     Capacity
	// ====================

	template <class Key, class Compare, class Allocator>
	bool
	multiset<Key, Compare, Allocator>::empty() const
	{
		// Complexity: O(1);
		return _tree.empty();
	}
	
	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::size_type
	multiset<Key, Compare, Allocator>::size() const
	{
		// Complexity: O(1);
		return _tree.size();
	}
	
	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::size_type
	multiset<Key, Compare, Allocator>::max_size() const
	{
		// Complexity: O(1);
		return _tree.max_size();
	}

	// =====================
	//	     Modifiers
	// =====================

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::iterator
	multiset<Key, Compare, Allocator>::insert(const value_type& x)
	{
		// Complexity: O(log(size()))
		return _tree.insert_multi(x).first;
	}

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::iterator
	multiset<Key, Compare, Allocator>::insert(iterator position, const value_type& x)
	{
		/*
		Complexity: 
			insertion just after pos:	amortized O(1)
			else:						O(log(size()))
		*/
		return _tree.insert_multi(position, x);
	}

	template <class Key, class Compare, class Allocator>
	template <class InputIterator>
	void
	multiset<Key, Compare, Allocator>::insert(InputIterator first, InputIterator last)
	{
		/*
		N = distance(first, last)
		Complexity: O(N * log(size() + N))
		*/
		for (; first != last; ++first)
			_tree.insert_multi(*first);
	}

	template <class Key, class Compare, class Allocator>
	void
	multiset<Key, Compare, Allocator>::erase(iterator position)
	{
		// Complexity: amortized O(1)
		_tree.erase(position);
	}

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::size_type
	multiset<Key, Compare, Allocator>::erase(const key_type& x)
	{
		// Complexity: O(size() + count(x))
		return _tree.erase(x);
	}

	template <class Key, class Compare, class Allocator>
	void
	multiset<Key, Compare, Allocator>::erase(iterator first, iterator last)
	{
		// Complexity: O(size() + distance(first, last))
		_tree.erase(first, last);
	}

	template <class Key, class Compare, class Allocator>
	void
	multiset<Key, Compare, Allocator>::swap(multiset<Key,Compare,Allocator>& other)
	{
		// Complexity: O(1)
		if (this != &other)
			_tree.swap(other._tree);
	}

	template <class Key, class Compare, class Allocator>
	void
	multiset<Key, Compare, Allocator>::clear()
	{
		// Complexity: O(size())
		_tree.clear();
	}

	// =====================
	//	     Observers
	// =====================

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::key_compare
	multiset<Key, Compare, Allocator>::key_comp() const
	{
		// Complexity: O(1);
		return _tree.key_comp();
	}

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::value_compare
	multiset<Key, Compare, Allocator>::value_comp() const
	{
		// Complexity: O(1);
		return _tree.key_comp();
	}

	// =====================
	//	   multiset Operations
	// =====================

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::iterator
	multiset<Key, Compare, Allocator>::find(const key_type& x)
	{
		// Complexity: O(log(size()))
		return _tree.find(x);
	}

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::const_iterator
	multiset<Key, Compare, Allocator>::find(const key_type& x) const
	{
		// Complexity: O(log(size()))
		return _tree.find(x);
	}

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::size_type
	multiset<Key, Compare, Allocator>::count(const key_type& x) const
	{
		// N = elements found
		// Complexity: O(log(size()) + N)
		return _tree.count(x);
	}

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::iterator
	multiset<Key, Compare, Allocator>::lower_bound(const key_type& x)
	{
		// Complexity: O(log(size())
		return _tree.lower_bound(x);
	}

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::const_iterator
	multiset<Key, Compare, Allocator>::lower_bound(const key_type& x) const
	{
		// Complexity: O(log(size())
		return _tree.lower_bound(x);
	}

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::iterator
	multiset<Key, Compare, Allocator>::upper_bound(const key_type& x)
	{
		// Complexity: O(log(size())
		return _tree.upper_bound(x);
	}

	template <class Key, class Compare, class Allocator>
	typename multiset<Key, Compare, Allocator>::const_iterator
	multiset<Key, Compare, Allocator>::upper_bound(const key_type& x) const
	{
		// Complexity: O(log(size())
		return _tree.upper_bound(x);
	}

	template <class Key, class Compare, class Allocator>
	pair<typename multiset<Key, Compare, Allocator>::iterator, typename multiset<Key, Compare, Allocator>::iterator>
	multiset<Key, Compare, Allocator>::equal_range(const key_type& x)
	{
		// Complexity: O(log(size())
		return _tree.equal_range(x);
	}

	template <class Key, class Compare, class Allocator>
	pair<typename multiset<Key, Compare, Allocator>::const_iterator, typename multiset<Key, Compare, Allocator>::const_iterator>
	multiset<Key, Compare, Allocator>::equal_range(const key_type& x) const
	{
		// Complexity: O(log(size())
		return _tree.equal_range(x);
	}

	// =====================
	//	    Non-Members
	// =====================

	template <class Key, class Compare, class Allocator>
	bool operator==(const multiset<Key,Compare,Allocator>& x, const multiset<Key,Compare,Allocator>& y)
	{
		/*
		Complexity:
			if x.size() != y.size():	O(1)
			else:						O(size())
		*/
		if (x.size() != y.size())
			return false;
		typedef typename multiset<Key,Compare,Allocator>::const_iterator const_iterator;
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

	template <class Key, class Compare, class Allocator>
	bool operator!=(const multiset<Key,Compare,Allocator>& x, const multiset<Key,Compare,Allocator>& y)
	{
		/*
		Complexity:
			if x.size() != y.size():	O(1)
			else:						O(size())
		*/
		return !(x == y);
	}

	template <class Key, class Compare, class Allocator>
	bool operator<(const multiset<Key,Compare,Allocator>& x, const multiset<Key,Compare,Allocator>& y)
	{
		// Complexity: O(size())
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class Key, class Compare, class Allocator>
	bool operator>(const multiset<Key,Compare,Allocator>& x, const multiset<Key,Compare,Allocator>& y)
	{
		// Complexity: O(size())
		return (y < x);
	}

	template <class Key, class Compare, class Allocator>
	bool operator>=(const multiset<Key,Compare,Allocator>& x, const multiset<Key,Compare,Allocator>& y)
	{
		// Complexity: O(size())
		return !(x < y);
	}

	template <class Key, class Compare, class Allocator>
	bool operator<=(const multiset<Key,Compare,Allocator>& x, const multiset<Key,Compare,Allocator>& y)
	{
		// Complexity: O(size())
		return !(y < x);
	}

	// ======================
	//	  Specialized Algo
	// ======================

	template <class Key, class Compare, class Allocator>
	void swap(multiset<Key,Compare,Allocator>& x, multiset<Key,Compare,Allocator>& y)
	{
		// Complexity: O(1)
		x.swap(y);
	}
}

#endif