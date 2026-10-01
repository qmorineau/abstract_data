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
		: _current(0)
	{}

	template <class T, class Pointer, class Reference>
	list_iterator<T, Pointer, Reference>::list_iterator(Node<T>* n)
		: _current(n)
	{}

	template <class T, class Pointer, class Reference>
	template <class T2, class Pointer2, class Reference2>
	list_iterator<T, Pointer, Reference>::list_iterator(const list_iterator<T2, Pointer2, Reference2>& other)
		: _current(other._current)
	{}

	template <class T, class Pointer, class Reference>
	list_iterator<T, Pointer, Reference>::~list_iterator()
	{}

	template <class T, class Pointer, class Reference>
	list_iterator<T, Pointer, Reference>&
	list_iterator<T, Pointer, Reference>::operator=(const list_iterator& other)
	{
		if (this != &other)
			_current = other._current;
		return *this;
	}

	// ====== base() ======
	template <class T, class Pointer, class Reference>
	Node<T>*
	list_iterator<T, Pointer, Reference>::base(void) const
	{
		return _current;
	}

	// ====== Input Iterator ======

	template <class T, class Pointer, class Reference>
	typename list_iterator<T, Pointer, Reference>::reference
	list_iterator<T, Pointer, Reference>::operator*(void) const
	{
		return _current->data;
	}

	template <class T, class Pointer, class Reference>
	typename ft::list_iterator<T, Pointer, Reference>::pointer
	list_iterator<T, Pointer, Reference>::operator->(void) const
	{
		return _current;
	}

	// ====== Bidirectional Iterator ======

	template <class T, class Pointer, class Reference>
	list_iterator<T, Pointer, Reference>&
	list_iterator<T, Pointer, Reference>::operator++(void)
	{
		_current = _current->next;
		return *this;
	}

	template <class T, class Pointer, class Reference>
	typename ft::list_iterator<T, Pointer, Reference>
	list_iterator<T, Pointer, Reference>::operator++(int)
	{
		list_iterator tmp(_current);
		_current = _current->next;
		return tmp;
	}

	template <class T, class Pointer, class Reference>
	list_iterator<T, Pointer, Reference>&
	list_iterator<T, Pointer, Reference>::operator--(void)
	{
		_current = _current->prev;
		return *this;
	}

	template <class T, class Pointer, class Reference>
	list_iterator<T, Pointer, Reference>
	list_iterator<T, Pointer, Reference>::operator--(int)
	{
		list_iterator tmp(_current);
		_current = _current->prev;
		return tmp;
	}

	// ====== Non-Members ======

	template <class T, class Pointer, class Reference>
	list_iterator<T, Pointer, Reference>
	operator+(typename list_iterator<T, Pointer, Reference>::difference_type n, const list_iterator<T, Pointer, Reference>& it)
	{
		if (n > 0)
		{
			while (n > 0)
			{
				++it;
				--n;
			}
		}
		else
		{
			while (n < 0)
			{
				--it;
				++n;
			}
		}
		return it;
	}
	
	template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
	bool
	operator==(const list_iterator<T, Pointer1, Reference1>& x, const list_iterator<T, Pointer2, Reference2>& y)
	{
		return x.base() == y.base();
	}
	
	template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
	bool
	operator!=(const list_iterator<T, Pointer1, Reference1>& x, const list_iterator<T, Pointer2, Reference2>& y)
	{
		return x.base() != y.base();
	}
}

#endif