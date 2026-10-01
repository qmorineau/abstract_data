#ifndef ITERATOR_TPP
#define ITERATOR_TPP

namespace ft
{
	// ========================
	//      Reverse Iterator
	// ========================

	// ====== Construct / Destruct ======
	template <class Iterator>
	ft::reverse_iterator<Iterator>::reverse_iterator()
		: current()
	{}

	template <class Iterator>
	ft::reverse_iterator<Iterator>::reverse_iterator(Iterator x)
		: current(x)
	{}

	template <class Iterator>
	template <class U>
	ft::reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<U>& u)
		: current(u.base())
	{}

	// ====== base() ======
	template <class Iterator>
	Iterator
	ft::reverse_iterator<Iterator>::base() const
	{
		return current;
	}

	// ====== Dereference Operators ======
	template <class Iterator>
	typename ft::reverse_iterator<Iterator>::reference
	ft::reverse_iterator<Iterator>::operator*(void) const
	{
		Iterator tmp = current;
		--tmp;
		return *tmp;
	}

	template <class Iterator>
	typename ft::reverse_iterator<Iterator>::pointer
	ft::reverse_iterator<Iterator>::operator->(void) const
	{
		return &(operator*());
	}

	// ====== Increment / Decrement ======
	template <class Iterator>
	ft::reverse_iterator<Iterator>&
	ft::reverse_iterator<Iterator>::operator++(void)
	{
		--current;
		return *this;
	}

	template <class Iterator>
	ft::reverse_iterator<Iterator>
	ft::reverse_iterator<Iterator>::operator++(int)
	{
		reverse_iterator tmp = *this;
		--current;
		return tmp;
	}

	template <class Iterator>
	ft::reverse_iterator<Iterator>&
	ft::reverse_iterator<Iterator>::operator--(void)
	{
		++current;
		return *this;
	}

	template <class Iterator>
	ft::reverse_iterator<Iterator>
	ft::reverse_iterator<Iterator>::operator--(int)
	{
		reverse_iterator tmp = *this;
		++current;
		return tmp;
	}

	// ====== Random Access Arithmetic ======
	template <class Iterator>
	ft::reverse_iterator<Iterator>&
	ft::reverse_iterator<Iterator>::operator+=(difference_type n)
	{
		current -= n;
		return *this;
	}

	template <class Iterator>
	ft::reverse_iterator<Iterator>
	ft::reverse_iterator<Iterator>::operator+(difference_type n) const
	{
		return reverse_iterator(current - n);
	}

	template <class Iterator>
	ft::reverse_iterator<Iterator>&
	ft::reverse_iterator<Iterator>::operator-=(difference_type n)
	{
		current += n;
		return *this;
	}

	template <class Iterator>
	ft::reverse_iterator<Iterator>
	ft::reverse_iterator<Iterator>::operator-(difference_type n) const
	{
		return reverse_iterator(current + n);
	}

	template <class Iterator>
	typename ft::reverse_iterator<Iterator>::reference
	ft::reverse_iterator<Iterator>::operator[](difference_type n) const
	{
		return *(*this + n);
	}

	// ====== Non-Members ======
	template <class Iterator>
	bool
	operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		return x.base() == y.base();
	}

	template <class Iterator>
	bool
	operator!=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		return x.base() != y.base();
	}

	template <class Iterator>
	bool
	operator<(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		return x.base() > y.base();
	}

	template <class Iterator>
	bool
	operator>(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		return x.base() < y.base();
	}

	template <class Iterator>
	bool
	operator>=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		return x.base() <= y.base();
	}

	template <class Iterator>
	bool
	operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		return x.base() >= y.base();
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type
	operator-(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
		return y.base() - x.base();
	}

	template <class Iterator>
	reverse_iterator<Iterator>
	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& x)
	{
		return x + n;
	}

	// ====== Helper ======
	template <class InputIt>
	typename iterator_traits<InputIt>::difference_type 
    distance(InputIt first, InputIt last)
	{
		return detail::do_distance(first, last, typename iterator_traits<InputIt>::iterator_category());
	}
}

#endif