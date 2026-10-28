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

	template <class RandomIt, class Compare>
	void make_heap(RandomIt first, RandomIt last, Compare comp)
	{
		typedef typename iterator_traits<RandomIt>::difference_type diff_t;

		diff_t n = last - first;
		
		if (n < 2)
			return;
		for (diff_t start = n / 2; start > 0; --start)
		{
			diff_t curr = start - 1;
			while (true)
			{
				diff_t largest = curr;
				diff_t left_child = curr * 2 + 1;
				diff_t right_child = curr * 2 + 2;

				if (left_child < n && comp(first[largest], first[left_child]))
					largest = left_child;
				if (right_child < n && comp(first[largest], first[right_child]))
					largest = right_child;
				if (curr == largest)
					break;
				ft::swap(first[curr], first[largest]);
				curr = largest;
			}
		}
	}

	template <class RandomIt, class Compare>
	void push_heap(RandomIt first, RandomIt last, Compare comp)
	{
		typedef typename iterator_traits<RandomIt>::difference_type diff_t;

		diff_t n = last - first;
		if (n < 2)
			return;
		diff_t curr = n - 1;
		while (curr > 0)
		{
			diff_t parent = (curr - 1) / 2;
			if (!comp(first[parent], first[curr]))
				break;
			ft::swap(first[parent], first[curr]);
			curr = parent;
		}
	}

	template <class RandomIt, class Compare>
	void pop_heap(RandomIt first, RandomIt last, Compare comp)
	{
		typedef typename iterator_traits<RandomIt>::difference_type diff_t;

		diff_t n = last - first;
		if (n < 2)
			return;
		diff_t size = n - 1;
		diff_t curr = 0;
		ft::swap(first[0], first[size]);
		while (true)
		{
			diff_t largest = curr;
			diff_t left_child = curr * 2 + 1;
			diff_t right_child = curr * 2 + 2;
			if (left_child < size && comp(first[largest], first[left_child]))
				largest = left_child;
			if (right_child < size && comp(first[largest], first[right_child]))
				largest = right_child;
			if (largest == curr)
				break;
			ft::swap(first[curr], first[largest]);
			curr = largest;
		}
	}
}

#endif