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
	}
	
	template <class T, class Allocator>
	template <class InputIterator>
	ft::list<T, Allocator>::list(InputIterator first, InputIterator last, const Allocator& alloc)
		: _allocator(alloc), _node_alloc(alloc), _size(0)
	{
		init_sentinel();
		while (first != last)
		{
			push_back(*first);
			++first;
		}
	}

	template <class T, class Allocator>
	ft::list<T, Allocator>::list(const list<T,Allocator>& x) : _allocator(x._allocator), _node_alloc(x._node_alloc), _size(0)
	{
		init_sentinel();
		for (iterator it = x.begin(); it != x.end(); ++it)
			push_back(*it);
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
		clear();
		insert(end(), x.begin(), x.end());
		return *this;
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void
	ft::list<T, Allocator>::assign(InputIterator first, InputIterator last)
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
		return allocator_type(_node_alloc);
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
		Node<T>* to_pop = begin().base();
		Node<T>* prev = to_pop->prev;
		Node<T>* next = to_pop->next;
		_allocator.destroy(to_pop->value);
		_node_alloc.deallocate(to_pop, 1);
		prev->next = next;
		next->prev = prev;
		--_size;
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
		T value = x;
		Node<T>* prev = position.base()->prev;
		Node<T>* next = position.base();
		Node<T>* new_node = _node_alloc.allocate(1);
		_allocator.construct(&new_node->value, value);
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
	ft::list<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last)
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