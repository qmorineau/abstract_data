#include "vector_iterator.hpp"

namespace ft
{
	template<class T>
	ft::vector_iterator<T>&
	ft::vector_iterator<T>::operator+=(difference_type n)
	{
		_ptr += n;
		return *this; // to do
	}
	template<class T>
	ft::vector_iterator<T>
	ft::vector_iterator<T>::operator+(difference_type n)
	{
		return *this; // to do
	}
	template<class T>
	ft::vector_iterator<T>&
	ft::vector_iterator<T>::operator-=(difference_type n)
	{
		return *this; // to do
	}
	template<class T>
	ft::vector_iterator<T>
	ft::vector_iterator<T>::operator-(difference_type n) const
	{
		return *this; // to do
	}
	template<class T>
	typename ft::vector_iterator<T>::difference_type
	ft::vector_iterator<T>::operator-(const ft::vector_iterator<T>&)
	{
		// to do
	}
	template<class T>
	typename ft::vector_iterator<T>::reference
	ft::vector_iterator<T>::operator[](difference_type n) const
	{
		return *_ptr; // to do
	}
	template<class T>
	bool
	ft::vector_iterator<T>::operator<(const ft::vector_iterator<T>&) const
	{
		return false; // to do
	}
	template<class T>
	bool
	ft::vector_iterator<T>::operator>(const ft::vector_iterator<T>&) const
	{
		return false; // to do
	}
	template<class T>
	bool
	ft::vector_iterator<T>::operator<=(const ft::vector_iterator<T>&) const
	{
		return false; // to do
	}
	template<class T>
	bool
	ft::vector_iterator<T>::operator>=(const ft::vector_iterator<T>&) const
	{
		return false; // to do
	}
	template<class T>
	ft::vector_iterator<T>
	ft::vector_iterator<T>::operator--(int)
	{
		return *this; // to do
	}
	template<class T>
	ft::vector_iterator<T>&
	ft::vector_iterator<T>::operator--(void)
	{
		return *this; // to do
	}
	template<class T>
	ft::vector_iterator<T>&
	ft::vector_iterator<T>::operator++(void)
	{
		return *this; // to do
	}
	template<class T>
	ft::vector_iterator<T>
	ft::vector_iterator<T>::operator++(int)
	{
		return *this; // to do
	}
	template<class T>
	typename ft::vector_iterator<T>::reference
	ft::vector_iterator<T>::operator*(void) const
	{
		return *_ptr; // to do
	}
}