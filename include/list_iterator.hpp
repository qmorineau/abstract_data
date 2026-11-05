#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

#include "iterator.hpp"
#include "cstddef.hpp"
#include "list_node.hpp"

namespace ft
{
	namespace detail
	{
		template <class T, class Pointer = T*, class Reference = T&>
		class list_iterator : public iterator<bidirectional_iterator_tag, T, ptrdiff_t, Pointer, Reference>
		{
			public:
				typedef Pointer						pointer;
				typedef Reference					reference;
				typedef T 							value_type;
				typedef ptrdiff_t					difference_type;
				typedef bidirectional_iterator_tag	iterator_category;
				typedef list_node<T>*				node_pointer;

				// construct / destruct / copy
				list_iterator(void);
				list_iterator(list_node<T>* p);
				template <class T2, class Pointer2, class Reference2>
				list_iterator(const list_iterator<T2, Pointer2, Reference2>& other);
				~list_iterator();
				list_iterator& operator=(const list_iterator& other);

				// input_iterator (== && !=)
				reference operator*(void) const;
				pointer operator->(void) const;
		
				// forward_iterator (default constructor)

				// bidirectional_iterator
				list_iterator& operator++(void);
				list_iterator operator++(int);
				list_iterator& operator--(void);
				list_iterator operator--(int);

				// getter
				node_pointer base(void) const;
			private:
				node_pointer _current;
		};
		// non-members

		template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
		bool operator==(const list_iterator<T, Pointer1, Reference1>& x, const list_iterator<T, Pointer2, Reference2>& y);
		
		template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
		bool operator!=(const list_iterator<T, Pointer1, Reference1>& x, const list_iterator<T, Pointer2, Reference2>& y);
	}
}

#include "list_iterator.tpp"

#endif