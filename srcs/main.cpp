#include "test.hpp"

struct timeval Timer::_start;

int main()
{
	std::cout << "=======================================" << std::endl 
	<< "Testing " << NAMESPACE_NAME << "::containers" << std::endl
	<< "=======================================" << std::endl << std::endl;
	// test_exceptions();
	// test_iterators();

	// test_sequence_container<nm::list>();
	// test_sequence_container<nm::deque>();
	test_sequence_container<nm::vector>();

	// test_associative_container<nm::map>();
	// test_associative_container<nm::set>();
	// test_associative_container<nm::multimap>();
	// test_associative_container<nm::multiset>();

	// test_container_adaptor<nm::stack>();
	// test_container_adaptor<nm::queue>();
	// test_container_adaptor<nm::priority_queue>();
	return (0);
}
