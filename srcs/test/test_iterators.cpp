#include "test.hpp"

#include "iterator.hpp"

// Forward iterator

template <class Iterator>
struct test_it_is_equal
{
	static void run(Iterator first, Iterator last)
	{
		std::cout << "===== operator==(it1, it2) =====" << std::endl;
		Iterator it = first;
		std::cout << (first == first) << "|" << (first == last) << "|";
		for (; !(it == last); ++it)
			std::cout << (it == first) << "|";
		std::cout << (last == last) << std::endl;
	}
};

template <class Iterator>
struct test_it_is_different
{
	static void run(Iterator first, Iterator last)
	{
		std::cout << "===== operator!=(it1, it2) =====" << std::endl;
		Iterator it = first;
		std::cout << (first != first) << "|" << (first != last) << "|";
		for (; first != last; ++first)
			std::cout << (it != first) << "|";
		std::cout << (last != last) << std::endl;
	}
};

template <class Iterator>
struct test_it_dereference
{
	static void run(Iterator first, Iterator last)
	{
		std::cout << "===== Iterator::operator*() =====" << std::endl;
		for (; first != last; ++first)
			std::cout << *first << "|";
		std::cout << std::endl;
	}
};

template <class Iterator>
struct test_it_pre_increment
{
	static void run(Iterator first, Iterator last)
	{
		std::cout << "===== Iterator::operator++(void) =====" << std::endl;
		for (; first != last;)
		{
			Iterator& ret = ++first;
			std::cout << (&ret == &first) << "|";
			if (ret != last)
				std::cout << "it" << *first;
			std::cout << "|";
		}
		std::cout << std::endl;
	}
};

template <class Iterator>
struct test_it_post_increment
{
	static void run(Iterator first, Iterator last)
	{
		std::cout << "===== Iterator::operator++(int) =====" << std::endl;
		for (; first != last;)
		{
			Iterator ret = first++;
			if (ret != last)
				std::cout << "ret" << *ret;
			std::cout << "|";
			if (first != last)
				std::cout << "it" << *first;
			std::cout << "|";
		}
		std::cout << std::endl;
	}
};

// bidirectional iterator

template <class Iterator>
struct test_it_pre_decrement
{
	static void run(Iterator first, Iterator last)
	{
		std::cout << "===== Iterator::operator--(void) =====" << std::endl;
		Iterator second = last;
		for (; first != second; )
		{
			Iterator& ret = --second;
			std::cout << (&ret == &second) << "|";
			if (ret != last)
				std::cout << "ret" << *ret << "|";
		}
		std::cout << std::endl;
	}
};

template <class Iterator>
struct test_it_post_decrement
{
	static void run(Iterator first, Iterator last)
	{
		std::cout << "===== Iterator::operator--(int) =====" << std::endl;
		Iterator second = last;
		for (; first != second; )
		{
			Iterator ret = second--;
			if (ret != last)
				std::cout << "ret" << *ret;
			std::cout << "|";
			if (second != first)
				std::cout << "it" << *second;
			std::cout << "|";
		}
		std::cout << std::endl;
	}
};

// random access iterator

template <class Iterator>
struct test_it_increment_n
{
	static void run(Iterator first, Iterator last)
	{
		std::cout << "===== Iterator::operator+(n) =====" << std::endl;
		typedef typename Iterator::difference_type difference_type;
		difference_type max_diff = std::distance(first, last);
		for (difference_type i = 0; i < max_diff; ++i)
		{
			Iterator tmp = first;
			Iterator ret = tmp + i;
			std::cout << *ret  << "|";
		}
		std::cout << std::endl << "negative nbr: ";
		for (difference_type i = -1; i >= -max_diff; --i)
		{
			Iterator tmp = last;
			Iterator ret = tmp + i;
			std::cout << *ret  << "|";
		}
		std::cout << std::endl;
	}
};

template <class Iterator>
struct test_it_n_add_iterator
{
	static void run(Iterator first, Iterator last)
	{
		std::cout << "===== operator+(n, it) =====" << std::endl;
		typedef typename Iterator::difference_type difference_type;
		difference_type max_diff = std::distance(first, last);
		for (difference_type i = 0; i < max_diff; ++i)
		{
			Iterator ret1 = i + first;
			Iterator ret2 = first + i;
			std::cout << (ret1 == ret2) << "|" << *ret1 << "|" << *ret2 << "|";
		}
		std::cout << std::endl << "negative nbr: ";
		for (difference_type i = -1; i >= -max_diff; --i)
		{
			Iterator ret1 = i + last;
			Iterator ret2 = last + i;
			std::cout << (ret1 == ret2) << "|" << *ret1 << "|" << *ret2 << "|";
		}
		std::cout << std::endl;
	}
};

