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
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>::deque_iterator(T* p)
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	template <class T2, class Pointer2, class Reference2>
	deque_iterator<T, Pointer, Reference>::deque_iterator(const deque_iterator<T2, Pointer2, Reference2>& other)
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>::~deque_iterator()
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>&
	deque_iterator<T, Pointer, Reference>::operator=(const deque_iterator& other)
	{
		// todo
	}

	// ====== Input Iterator ======

	template <class T, class Pointer, class Reference>
	typename deque_iterator<T, Pointer, Reference>::reference
	deque_iterator<T, Pointer, Reference>::operator*(void) const
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	typename ft::deque_iterator<T, Pointer, Reference>::pointer
	deque_iterator<T, Pointer, Reference>::operator->(void) const
	{
		// todo
	}

	// ====== Bidirectional Iterator ======

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>&
	deque_iterator<T, Pointer, Reference>::operator++(void)
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	typename ft::deque_iterator<T, Pointer, Reference>
	deque_iterator<T, Pointer, Reference>::operator++(int)
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>&
	deque_iterator<T, Pointer, Reference>::operator--(void)
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>
	deque_iterator<T, Pointer, Reference>::operator--(int)
	{
		// todo
	}


	// ====== Random Access Arithmetic ======

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>&
	deque_iterator<T, Pointer, Reference>::operator+=(difference_type n)
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>
	deque_iterator<T, Pointer, Reference>::operator+(difference_type n) const
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>&
	deque_iterator<T, Pointer, Reference>::operator-=(difference_type n)
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>
	deque_iterator<T, Pointer, Reference>::operator-(difference_type n) const
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	typename deque_iterator<T, Pointer, Reference>::difference_type
	deque_iterator<T, Pointer, Reference>::operator-(const deque_iterator&) const
	{
		return 0;// todo
	}

	template <class T, class Pointer, class Reference>
	typename deque_iterator<T, Pointer, Reference>::reference
	deque_iterator<T, Pointer, Reference>::operator[](difference_type n) const
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	bool
	deque_iterator<T, Pointer, Reference>::operator<(const deque_iterator&) const
	{
		return false; // todo
	}

	template <class T, class Pointer, class Reference>
	bool
	deque_iterator<T, Pointer, Reference>::operator>(const deque_iterator&) const
	{
		return false; // todo
	}

	template <class T, class Pointer, class Reference>
	bool
	deque_iterator<T, Pointer, Reference>::operator<=(const deque_iterator&) const
	{
		return false; // todo
	}

	template <class T, class Pointer, class Reference>
	bool
	deque_iterator<T, Pointer, Reference>::operator>=(const deque_iterator&) const
	{
		return false; // todo
	}

	// ====== Non-Members ======

	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>
	operator+(typename deque_iterator<T, Pointer, Reference>::difference_type n, const deque_iterator<T, Pointer, Reference>& it)
	{
		return false;return false;// todo
	}
	
	template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
	bool
	operator==(const deque_iterator<T, Pointer1, Reference1>& x, const deque_iterator<T, Pointer2, Reference2>& y)
	{
		return false;// todo
	}
	
	template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
	bool
	operator!=(const deque_iterator<T, Pointer1, Reference1>& x, const deque_iterator<T, Pointer2, Reference2>& y)
	{
		return false;// todo
	}
}

#endif