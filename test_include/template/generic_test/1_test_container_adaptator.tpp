#ifndef TEST_CONTAINER_ADAPATATOR_TPP
#define TEST_CONTAINER_ADAPATATOR_TPP

template <class Container>
static void test_container_adaptator_type(std::string type)
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
	test_operations_func<Container>();
	test_non_member_func<Container>();
}

template <template <typename, typename> class Container>
void test_container_adaptor(std::string name, container_adaptator c)
{
	if (c == STACK || c == QUEUE)
	{
		std::string container = "deque";
		test_container_adaptator_type<Container<int, ns::deque<int> > >(name + "<int, " + container + "<int>>");
		test_container_adaptator_type<Container<std::string, ns::deque<std::string> > >(name + "<std::string, " + container + "<std::string>>");
		test_container_adaptator_type<Container<Foo, ns::deque<Foo> > >(name + "<Foo, " + container + "<Foo>>");
		test_container_adaptator_type<Container<Throwing, ns::deque<Throwing> > >(name + "<Throwing, " + container + "<Throwing>>");
	}
	if (c == STACK)
	{
		std::string container = "vector";
		test_container_adaptator_type<Container<int, ns::vector<int> > >(name + "<int, " + container + "<int>>");
		test_container_adaptator_type<Container<std::string, ns::vector<std::string> > >(name + "<std::string, " + container + "<std::string>>");
		test_container_adaptator_type<Container<Foo, ns::vector<Foo> > >(name + "<Foo, " + container + "<Foo>>");
		test_container_adaptator_type<Container<Throwing, ns::vector<Throwing> > >(name + "<Throwing, " + container + "<Throwing>>");
	}
	if (c == STACK || c == QUEUE)
	{
		std::string container = "list";
		test_container_adaptator_type<Container<int, ns::list<int> > >(name + "<int, " + container + "<int>>");
		test_container_adaptator_type<Container<std::string, ns::list<std::string> > >(name + "<std::string, " + container + "<std::string>>");
		test_container_adaptator_type<Container<Foo, ns::list<Foo> > >(name + "<Foo, " + container + "<Foo>>");
		test_container_adaptator_type<Container<Throwing, ns::list<Throwing> > >(name + "<Throwing, " + container + "<Throwing>>");
	}
}

#endif