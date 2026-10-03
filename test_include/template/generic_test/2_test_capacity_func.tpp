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
struct test_empty
{
	static void run()
	{
		std::cout << "===== Test: empty() =====" << std::endl;
		for (size_t i = 0; i < 10; ++i)
		{
			Container c = fill_n<Container>(i % 3);
			std::cout << c.empty() << "|";
		}
		std::cout << std::endl;
	}
};

template <typename Container>
struct test_size
{
	static void run()
	{
		std::cout << "===== Test: size() =====" << std::endl;
		for (size_t i = 0; i < 15; ++i)
		{
			Container c = fill_n<Container>(i);
			std::cout << c.size() << "|";
		}
		std::cout << std::endl;
	}
};

template <typename Container>
struct test_max_size
{
	static void run()
	{
		std::cout << "===== Test: max_size() =====" << std::endl;
		Container c;
		std::cout << c.max_size() << std::endl;
	}
};

template <typename Container>
struct test_reserve
{
	static void run()
	{
		std::cout << "===== Test: reserve() =====" << std::endl;
		// todo
	}
};

template <typename Container>
struct test_capacity
{
	static void run()
	{
		std::cout << "===== Test: capacity() =====" << std::endl;
		// todo
	}
};

template <typename Container>
void test_capacity_func()
{
	std::cout << "=======================================" << std::endl 
	<< "===== Capacity Func" << std::endl
	<< "=======================================" << std::endl;
	RUN_IF(has_empty, test_empty, Container);
	RUN_IF(has_size, test_size, Container);
	RUN_IF(has_max_size, test_max_size, Container);
	RUN_IF(has_reserve, test_reserve, Container);
	RUN_IF(has_capacity, test_capacity, Container);
}

#endif