template <class Iterator>
struct test_it_decrement_n
{
	static void run(Iterator first, Iterator last)
	{
		std::cout << "===== Iterator::operator-(n) =====" << std::endl;
		typedef typename Iterator::difference_type difference_type;
		difference_type max_diff = std::distance(first, last);
		for (difference_type i = 1; i <= max_diff; ++i)
		{
			Iterator tmp = last;
			Iterator ret = tmp - i;
			std::cout << *ret  << "|";
		}
		std::cout << std::endl << "negative nbr: ";
		for (difference_type i = -1; i > -max_diff; --i)
		{
			Iterator tmp = first;
			Iterator ret = tmp - i;
			std::cout << *ret  << "|";
		}
		std::cout << std::endl;
	}
};

template <class Iterator>
struct test_it_subtract_it
{
	static void run(Iterator first, Iterator last)
	{
		std::cout << "===== Iterator::operator-(it) =====" << std::endl;
		for (Iterator it1 = first; it1 != last; ++it1)
		{
			for (Iterator it2 = first; it2 != last; ++it2)
				std::cout << (it1 - it2) << "|" << (it2 - it1) << "|";
		}
		std::cout << std::endl;
	}
};

template <class Iterator>
struct test_it_add_n
{
	static void run(Iterator first, Iterator last)
	{
		std::cout << "===== Iterator::operator+=(n) =====" << std::endl;
		typedef typename Iterator::difference_type difference_type;
		difference_type max_diff = std::distance(first, last);
		for (difference_type i = 0; i < max_diff; ++i)
		{
			Iterator tmp = first;
			Iterator& ret = (tmp += i);
			std::cout << (&ret == &tmp) << "|" << *ret << "|";
		}
		std::cout << std::endl << "negative nbr: ";
		for (difference_type i = -1; i >= -max_diff; --i)
		{
			Iterator tmp = last;
			Iterator& ret = (tmp += i);
			std::cout << (&ret == &tmp) << "|" << *ret << "|";
		}
		std::cout << std::endl;
	}
};

template <class Iterator>
struct test_it_subtract_n
{
	static void run(Iterator first, Iterator last)
	{
		std::cout << "===== Iterator::operator-=(n) =====" << std::endl;
		typedef typename Iterator::difference_type difference_type;
		difference_type max_diff = std::distance(first, last);
		for (difference_type i = 1; i <= max_diff; ++i)
		{
			Iterator tmp = last;
			Iterator& ret = (tmp -= i);
			std::cout << (&ret == &tmp) << "|" << *ret << "|";
		}
		std::cout << std::endl << "negative nbr: ";
		for (difference_type i = 0; i > -max_diff; --i)
		{
			Iterator tmp = first;
			Iterator& ret = (tmp -= i);
			std::cout << (&ret == &tmp) << "|" << *ret << "|";
		}
		std::cout << std::endl;
	}
};

template <class Iterator>
struct test_it_access
{
	static void run(Iterator first, Iterator last)
	{
		std::cout << "===== Iterator::operator[](n) =====" << std::endl;
		typedef typename Iterator::difference_type difference_type;
		difference_type max_diff = std::distance(first, last);
		for (difference_type i = 0; i < max_diff; ++i)
			std::cout << first[i] << "|";
		std::cout << std::endl << "negative_nbr: ";
		for (difference_type i = -1; i >= -max_diff; --i)
			std::cout << last[i] << "|";
		std::cout << std::endl;
	}
};

#include "deque_position.hpp"

template <class Iterator>
struct test_it_lesser
{
	static void run(Iterator first, Iterator last)
	{
		std::cout << "===== Iterator::operator<(it) =====" << std::endl;
		for (Iterator it1 = first; it1 != last; ++it1)
		{
			for (Iterator it2 = first; it2 != last; ++it2)
				std::cout << (it1 < it2) << "|" << (it2 < it1) << "|";
		}
		std::cout << std::endl;
	}
};

template <class Iterator>
struct test_it_lesser_equal
{
	static void run(Iterator first, Iterator last)
	{
		std::cout << "===== Iterator::operator<=(it) =====" << std::endl;
		for (Iterator it1 = first; it1 != last; ++it1)
		{
			for (Iterator it2 = first; it2 != last; ++it2)
				std::cout << (it1 <= it2) << "|" << (it2 <= it1) << "|";
		}
		std::cout << std::endl;
	}
};

