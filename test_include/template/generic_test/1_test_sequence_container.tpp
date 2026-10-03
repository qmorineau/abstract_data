#ifndef TEST_SEQUENCE_CONTAINER_TPP
#define TEST_SEQUENCE_CONTAINER_TPP

template <class Container>
static void test_sequence_container_type(std::string type)
{
	std::cout << "=======================================" << std::endl
	<< "=======================================" << std::endl
	<< "Testing " << type << std::endl
	<< "=======================================" << std::endl 
	<< "=======================================" << std::endl << std::endl;
	test_common_func<Container>();
	test_element_access_func<Container>();
	test_iterators_func<Container>();
	test_capacity_func<Container>();
	test_modifiers_func<Container>();
	test_non_member_func<Container>();
}

template <template <typename, typename> class Container>
void test_sequence_container(std::string name)
{
	test_sequence_container_type<Container<int, std::allocator<int> > >(name + "<int>");
	test_sequence_container_type<Container<std::string, std::allocator<std::string> > >(name + "<int>");
	test_sequence_container_type<Container<Foo, std::allocator<Foo> > >(name + "<int>");
	// Throwing class
	// test_sequence_container_type_typed<Container, ThrowingClass>();
}

#endif