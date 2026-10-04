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
		init_sentinel();
	}

	template <class T, class Allocator>
	ft::list<T, Allocator>::list(size_type n, const T& value, const Allocator& alloc)
		: _allocator(alloc), _node_alloc(alloc), _size(0)
	{
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
		clear();
		insert(begin(), first, last);
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::assign(size_type n, const T& t)
	{
		clear();
		for (size_type i = 0; i < n; ++i)
			push_back(t);
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::allocator_type
	ft::list<T, Allocator>::get_allocator() const
	{
		return _allocator;
	}

	// =====================
	//	     Iterators
	// =====================
	
	template <class T, class Allocator>
	typename ft::list<T, Allocator>::iterator
	ft::list<T, Allocator>::begin()
	{
		return iterator(_sentinel->next);
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::const_iterator
	ft::list<T, Allocator>::begin() const
	{
		return const_iterator(_sentinel->next);
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::iterator
	ft::list<T, Allocator>::end()
	{
		return iterator(_sentinel);
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::const_iterator
	ft::list<T, Allocator>::end() const
	{
		return const_iterator(_sentinel);
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::reverse_iterator
	ft::list<T, Allocator>::rbegin()
	{
		return reverse_iterator(end());
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::const_reverse_iterator
	ft::list<T, Allocator>::rbegin() const
	{
		return const_reverse_iterator(end());
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::reverse_iterator
	ft::list<T, Allocator>::rend()
	{
		return reverse_iterator(begin());
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::const_reverse_iterator
	ft::list<T, Allocator>::rend() const
	{
		return const_reverse_iterator(begin());
	}

	// ====================
	//	     Capacity
	// ====================

	template <class T, class Allocator>
	bool
	ft::list<T, Allocator>::empty() const
	{
		return _size == 0;
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::size_type
	ft::list<T, Allocator>::size() const
	{
		return _size;
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::size_type
	ft::list<T, Allocator>::max_size() const
	{
		return _node_alloc.max_size();
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::resize(size_type sz, T c)
	{
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
		return *begin();
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::const_reference
	ft::list<T, Allocator>::front() const
	{
		return *begin();
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::reference
	ft::list<T, Allocator>::back()
	{
		return *(--end());
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::const_reference
	ft::list<T, Allocator>::back() const
	{
		return *(--end());
	}

	// =====================
	//	     Modifiers
	// =====================

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::push_front(const T& x)
	{
		insert(begin(), x);
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::pop_front()
	{
		erase(begin());
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::push_back(const T& x)
	{
		insert(end(), x);
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::pop_back()
	{
		erase(--end());
	}

	template <class T, class Allocator>
	typename ft::list<T, Allocator>::iterator
	ft::list<T, Allocator>::insert(iterator position, const T& x)
	{
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
		for (size_type i = 0; i < n; ++i)
			insert(position, x);
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void
	ft::list<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
	{
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
		while (position != last)
			erase(position++);
		return last;
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::swap(list<T,Allocator>& other)
	{
		ft::swap(_allocator, other._allocator);
		ft::swap(_node_alloc, other._node_alloc);
		ft::swap(_size, other._size);
		ft::swap(_sentinel, other._sentinel);
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::clear()
	{
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
		--first;
		--last;
		while (first != last)
		{
			iterator it = last--;
			splice(position, x, it);
			--position;
		}
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::remove(const T& value)
	{
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
		unique(ft::equal_to<T>());
	}

	template <class T, class Allocator>
	template <class BinaryPredicate>
	void
	ft::list<T, Allocator>::unique(BinaryPredicate binary_pred)
	{
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
		merge(x, ft::less<T>());
	}

	template <class T, class Allocator>
	template <class Compare>
	void
	ft::list<T, Allocator>::merge(list<T,Allocator>& x, Compare comp)
	{
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
		mergeSort(*this, ft::less<T>());
	}

	template <class T, class Allocator>
	template <class Compare>
	void
	ft::list<T, Allocator>::sort(Compare comp)
	{
		mergeSort(*this, comp);
	}

	template <class T, class Allocator>
	void
	ft::list<T, Allocator>::reverse()
	{
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
		return !(x == y);
	}

	template <class T, class Allocator>
	bool
	operator< (const list<T,Allocator>& x, const list<T,Allocator>& y)
	{
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class T, class Allocator>
	bool
	operator> (const list<T,Allocator>& x, const list<T,Allocator>& y)
	{
		return (y < x);
	}

	template <class T, class Allocator>
	bool
	operator>=(const list<T,Allocator>& x, const list<T,Allocator>& y)
	{
		return !(x < y);
	}

	template <class T, class Allocator>
	bool
	operator<=(const list<T,Allocator>& x, const list<T,Allocator>& y)
	{
		return !(y < x);
	}

	// ======================
	//	  Specialized Algo
	// ======================

	template <class T, class Allocator>
	void
	swap(list<T,Allocator>& x, list<T,Allocator>& y)
	{
		x.swap(y);
	}
}

#endif