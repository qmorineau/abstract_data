#include "test.hpp"

template <template <typename, typename> class Container, typename T>
static void test_sequence_container_type_typed()
{
	test_common_func<Container<T, std::allocator<T> > >();
	test_element_access_func<Container<T, std::allocator<T> > >();
	test_iterators_func<Container<T, std::allocator<T> > >();
	test_capacity_func<Container<T, std::allocator<T> > >();
	test_modifiers_func<Container<T, std::allocator<T> > >();
	test_non_member_func<Container<T, std::allocator<T> > >();
}

template <template <typename, typename> class Container>
static void test_sequence_container_type()
{
	// Int
	std::cout << "=======================================" << std::endl
	<< "=======================================" << std::endl
	<< "Testing int" << std::endl
	<< "=======================================" << std::endl 
	<< "=======================================" << std::endl << std::endl;
	std::cerr << std::endl << "=== int ===" << std::endl;
	test_sequence_container_type_typed<Container, int>();
	// String
	std::cout << "=======================================" << std::endl
	<< "=======================================" << std::endl
	<< "Testing std::string" << std::endl
	<< "=======================================" << std::endl 
	<< "=======================================" << std::endl << std::endl;
	std::cerr << std::endl << "=== std::string ===" << std::endl;
	test_sequence_container_type_typed<Container, std::string>();
	std::cout << "=======================================" << std::endl
	<< "=======================================" << std::endl
	<< "Testing Foo" << std::endl
	<< "=======================================" << std::endl 
	<< "=======================================" << std::endl << std::endl;
	std::cerr << std::endl << "=== Foo ===" << std::endl;
	test_sequence_container_type_typed<Container, Foo>();
	// Throwing class
	// test_sequence_container_type_typed<Container, ThrowingClass>();
}

template <template <typename, typename> class Container>
void test_sequence_container()
{
	std::cout << "=======================================" << std::endl 
	<< "===== Testing vector" << std::endl
	<< "=======================================" << std::endl << std::endl;
	std::cerr << std::endl << "===== Vector =====" << std::endl;
	test_sequence_container_type<nm::vector>();
	std::cout << "=======================================" << std::endl 
	<< "===== Testing deque" << std::endl
	<< "=======================================" << std::endl << std::endl;
	std::cerr << std::endl << "===== Deque =====" << std::endl;
	// test_sequence_container_type<nm::deque>();
	std::cout << "=======================================" << std::endl 
	<< "===== Testing list" << std::endl
	<< "=======================================" << std::endl << std::endl;
	std::cerr << std::endl << "===== List =====" << std::endl;
	// test_sequence_container_type<nm::list>();
}
