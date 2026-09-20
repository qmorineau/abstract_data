	#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
	template<class T>
	class vector_iterator : public iterator<ft::random_access_iterator_tag, T> 
	{
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
			vector_iterator(T* p) : _ptr(p) {};
			/* 
				i, a, b object of type It or const It
				r, an lvalue of type It
				n, an integer of type difference_type
			 */
			// random_access_iterator
			vector_iterator& operator+=(difference_type n);		// r += n
			vector_iterator operator+(difference_type n);		// a + n
			vector_iterator& operator-=(difference_type n);		// r -= n
			vector_iterator operator-(difference_type n) const;	// i - n
			difference_type operator-(const vector_iterator&);	// b - a
			reference operator[](difference_type n) const;		// i[n]
			bool operator<(const vector_iterator&) const;		// a < b
			bool operator>(const vector_iterator&) const;		// a > b
			bool operator<=(const vector_iterator&) const;		// a <= b
			bool operator>=(const vector_iterator&) const;		// a >= b
			// bidirectional_iterator
			vector_iterator operator--(int);					// a--
			vector_iterator& operator--(void);					// --a
			// forward_iterator
			vector_iterator operator++(int);					// ++r
			vector_iterator& operator++(void);					// r++
			reference operator*(void) const;					// *a
			// input_iterator
																// *a = value
			// output_iterator
																// value = *a
		private:
			T*	_ptr;
	};
	template <class T>
	vector_iterator<T> operator+(typename vector_iterator<T>::difference_type n,
		const vector_iterator<T>& it);	// n + a
}

#include "vector_iterator.tpp"

#endif	