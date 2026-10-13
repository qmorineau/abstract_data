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
		: _owner(0), _map_idx(0), _offset(0)
	{}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>::deque_iterator(deque<T>* owner, ft::size_t map_idx, ft::size_t offset)
		: _owner(owner), _map_idx(map_idx), _offset(offset)
	{}

	template <class T, class Pointer, class Reference>
	template <class T2, class Pointer2, class Reference2>
	deque_iterator<T, Pointer, Reference>::deque_iterator(const deque_iterator<T2, Pointer2, Reference2>& other)
		: _owner(other.owner), _map_idx(other.map_idx), _offset(other.offset)
	{}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>::~deque_iterator()
	{}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>&
	deque_iterator<T, Pointer, Reference>::operator=(const deque_iterator& other)
	{
		_owner = other.owner;
		_map_idx = other.map_idx;
		_offset = other.offset;
		return *this;
	}

	// ====== base() ======
	template <class T, class Pointer, class Reference>
	typename deque_iterator<T, Pointer, Reference>::pointer
	deque_iterator<T, Pointer, Reference>::base(void) const
	{
		return _ptr;
	}

	// ====== Input Iterator ======
	template <class T, class Pointer, class Reference>
	typename deque_iterator<T, Pointer, Reference>::reference
	deque_iterator<T, Pointer, Reference>::operator*() const
	{
		return *_ptr;
	}
	
	template <class T, class Pointer, class Reference>
	typename deque_iterator<T, Pointer, Reference>::pointer
	deque_iterator<T, Pointer, Reference>::operator->() const
	{
		return _ptr;
	}

	// ====== Bidirectional Iterator ======
	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>&
	deque_iterator<T, Pointer, Reference>::operator++(void)
	{
		++_ptr;
		return *this;
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>
	deque_iterator<T, Pointer, Reference>::operator++(int)
	{
		deque_iterator tmp = *this;
		++_ptr;
		return tmp;
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>&
	deque_iterator<T, Pointer, Reference>::operator--(void)
	{
		--_ptr;
		return *this;
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>
	deque_iterator<T, Pointer, Reference>::operator--(int)
	{
		deque_iterator tmp = *this;
		--_ptr;
		return tmp;
	}

	// ====== Random Access Arithmetic ======
	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>&
	deque_iterator<T, Pointer, Reference>::operator+=(difference_type n)
	{
		_ptr += n;
		return *this;
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>
	deque_iterator<T, Pointer, Reference>::operator+(difference_type n) const
	{
		return deque_iterator(_ptr + n);
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>&
	deque_iterator<T, Pointer, Reference>::operator-=(difference_type n)
	{
		_ptr -= n;
		return *this;
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>
	deque_iterator<T, Pointer, Reference>::operator-(difference_type n) const
	{
		return deque_iterator(_ptr - n);
	}

	template <class T, class Pointer, class Reference>
	typename deque_iterator<T, Pointer, Reference>::difference_type
	deque_iterator<T, Pointer, Reference>::operator-(const deque_iterator& other) const
	{
		return _ptr - other._ptr;
	}

	template <class T, class Pointer, class Reference>
	typename deque_iterator<T, Pointer, Reference>::reference
	deque_iterator<T, Pointer, Reference>::operator[](difference_type n) const
	{
		return *(_ptr + n);
	}

	template <class T, class Pointer, class Reference>
	bool
	deque_iterator<T, Pointer, Reference>::operator<(const deque_iterator& other) const
	{
		return _ptr < other._ptr;
	}

	template <class T, class Pointer, class Reference>
	bool
	deque_iterator<T, Pointer, Reference>::operator>(const deque_iterator& other) const
	{
		return _ptr > other._ptr;
	}

	template <class T, class Pointer, class Reference>
	bool
	deque_iterator<T, Pointer, Reference>::operator<=(const deque_iterator& other) const
	{
		return _ptr <= other._ptr;
	}

	template <class T, class Pointer, class Reference>
	bool
	deque_iterator<T, Pointer, Reference>::operator>=(const deque_iterator& other) const
	{
		return _ptr >= other._ptr;
	}

	// ====== Non-Members ======
	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>
	operator+(typename deque_iterator<T, Pointer, Reference>::difference_type n, const deque_iterator<T, Pointer, Reference>& it)
	{
		return it + n;
	}

	template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
	bool operator==(const deque_iterator<T, Pointer1, Reference1>& x,
		const deque_iterator<T, Pointer2, Reference2>& y)
	{
		return x.base() == y.base();
	}
	template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
	bool operator!=(const deque_iterator<T, Pointer1, Reference1>& x,
		const deque_iterator<T, Pointer2, Reference2>& y)
	{
		return x.base() != y.base();
	}
}

#endif