#ifndef LIST_HPP
#define LIST_HPP

#include <memory>

#include "cstddef.hpp"
#include "type_traits.hpp"
#include "list_iterator.hpp"
#include "list_node.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<Node<T> > >
	class list
	{
		public:
			// types:
			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef T										value_type;
			typedef ft::size_t								size_type;
			typedef ft::ptrdiff_t							difference_type;
			typedef Allocator								allocator_type;
			typedef list_iterator<T>						iterator;
			typedef list_iterator<T, const T*, const T&>	const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			// construct/copy/destroy:
			explicit list(const Allocator& = Allocator());
			explicit list(size_type n, const T& value = T(), const Allocator& = Allocator());
			template <class InputIterator>
			list(InputIterator first, InputIterator last, const Allocator& = Allocator());
			list(const list<T,Allocator>& x);
			~list();
			list<T,Allocator>& operator=(const list<T,Allocator>& x);
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last);
			void assign(size_type n, const T& t);
			allocator_type get_allocator() const;
			// iterators:
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;
			// capacity:
			bool empty() const;
			size_type size() const;
			size_type max_size() const;
			void resize(size_type sz, T c = T());
			// element access:
			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;
			// modifiers:
			void push_front(const T& x);
			void pop_front();
			void push_back(const T& x);
			void pop_back();
			iterator insert(iterator position, const T& x);
			void insert(iterator position, size_type n, const T& x);
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last);
			iterator erase(iterator position);
			iterator erase(iterator position, iterator last);
			void swap(list<T,Allocator>&);
			void clear();
			// list operations:
			void splice(iterator position, list<T,Allocator>& x);
			void splice(iterator position, list<T,Allocator>& x, iterator i);
			void splice(iterator position, list<T,Allocator>& x, iterator first, iterator last);
			void remove(const T& value);
			template <class Predicate> void remove_if(Predicate pred);
			void unique();
			template <class BinaryPredicate>
			void unique(BinaryPredicate binary_pred);
			void merge(list<T,Allocator>& x);
			template <class Compare> void merge(list<T,Allocator>& x, Compare comp);
			void sort();
			template <class Compare> void sort(Compare comp);
			void reverse();
		private:
			Allocator	_allocator;
			size_type	_size;
			Node<T>*	_head;
			Node<T>*	_tail;
	};
	// non-members
	template <class T, class Allocator>
	bool operator==(const list<T,Allocator>& x, const list<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator< (const list<T,Allocator>& x, const list<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator!=(const list<T,Allocator>& x, const list<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator> (const list<T,Allocator>& x, const list<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator>=(const list<T,Allocator>& x, const list<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator<=(const list<T,Allocator>& x, const list<T,Allocator>& y);
	// specialized algorithms:
	template <class T, class Allocator>
	void swap(list<T,Allocator>& x, list<T,Allocator>& y);
			
}

#include "list.tpp"

#endif