#ifndef DEQUE_ITERATOR_TPP
#define DEQUE_ITERATOR_TPP

namespace ft
{
	// ========================
	//      Deque Iterator
	// ========================

	// ====== Construct / Destruct ======
	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>::deque_iterator(void)
		: _map(0), _map_idx(0), _offset(0)
	{}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>::deque_iterator(const vector<T*>* map, ft::size_t map_idx, ft::size_t offset)
		: _map(map), _map_idx(map_idx), _offset(offset)
	{}

	template <class T, class Pointer, class Reference>
	template <class T2, class Pointer2, class Reference2>
	deque_iterator<T, Pointer, Reference>::deque_iterator(const deque_iterator<T2, Pointer2, Reference2>& other)
		: _map(other._map), _map_idx(other._map_idx), _offset(other._offset)
	{}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>::~deque_iterator()
	{}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>&
	deque_iterator<T, Pointer, Reference>::operator=(const deque_iterator& other)
	{
		_map = other._map;
		_map_idx = other._map_idx;
		_offset = other._offset;
		return *this;
	}

	// ====== Input Iterator ======
	template <class T, class Pointer, class Reference>
	typename deque_iterator<T, Pointer, Reference>::reference
	deque_iterator<T, Pointer, Reference>::operator*() const
	{
		return (*_map)[_map_idx][_offset];
	}
	
	template <class T, class Pointer, class Reference>
	typename deque_iterator<T, Pointer, Reference>::pointer
	deque_iterator<T, Pointer, Reference>::operator->() const
	{
		return &(*_map)[_map_idx][_offset];
	}

	// ====== Bidirectional Iterator ======
	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>&
	deque_iterator<T, Pointer, Reference>::operator++(void)
	{
		++_offset;
		if (_offset == deque_chunk_size && _map_idx != deque_chunk_size)
		{
			++_map_idx;
			_offset = 0;
		}
		return *this;
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>
	deque_iterator<T, Pointer, Reference>::operator++(int)
	{
		deque_iterator tmp = *this;
		++(*this);
		return tmp;
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>&
	deque_iterator<T, Pointer, Reference>::operator--(void)
	{
		if (_offset == 0)
		{
			--_map_idx;
			_offset = deque_chunk_size - 1;
		}
		else
			--_offset;
		return *this;
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>
	deque_iterator<T, Pointer, Reference>::operator--(int)
	{
		deque_iterator tmp = *this;
		--(*this);
		return tmp;
	}

	// ====== Random Access Arithmetic ======
	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>&
	deque_iterator<T, Pointer, Reference>::operator+=(difference_type n)
	{
		ft::size_t curr_chunk_diff = deque_chunk_size - 1 - _offset;
		if (n < static_cast<ft::ptrdiff_t>(curr_chunk_diff))
			_offset += n;
		else
		{
			ft::size_t incr_map = (n - curr_chunk_diff) / deque_chunk_size;
			ft::size_t new_offset = (n - curr_chunk_diff) % deque_chunk_size; 
			_offset = new_offset;
			_map_idx += incr_map;
		}
		return *this;
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>
	deque_iterator<T, Pointer, Reference>::operator+(difference_type n) const
	{
		deque_iterator tmp(*this);
		tmp += n;
		return tmp;
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>&
	deque_iterator<T, Pointer, Reference>::operator-=(difference_type n)
	{
		if (n < static_cast<difference_type>(_offset))
			_offset -= n;
		else
		{
			ft::size_t decr_map = (n - _offset) / deque_chunk_size;
			ft::size_t new_offset = deque_chunk_size - ((n - _offset) % deque_chunk_size);
			_map_idx -= decr_map;
			_offset = new_offset;
		}
		return *this;
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>
	deque_iterator<T, Pointer, Reference>::operator-(difference_type n) const
	{
		deque_iterator tmp(*this);
		tmp -= n;
		return tmp;
	}

	template <class T, class Pointer, class Reference>
	typename deque_iterator<T, Pointer, Reference>::difference_type
	deque_iterator<T, Pointer, Reference>::operator-(const deque_iterator& other) const
	{
		difference_type total_diff = 0;

		difference_type map_diff = _map_idx - other._map_idx;
		(void) map_diff;
		return total_diff;
		// todo
	}

	template <class T, class Pointer, class Reference>
	typename deque_iterator<T, Pointer, Reference>::reference
	deque_iterator<T, Pointer, Reference>::operator[](difference_type n) const
	{
		return *deque_iterator(*this + n);
		// not sure
	}

	template <class T, class Pointer, class Reference>
	bool
	deque_iterator<T, Pointer, Reference>::operator<(const deque_iterator& other) const
	{
		if (_map_idx == other._map_idx)
			return (_offset < other._offset);
		return (_map_idx < other._map_idx);
	}

	template <class T, class Pointer, class Reference>
	bool
	deque_iterator<T, Pointer, Reference>::operator>(const deque_iterator& other) const
	{
		return !(*this < other);
	}

	template <class T, class Pointer, class Reference>
	bool
	deque_iterator<T, Pointer, Reference>::operator<=(const deque_iterator& other) const
	{
		return !(*this > other);
	}

	template <class T, class Pointer, class Reference>
	bool
	deque_iterator<T, Pointer, Reference>::operator>=(const deque_iterator& other) const
	{
		return !(*this < other);
	}

	// ====== Non-Members ======
	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>
	operator+(typename deque_iterator<T, Pointer, Reference>::difference_type n, const deque_iterator<T, Pointer, Reference>& it)
	{
		return it + n;
	}

	template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
	bool
	operator==(const deque_iterator<T, Pointer1, Reference1>& x, const deque_iterator<T, Pointer2, Reference2>& y)
	{
		// return x.base() == y.base();
		(void) x;
		(void) y;
		return false;
	}
	template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
	bool
	operator!=(const deque_iterator<T, Pointer1, Reference1>& x, const deque_iterator<T, Pointer2, Reference2>& y)
	{
		(void) x;
		(void) y;
		// return x.base() != y.base();
		return false;
	}
}

#endif