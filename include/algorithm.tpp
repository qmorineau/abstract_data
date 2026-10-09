#ifndef ALGORITHM_TPP
#define ALGORITHM_TPP

namespace ft
{
	template <class Input1, class Input2>
	bool lexicographical_compare(Input1 first1, Input1 last1, Input2 first2, Input2 last2)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
		{
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class Input1, class Input2, class Compare>
	bool lexicographical_compare(Input1 first1, Input1 last1, Input2 first2, Input2 last2, Compare comp)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
		{
			if (comp(*first1, *first2))
				return true;
			if (comp(*first2, *first1))
				return false;
		}
	    return (first1 == last1) && (first2 != last2);
	}

	template <class T>
	void swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template <class T>
	const T& min(const T& a, const T& b)
	{
		return (b < a) ? b : a;
	}

	template <class T, class Compare>
	const T& min(const T& a, const T& b, Compare comp)
	{
		return (comp(b, a)) ? b : a;
	}

	template <class T>
	const T& max(const T& a, const T& b)
	{
		return (a < b) ? b : a;
	}

	template <class T, class Compare>
	const T& max(const T& a, const T& b, Compare comp)
	{
		return (comp(a, b)) ? b : a;
	}
}

#endif