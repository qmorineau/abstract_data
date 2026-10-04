#ifndef FUNCTIONAL_HPP
#define FUNCTIONAL_HPP

namespace ft
{
	template <class T>
	struct equal_to
	{
		bool operator() (const T& lhs, const T& rhs) const
		{
			return lhs == rhs;
		}
	};

	template <class T>
	struct not_equal_to
	{
		bool operator() (const T& lhs, const T& rhs) const
		{
			return lhs != rhs;
		}
	};

	template <class T>
	struct greater
	{
		bool operator() (const T& lhs, const T& rhs) const
		{
			return lhs > rhs;
		}
	};

	template <class T>
	struct less
	{
		bool operator() (const T& lhs, const T& rhs) const
		{
			return lhs < rhs;
		}
	};

	template <class T>
	struct greater_equal
	{
		bool operator() (const T& lhs, const T& rhs) const
		{
			return lhs >= rhs;
		}
	};

	template <class T>
	struct less_equal
	{
		bool operator() (const T& lhs, const T& rhs) const
		{
			return lhs <= rhs;
		}
	};
}

#endif