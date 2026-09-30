#include "test.hpp"

struct timeval Timer::_start;

static bool test()
{
	// return false;
	// ft::vector<int> t1;
	std::vector<int> v2;
	// fill_n(t1, 15);
	fill_n(v2, 15);
	// ft::vector<int> v1(t1.begin(), t1.end());
	// std::vector<int> v2(t2.begin(), t2.end());
	std::vector<int>::iterator b = v2.begin();
	v2.insert(++b, 67);
	for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	// for (ft::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
	// 	std::cout << *it << std::endl;
	return true;
}

int main()
{
	if (false && test())
		return 1;
	std::cout << "=======================================" << std::endl 
	<< "Testing " << NAMESPACE_NAME << "::containers" << std::endl
	<< "=======================================" << std::endl << std::endl;
	std::cout << "=======================================" << std::endl 
	<< "Generic Test" << std::endl
	<< "=======================================" << std::endl << std::endl;
	// test_exceptions();
	// test_iterators();

	// test_sequence_container<ns::list>();
	// test_sequence_container<ns::deque>();
	// test_sequence_container<ns::vector>();

	// test_associative_container<ns::map>();
	// test_associative_container<ns::set>();
	// test_associative_container<ns::multimap>();
	// test_associative_container<ns::multiset>();

	// test_container_adaptor<ns::stack>();
	// test_container_adaptor<ns::queue>();
	// test_container_adaptor<ns::priority_queue>();
	std::cout << "=======================================" << std::endl 
	<< "Specific Test" << std::endl
	<< "=======================================" << std::endl << std::endl;
	// test_list();
	// test_deque();
	test_vector();
	
	// test_map();
	// test_set();
	// test_multimap();
	// test_multiset();

	// test_stack();
	// test_queue();
	// test_priority_queue();
	return (0);
}
