#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

#include "cstddef.hpp"

namespace ft
{
	// ========================
	// Standard Iterator Tag
	// ========================
	typedef std::input_iterator_tag			input_iterator_tag;
	typedef std::output_iterator_tag		output_iterator_tag;
	typedef std::forward_iterator_tag		forward_iterator_tag;
	typedef std::bidirectional_iterator_tag bidirectional_iterator_tag;
	typedef std::random_access_iterator_tag random_access_iterator_tag;

	// ========================
	// Basic Iterator
	// ========================
	template <class Category, class T, class Distance = ft::ptrdiff_t, class Pointer = T*, class Reference = T&> 
	struct iterator {
		typedef T 			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	// ========================
	// Iterator Traits
	// ========================
	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t					difference_type;
		typedef T 							value_type;
		typedef const T* 					pointer;
		typedef const T&					reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	// template <class T>
	// struct iterator_traits<BinaryTreeIterator<T> >
	// {
	// 	typedef ptrdiff_t difference_type;
	// 	typedef T value_type;
	// 	typedef T* pointer;
	// 	typedef T& reference;
	// 	typedef bidirectional_iterator_tag iterator_category;
	// };

	// ========================
	//      Reverse Iterator
	// ========================
	template <class Iterator>
	class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category,
		typename iterator_traits<Iterator>::value_type,
		typename iterator_traits<Iterator>::difference_type,
		typename iterator_traits<Iterator>::pointer,
		typename iterator_traits<Iterator>::reference>
	{
		protected:
			Iterator current;
		public:
			typedef Iterator											iterator_type;
			typedef typename iterator_traits<Iterator>::difference_type difference_type;
			typedef typename iterator_traits<Iterator>::reference		reference;
			typedef typename iterator_traits<Iterator>::pointer			pointer;
			reverse_iterator();
			explicit reverse_iterator(Iterator x);
			template <class U>
			reverse_iterator(const reverse_iterator<U>& u);
			Iterator base() const; // explicit
			reference operator*(void) const;
			pointer operator->(void) const;
			reverse_iterator& operator++(void);
			reverse_iterator operator++(int);
			reverse_iterator& operator--(void);
			reverse_iterator operator--(int);
			reverse_iterator operator+ (difference_type n) const;
			reverse_iterator& operator+=(difference_type n);
			reverse_iterator operator-(difference_type n) const;
			reverse_iterator& operator-=(difference_type n);
			reference operator[](difference_type n) const;
	};

	template <class Iterator1, class Iterator2>
	bool
	operator==(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y);

	template <class Iterator1, class Iterator2>
	bool
	operator<(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y);

	template <class Iterator1, class Iterator2>
	bool
	operator!=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y);

	template <class Iterator1, class Iterator2>
	bool
	operator>(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y);

	template <class Iterator1, class Iterator2>
	bool
	operator>=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y);

	template <class Iterator1, class Iterator2>
	bool
	operator<=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y);

	template <class Iterator1, class Iterator2>
	typename reverse_iterator<Iterator1>::difference_type
	operator-(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y);

	template <class Iterator>
	reverse_iterator<Iterator>
	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& x);

	template <class InputIt>
	typename iterator_traits<InputIt>::difference_type 
    distance(InputIt first, InputIt last);

	namespace detail
	{
		template <class It>
		typename iterator_traits<It>::difference_type
		do_distance(It first, It last, input_iterator_tag);

		template <class It>
		typename iterator_traits<It>::difference_type
		do_distance(It first, It last, random_access_iterator_tag);
	}
}

#include "iterator.tpp"

#endif