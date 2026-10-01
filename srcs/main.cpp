#include "test.hpp"

struct timeval Timer::_start;

int main()
{
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
	test_list();
	// test_deque();
	// test_vector();
	
	// test_map();
	// test_set();
	// test_multimap();
	// test_multiset();

	// test_stack();
	// test_queue();
	// test_priority_queue();
	return (0);
}
