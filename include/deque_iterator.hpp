#ifndef DEQUE_ITERATOR_HPP
#define DEQUE_ITERATOR_HPP

#include "iterator.hpp"
#include "cstddef.hpp"

template <class T, class Allocator = std::allocator<T> >
class deque;

namespace ft
{
	template <class T, class Pointer = T*, class Reference = T&>
	class deque_iterator : public iterator<ft::random_access_iterator_tag, T, ft::ptrdiff_t, Pointer, Reference>
	{
		public:
			typedef Pointer								pointer;
			typedef Reference							reference;
			typedef T 									value_type;
			typedef ft::ptrdiff_t						difference_type;
			typedef ft::random_access_iterator_tag		iterator_category;
 
			// construct / destruct / copy
			deque_iterator(void);
			deque_iterator(deque<T>* owner, ft::size_t map_idx, ft::size_t offset);
			template <class T2, class Pointer2, class Reference2>
			deque_iterator(const deque_iterator<T2, Pointer2, Reference2>& other);
			~deque_iterator();
			deque_iterator& operator=(const deque_iterator& other);

			// input_iterator (== && !=)
			reference operator*(void) const;
			pointer operator->(void) const;
	
			// forward_iterator (default constructor)

			// bidirectional_iterator
			deque_iterator& operator++(void);
			deque_iterator operator++(int);
			deque_iterator& operator--(void);
			deque_iterator operator--(int);

			// random_access_iterator
			deque_iterator& operator+=(difference_type n);
			deque_iterator operator+(difference_type n) const;
			deque_iterator& operator-=(difference_type n);
			deque_iterator operator-(difference_type n) const;
			difference_type operator-(const deque_iterator&) const;
			reference operator[](difference_type n) const;
			bool operator<(const deque_iterator&) const;
			bool operator>(const deque_iterator&) const;
			bool operator<=(const deque_iterator&) const;
			bool operator>=(const deque_iterator&) const;

			// getter
			pointer base(void) const;
		private:
			deque<T>*	_owner;
			ft::size_t	_map_idx;
			ft::size_t	_offset;
	};
	// non-members
	template <class T, class Pointer, class Reference>
	deque_iterator<T, Pointer, Reference>
	operator+(typename deque_iterator<T, Pointer, Reference>::difference_type n, const deque_iterator<T, Pointer, Reference>& it);
	
	template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
	bool operator==(const deque_iterator<T, Pointer1, Reference1>& x, const deque_iterator<T, Pointer2, Reference2>& y);
	
	template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
	bool operator!=(const deque_iterator<T, Pointer1, Reference1>& x, const deque_iterator<T, Pointer2, Reference2>& y);
}

// #include "deque_iterator.tpp"

#endif