#ifndef UTILITY_TPP
#define UTILITY_TPP

namespace ft
{
	template <class T1, class T2>
	ft::pair<T1, T2>::pair()
		: first(), second() 
	{}

	template <class T1, class T2>
	ft::pair<T1, T2>::pair(const T1& x, const T2& y)
		: first(x), second(y)
	{}

	template <class T1, class T2>
	template <class U, class V>
	ft::pair<T1, T2>::pair(const pair<U, V>& p)
		: first(p.first), second(p.second)
	{}

	template <class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return ft::pair<T1, T2>(x, y);
	}

	template <class T1, class T2>
	bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		if (lhs.first < rhs.first)
			return true;
		else if (rhs.first < lhs.first)
			return false;
		else if (lhs.second < rhs.second)
			return true;
		return false;
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(lhs < rhs);
	}
}

#endif