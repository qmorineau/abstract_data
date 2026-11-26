#ifndef TEST_ASSOCIATIVE_CONTAINER_TPP
#define TEST_ASSOCIATIVE_CONTAINER_TPP

template <class Container>
static void test_associative_container_func(std::string type)
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
	test_input_iterators_func<Container>();
}

// Map / Multimap

template <template <typename, typename, typename, typename> class Container, typename K, typename V>
static void test_map_associative_container_value_type(std::string& name, std::string& key, std::string value)
{
	test_associative_container_func<Container<K,V,std::less<K>,std::allocator<ns::pair<const K,V> > > >(name + "<" + key + "," + value + ",std::less<pair<" + key + "," + value + "> > >");
	test_associative_container_func<Container<K,V,std::greater<K>,std::allocator<ns::pair<const K,V> > > >(name + "<" + key + "," + value + ",std::greater<pair<" + key + "," + value + "> > >");
}

template <template <typename, typename, typename, typename> class Container, typename K>
static void test_map_associative_container_key_type(std::string& name, std::string key)
{
	test_map_associative_container_value_type<Container, K, int>(name, key, "int");
	test_map_associative_container_value_type<Container, K, std::string>(name, key, "std::string");
	test_map_associative_container_value_type<Container, K, Foo>(name, key, "Foo");
	test_map_associative_container_value_type<Container, K, Throwing>(name, key, "Throwing");
}

template <template <typename, typename, typename, typename> class Container>
void test_map_associative_container(std::string name)
{
	test_map_associative_container_key_type<Container, int>(name, "int");
	test_map_associative_container_key_type<Container, std::string>(name, "std::string");
	test_map_associative_container_key_type<Container, Foo>(name, "Foo");
	test_map_associative_container_key_type<Container, Throwing>(name, "Throwing");
}

// Set / Multiset

template <template <typename, typename, typename> class Container, typename K>
static void test_set_associative_container_key_type(std::string& name, std::string key)
{
	test_associative_container_func<Container<K,std::less<K>,std::allocator<K> > >(name + "<" + key + ",std::less<" + key + "> > >");
	test_associative_container_func<Container<K,std::greater<K>,std::allocator<K> > >(name + "<" + key + ",std::greater<" + key + "> > >");
}

template <template <typename, typename, typename> class Container>
void test_set_associative_container(std::string name)
{
	test_set_associative_container_key_type<Container, int>(name, "int");
	test_set_associative_container_key_type<Container, std::string>(name, "std::string");
	test_set_associative_container_key_type<Container, Foo>(name, "Foo");
	test_set_associative_container_key_type<Container, Throwing>(name, "Throwing");
}

#endif