#ifndef FUNCTIONAL_HPP
#define FUNCTIONAL_HPP

namespace ft
{
	template <class Arg1, class Arg2, class Result>
	struct binary_function
	{
		typedef Arg1	first_argument_type;
		typedef Arg2	second_argument_type;
		typedef Result	result_type;
	};

	template <class T>
	struct equal_to : public binary_function<T, T, bool>
	{
		bool operator() (const T& lhs, const T& rhs) const
		{
			return lhs == rhs;
		}
	};

	template <class T>
	struct not_equal_to : public binary_function<T, T, bool>
	{
		bool operator() (const T& lhs, const T& rhs) const
		{
			return lhs != rhs;
		}
	};

	template <class T>
	struct greater : public binary_function<T, T, bool>
	{
		bool operator() (const T& lhs, const T& rhs) const
		{
			return lhs > rhs;
		}
	};

	template <class T>
	struct less : public binary_function<T, T, bool>
	{
		bool operator() (const T& lhs, const T& rhs) const
		{
			return lhs < rhs;
		}
	};

	template <class T>
	struct greater_equal : public binary_function<T, T, bool>
	{
		bool operator() (const T& lhs, const T& rhs) const
		{
			return lhs >= rhs;
		}
	};

	template <class T>
	struct less_equal : public binary_function<T, T, bool>
	{
		bool operator() (const T& lhs, const T& rhs) const
		{
			return lhs <= rhs;
		}
	};
}

#endif