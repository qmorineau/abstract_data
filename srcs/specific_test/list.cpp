#include "test.hpp"

//print
template <class T>
static void print_list(ns::list<T>& l)
{
	std::cout << "print_list: ";
	print<ns::list<T> >(l);
	std::cout << "size = " << l.size() << std::endl;
}

// splice

static void test_list_splice_full()
{
	std::cout << "===== Test: list::splice(pos, list) =====" << std::endl;
	ns::list<int> test = fill_n<ns::list<int> >(10);
	ns::list<int> test2;
	for (int i = 1; i < 10; ++i)
		test2.push_back(i * 100);
	ns::list<int> tmp = test2;
	print_list(test);
	print_list(tmp);
	test.splice(test.begin(), tmp);
	print_list(test);
	print_list(tmp);

	tmp = test2;
	typename ns::list<int>::iterator it = test.begin();
	for (int i = 0; i < 15; ++i)
		++it;
	test.splice(it, tmp);
	print_list(test);
	print_list(tmp);

	tmp = test2;
	test.splice(test.end(), tmp);
	print_list(test);
	print_list(tmp);
}
static void test_list_splice_single()
{
	std::cout << "===== Test: list::splice(pos, list, it) =====" << std::endl;
	ns::list<int> test = fill_n<ns::list<int> >(10);
	ns::list<int> test2;
	for (int i = 1; i < 10; ++i)
		test2.push_back(i * 100);
	print_list(test);
	print_list(test2);
	test.splice(test.begin(), test2, test2.begin());

	typename ns::list<int>::iterator it1 = test.begin();
	typename ns::list<int>::iterator it2 = test2.begin();
	for (int i = 0; i < 5; ++i)
	{
		++it1;
		++it2;
	}
	test.splice(it1, test2, it2);
	print_list(test);
	print_list(test2);

	test.splice(test.end(), test2, --test2.end());
	print_list(test);
	print_list(test2);
}
static void test_list_splice_it()
{
	std::cout << "===== Test: list::splice(pos, list, first, last) =====" << std::endl;
	ns::list<int> test = fill_n<ns::list<int> >(10);
	ns::list<int> test2;
	for (int i = 1; i < 10; ++i)
		test2.push_back(i * 100);
	print_list(test);
	print_list(test2);
	typedef typename ns::list<int>::iterator iterator;
	iterator first = test2.begin();
	iterator last = test2.begin();
	std::advance(last, 3);
	test.splice(test.begin(), test2, first, last);
	print_list(test);
	print_list(test2);

	first = test2.begin();
	std::advance(first, 3);
	last = first;
	std::advance(last, 2);
	iterator it = test.begin();
	std::advance(it, 5);
	test.splice(it, test2, first, last);
	print_list(test);
	print_list(test2);

	test.splice(test.end(), test2, test2.begin(), test2.end());
	print_list(test);
	print_list(test2);
}
static void test_list_splice()
{
	test_list_splice_full();
	test_list_splice_single();
	test_list_splice_it();
}

//remove

static void test_list_remove_value()
{
	std::cout << "===== Test: list::remove(const T& value) =====" << std::endl;
	ns::list<int> test = fill_n<ns::list<int> >(150);
	print_list(test);
	test.remove(1500);
	print_list(test);
	test.remove(1);
	print_list(test);
	test.remove(67);
	print_list(test);
	test.remove(149);
	print_list(test);
	for (int i = 0; i < 150; ++i)
	{
		test.remove(i);
		print_list(test);
	}
}
static void test_list_remove_if()
{
	std::cout << "===== Test: list::remove_if(Predicate pred) =====" << std::endl;
	ns::list<int> test = fill_n<ns::list<int> >(15);
	print_list(test);
	test.remove_if(PredEqualTo<int>(13));
	print_list(test);
	test.remove_if(PredEqualTo<int>(0));
	print_list(test);
	test.remove_if(PredLesserThan<int>(5));
	print_list(test);
	test.remove_if(PredLesserThan<int>(3));
	print_list(test);
	test.remove_if(PredLesserThan<int>(10));
	print_list(test);
	test.remove_if(PredLesserThan<int>(150));
	print_list(test);
}
static void test_list_remove()
{
	test_list_remove_value();
	test_list_remove_if();
}

// unique

static void test_list_unique_no_pred()
{
	std::cout << "===== Test: list::unique() =====" << std::endl;
	ns::list<int> test = fill_n<ns::list<int> >(15);
	print_list(test);
	test.unique();
	for (int i = 0; i < 10; ++i)
	{
		test.push_front(i);
		test.push_front(i);
		test.push_front(i);
		test.push_back(i);
		test.push_back(i);
		test.push_back(i);
	}
	print_list(test);
	test.unique();
	print_list(test);
}
static void test_list_unique_pred()
{
	std::cout << "===== Test: list::unique(Predicate pred) =====" << std::endl;
	ns::list<int> test = fill_n<ns::list<int> >(15);
	print_list(test);
	test.unique(BinaryPredEqualTo<int>());
	test.push_back(14);
	print_list(test);
	test.unique(BinaryPredEqualTo<int>());
	print_list(test);
	for (int i = 0; i < 10; ++i)
		test.push_back(i);
	print_list(test);
	test.unique(BinaryPredGreaterThan<int>());
	print_list(test);
}
static void test_list_unique()
{
	test_list_unique_no_pred();
	test_list_unique_pred();
}

// merge

static void test_list_merge_normal()
{
	std::cout << "===== Test: list::merge(list) =====" << std::endl;
	ns::list<int> test;
	ns::list<int> test2;
	for (int i = 0; i < 15; ++i)
	{
		if (i % 2)
		{
			test.push_back(i);
			test2.push_back(i * 2);
			test2.push_back(i);
		}
		else
		{
			test.push_front(i);
			test2.push_front(i * 2);
			test2.push_front(i);
		}
	}
	print_list(test);
	print_list(test2);
	test.sort();
	test2.sort();
	print_list(test);
	print_list(test2);
	test.merge(test2);
	print_list(test);
	print_list(test2);
}
static void test_list_merge_compare()
{
	std::cout << "===== Test: list::merge(list, compare) =====" << std::endl;
	// todo
}
static void test_list_merge()
{
	test_list_merge_normal();
	test_list_merge_compare();
}


// sort

static void test_list_sort_normal()
{
	std::cout << "===== Test: list::sort() =====" << std::endl;
	// todo
}
static void test_list_sort_compare()
{
	std::cout << "===== Test: list::sort(compare) =====" << std::endl;
	// todo
}
static void test_list_sort()
{
	test_list_sort_normal();
	test_list_sort_compare();
}

// reverse

static void test_list_reverse()
{
	std::cout << "===== Test: list::reverse() =====" << std::endl;
	ns::list<int> test = fill_n<ns::list<int> >(150);
	print_list(test);
	test.reverse();
	print_list(test);
	test.reverse();
	print_list(test);
}

void test_list()
{
	test_list_merge();
	return ;
	std::cout << "=======================================" << std::endl 
	<< "Testing ::list" << std::endl
	<< "=======================================" << std::endl;
	test_list_splice();
	test_list_remove();
	test_list_unique();
	test_list_sort();
	test_list_reverse();
}