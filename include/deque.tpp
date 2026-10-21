#ifndef DEQUE_TPP
#define DEQUE_TPP

namespace ft
{
	// ======================
	//	Construct / Destruct
	// ======================

	template <class T, class Allocator>
	ft::deque<T, Allocator>::deque(const Allocator& alloc)
		: _allocator(alloc), _size(0)
	{
		try
		{
			init_deque();
		}
		catch(...)
		{
			destroy_all();
			throw ;
		}
	}

	template <class T, class Allocator>
	ft::deque<T, Allocator>::deque(size_type n, const T& value, const Allocator& alloc)
		: _allocator(alloc), _size(0)
	{
		try
		{
			init_deque();
			assign(n, value);
		}
		catch(...)
		{
			destroy_all();
			throw ;
		}
	}

	template <class T, class Allocator>
	template <class InputIterator>
	ft::deque<T, Allocator>::deque(InputIterator first, InputIterator last, const Allocator& alloc)
		: _allocator(alloc), _size(0)
	{
		try
		{
			init_deque();
			assign(first, last);
		}
		catch(...)
		{
			destroy_all();
			throw ;
		}
	}

	template <class T, class Allocator>
	ft::deque<T, Allocator>::deque(const deque<T,Allocator>& x)
		: _allocator(x._allocator), _size(0)
	{
		try
		{
			init_deque();
			assign(x.begin(), x.end());
		}
		catch(...)
		{
			destroy_all();
			throw ;
		}
	}

	template <class T, class Allocator>
	ft::deque<T, Allocator>::~deque()
	{
		destroy_all();
	}

	// =====================
	//	    Assignement
	// =====================

	template <class T, class Allocator>
	deque<T,Allocator>&
	ft::deque<T,Allocator>::operator=(const deque<T,Allocator>& x)
	{
		if (this != &x)
		{
			assign(x.begin(), x.end());
		}
		return *this;
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void
	ft::deque<T,Allocator>::assign(InputIterator first, InputIterator last)
	{
		assign_dispatch(first, last, typename iterator_traits<InputIterator>::iterator_category());
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::assign(size_type n, const T& t)
	{
		// to do -> not clear, put assign each chunk, then delete like in optimisation in vector
		clear();
		for (size_type i = 0; i < n; ++i)
			push_back(t);
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::allocator_type
	ft::deque<T,Allocator>::get_allocator() const
	{
		return _allocator;
	}

	// =====================
	//	     Iterators
	// =====================

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::iterator
	ft::deque<T,Allocator>::begin()
	{
		return iterator(&_map, _start.map_index, _start.offset);
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_iterator
	ft::deque<T,Allocator>::begin() const
	{
		return const_iterator(&_map, _start.map_index, _start.offset);
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::iterator
	ft::deque<T,Allocator>::end()
	{
		return iterator(&_map, _end.map_index, _end.offset);
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_iterator
	ft::deque<T,Allocator>::end() const
	{
		return const_iterator(&_map, _end.map_index, _end.offset);
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::reverse_iterator
	ft::deque<T,Allocator>::rbegin()
	{
		return reverse_iterator(end());
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_reverse_iterator
	ft::deque<T,Allocator>::rbegin() const
	{
		return const_reverse_iterator(end());
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::reverse_iterator
	ft::deque<T,Allocator>::rend()
	{
		return reverse_iterator(begin());
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_reverse_iterator
	ft::deque<T,Allocator>::rend() const
	{
		return const_reverse_iterator(begin());
	}

	// ====================
	//	     Capacity
	// ====================

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::size_type
	ft::deque<T,Allocator>::size() const
	{
		return _size;
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::size_type
	ft::deque<T,Allocator>::max_size() const
	{
		return _allocator.max_size();
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
		return _size == 0;
	}

	// ======================
	//	   Element Access
	// ======================

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::reference
	ft::deque<T,Allocator>::operator[](size_type n)
	{
		iterator it = begin();
		it += n;
		return *it;
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_reference
	ft::deque<T,Allocator>::operator[](size_type n) const
	{
		const_iterator it = begin();
		it += n;
		return *it;
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::reference
	ft::deque<T,Allocator>::at(size_type n)
	{
		if (n > _size)
			throw_out_of_range(n);
		iterator it = begin();
		it += n;
		return *it;
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_reference
	ft::deque<T,Allocator>::at(size_type n) const
	{
		if (n > _size)
			throw_out_of_range(n);
		const_iterator it = begin();
		it += n;
		return *it;
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
		if (_end.offset == deque_chunk_size - 1)
		{
			if (_map.size() == _end.map_index + 1)
				_map.push_back(NULL);
			_map[_end.map_index + 1] = create_chunk();
		}
		_allocator.construct(_map[_end.map_index] + _end.offset, x);
		++_end.offset;
		++_size;
		if (_end.offset == deque_chunk_size)
		{
			++_end.map_index;
			_end.offset = 0;
		}
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
	ft::deque<T,Allocator>::swap(deque<T,Allocator>& other)
	{
		if (this != &other)
		{
			ft::swap(_allocator, other._allocator);
			ft::swap(_map, other._map);

			ft::swap(_start, other._start);
			ft::swap(_end, other._end);
			ft::swap(_size, other._size);
		}
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::clear()
	{
		if (_size > 0)
		{
			for (ft::size_t map_idx = _start.map_index; map_idx != _end.map_index + 1; ++map_idx)
			{
				ft::size_t offset = 0;
				ft::size_t end_chunk = deque_chunk_size;
				if (map_idx == _start.map_index)
					offset = _start.offset;
				if (map_idx == _end.map_index)
					end_chunk = _end.offset;
				for (; offset < end_chunk; ++offset)
					_allocator.destroy(_map[map_idx] + offset);
				if (map_idx != _start.map_index)
				{
					_allocator.deallocate(_map[map_idx], deque_chunk_size);
					_map[map_idx] = NULL;
				}
			}
			_size = 0;
			_start.offset = deque_chunk_size / 2;
			_end.map_index = _start.map_index;
			_end.offset = _start.offset;
		}
	}

	// =====================
	//	  Private-Members
	// =====================

	template <class T, class Allocator>
	T*
	ft::deque<T,Allocator>::create_chunk()
	{
		return _allocator.allocate(sizeof(T) * deque_chunk_size);
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::throw_out_of_range(size_type n) const
	{
		throw ft::out_of_range(
			"TODO"	
		);
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::init_deque()
	{
		_map.assign(5, NULL);
		T* new_chunk = create_chunk();
		_start.map_index = 2;
		_map[_start.map_index] = new_chunk;

		_end.map_index = _start.map_index;
		_start.offset = deque_chunk_size / 2;
		_end.offset = _start.offset;
	}

	template <class T, class Allocator>
	template <class InputIt>
	void
	ft::deque<T,Allocator>::assign_dispatch(InputIt first, InputIt last, input_iterator_tag)
	{
		ft::vector<T, Allocator> tmp;
		for (; first != last; ++first)
			tmp.push_back(*first);
		assign_dispatch(tmp.begin(), tmp.end(), forward_iterator_tag());
	}

	template <class T, class Allocator>
	template <class ForwardIt>
	void
	ft::deque<T,Allocator>::assign_dispatch(ForwardIt first, ForwardIt last, forward_iterator_tag)
	{
		deque<T> tmp(_allocator);
		for (; first != last; ++first)
			tmp.push_back(*first);
		swap(tmp);
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::destroy_all()
	{
		clear();
		_allocator.deallocate(_map[_start.map_index], deque_chunk_size);
	}

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