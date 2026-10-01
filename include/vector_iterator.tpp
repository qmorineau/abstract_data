#ifndef VECTOR_ITERATOR_TPP
#define VECTOR_ITERATOR_TPP

namespace ft
{
	// ========================
	//      Vector Iterator
	// ========================

	// ====== Construct / Destruct ======
	template <class T, class Pointer, class Reference>
	vector_iterator<T, Pointer, Reference>::vector_iterator(void)
		: _ptr(0)
	{}

	template <class T, class Pointer, class Reference>
	vector_iterator<T, Pointer, Reference>::vector_iterator(T* p)
		: _ptr(p)
	{}

	template <class T, class Pointer, class Reference>
	template <class T2, class Pointer2, class Reference2>
	vector_iterator<T, Pointer, Reference>::vector_iterator(const vector_iterator<T2, Pointer2, Reference2>& other)
		: _ptr(other.base())
	{}

	template <class T, class Pointer, class Reference>
	vector_iterator<T, Pointer, Reference>::~vector_iterator()
	{}

	template <class T, class Pointer, class Reference>
	vector_iterator<T, Pointer, Reference>&
	vector_iterator<T, Pointer, Reference>::operator=(const vector_iterator& other)
	{
		if (this != &other)
			_ptr = other._ptr;
		return *this;
	}

	// ====== base() ======
	template <class T, class Pointer, class Reference>
	typename vector_iterator<T, Pointer, Reference>::value_type*
	vector_iterator<T, Pointer, Reference>::base(void) const
	{
		return _ptr;
	}

	// ====== Input Iterator ======
	template <class T, class Pointer, class Reference>
	typename vector_iterator<T, Pointer, Reference>::reference
	vector_iterator<T, Pointer, Reference>::operator*() const
	{
		return *_ptr;
	}
	
	template <class T, class Pointer, class Reference>
	typename vector_iterator<T, Pointer, Reference>::pointer
	vector_iterator<T, Pointer, Reference>::operator->() const
	{
		return _ptr;
	}

	// ====== Bidirectional Iterator ======
	template <class T, class Pointer, class Reference>
	vector_iterator<T, Pointer, Reference>&
	vector_iterator<T, Pointer, Reference>::operator++(void)
	{
		++_ptr;
		return *this;
	}

	template <class T, class Pointer, class Reference>
	vector_iterator<T, Pointer, Reference>
	vector_iterator<T, Pointer, Reference>::operator++(int)
	{
		vector_iterator tmp = *this;
		++_ptr;
		return tmp;
	}

	template <class T, class Pointer, class Reference>
	vector_iterator<T, Pointer, Reference>&
	vector_iterator<T, Pointer, Reference>::operator--(void)
	{
		--_ptr;
		return *this;
	}

	template <class T, class Pointer, class Reference>
	vector_iterator<T, Pointer, Reference>
	vector_iterator<T, Pointer, Reference>::operator--(int)
	{
		vector_iterator tmp = *this;
		--_ptr;
		return tmp;
	}

	// ====== Random Access Arithmetic ======
	template <class T, class Pointer, class Reference>
	vector_iterator<T, Pointer, Reference>&
	vector_iterator<T, Pointer, Reference>::operator+=(difference_type n)
	{
		_ptr += n;
		return *this;
	}

	template <class T, class Pointer, class Reference>
	vector_iterator<T, Pointer, Reference>
	vector_iterator<T, Pointer, Reference>::operator+(difference_type n) const
	{
		return vector_iterator(_ptr + n);
	}

	template <class T, class Pointer, class Reference>
	vector_iterator<T, Pointer, Reference>&
	vector_iterator<T, Pointer, Reference>::operator-=(difference_type n)
	{
		_ptr -= n;
		return *this;
	}

	template <class T, class Pointer, class Reference>
	vector_iterator<T, Pointer, Reference>
	vector_iterator<T, Pointer, Reference>::operator-(difference_type n) const
	{
		return vector_iterator(_ptr - n);
	}

	template <class T, class Pointer, class Reference>
	typename vector_iterator<T, Pointer, Reference>::difference_type
	vector_iterator<T, Pointer, Reference>::operator-(const vector_iterator& other) const
	{
		return _ptr - other._ptr;
	}

	template <class T, class Pointer, class Reference>
	typename vector_iterator<T, Pointer, Reference>::reference
	vector_iterator<T, Pointer, Reference>::operator[](difference_type n) const
	{
		return *(_ptr + n);
	}

	template <class T, class Pointer, class Reference>
	bool
	vector_iterator<T, Pointer, Reference>::operator<(const vector_iterator& other) const
	{
		return _ptr < other._ptr;
	}

	template <class T, class Pointer, class Reference>
	bool
	vector_iterator<T, Pointer, Reference>::operator>(const vector_iterator& other) const
	{
		return _ptr > other._ptr;
	}

	template <class T, class Pointer, class Reference>
	bool
	vector_iterator<T, Pointer, Reference>::operator<=(const vector_iterator& other) const
	{
		return _ptr <= other._ptr;
	}

	template <class T, class Pointer, class Reference>
	bool
	vector_iterator<T, Pointer, Reference>::operator>=(const vector_iterator& other) const
	{
		return _ptr >= other._ptr;
	}

	// ====== Non-Members ======
	template <class T, class Pointer, class Reference>
	vector_iterator<T, Pointer, Reference>
	operator+(typename vector_iterator<T, Pointer, Reference>::difference_type n, const vector_iterator<T, Pointer, Reference>& it)
	{
		return it + n;
	}

	template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
	bool operator==(const vector_iterator<T, Pointer1, Reference1>& x,
		const vector_iterator<T, Pointer2, Reference2>& y)
	{
		return x.base() == y.base();
	}
	template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
	bool operator!=(const vector_iterator<T, Pointer1, Reference1>& x,
		const vector_iterator<T, Pointer2, Reference2>& y)
	{
		return x.base() != y.base();
	}
}

#endif