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
	std::cout << "||||| Type = int |||||" << std::endl;
	test_sequence_container_type_typed<Container, int>();
	// String
	std::cout << "||||| Type = std::string |||||" << std::endl;
	test_sequence_container_type_typed<Container, std::string>();
	// Throwing class
	// test_sequence_container_type_typed<Container, ThrowingClass>();
	// Foo
	// test_sequence_container_type_typed<Container, Foo>();
}

template <template <typename, typename> class Container>
void test_sequence_container()
{
	std::cout << "|=|=|=|=|=|=|=|=|=|=|=|=|=|" << std::endl;
	std::cout << "||||| Testing vector  |||||" << std::endl;
	std::cout << "|=|=|=|=|=|=|=|=|=|=|=|=|=|" << std::endl;
	test_sequence_container_type<nm::vector>();
	std::cout << "|=|=|=|=|=|=|=|=|=|=|=|=|=|" << std::endl;
	std::cout << "|||||  Testing deque  |||||" << std::endl;
	std::cout << "|=|=|=|=|=|=|=|=|=|=|=|=|=|" << std::endl;
	// test_sequence_container_type<nm::deque>();
	std::cout << "|=|=|=|=|=|=|=|=|=|=|=|=|=|" << std::endl;
	std::cout << "|||||  Testing list   |||||" << std::endl;
	std::cout << "|=|=|=|=|=|=|=|=|=|=|=|=|=|" << std::endl;
	// test_sequence_container_type<nm::list>();
}
