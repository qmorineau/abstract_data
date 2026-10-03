#ifndef TEST_MODIFIERS_FUNC_TPP
#define TEST_MODIFIERS_FUNC_TPP

/*
	clear
	insert
	erase
	push_back
	pop_back
	resize
	swap
*/

template <typename Container>
struct test_clear
{
	static void run()
	{
		std::cout << "===== Test: clear() =====" << std::endl;
		// to do
	}
};

template <typename Container>
struct test_insert
{
	static void run()
	{
		std::cout << "===== Test: insert() =====" << std::endl;
		// to do
	}
};

template <typename Container>
struct test_erase
{
	static void run()
	{
		std::cout << "===== Test: erase() =====" << std::endl;
		// to do
	}
};

template <typename Container>
struct test_push_back
{
	static void run()
	{
		std::cout << "===== Test: push_back() =====" << std::endl;
		Container c;
		for (std::size_t i = 0; i < 150; ++i)
		{
			c.push_back(generate_value<Container>(i));
			std::cout << *c.rbegin() << "|";
		}
		std::cout << std::endl;
	}
};

template <typename Container>
struct test_pop_back
{
	static void run()
	{
		std::cout << "===== Test: pop_back() =====" << std::endl;
		typedef typename Container::size_type size_type;
		size_type size = 150;
		Container c = fill_n<Container>(size);
		for (size_type i = 0; i < size - 1; ++i)
		{
			c.pop_back();
			std::cout << *c.rbegin() << "|";
		}
		std::cout << std::endl;
	}
};

template <typename Container>
struct test_resize
{
	static void run()
	{
		std::cout << "===== Test: resize() =====" << std::endl;
		// to do
	}
};

template <typename Container>
struct test_swap
{
	static void run()
	{
		std::cout << "===== Test: swap() =====" << std::endl;
		// to do
	}
};

template <typename Container>
void test_modifiers_func()
{
	std::cout << "=======================================" << std::endl 
	<< "===== Modifiers Func" << std::endl
	<< "=======================================" << std::endl;
	RUN_IF(has_clear, test_clear, Container);
	RUN_IF(has_insert, test_insert, Container);
	RUN_IF(has_erase, test_erase, Container);
	RUN_IF(has_push_back, test_push_back, Container);
	RUN_IF(has_pop_back, test_pop_back, Container);
	RUN_IF(has_resize, test_resize, Container);
	RUN_IF(has_swap, test_swap, Container);
}

#endif