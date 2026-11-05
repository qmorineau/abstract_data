#ifndef RBTREE_ITERATOR_HPP
#define RBTREE_ITERATOR_HPP

#include "iterator.hpp"
#include "cstddef.hpp"

#include "rbtree_node.hpp"

namespace ft
{
	namespace detail
	{
		template <class T, class Pointer = T*, class Reference = T&>
		class rbtree_iterator : public iterator<ft::bidirectional_iterator_tag, T, ft::ptrdiff_t, Pointer, Reference>
		{
			public:
				typedef Pointer								pointer;
				typedef Reference							reference;
				typedef T 									value_type;
				typedef ft::ptrdiff_t						difference_type;
				typedef ft::bidirectional_iterator_tag		iterator_category;

				// construct / destruct / copy
				rbtree_iterator(void);
				rbtree_iterator(rbtree_node<T>* p, rbtree_node<T>* sentinelle);
				template <class T2, class Pointer2, class Reference2>
				rbtree_iterator(const rbtree_iterator<T2, Pointer2, Reference2>& other);
				~rbtree_iterator();
				rbtree_iterator& operator=(const rbtree_iterator& other);

				// input_iterator (== && !=)
				reference operator*(void) const;
				pointer operator->(void) const;
		
				// forward_iterator (default constructor)

				// bidirectional_iterator
				rbtree_iterator& operator++(void);
				rbtree_iterator operator++(int);
				rbtree_iterator& operator--(void);
				rbtree_iterator operator--(int);

				// getter
				rbtree_node<T>* base(void) const;
			private:
				rbtree_node<T>* _current;
				rbtree_node<T>* _null;
		};

		// non-members

		template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
		bool operator==(const rbtree_iterator<T, Pointer1, Reference1>& x, const rbtree_iterator<T, Pointer2, Reference2>& y);
		
		template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
		bool operator!=(const rbtree_iterator<T, Pointer1, Reference1>& x, const rbtree_iterator<T, Pointer2, Reference2>& y);
	}
}

#include "rbtree_iterator.tpp"

#endif
