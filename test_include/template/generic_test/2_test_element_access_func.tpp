#ifndef TEST_ELEMENT_FUNC_ACCESS_TPP
#define TEST_ELEMENT_FUNC_ACCESS_TPP

/*
	Functions managed:
	- at()
	- operator[]
	- front()
	- back()
	- data()
*/

template <typename Container>
struct test_at
{
	static void run()
	{
		std::cout << "===== Test: at() =====" << std::endl;
		
		typedef typename Container::size_type size_type;
		typedef typename Container::value_type value_type;
		size_type size = 10;
		Container c = fill_n<Container>(size);
		try
		{
			for (size_type i = 0; i < size; ++i)
			{
				value_type v = c.at(i);
				const value_type cv = c.at(i);
				std::cout << "v&:"<< v << "| const v&:" << cv << "||";
			}
			std::cout << std::endl;
			c.at(-1);
		}
		catch(const ns::out_of_range& e)
		{
			std::cout << e.what() << '\n';
		}
		catch(...)
		{
			std::cout << "test_at(): wrong exception";
		}
	}
};

template <typename Container>
struct test_operator_square_bracket
{
	static void run()
	{
		std::cout << "===== Test: operator[] =====" << std::endl;
		typedef typename Container::size_type size_type;
		typedef typename Container::value_type value_type;
		size_type size = 10;
		Container c = fill_n<Container>(size);
		for (size_type i = 0; i < size; ++i)
		{
			value_type v = c[i];
			const value_type cv = c[i];
			std::cout << "v&:"<< v << "| const v&:" << cv << "||";
		}
		std::cout << std::endl;
	}
};

template <typename Container>
struct test_front
{
	static void run()
	{
		std::cout << "===== Test: front() =====" << std::endl;
		typedef typename Container::size_type size_type;
		typedef typename Container::value_type value_type;
		size_type size = 3;
		Container c = fill_n<Container>(size);
		value_type v = c.front();
		const value_type cv = c.front();
		std::cout << "v&:"<< v << "| const v&:" << cv << std::endl;
	}
};

template <typename Container>
struct test_back
{
	static void run()
	{
		std::cout << "===== Test: back() =====" << std::endl;
		typedef typename Container::size_type size_type;
		typedef typename Container::value_type value_type;
		for (size_type size = 1; size < 15; ++size)
		{
			Container c = fill_n<Container>(size);
			value_type v = c.back();
			const value_type cv = c.back();
			std::cout << "v&:"<< v << "| const v&:" << cv << "||";
		}
		std::cout << std::endl;
	}
};

template <typename Container>
struct test_data
{
	static void run()
	{
		std::cout << "===== Test: data() =====" << std::endl;
		typedef typename Container::size_type size_type;
		typedef typename Container::pointer pointer;
		size_type size = 3;
		Container c = fill_n<Container>(size);
		pointer p = c.data();
		const pointer cp = c.data();
		assert(p == &c.front());
		assert(cp == &c.front());
	}
};

template <typename Container>
void test_element_access_func()
{
	std::cout << "=======================================" << std::endl 
	<< "===== Element Access Func" << std::endl
	<< "=======================================" << std::endl;
	RUN_IF(has_at, test_at, Container);
	RUN_IF(has_operator_square_bracket, test_operator_square_bracket, Container);
	RUN_IF(has_front, test_front, Container);
	RUN_IF(has_back, test_back, Container);
	RUN_IF(has_data, test_data, Container);
}

#endif