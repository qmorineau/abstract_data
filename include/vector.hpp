#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

#include "stdexcept.hpp"
#include "string.hpp"
#include "algorithm.hpp"
#include "cstddef.hpp"
#include "type_traits.hpp"
#include "vector_iterator.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			// types
			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef T										value_type;
			typedef ft::size_t								size_type;
			typedef ft::ptrdiff_t							difference_type;
			typedef Allocator								allocator_type;
			typedef vector_iterator<T>						iterator;
			typedef vector_iterator<T, const T*, const T&>	const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			// construct / copy / destroy
			explicit vector(const Allocator& = Allocator());
			explicit vector(size_type n, const T& value = T(), const Allocator& = Allocator());
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const Allocator& = Allocator(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0);
			vector(const vector<T,Allocator>& x);
			~vector();
			vector<T,Allocator>& operator=(const vector<T,Allocator>& x);
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0);
			void assign(size_type n, const T& u);
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
			// capacity
			size_type size() const;
			size_type max_size() const;
			void resize(size_type sz, T c = T());
			size_type capacity() const;
			bool empty() const;
			void reserve(size_type n);
			// element access
			reference operator[](size_type n);
			const_reference operator[](size_type n) const;
			const_reference at(size_type n) const;
			reference at(size_type n);
			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;
			T* data();
			const T* data() const;
			// modifiers
			void push_back(const T& x);
			void pop_back();
			iterator insert(iterator position, const T& x);
			void insert(iterator position, size_type n, const T& x);
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0);
			iterator erase(iterator position);
			iterator erase(iterator first, iterator last);
			void swap(vector<T,Allocator>&);
			void clear();
		private:
			T*				_data;
			size_type		_size;
			allocator_type	_allocator;
			size_type		_capacity;

			void range_check(size_type n);
	};
	// operator
	template <class T, class Allocator>
	bool operator==(const ft::vector<T,Allocator>& x,
		const ft::vector<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator< (const ft::vector<T,Allocator>& x,
		const ft::vector<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator!=(const ft::vector<T,Allocator>& x,
		const ft::vector<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator> (const ft::vector<T,Allocator>& x,
		const ft::vector<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator>=(const ft::vector<T,Allocator>& x,
		const ft::vector<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator<=(const ft::vector<T,Allocator>& x,
		const ft::vector<T,Allocator>& y);
	// specialized algorithms:
	template <class T, class Allocator>
	void swap(ft::vector<T,Allocator>& x, ft::vector<T,Allocator>& y);
}

#include "vector.tpp"

#endif