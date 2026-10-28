#include "test.hpp"

void test(int i)
{
	(void) i;
	// SilenceScope mute;
	// ns::deque<Throwing> d = fill_n<ns::deque<Throwing> >(15);
	// ns::deque<Throwing> d2 = fill_n<ns::deque<Throwing> >(5);
	// print<ns::deque<Throwing> >(d);
	// std::cout << d.size() << std::endl;
	// typename ns::deque<Throwing>::iterator begin = d.begin();
	// begin += 5;
	// try
	// {
	// 	ThrowingCounter::reset(i);
	// 	d.insert(begin, 5, Throwing(67));
	// 	d.size();
	// }
	// catch(...)
	// {
	// 	std::cout << "la";
	// 	d.print();
	// }
	// std::cout << "ICI";
	// 	d.print();
	// print<ns::deque<Throwing> >(d);
	// std::cout << d.size() << std::endl;
}

std::size_t ThrowingCounter::count = 0;
std::size_t ThrowingCounter::limit = 10;
bool		ThrowingCounter::enabled = true;

int main()
{
	// for (int i = 0; i < 15; ++i)
	// 	test(12);
	// return 1;
	std::cout << "=======================================" << std::endl 
	<< "Testing ::containers" << std::endl
	<< "=======================================" << std::endl << std::endl;
	std::cout << "=======================================" << std::endl 
	<< "Generic Test" << std::endl
	<< "=======================================" << std::endl << std::endl;
	// test_exceptions();
	test_iterators();
	test_helpers();
	test_sequence_container<ns::vector>("vector");
	test_sequence_container<ns::deque>("deque");
	test_sequence_container<ns::list>("list");

	// test_associative_container<ns::map>();
	// test_associative_container<ns::set>();
	// test_associative_container<ns::multimap>();
	// test_associative_container<ns::multiset>();

	test_container_adaptor<ns::stack>("stack");
	// test_container_adaptor<ns::queue>("queue");
	// test_container_adaptor<ns::priority_queue>("priority_queue");
	std::cout << "=======================================" << std::endl 
	<< "Specific Test" << std::endl
	<< "=======================================" << std::endl << std::endl;
	test_vector();
	test_deque();
	test_list();
	
	// test_map();
	// test_set();
	// test_multimap();
	// test_multiset();

	test_stack();
	// test_queue();
	// test_priority_queue();
	return (0);
}
