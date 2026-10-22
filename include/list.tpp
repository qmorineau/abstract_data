#ifndef LIST_TPP
#define LIST_TPP

namespace ft
{
	// ======================
	//	Construct / Destruct
	// ======================

	template <class T, class Allocator>
	ft::list<T, Allocator>::list(const Allocator& alloc)
		: _allocator(alloc), _node_alloc(alloc), _size(0)
	{
		// Complexity: O(1)
		init_sentinel();
	}

	template <class T, class Allocator>
	ft::list<T, Allocator>::list(size_type n, const T& value, const Allocator& alloc)
		: _allocator(alloc), _node_alloc(alloc), _size(0)
	{
		// Complexity: O(n)
		init_sentinel();
		try
		{
			insert(end(), n, value);		
		}
		catch(...)
		{
			clear();
			_node_alloc.deallocate(_sentinel, 1);
			throw;
		}
	}
	
	template <class T, class Allocator>
	template <class InputIterator>
	ft::list<T, Allocator>::list(InputIterator first, InputIterator last, const Allocator& alloc, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
		: _allocator(alloc), _node_alloc(alloc), _size(0)
	{
		// Complexity: O(distance(first, last))
		init_sentinel();
		try
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		catch(...)
		{
			clear();
			_node_alloc.deallocate(_sentinel, 1);
			throw ;
		}
	}

	template <class T, class Allocator>
	ft::list<T, Allocator>::list(const list<T,Allocator>& x) : _allocator(x._allocator), _node_alloc(x._node_alloc), _size(0)
	{
		// Complexity: O(x.size())
		init_sentinel();
		try
		{
			for (const_iterator it = x.begin(); it != x.end(); ++it)
				push_back(*it);
		}
		catch(...)
		{
			clear();
			_node_alloc.deallocate(_sentinel, 1);
			throw ;
		}
	}

	template <class T, class Allocator>
	ft::list<T, Allocator>::~list()
	{
		// Complexity: O(size())
		clear();
		_node_alloc.deallocate(_sentinel, 1);
	}

	// =====================
	//	    Assignement
	// =====================

	template <class T, class Allocator>
	list<T,Allocator>&
	ft::list<T, Allocator>::operator=(const list<T,Allocator>& x)
	{
		/*
			Complexity:
			this: O(size())
			x: O(x.size())
		*/
		if (this != &x)
		{
			clear();
			insert(end(), x.begin(), x.end());
		}
		return *this;
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void
	ft::list<T, Allocator>::assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
	{
		// Complexity: O(distance(first, last))
		clear();
		insert(begin(), first, last);
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::assign(size_type n, const T& t)
	{
		// Complexity: O(n)
		clear();
		for (size_type i = 0; i < n; ++i)
			push_back(t);
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::allocator_type
	ft::list<T, Allocator>::get_allocator() const
	{
		// Complexity: O(1)
		return _allocator;
	}

	// =====================
	//	     Iterators
	// =====================
	
	template <class T, class Allocator>
	typename ft::list<T, Allocator>::iterator
	ft::list<T, Allocator>::begin()
	{
		// Complexity: O(1)
		return iterator(_sentinel->next);
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::const_iterator
	ft::list<T, Allocator>::begin() const
	{
		// Complexity: O(1)
		return const_iterator(_sentinel->next);
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::iterator
	ft::list<T, Allocator>::end()
	{
		// Complexity: O(1)
		return iterator(_sentinel);
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::const_iterator
	ft::list<T, Allocator>::end() const
	{
		// Complexity: O(1)
		return const_iterator(_sentinel);
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::reverse_iterator
	ft::list<T, Allocator>::rbegin()
	{
		// Complexity: O(1)
		return reverse_iterator(end());
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::const_reverse_iterator
	ft::list<T, Allocator>::rbegin() const
	{
		// Complexity: O(1)
		return const_reverse_iterator(end());
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::reverse_iterator
	ft::list<T, Allocator>::rend()
	{
		// Complexity: O(1)
		return reverse_iterator(begin());
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::const_reverse_iterator
	ft::list<T, Allocator>::rend() const
	{
		// Complexity: O(1)
		return const_reverse_iterator(begin());
	}

	// ====================
	//	     Capacity
	// ====================

	template <class T, class Allocator>
	bool
	ft::list<T, Allocator>::empty() const
	{
		// Complexity: O(1)
		return _size == 0;
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::size_type
	ft::list<T, Allocator>::size() const
	{
		// Complexity: O(1) or O(size())
		return _size;
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::size_type
	ft::list<T, Allocator>::max_size() const
	{
		// Complexity: O(1)
		return _node_alloc.max_size();
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::resize(size_type sz, T c)
	{
		// Complexity: O(size() - sz)
		if (sz < _size)
		{
			while (sz < _size)
				pop_back();
		}
		else
		{
			while (_size < sz)
				insert(end(), c);
		}
	}

	// ======================
	//	   Element Access
	// ======================

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::reference
	ft::list<T, Allocator>::front()
	{
		// Complexity: O(1)
		return *begin();
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::const_reference
	ft::list<T, Allocator>::front() const
	{
		// Complexity: O(1)
		return *begin();
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::reference
	ft::list<T, Allocator>::back()
	{
		// Complexity: O(1)
		return *(--end());
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::const_reference
	ft::list<T, Allocator>::back() const
	{
		// Complexity: O(1)
		return *(--end());
	}

	// =====================
	//	     Modifiers
	// =====================

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::push_front(const T& x)
	{
		// Complexity: O(1)
		insert(begin(), x);
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::pop_front()
	{
		// Complexity: O(1)
		erase(begin());
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::push_back(const T& x)
	{
		// Complexity: O(1)
		insert(end(), x);
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::pop_back()
	{
		// Complexity: O(1)
		erase(--end());
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::iterator
	ft::list<T, Allocator>::insert(iterator position, const T& x)
	{
		// Complexity: O(1)
		Node<T>* prev = position.base()->prev;
		Node<T>* next = position.base();
		Node<T>* new_node = _node_alloc.allocate(1);
		try
		{
			_allocator.construct(&new_node->value, x);
		}
		catch(...)
		{
			_node_alloc.deallocate(new_node, 1);
			throw ;
		}
		new_node->prev = prev;
		new_node->next = next;
		next->prev = new_node;
		prev->next = new_node;
		++_size;
		return iterator(new_node);
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::insert(iterator position, size_type n, const T& x)
	{
		// Complexity: O(n)
		for (size_type i = 0; i < n; ++i)
			insert(position, x);
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void
	ft::list<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
	{
		// Complexity: O(distance(first, last))
		while (first != last)
		{
			insert(position, *first);
			++first;
		}
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::iterator
	ft::list<T, Allocator>::erase(iterator position)
	{
		// Complexity: O(1)
		Node<T>* to_destroy = position.base();
		iterator ret = iterator(to_destroy->next);
		to_destroy->next->prev = to_destroy->prev;
		to_destroy->prev->next = to_destroy->next;
		_allocator.destroy(&to_destroy->value);
		_node_alloc.deallocate(to_destroy, 1);
		--_size;
		return ret;
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::iterator
	ft::list<T, Allocator>::erase(iterator position, iterator last)
	{
		// Complexity: O(distance(pos, last))
		while (position != last)
			erase(position++);
		return last;
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::swap(list<T,Allocator>& other)
	{
		// Complexity: O(1)
		ft::swap(_allocator, other._allocator);
		ft::swap(_node_alloc, other._node_alloc);
		ft::swap(_size, other._size);
		ft::swap(_sentinel, other._sentinel);
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::clear()
	{
		// Complexity: O(size())
		iterator it = begin();
		while (it != end())
		{
			Node<T>* to_destroy = (it++).base();
			_allocator.destroy(&to_destroy->value);
			_node_alloc.deallocate(to_destroy, 1);
			--_size;
		}
		_sentinel->prev = _sentinel;
		_sentinel->next = _sentinel;
	}

	// =====================
	//	  List Operation
	// =====================

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::splice(iterator position, list<T,Allocator>& x)
	{
		// Complexity: O(1)
		while (!x.empty())
		{
			iterator it = --x.end();
			splice(position, x, it);
			--position;
		}
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::splice(iterator position, list<T,Allocator>& x, iterator it)
	{
		// Complexity: O(1) 
		if (position == it)
			return ;
		Node<T>* to_insert = it.base();
		to_insert->prev->next = to_insert->next;
		to_insert->next->prev = to_insert->prev;
		Node<T>* pos = position.base();
		to_insert->prev = pos->prev;
		to_insert->next = pos;
		to_insert->prev->next = to_insert;
		to_insert->next->prev = to_insert;
		--x._size;
		++_size;
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::splice(iterator position, list<T,Allocator>& x, iterator first, iterator last)
	{
		/*
			Complexity:
				x == *this: O(1)
				else: O(distance(first, last))
		*/
		if (this == &x)
		{
			// todo
		}
		else
		{
			--first;
			--last;
			while (first != last)
			{
				// transfer all plage at once
				iterator it = last--;
				splice(position, x, it);
				--position;
			}
		}
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::remove(const T& value)
	{
		// Complexity: comparaison: O(distance(begin(), end()) 
		ft::list<T, Allocator> to_remove;
		iterator it = begin();
		while (it != end())
		{
			iterator next = it;
			++next;
			if (*it == value)
				to_remove.splice(to_remove.end(), *this, it);
			it = next;
		}
	}

	template <class T, class Allocator>
	template <class Predicate>
	void
	ft::list<T, Allocator>::remove_if(Predicate pred)
	{
		// Complexity: predicate use: O(distance(begin(), end()) 
		ft::list<T, Allocator> to_remove;
		iterator it = begin();
		while (it != end())
		{
			iterator next = it;
			++next;
			if (pred(*it))
				to_remove.splice(to_remove.end(), *this, it);
			it = next;
		}
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::unique()
	{
		/*
			N = distance(begin(), end())
			Complexity:
				empty: no comparison
				comparaison==: exactly O(N)
		*/
		unique(ft::equal_to<T>());
	}

	template <class T, class Allocator>
	template <class BinaryPredicate>
	void
	ft::list<T, Allocator>::unique(BinaryPredicate binary_pred)
	{
		/*
			N = distance(begin(), end())
			Complexity:
				empty: no comparison
				predicate: exactly O(N)
		*/
		if (empty())
			return ;
		iterator it = begin();
		iterator next = it;
		++next;
		while (next != end())
		{
			if (binary_pred(*it, *next))
				next = erase(next);
			else
				it = next++;
		}
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::merge(list<T,Allocator>& x)
	{
		/*
			Complexicity:
				x == *this: no comparaison
				else: comparison < : at most 0(distance(begin(), end()) + distance(x.begin(), x.end()) - 1)
		*/
		merge(x, ft::less<T>());
	}

	template <class T, class Allocator>
	template <class Compare>
	void
	ft::list<T, Allocator>::merge(list<T,Allocator>& x, Compare comp)
	{
		/*
			Complexicity:
				x == *this: no comparaison
				else: comparison comp: at most 0(distance(begin(), end()) + distance(x.begin(), x.end()) - 1)
		*/
		if (this != &x)
		{
			iterator it = begin();
			while (it != end())
			{
				iterator to_insert = x.begin();
				if (to_insert == x.end())
					return;
				if (comp(*to_insert, *it))
					splice(it, x, to_insert);
				else
					++it;
			}
			splice(end(), x, x.begin(), x.end());
		}
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::sort()
	{
		// Complexity: N = size() 
		//		comparaison: approximately N⋅log(N)
		mergeSort(*this, ft::less<T>());
	}

	template <class T, class Allocator>
	template <class Compare>
	void
	ft::list<T, Allocator>::sort(Compare comp)
	{
		// Complexity: N = size() 
		//		comparaison comp: approximately N⋅log(N)
		mergeSort(*this, comp);
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::reverse()
	{
		// Complexity: O(size())
		Node<T>* current = _sentinel;
		do
		{
			ft::swap(current->prev, current->next);
			current = current->prev;
		}
		while (current != _sentinel);
	}

	// =====================
	//	  Private-Members
	// =====================

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::init_sentinel()
	{
		_sentinel = _node_alloc.allocate(1);
		_sentinel->prev = _sentinel;
		_sentinel->next = _sentinel;
	}

	template <class T, class Allocator>
	template <class Compare>
	void
	ft::list<T, Allocator>::mergeSort(ft::list<T,Allocator>& l, Compare comp)
	{
		if (l.size() < 2)
			return ;
		iterator middle = l.begin();
		for (size_type i = 0; i < l.size() / 2; ++i)
			++middle;
		ft::list<T, Allocator> right;
		right.splice(right.begin(), l, middle, l.end());
		mergeSort(l, comp);
		mergeSort(right, comp);
		l.merge(right, comp);
	}

	// =====================
	//	    Non-Members
	// =====================

	template <class T, class Allocator>
	bool
	operator==(const list<T,Allocator>& x, const list<T,Allocator>& y)
	{
		/*
			Complexity:
				x.size() != y.size(): O(1)
				else: O(size())
		*/
		if (x.size() != y.size())
			return false;
		typedef typename list<T,Allocator>::const_iterator const_iterator;
		const_iterator itx = x.begin();
		const_iterator ity = y.begin();
		for (; itx != x.end() && ity != y.end(); ++itx, ++ity)
		{
			if (!(*itx == *ity))
				return false;
		}
		return true;
	}

	template <class T, class Allocator>
	bool
	operator!=(const list<T,Allocator>& x, const list<T,Allocator>& y)
	{
		/*
			Complexity:
				x.size() != y.size(): O(1)
				else: O(size())
		*/
		return !(x == y);
	}

	template <class T, class Allocator>
	bool
	operator< (const list<T,Allocator>& x, const list<T,Allocator>& y)
	{
		// Complexity: O(size())
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class T, class Allocator>
	bool
	operator> (const list<T,Allocator>& x, const list<T,Allocator>& y)
	{
		// Complexity: O(size())
		return (y < x);
	}

	template <class T, class Allocator>
	bool
	operator>=(const list<T,Allocator>& x, const list<T,Allocator>& y)
	{
		// Complexity: O(size())
		return !(x < y);
	}

	template <class T, class Allocator>
	bool
	operator<=(const list<T,Allocator>& x, const list<T,Allocator>& y)
	{
		// Complexity: O(size())
		return !(y < x);
	}

	// ======================
	//	  Specialized Algo
	// ======================

	template <class T, class Allocator>
	void
	swap(list<T,Allocator>& x, list<T,Allocator>& y)
	{
		// Complexity: O(1)
		x.swap(y);
	}
}

#endif