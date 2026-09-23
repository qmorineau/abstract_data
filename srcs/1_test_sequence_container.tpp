#include "test.hpp"

template <template <typename, typename> class Container, typename T>
static void test_sequence_container_type_typed()
{
	test_iterators_func<Container<T, std::allocator<T> > >();
}

template <template <typename, typename> class Container>
static void test_sequence_container_type()
{
	// Int
	test_sequence_container_type_typed<Container, int>();
	// String
	test_sequence_container_type_typed<Container, std::string>();
	// Throwing class
	// test_sequence_container_type_typed<Container, ThrowingClass>();
	// Foo
	// test_sequence_container_type_typed<Container, Foo>();
}

template <template <typename, typename> class Container>
void test_sequence_container()
{
	test_sequence_container_type<nm::vector>();
	// test_sequence_container_type<nm::deque>();
	// test_sequence_container_type<nm::list>();
}
