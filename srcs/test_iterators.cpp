#include <vector>
#include <iostream>

#include "vector.hpp"

#ifdef STD
	namespace nm = std;
	# define NAMESPACE_NAME "std"
#else
	namespace nm = ft;
	# define NAMESPACE_NAME "ft"
#endif

template <class Iterator>
static void test_increment(Iterator start, Iterator end)
{
	std::cout << "==== Iterator Pre-Increment =====" << std::endl;
	for (Iterator it = start; it != end; )
	{
		Iterator tmp = ++it;
		if (!(it == end))
			std::cout << "tmp" << *it;
		std::cout << "|";
		if (tmp != end)
			std::cout << "it" << *tmp;
		std::cout << "|";
	}
	std::cout << std::endl;
	std::cout << "==== Iterator Post-Increment =====" << std::endl;
	for (Iterator it = start; it != end; )
	{
		Iterator tmp = it++;
		if (it != end)
			std::cout << "tmp" << *it;
		std::cout << "|";
		if (!(tmp == end))
			std::cout << "it" << *tmp;
		std::cout << "|";
	}
	std::cout << std::endl;
}

template <class Iterator>
static void test_decrement(Iterator start, Iterator end)
{
	std::cout << "==== Iterator Post-Decrement =====" << std::endl;
	for (Iterator it = start; it != end; )
	{
		Iterator tmp = --it;
		if (it != start)
			std::cout << "it" << *it;
		std::cout << "|";
		if (!(tmp == start))
			std::cout << "tmp" << *tmp;
		std::cout << "|";
	}
	std::cout << std::endl;
	std::cout << "==== Iterator Post-Decrement =====" << std::endl;
	for (Iterator it = start; it != end; )
	{
		Iterator tmp = it--;
		if (!(it == start))
			std::cout << "tmp" << *it;
		std::cout << "|";
		if (tmp != start)
			std::cout << "it" << *tmp;
		std::cout << "|";
	}
	std::cout << std::endl;
}

template <class Iterator>
static void test_comparaison(Iterator a, Iterator b)
{
	std::cout << "==== Iterator Comparaison =====" << std::endl;
	std::cout << (a < b) << "|"
	<< (a > b) << "|"
	<< (a <= b) << "|"
	<< (a >= b) << std::endl;
}

template <class Iterator, typename T>
static void test_access(Iterator it, T max_diff)
{
	std::cout << "==== Iterator Access [] =====" << std::endl;
	for (T i = 0; i < max_diff; i++)
		std::cout << it[i] << "|";
	std::cout << std::endl;
}

template <class Iterator, typename T>
static void test_random_access_operator(Iterator begin, Iterator end, T max_diff)
{
	std::cout << "==== Iterator operator+= =====" << std::endl;
	for (T i = 0; i < max_diff; i++)
	{
		Iterator tmp = begin;
		std::cout << *(tmp += i)  << "|";
	}
	std::cout << std::endl;

	std::cout << "==== Iterator operator+ =====" << std::endl;
	for (T i = 0; i < max_diff; i++)
	{
		Iterator tmp = begin;
		std::cout << *(tmp + i)  << "|";
		tmp = begin;
		std::cout << *(i + tmp)  << "|";
	}
	std::cout << std::endl;

	std::cout << "==== Iterator operator-= =====" << std::endl;
	for (T i = 1; i < max_diff; i++)
	{
		Iterator tmp = end;
		std::cout << *(tmp -= i)  << "|";
	}
	std::cout << std::endl;

	std::cout << "==== Iterator operator it - n =====" << std::endl;
	for (T i = 1; i < max_diff; i++)
	{
		Iterator tmp = end;
		std::cout << *(tmp - i)  << "|";
	}
	std::cout << std::endl;

	std::cout << "==== Iterator operator it - it =====" << std::endl;
	for (T i = 1; i < max_diff; i++)
	{
		Iterator tmp = begin;
		std::cout << (tmp + i) - end  << "|";
	}
	std::cout << std::endl;
}

template <typename Container, typename T>
static void test_container(bool is_random_access, std::string name)
{
	std::cout << "==== Testing Iterator " + name + " =====" << std::endl;
	Container test;
	for (int i = 0; i < 10; i++)
		test.push_back(T(i));

	test_increment<typename Container::iterator>(test.begin(), test.end());
	test_increment<typename Container::const_iterator>(test.begin(), test.end());
	test_increment<typename Container::reverse_iterator>(test.rbegin(), test.rend());
	test_increment<typename Container::const_reverse_iterator>(test.rbegin(), test.rend());

	test_decrement<typename Container::iterator>(test.end(), test.begin());
	test_decrement<typename Container::const_iterator>(test.end(), test.begin());
	test_decrement<typename Container::reverse_iterator>(test.rend(), test.rbegin());
	test_decrement<typename Container::const_reverse_iterator>(test.rend(), test.rbegin());

	if (is_random_access)
	{
		test_comparaison<typename Container::iterator>(test.begin(), test.end());
		test_comparaison<typename Container::const_iterator>(test.begin(), test.end());
		test_comparaison<typename Container::reverse_iterator>(test.rbegin(), test.rend());
		test_comparaison<typename Container::const_reverse_iterator>(test.rbegin(), test.rend());

		test_access<typename Container::iterator, typename Container::difference_type>(test.begin(), test.size());
		test_access<typename Container::const_iterator, typename Container::difference_type>(test.begin(), test.size());
		test_access<typename Container::reverse_iterator, typename Container::difference_type>(test.rbegin(), test.size());
		test_access<typename Container::const_reverse_iterator, typename Container::difference_type>(test.rbegin(), test.size());

		test_random_access_operator<typename Container::iterator, typename Container::difference_type>(test.begin(), test.end(), test.size());
		test_random_access_operator<typename Container::const_iterator, typename Container::difference_type>(test.begin(), test.end(), test.size());
		test_random_access_operator<typename Container::reverse_iterator, typename Container::difference_type>(test.rbegin(), test.rend(), test.size());
		test_random_access_operator<typename Container::const_reverse_iterator, typename Container::difference_type>(test.rbegin(), test.rend(), test.size());
	}
}
template <template <typename, typename> class Container>
static void test_pointer()
{
	std::cout << "==== Testing Iterator->size() on <std::string> =====" << std::endl;
	Container<std::string,std::allocator<std::string> > test;
	test.push_back("Hello");
	test.push_back("World !");
	typename Container<std::string,std::allocator<std::string> >::iterator it = test.begin();
	std::cout << it->size() << "|";
	++it;
	std::cout << it->size() << std::endl;
}

void test_iterators()
{
	std::cout << "=======================================" << std::endl 
	<< "Testing Iterator" << std::endl
	<< "=======================================" << std::endl;
	std::cout << "=======================================" << std::endl 
	<< "Testing Vector Iterator" << std::endl
	<< "=======================================" << std::endl;
	test_container<nm::vector<int>, int>(true, "vector<int>");
	test_pointer<nm::vector>();
	// test_container<nm::vector<std::string>, std::string>(true, "vector<std::string>");
}