#ifndef LIST_ITERATOR_TPP
#define LIST_ITERATOR_TPP

namespace ft
{
	// ========================
	//      List Iterator
	// ========================

	// ====== Construct / Destruct ======

	template <class T, class Pointer, class Reference>
	list_iterator<T, Pointer, Reference>::list_iterator(void)
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	list_iterator<T, Pointer, Reference>::list_iterator(T* p)
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	template <class T2, class Pointer2, class Reference2>
	list_iterator<T, Pointer, Reference>::list_iterator(const list_iterator<T2, Pointer2, Reference2>& other)
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	list_iterator<T, Pointer, Reference>::~list_iterator()
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	list_iterator<T, Pointer, Reference>&
	list_iterator<T, Pointer, Reference>::operator=(const list_iterator& other)
	{
		// todo
	}

	// ====== Input Iterator ======

	template <class T, class Pointer, class Reference>
	typename list_iterator<T, Pointer, Reference>::reference
	list_iterator<T, Pointer, Reference>::operator*(void) const
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	typename ft::list_iterator<T, Pointer, Reference>::pointer
	list_iterator<T, Pointer, Reference>::operator->(void) const
	{
		// todo
	}

	// ====== Bidirectional Iterator ======

	template <class T, class Pointer, class Reference>
	list_iterator<T, Pointer, Reference>&
	list_iterator<T, Pointer, Reference>::operator++(void)
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	typename ft::list_iterator<T, Pointer, Reference>
	list_iterator<T, Pointer, Reference>::operator++(int)
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	list_iterator<T, Pointer, Reference>&
	list_iterator<T, Pointer, Reference>::operator--(void)
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	list_iterator<T, Pointer, Reference>
	list_iterator<T, Pointer, Reference>::operator--(int)
	{
		// todo
	}


	// ====== Random Access Arithmetic ======

	template <class T, class Pointer, class Reference>
	list_iterator<T, Pointer, Reference>&
	list_iterator<T, Pointer, Reference>::operator+=(difference_type n)
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	list_iterator<T, Pointer, Reference>
	list_iterator<T, Pointer, Reference>::operator+(difference_type n) const
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	list_iterator<T, Pointer, Reference>&
	list_iterator<T, Pointer, Reference>::operator-=(difference_type n)
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	list_iterator<T, Pointer, Reference>
	list_iterator<T, Pointer, Reference>::operator-(difference_type n) const
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	typename list_iterator<T, Pointer, Reference>::difference_type
	list_iterator<T, Pointer, Reference>::operator-(const list_iterator&) const
	{
		return 0;// todo
	}

	template <class T, class Pointer, class Reference>
	typename list_iterator<T, Pointer, Reference>::reference
	list_iterator<T, Pointer, Reference>::operator[](difference_type n) const
	{
		// todo
	}

	template <class T, class Pointer, class Reference>
	bool
	list_iterator<T, Pointer, Reference>::operator<(const list_iterator&) const
	{
		return false; // todo
	}

	template <class T, class Pointer, class Reference>
	bool
	list_iterator<T, Pointer, Reference>::operator>(const list_iterator&) const
	{
		return false; // todo
	}

	template <class T, class Pointer, class Reference>
	bool
	list_iterator<T, Pointer, Reference>::operator<=(const list_iterator&) const
	{
		return false; // todo
	}

	template <class T, class Pointer, class Reference>
	bool
	list_iterator<T, Pointer, Reference>::operator>=(const list_iterator&) const
	{
		return false; // todo
	}

	// ====== Non-Members ======

	template <class T, class Pointer, class Reference>
	list_iterator<T, Pointer, Reference>
	operator+(typename list_iterator<T, Pointer, Reference>::difference_type n, const list_iterator<T, Pointer, Reference>& it)
	{
		return false;return false;// todo
	}
	
	template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
	bool
	operator==(const list_iterator<T, Pointer1, Reference1>& x, const list_iterator<T, Pointer2, Reference2>& y)
	{
		return false;// todo
	}
	
	template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
	bool
	operator!=(const list_iterator<T, Pointer1, Reference1>& x, const list_iterator<T, Pointer2, Reference2>& y)
	{
		return false;// todo
	}
}

#endif