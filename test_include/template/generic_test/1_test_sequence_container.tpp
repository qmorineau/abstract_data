#ifndef TEST_SEQUENCE_CONTAINER_TPP
#define TEST_SEQUENCE_CONTAINER_TPP

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
void test_sequence_container(std::string name)
{
	std::cout << "=======================================" << std::endl 
	<< "===== Testing " << name << std::endl
	<< "=======================================" << std::endl << std::endl;

	std::cout << "=======================================" << std::endl
	<< "=======================================" << std::endl
	<< "Testing int" << std::endl
	<< "=======================================" << std::endl 
	<< "=======================================" << std::endl << std::endl;
	test_sequence_container_type_typed<Container, int>();
	// String
	std::cout << "=======================================" << std::endl
	<< "=======================================" << std::endl
	<< "Testing std::string" << std::endl
	<< "=======================================" << std::endl 
	<< "=======================================" << std::endl << std::endl;
	test_sequence_container_type_typed<Container, std::string>();
	std::cout << "=======================================" << std::endl
	<< "=======================================" << std::endl
	<< "Testing Foo" << std::endl
	<< "=======================================" << std::endl 
	<< "=======================================" << std::endl << std::endl;
	test_sequence_container_type_typed<Container, Foo>();
	// Throwing class
	// test_sequence_container_type_typed<Container, ThrowingClass>();
}

#endif