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

	// ====== base() ======
	template <class T, class Pointer, class Reference>
	deque_position
	deque_iterator<T, Pointer, Reference>::base(void) const
	{
		return deque_position(_map_idx, _offset);
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
		if (_offset == deque_chunk_size)
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
		const difference_type chunk_size = static_cast<difference_type>(deque_chunk_size);
		difference_type pos = static_cast<difference_type>(_map_idx) * chunk_size
								+ static_cast<difference_type>(_offset) + n;
		_map_idx = static_cast<ft::size_t>(pos / chunk_size);
		_offset = static_cast<ft::size_t>(pos % chunk_size);
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
		return *this += -n;
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
		const difference_type chunk_size = static_cast<difference_type>(deque_chunk_size);
		difference_type curr_pos = static_cast<difference_type>(_map_idx) * chunk_size
								+ static_cast<difference_type>(_offset);
		difference_type other_pos = static_cast<difference_type>(other._map_idx) * chunk_size
								+ static_cast<difference_type>(other._offset);
		return curr_pos - other_pos;
	}

	template <class T, class Pointer, class Reference>
	typename deque_iterator<T, Pointer, Reference>::reference
	deque_iterator<T, Pointer, Reference>::operator[](difference_type n) const
	{
		return *deque_iterator(*this + n);
	}

	template <class T, class Pointer, class Reference>
	bool
	deque_iterator<T, Pointer, Reference>::operator<(const deque_iterator& other) const
	{
		return (_map_idx < other._map_idx || (_map_idx == other._map_idx && _offset < other._offset));
	}

	template <class T, class Pointer, class Reference>
	bool
	deque_iterator<T, Pointer, Reference>::operator>(const deque_iterator& other) const
	{
		return (_map_idx > other._map_idx || (_map_idx == other._map_idx && _offset > other._offset));
	}

	template <class T, class Pointer, class Reference>
	bool
	deque_iterator<T, Pointer, Reference>::operator<=(const deque_iterator& other) const
	{
		return (_map_idx < other._map_idx || (_map_idx == other._map_idx && _offset <= other._offset));
	}

	template <class T, class Pointer, class Reference>
	bool
	deque_iterator<T, Pointer, Reference>::operator>=(const deque_iterator& other) const
	{
		return (_map_idx > other._map_idx || (_map_idx == other._map_idx && _offset >= other._offset));
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
		deque_position x_base = x.base();
		deque_position y_base = y.base();

		return (x_base.map_index == y_base.map_index && x_base.offset == y_base.offset);
	}
	template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
	bool
	operator!=(const deque_iterator<T, Pointer1, Reference1>& x, const deque_iterator<T, Pointer2, Reference2>& y)
	{
		deque_position x_base = x.base();
		deque_position y_base = y.base();

		return !(x_base.map_index == y_base.map_index && x_base.offset == y_base.offset);
	}
}

#endif