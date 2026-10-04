#include "test.hpp"

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		if (std::string(argv[1]) == "benchmark")
		{
			// benchmark();
		}
		else
		{
			std::cerr << "Error: wrong argument: no test done" << std::endl;
			return (1);
		}
	}
	else
	{
		std::cout << "=======================================" << std::endl 
		<< "Testing ::containers" << std::endl
		<< "=======================================" << std::endl << std::endl;
		std::cout << "=======================================" << std::endl 
		<< "Generic Test" << std::endl
		<< "=======================================" << std::endl << std::endl;
		// test_exceptions();
		// test_iterators();

		// test_sequence_container<ns::vector>("vector");
		// test_sequence_container<ns::deque>("deque");
		// test_sequence_container<ns::list>("list");

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
		// test_vector();
		// test_deque();
		test_list();
		
		// test_map();
		// test_set();
		// test_multimap();
		// test_multiset();

		// test_stack();
		// test_queue();
		// test_priority_queue();
	}
	return (0);
}
