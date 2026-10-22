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
		// Complexity: O(1)
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
		// Complexity: O(n)
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
		// Complexity: O(distance(first, last))
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
		// Complexity: O(x.size())
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
		// Complexity: O(size())
		destroy_all();
	}

	// =====================
	//	    Assignement
	// =====================

	template <class T, class Allocator>
	deque<T,Allocator>&
	ft::deque<T,Allocator>::operator=(const deque<T,Allocator>& x)
	{
		// Complexity: O(size()) and O(x.size())
		if (this != &x)
		{
			assign(x.begin(), x.end());
		}
		return *this;
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void
	ft::deque<T,Allocator>::assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
	{
		// Complexity: O(distance(first, last))
		assign_dispatch(first, last, typename iterator_traits<InputIterator>::iterator_category());
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::assign(size_type n, const T& t)
	{
		// Complexity: O(n)
		// to do -> not clear, put assign each chunk, then delete like in optimisation in vector
		clear();
		for (size_type i = 0; i < n; ++i)
			push_back(t);
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::allocator_type
	ft::deque<T,Allocator>::get_allocator() const
	{
		// Complexity: O(1)
		return _allocator;
	}

	// =====================
	//	     Iterators
	// =====================

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::iterator
	ft::deque<T,Allocator>::begin()
	{
		// Complexity: O(1)
		return iterator(&_map, _start.map_index, _start.offset);
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_iterator
	ft::deque<T,Allocator>::begin() const
	{
		// Complexity: O(1)
		return const_iterator(&_map, _start.map_index, _start.offset);
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::iterator
	ft::deque<T,Allocator>::end()
	{
		// Complexity: O(1)
		return iterator(&_map, _end.map_index, _end.offset);
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_iterator
	ft::deque<T,Allocator>::end() const
	{
		// Complexity: O(1)
		return const_iterator(&_map, _end.map_index, _end.offset);
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::reverse_iterator
	ft::deque<T,Allocator>::rbegin()
	{
		// Complexity: O(1)
		return reverse_iterator(end());
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_reverse_iterator
	ft::deque<T,Allocator>::rbegin() const
	{
		// Complexity: O(1)
		return const_reverse_iterator(end());
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::reverse_iterator
	ft::deque<T,Allocator>::rend()
	{
		// Complexity: O(1)
		return reverse_iterator(begin());
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_reverse_iterator
	ft::deque<T,Allocator>::rend() const
	{
		// Complexity: O(1)
		return const_reverse_iterator(begin());
	}

	// ====================
	//	     Capacity
	// ====================

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::size_type
	ft::deque<T,Allocator>::size() const
	{
		// Complexity: O(1)
		return _size;
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::size_type
	ft::deque<T,Allocator>::max_size() const
	{
		// Complexity: O(1)
		return _allocator.max_size();
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::resize(size_type sz, T c)
	{
		// Complexity: O(abs(size() - sz))
		if (_size < sz)
		{
			for (size_type i = _size; i <= sz; ++i)
				push_back(c);
		}
		else
		{
			iterator new_end = begin() + sz;
			while (new_end != end())
				pop_back();
		}
	}

	template <class T, class Allocator>
	bool
	ft::deque<T,Allocator>::empty() const
	{
		// Complexity: O(1)
		return _size == 0;
	}

	// ======================
	//	   Element Access
	// ======================

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::reference
	ft::deque<T,Allocator>::operator[](size_type n)
	{
		// Complexity: O(1)
		iterator it = begin();
		it += n;
		return *it;
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_reference
	ft::deque<T,Allocator>::operator[](size_type n) const
	{
		// Complexity: O(1)
		const_iterator it = begin();
		it += n;
		return *it;
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::reference
	ft::deque<T,Allocator>::at(size_type n)
	{
		// Complexity: O(1)
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
		// Complexity: O(1)
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
		// Complexity: O(1)
		return _map[_start.map_index][_start.offset];
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_reference
	ft::deque<T,Allocator>::front() const
	{
		// Complexity: O(1)
		return _map[_start.map_index][_start.offset];
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::reference
	ft::deque<T,Allocator>::back()
	{
		// Complexity: O(1)
		if (_end.offset == 0)
			_map[_end.map_index - 1][deque_chunk_size - 1];
		return _map[_end.map_index][_end.offset - 1];
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::const_reference
	ft::deque<T,Allocator>::back() const
	{
		// Complexity: O(1)
		if (_end.offset == 0)
			_map[_end.map_index - 1][deque_chunk_size - 1];
		return _map[_end.map_index][_end.offset - 1];
	}

	// =====================
	//	     Modifiers
	// =====================

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::push_front(const T& x)
	{
		// Complexity: O(1)
		// todo
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::push_back(const T& x)
	{
		// Complexity: O(1)
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
		// n = lesser distances betzeen pos and either of the ends of container
		// Complexity: O(1 + n)
		size_type pos = static_cast<size_type>(position - begin());
		insert(begin() + pos, 1, x);
		return begin() + pos;
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::insert(iterator position, size_type n, const T& x)
	{
		// dist = lesser distances betzeen pos and either of the ends of container
		// Complexity: O(n + dist)
		// todo
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void
	ft::deque<T,Allocator>::insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
	{
		// dist = lesser distances between pos and either of the ends of container
		// Complexity: O(distance(first, last) + dist)
		insert_dispatch(position, first, last, typename iterator_traits<InputIterator>::iterator_category());
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::pop_front()
	{
		// Complexity: O(1)
		deque_position new_start;
		if (_start.offset == deque_chunk_size - 1)
		{
			new_start.map_index = _start.map_index + 1;
			new_start.offset = 0;
			_allocator.destroy(_map[_start.map_index] + _start.offset);
			_allocator.deallocate(_map[_start.map_index], deque_chunk_size);
			_map[_start.map_index] = NULL;
		}
		else
		{
			new_start.map_index = _start.map_index;
			new_start.offset = _start.offset + 1;
			_allocator.destroy(_map[_start.map_index] + _start.offset);
		}
		_start = new_start;
		--_size;
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::pop_back()
	{
		// Complexity: O(1)
		deque_position pos;
		if (_end.offset == 0)
		{
			pos.map_index = _end.map_index - 1;
			pos.offset = deque_chunk_size - 1;
			_allocator.destroy(_map[pos.map_index] + pos.offset);
			_allocator.deallocate(_map[_end.map_index], deque_chunk_size);
			_map[_end.map_index] = NULL;
		}
		else
		{
			pos.map_index = _end.map_index;
			pos.offset = _end.offset - 1;
			_allocator.destroy(_map[pos.map_index] + pos.offset);
		}
		_end = pos;
		--_size;
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::iterator
	ft::deque<T,Allocator>::erase(iterator position)
	{
		/*
			n1 = element to erase
			n2 = lesser number of elements before erased elements or after erased elements
			Complexity:
				destructor: O(n1)
				assignement: O(n2)
		*/
		return erase(position, position + 1);
	}

	template <class T, class Allocator>
	typename ft::deque<T,Allocator>::iterator
	ft::deque<T,Allocator>::erase(iterator first, iterator last)
	{
		/*
			n1 = element to erase
			n2 = lesser number of elements before erased elements or after erased elements
			Complexity:
				destructor: O(n1)
				assignement: O(n2)
		*/
		iterator ret = first;
		for (iterator it = last; it != end(); ++it, ++first)
			*first = *it;
		_end = first.base();
		for (iterator it = first; it != end(); ++it)
			_allocator.destroy(&*it);
		_size -= (last - ret);
		for (ft::size_t i = _end.map_index + 1; i < _map.size(); ++i)
		{
			_allocator.deallocate(_map[i], deque_chunk_size);
			_map[i] = NULL;
		}
		return ret;
	}

	template <class T, class Allocator>
	void
	ft::deque<T,Allocator>::swap(deque<T,Allocator>& other)
	{
		// Complexity: O(1)
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
		// Complexity: O(size())
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
			std::string("deque::range_check: n (which is "
				+ ft::to_string(n)
				+ ") >= this->size() (which is "
				+ ft::to_string(this->size()) + ")")
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
	ft::deque<T,Allocator>::insert_dispatch(iterator pos, InputIt first, InputIt last, input_iterator_tag)
	{
		vector<T, Allocator> tmp;
		for (; first != last; ++first)
			tmp.push_back(*first);
		insert_dispatch(pos, tmp.begin(), tmp.end(), forward_iterator_tag());
	}
	
	template <class T, class Allocator>
	template <class ForwardIt>
	void
	ft::deque<T,Allocator>::insert_dispatch(iterator pos, ForwardIt first, ForwardIt last, forward_iterator_tag)
	{
		// todo
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
		/*
			Complexity:
				x.size() != y.size(): O(1)
				else: O(size())
		*/
		if (x.size() != y.size())
			return false;
		typedef typename vector<T,Allocator>::const_iterator const_iterator;
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

	template <class T, class Allocator>
	bool
	operator!=(const deque<T,Allocator>& x, const deque<T,Allocator>& y)
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
	operator< (const deque<T,Allocator>& x, const deque<T,Allocator>& y)
	{
		// Complexity: O(size())
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class T, class Allocator>
	bool
	operator> (const deque<T,Allocator>& x, const deque<T,Allocator>& y)
	{
		// Complexity: O(size())
		return (y < x);
	}

	template <class T, class Allocator>
	bool
	operator>=(const deque<T,Allocator>& x, const deque<T,Allocator>& y)
	{
		// Complexity: O(size())
		return !(x < y);
	}

	template <class T, class Allocator>
	bool
	operator<=(const deque<T,Allocator>& x, const deque<T,Allocator>& y)
	{
		// Complexity: O(size())
		return !(y < x);
	}

	// ======================
	//	  Specialized Algo
	// ======================

	template <class T, class Allocator>
	void
	swap(deque<T,Allocator>& x, deque<T,Allocator>& y)
	{
		// Complexity: O(1)
		x.swap(y);
	}
}

#endif