#ifndef SET_HPP
#define SET_HPP

#include <memory>

#include "functional.hpp"
#include "rbtree.hpp"

namespace ft
{
	// Set

	template <class Key, class Compare = less<Key>, class Allocator = std::allocator<Key> >
	class set
	{
		private:
			typedef detail::rbtree<Key>	tree;
		public:
			// types:
			typedef Key			key_type;
			typedef Key			value_type;
			typedef Compare		key_compare;
			typedef Compare		value_compare;
			typedef Allocator	allocator_type;

			typedef typename Allocator::reference		reference;	
			typedef typename Allocator::const_reference	const_reference;
			typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;

			typedef typename tree::iterator					iterator;
			typedef typename tree::const_iterator 			const_iterator;
			typedef typename tree::reverse_iterator			reverse_iterator;
			typedef typename tree::const_reverse_iterator	const_reverse_iterator;
			typedef typename tree::size_type				size_type;
			typedef typename tree::difference_type			difference_type;
			// construct/copy/destroy:
			explicit set(const Compare& comp = Compare(), const Allocator& = Allocator());
			template <class InputIterator>
			set(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& = Allocator());
			set(const set& x);
			~set();
			set<Key,Compare,Allocator>& operator=(const set<Key,Compare,Allocator>& x);
			allocator_type get_allocator() const;
			// iterators:
			iterator				begin();
			const_iterator			begin() const;
			iterator				end();
			const_iterator			end() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;
			// capacity:
			bool		empty() const;
			size_type	size() const;
			size_type	max_size() const;
			// modifiers:
			pair<iterator,bool> insert(const value_type& x);
			iterator			insert(iterator position, const value_type& x);
			template <class InputIterator>
			void				insert(InputIterator first, InputIterator last);
			void		erase(iterator position);
			size_type	erase(const key_type& x);
			void		erase(iterator first, iterator last);
			void		swap(set<Key,Compare,Allocator>&);
			void		clear();
			// observers:
			key_compare		key_comp() const;
			value_compare	value_comp() const;
			// set operations:
			iterator				find(const key_type& x) const;
			size_type				count(const key_type& x) const;
			iterator				lower_bound(const key_type& x) const;
			iterator				upper_bound(const key_type& x) const;
			pair<iterator,iterator>	equal_range(const key_type& x) const;
		private:

	};
	template <class Key, class Compare, class Allocator>
	bool operator==(const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y);
	template <class Key, class Compare, class Allocator>
	bool operator< (const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y);
	template <class Key, class Compare, class Allocator>
	bool operator!=(const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y);
	template <class Key, class Compare, class Allocator>
	bool operator> (const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y);
	template <class Key, class Compare, class Allocator>
	bool operator>=(const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y);
	template <class Key, class Compare, class Allocator>
	bool operator<=(const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y);
	// specialized algorithms:
	template <class Key, class Compare, class Allocator>
	void swap(set<Key,Compare,Allocator>& x, set<Key,Compare,Allocator>& y);

	// Multiset

	template <class Key, class Compare = less<Key>, class Allocator = std::allocator<Key> >
	class multiset
	{
		private:
			typedef detail::rbtree<Key>	tree;
		public:
			// types:
			typedef Key			key_type;
			typedef Key			value_type;
			typedef Compare		key_compare;
			typedef Compare		value_compare;
			typedef Allocator	allocator_type;

			typedef typename Allocator::reference		reference;
			typedef typename Allocator::const_reference	const_reference;
			typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;

			typedef typename tree::iterator					iterator;
			typedef typename tree::const_iterator 			const_iterator;
			typedef typename tree::reverse_iterator			reverse_iterator;
			typedef typename tree::const_reverse_iterator	const_reverse_iterator;
			typedef typename tree::size_type				size_type;
			typedef typename tree::difference_type			difference_type;
			// construct/copy/destroy:
			explicit multiset(const Compare& comp = Compare(), const Allocator& = Allocator());
			template <class InputIterator>
			multiset(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& = Allocator());
			multiset(const multiset<Key,Compare,Allocator>& x);
			~multiset();
			multiset<Key,Compare,Allocator>& operator=(const multiset<Key,Compare,Allocator>& x);
			allocator_type get_allocator() const;
			// iterators:
			iterator				begin();
			const_iterator			begin() const;
			iterator				end();
			const_iterator			end() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;
			// capacity:
			bool		empty() const;
			size_type	size() const;
			size_type	max_size() const;
			// modifiers:
			iterator	insert(const value_type& x);
			iterator	insert(iterator position, const value_type& x);
			template <class InputIterator>
			void		insert(InputIterator first, InputIterator last);
			void		erase(iterator position);
			size_type	erase(const key_type& x);
			void		erase(iterator first, iterator last);
			void		swap(multiset<Key,Compare,Allocator>&);
			void		clear();
			// observers:
			key_compare		key_comp() const;
			value_compare	value_comp() const;
			// set operations:
			iterator				find(const key_type& x) const;
			size_type				count(const key_type& x) const;
			iterator				lower_bound(const key_type& x) const;
			iterator				upper_bound(const key_type& x) const;
			pair<iterator,iterator>	equal_range(const key_type& x) const;
		private:
	};
	template <class Key, class Compare, class Allocator>
	bool operator==(const multiset<Key,Compare,Allocator>& x, const multiset<Key,Compare,Allocator>& y);
	template <class Key, class Compare, class Allocator>
	bool operator< (const multiset<Key,Compare,Allocator>& x, const multiset<Key,Compare,Allocator>& y);
	template <class Key, class Compare, class Allocator>
	bool operator!=(const multiset<Key,Compare,Allocator>& x, const multiset<Key,Compare,Allocator>& y);
	template <class Key, class Compare, class Allocator>
	bool operator> (const multiset<Key,Compare,Allocator>& x, const multiset<Key,Compare,Allocator>& y);
	template <class Key, class Compare, class Allocator>
	bool operator>=(const multiset<Key,Compare,Allocator>& x, const multiset<Key,Compare,Allocator>& y);
	template <class Key, class Compare, class Allocator>
	bool operator<=(const multiset<Key,Compare,Allocator>& x, const multiset<Key,Compare,Allocator>& y);
	// specialized algorithms:
	template <class Key, class Compare, class Allocator>
	void swap(multiset<Key,Compare,Allocator>& x, multiset<Key,Compare,Allocator>& y);
}

#include "set.tpp"
#include "multiset.tpp"

#endif