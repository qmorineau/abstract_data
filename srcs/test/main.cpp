#include "test.hpp"

void test()
{
	ns::map<int, int> m;
	for (int i = 0; i < 3; ++i)
	{
		typedef typename ns::map<int, int>::iterator iterator;
		ns::pair<iterator, bool> p = m.insert(ns::make_pair<int, int>(1, 2));
		std::cout << (*p.first).first << "---" << (*p.first).second << "|" << p.second << std::endl;
	}
}

std::size_t ThrowingCounter::count = 0;
std::size_t ThrowingCounter::limit = 10;
bool		ThrowingCounter::enabled = true;

int main()
{
	// test();
	// return 0;
	std::cout << "=======================================" << std::endl 
	<< "Testing ::containers" << std::endl
	<< "=======================================" << std::endl << std::endl;
	std::cout << "=======================================" << std::endl 
	<< "Generic Test" << std::endl
	<< "=======================================" << std::endl << std::endl;
	// test_exceptions();
	// test_iterators();
	// test_helpers();
	// test_sequence_container<ns::vector>("vector");
	// test_sequence_container<ns::deque>("deque");
	// test_sequence_container<ns::list>("list");

	test_associative_container<ns::map>("map");
	// test_associative_container<ns::multimap>();
	// test_associative_container<ns::set>();
	// test_associative_container<ns::multiset>();

	// test_container_adaptor<ns::stack>("stack", STACK);
	// test_container_adaptor<ns::queue>("queue", QUEUE);

	std::cout << "=======================================" << std::endl 
	<< "Specific Test" << std::endl
	<< "=======================================" << std::endl << std::endl;
	// test_vector();
	// test_deque();
	// test_list();
	
	// test_map();
	// test_set();
	// test_multimap();
	// test_multiset();

	// test_stack();
	// test_queue();
	// test_priority_queue();
	return (0);
}