template <class Iterator>
struct test_it_greater
{
	static void run(Iterator first, Iterator last)
	{
		std::cout << "===== Iterator::operator>(it) =====" << std::endl;
		for (Iterator it1 = first; it1 != last; ++it1)
		{;
			for (Iterator it2 = first; it2 != last; ++it2)
				std::cout << (it1 > it2) << "|" << (it2 > it1) << "|";
		}
		std::cout << std::endl;
	}
};

template <class Iterator>
struct test_it_greater_equal
{
	static void run(Iterator first, Iterator last)
	{
		std::cout << "===== Iterator::operator>=(it) =====" << std::endl;
		for (Iterator it1 = first; it1 != last; ++it1)
		{
			for (Iterator it2 = first; it2 != last; ++it2)
				std::cout << (it1 >= it2) << "|" << (it2 >= it1) << "|";
		}
		std::cout << std::endl;
	}
};

// generic test

template <class C, template <class> class Func>
static void test_all_iterators(C c)
{
	typedef typename C::iterator iterator;
	typedef typename C::const_iterator const_iterator;
	// typedef typename C::reverse_iterator reverse_iterator;
	// typedef typename C::const_reverse_iterator const_reverse_iterator;

	Func<iterator>::run(c.begin(), c.end());
	// Func<reverse_iterator>::run(c.rbegin(), c.rend());

	const C& cc = c;

	Func<const_iterator>::run(cc.begin(), cc.end());
	// Func<const_reverse_iterator>::run(cc.rbegin(), cc.rend());
}

template <class C>
static void test_iterator_dispatch(C& test, ns::bidirectional_iterator_tag)
{
	// forward
	test_all_iterators<C, test_it_is_equal>(test);			// it1 == it2
	test_all_iterators<C, test_it_is_different>(test);		// it1 != it2
	test_all_iterators<C, test_it_dereference>(test);		// *it
	test_all_iterators<C, test_it_pre_increment>(test);		// ++it
	test_all_iterators<C, test_it_post_increment>(test);	// it++
	// // bidirectional
	test_all_iterators<C, test_it_pre_decrement>(test);		// --it
	test_all_iterators<C, test_it_post_decrement>(test);	// it--
}

template <class C>
static void test_iterator_dispatch(C& test, ns::random_access_iterator_tag)
{
	test_iterator_dispatch<C>(test, ns::bidirectional_iterator_tag());

	test_all_iterators<C, test_it_increment_n>(test);		// it + n
	test_all_iterators<C, test_it_n_add_iterator>(test);	// n + it
	test_all_iterators<C, test_it_decrement_n>(test);		// it - n
	test_all_iterators<C, test_it_subtract_it>(test);		// it1 - it2
	test_all_iterators<C, test_it_add_n>(test);				// it += n
	test_all_iterators<C, test_it_subtract_n>(test);		// it -= n
	test_all_iterators<C, test_it_access>(test);			// it[n]
	test_all_iterators<C, test_it_lesser>(test);			// it < it2
	test_all_iterators<C, test_it_lesser_equal>(test);		// it <= it2
	test_all_iterators<C, test_it_greater>(test);			// it > it2
	test_all_iterators<C, test_it_greater_equal>(test);		// it >= it2
}

template <class C>
static void test_it_container_type(std::string type)
{
	std::cout << "==================" << std::endl
	<< "Testing " + type + " iterators" << std::endl
	<< "==================" << std::endl;

	typedef typename ns::iterator_traits<typename C::iterator>::iterator_category category;

	C c = fill_n<C>(0);
	test_iterator_dispatch<C>(c, category());
	c = fill_n<C>(1);
	test_iterator_dispatch<C>(c, category());
	c = fill_n<C>(10);
	test_iterator_dispatch<C>(c, category());
	c = fill_n<C>(100);
	test_iterator_dispatch<C>(c, category());
}

template <template <typename, typename> class Container>
static void test_it_seq_container(std::string name)
{
	test_it_container_type<Container<int, std::allocator<int> > >(name + "<int>");
	test_it_container_type<Container<std::string, std::allocator<std::string> > >(name + "<std::string>");
	test_it_container_type<Container<Foo, std::allocator<Foo> > >(name + "<Foo>");
}

void test_iterators()
{
	std::cout << "=======================================" << std::endl 
	<< "Testing Iterator" << std::endl
	<< "=======================================" << std::endl;
	std::cout << "=======================================" << std::endl 
	<< "Testing Vector Iterator" << std::endl
	<< "=======================================" << std::endl;
	test_it_seq_container<ns::vector>("vector");
	test_it_seq_container<ns::list>("list");
	test_it_seq_container<ns::deque>("deque");

	// test_container<ns::vector<int>, int>(true, "vector<int>");
	// test_pointer<ns::vector>();
	// test_container<ns::vector<std::string>, std::string>(true, "vector<std::string>");
}