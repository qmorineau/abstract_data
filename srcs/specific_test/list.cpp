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
	// todo
}

static void test_list_splice_it()
{
	std::cout << "===== Test: list::splice(pos, list, first, last) =====" << std::endl;
	// todo
}

static void test_list_splice()
{
	test_list_splice_full();
	test_list_splice_single();
	test_list_splice_it();
}

void test_list()
{
	std::cout << "=======================================" << std::endl 
	<< "Testing ::list" << std::endl
	<< "=======================================" << std::endl;
	// ns::list<int> test;
	// ns::list<int> test2;
	// for (int i = 1; i < 10; ++i)
	// {
	// 	test.push_back(i);
	// 	test2.push_back(i * 100);
	// }
	// print_list(test);
	// print_list(test2);
	// typedef typename ns::list<int>::iterator iterator;
	// iterator it = test.begin();
	// iterator it2 = test2.begin();
	// for (int i = 0; i < 3; ++i)
	// {
	// 	++it;
	// 	++it2;
	// }
	// iterator it3 = it2;
	// for (int i = 0; i < 3; ++i)
	// 	++it3;
	// TimerAccum t("bla");
	// {
	// 	Accum a(t.total());
		
	// 	test.splice(it, test2, it2, it3);
	// }
	// print_list(test);
	// print_list(test2);
	test_list_splice();
}