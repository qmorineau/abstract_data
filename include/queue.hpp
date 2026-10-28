#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "deque.hpp"
// #include "vector.hpp"
// #include "functional.hpp"

namespace ft
{
	// Queue

	template <class T, class Container = deque<T> >
	class queue {
		public:
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;
			typedef Container 							container_type;
		protected:
			Container c;
		public:
			explicit queue(const Container& = Container());
			bool empty() const;
			size_type size() const;
			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;
			void push(const value_type& x);
			void pop();

			// friends
			template <class U, class C>
			friend bool operator==(const queue<U, C>& x, const queue<U, C>& y);
			template <class U, class C>
			friend bool operator!=(const queue<U, C>& x, const queue<U, C>& y);
			template <class U, class C>
			friend bool operator<(const queue<U, C>& x, const queue<U, C>& y);
			template <class U, class C>
			friend bool operator>(const queue<U, C>& x, const queue<U, C>& y);
			template <class U, class C>
			friend bool operator>=(const queue<U, C>& x, const queue<U, C>& y);
			template <class U, class C>
			friend bool operator<=(const queue<U, C>& x, const queue<U, C>& y);
	};
	template <class T, class C>
	bool operator==(const queue<T, C>& x, const queue<T, C>& y);
	template <class T, class C>
	bool operator< (const queue<T, C>& x, const queue<T, C>& y);
	template <class T, class C>
	bool operator!=(const queue<T, C>& x, const queue<T, C>& y);
	template <class T, class C>
	bool operator> (const queue<T, C>& x, const queue<T, C>& y);
	template <class T, class C>
	bool operator>=(const queue<T, C>& x, const queue<T, C>& y);
	template <class T, class C>
	bool operator<=(const queue<T, C>& x, const queue<T, C>& y);

	// Priority Queue

	// template <class T, class Container = vector<T>, class Compare = ft::less<typename Container::value_type> >
	// class priority_queue {
	// 	public:
	// 		typedef typename Container::value_type value_type;
	// 		typedef typename Container::size_type size_type;
	// 		typedef Container container_type;
	// 	protected:
	// 		Container c;
	// 		Compare comp;
	// 	public:
	// 		explicit priority_queue(const Compare& x = Compare(), const Container& = Container());
	// 		template <class InputIterator>
	// 		priority_queue(InputIterator first, InputIterator last, const Compare& x = Compare(), const Container& = Container());
	// 		bool empty() const { return c.empty(); }
	// 		size_type size() const { return c.size(); }
	// 		const value_type& top() const { return c.front(); }
	// 		void push(const value_type& x);
	// 		void pop();
	// };
}

#include "queue.tpp"
// #include "priority_queue.tpp"

#endif