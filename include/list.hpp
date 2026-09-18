#ifndef LIST_HPP
#define LIST_HPP

#include <memory>

namespace ft
{
	template <class T, class Allocator = std::allocator<T>>
	class list
	{
		public:
			list();
			~list();
			operator=();
			assign();
			get_allocator();
			// element access
			front();
			back();
			// iterators
			begin();
			end();
			rbegin();
			rend();
			// capacity
			empty();
			size();
			max_size();
			// modifiers
			clear();
			insert();
			erase();
			push_back();
			pop_back();
			push_front();
			pop_front();
			resize();
			swap();
			// operations
			merge();
			splice();
			remove();
			remove_if();
			reverse();
			unique();
			sort();
			// non member
			static operator==();
			static operator!=();
			static operator<();
			static operator<=();
			static operator>();
			static operator>=();
			// std::swap(std::list) pas sur de ca
		private:
			T							value_type;
			Allocator					allocator_type;
			size_t						size_type;
			// difference type
			value_type& 				reference;
			const value_type&			const_reference;
			Allocator::pointer			pointer;
			Allocator::const_pointer	const_pointer;
			// iterator
			// const iterator
			// reverse iterator
			// const reverse iterator
	};
}

#include "list.tpp"

#endif