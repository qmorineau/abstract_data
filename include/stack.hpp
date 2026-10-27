#ifndef STACK_HPP
#define STACK_HPP

#include "deque.hpp"

namespace ft
{
	template <class T, class Container = ft::deque<T> >
	class stack
	{
		public:
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;
			typedef Container							container_type;
		protected:
			Container c;
		public:
			explicit stack(const Container& = Container());
			bool empty() const;
			size_type size() const;
			value_type& top();
			const value_type& top() const;
			void push(const value_type& x);
			void pop();

			// non member
			template <class U, class C>
			friend bool operator==(const stack<U, C>& x, const stack<U, C>& y);
			template <class U, class C>
			friend bool operator!=(const stack<U, C>& x, const stack<U, C>& y);
			template <class U, class C>
			friend bool operator<(const stack<U, C>& x, const stack<U, C>& y);
			template <class U, class C>
			friend bool operator>(const stack<U, C>& x, const stack<U, C>& y);
			template <class U, class C>
			friend bool operator>=(const stack<U, C>& x, const stack<U, C>& y);
			template <class U, class C>
			friend bool operator<=(const stack<U, C>& x, const stack<U, C>& y);
	};
}

#include "stack.tpp"

#endif