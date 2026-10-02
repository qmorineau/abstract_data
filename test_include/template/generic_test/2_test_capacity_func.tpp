#ifndef TEST_CAPACITY_FUNC_TPP
#define TEST_CAPACITY_FUNC_TPP

/*
	empty
	size
	max_size
	reserve
	capacity
*/

template <typename Container>
static void test_empty()
{
	std::cout << "===== Test: empty() =====" << std::endl;
	// todo
}

template <typename Container>
static void test_size()
{
	std::cout << "===== Test: size() =====" << std::endl;
	
}

template <typename Container>
static void test_max_size()
{
	std::cout << "===== Test: max_size() =====" << std::endl;
	Container c;
	std::cout << c.max_size() << std::endl;
}

template <typename Container>
static void test_reserve()
{
	std::cout << "===== Test: reserve() =====" << std::endl;
	// todo
}

template <typename Container>
static void test_capacity()
{
	std::cout << "===== Test: capacity() =====" << std::endl;
	// todo
}

template <typename Container>
static void test_modifier(CapacityModifier modifier)
{
	switch (modifier)
	{
		case MOD_EMPTY:
			if (container_traits<Container>::has_empty)
				test_empty<Container>();
			break;
		case MOD_SIZE:
			if (container_traits<Container>::has_size)
				test_size<Container>();
			break;
		case MOD_MAX_SIZE:
			if (container_traits<Container>::has_max_size)
				test_max_size<Container>();
			break;
		case MOD_RESERVE:
			if (container_traits<Container>::has_reserve)
				test_reserve<Container>();
			break;
		case MOD_CAPACITY:
			if (container_traits<Container>::has_capacity)
				test_capacity<Container>();
			break;
		default:
			std::cout << "CapacityModifier not managed" << std::endl;
			break;
	}
}

template <typename Container>
void test_capacity_func()
{
	std::cout << "=======================================" << std::endl 
	<< "===== Capacity Func" << std::endl
	<< "=======================================" << std::endl;
	test_modifier<Container>(MOD_EMPTY);
	test_modifier<Container>(MOD_SIZE);
	test_modifier<Container>(MOD_MAX_SIZE);
	test_modifier<Container>(MOD_RESERVE);
	test_modifier<Container>(MOD_CAPACITY);
}

#endif