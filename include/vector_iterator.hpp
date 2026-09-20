	#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
	template <class T, class Pointer = T*, class Reference = T&>
	class vector_iterator : public iterator<ft::random_access_iterator_tag, T, ft::ptrdiff_t, Pointer, Reference>
	{
		public:
			typedef Pointer								pointer;
			typedef Reference							reference;
			typedef T 									value_type;
			typedef ft::ptrdiff_t						difference_type;
			typedef ft::random_access_iterator_tag		iterator_category;

			// construct / destruct / copy
			vector_iterator(void);
			vector_iterator(T* p);
			vector_iterator(const vector_iterator& other);
			vector_iterator(const vector_iterator<T, T*, T&>& other);
			~vector_iterator();
			vector_iterator& operator=(const vector_iterator& other);

			// input_iterator (== && !=)
			reference operator*(void) const;
			pointer operator->(void) const;
	
			// forward_iterator (default constructor)

			// bidirectional_iterator
			vector_iterator& operator++(void);
			vector_iterator operator++(int);
			vector_iterator& operator--(void);
			vector_iterator operator--(int);

			// random_access_iterator
			vector_iterator& operator+=(difference_type n);
			vector_iterator operator+(difference_type n) const;
			vector_iterator& operator-=(difference_type n);
			vector_iterator operator-(difference_type n) const;
			difference_type operator-(const vector_iterator&);
			reference operator[](difference_type n) const;
			bool operator<(const vector_iterator&) const;
			bool operator>(const vector_iterator&) const;
			bool operator<=(const vector_iterator&) const;
			bool operator>=(const vector_iterator&) const;

			// getter
			T* base(void) const;
		private:
			T*	_ptr;
	};
	// non-members
	template <class T, class Pointer, class Reference>
	vector_iterator<T, Pointer, Reference> operator+(typename vector_iterator<T, Pointer, Reference>::difference_type n, const vector_iterator<T, Pointer, Reference>& it);
	template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
	bool operator==(const vector_iterator<T, Pointer1, Reference1>& a, const vector_iterator<T, Pointer2, Reference2>& b);
	template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
	bool operator!=(const vector_iterator<T, Pointer1, Reference1>& a, const vector_iterator<T, Pointer2, Reference2>& b);
}

#include "vector_iterator.tpp"

#endif	