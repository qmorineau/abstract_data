#ifndef TEST_CAPACITY_FUNC_TPP
#define TEST_CAPACITY_FUNC_TPP

/*
	empty
	size
	max_size
	resize
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
			bool ret = c.empty();
			std::cout << ret << "|";
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
			typename Container::size_type ret = c.size();
			std::cout << ret << "|";
		}
		std::cout << std::endl;
	}
};

template <typename Container>
struct test_max_size
{
	static void run()
	{
		std::cout << "===== Test: max_size()* =====" << std::endl;
		Container c;
		typename Container::size_type ret = c.max_size();
		std::cout << "*: could be different, implement dependant => " << ret << std::endl;
	}
};

template <typename Container>
struct test_resize
{
	static void run()
	{
		std::cout << "===== Test: resize(size_type sz, T c) =====" << std::endl;
		for (size_t i = 0; i < 15; ++i)
		{
			Container c = fill_n<Container>(i);
			c.resize(i > 3 ? i : 0, generate_value<Container>(67));
			print(c);
			std::cout << "||" << c.size() << "||";
		}
		std::cout << std::endl;
		for (size_t i = 0; i < 15; ++i)
		{
			Container c = fill_n<Container>(i);
			c.resize(i + 7, generate_value<Container>(19));
			print(c);
			std::cout << "||" << c.size() << "||";
		}
		std::cout << std::endl;
		for (size_t i = 0; i < 15; ++i)
		{
			Container c = fill_n<Container>(i);
			c.resize(i, generate_value<Container>(42));
			print(c);
			std::cout << "||" << c.size() << "||";
		}
		std::cout << std::endl;
	}
};

template <typename Container>
struct test_reserve
{
	static void run()
	{
		std::cout << "===== Test: reserve() =====" << std::endl;
		typedef typename Container::size_type size_type;
		typedef typename Container::pointer   pointer;

		// n > capacity
		{
			Container c = fill_n<Container>(10);
			c.reserve(100);
			print(c);
			std::cout << "||" << c.size() << "||" << (c.capacity() >= 100) << std::endl;
		}

		// n <= capacity
		{
			Container c = fill_n<Container>(10);
			c.reserve(50);
			size_type cap = c.capacity();
			pointer p = &c[0];
			c.reserve(5);
			print(c);
			std::cout << (c.capacity() == cap) << (&c[0] == p) << std::endl;
		}
		// no reallocation until n
		{
			Container c;
			c.reserve(64);
			c.push_back(generate_value<Container>(0));
			pointer p = &c[0];
			for (size_type i = 1; i < 64; ++i)
				c.push_back(generate_value<Container>(i));
			print(c);
			std::cout << (&c[0] == p) << std::endl;
		}
		// length_error if n > max_size()
		{
			Container c = fill_n<Container>(10);
			bool thrown = false;
			try
			{
				c.reserve(c.max_size() + 1);
			}
			catch (ns::length_error&)
			{
				thrown = true;
			}
			print(c);
			std::cout << thrown << std::endl;
		}
	}
};

template <typename Container>
struct test_capacity
{
	static void run()
	{
		std::cout << "===== Test: capacity() =====" << std::endl;
		// Basic check
		for (size_t i = 0; i < 15; ++i)
		{
			Container c = fill_n<Container>(i);
			if (c.capacity() < c.size())
				std::abort();
		}
		// Change capacity without changing size
		{
		Container c = fill_n<Container>(10);
			c.reserve(100);
			if (c.capacity() < 100 || c.size() != 10)
				std::abort();
		}
		// No change in capacity if when removing element
		{
			Container c = fill_n<Container>(20);
			typename Container::size_type cap = c.capacity();
			c.clear();
			if (c.capacity() != cap)
				std::abort();
		}
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
	RUN_IF(has_resize, test_resize, Container);
	RUN_IF(has_reserve, test_reserve, Container);
	RUN_IF(has_capacity, test_capacity, Container);
}

#endif