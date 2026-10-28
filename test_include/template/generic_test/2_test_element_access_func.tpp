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
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;
		size_type size = 10;
		Container c = fill_n<Container>(size);
		const Container cc = fill_n<Container>(size);
		for (size_type i = 0; i < size + 3; ++i)
		{
			try
			{
				reference v = c.at(i);
				std::cout << "v&:"<< v << "|";
			}
			catch(const ns::out_of_range& e)
			{
				std::cout << "Good exception" << '\n';
			}
			catch(...)
			{
				std::cout << "test_at(): wrong exception";
			}
		}
		std::cout << std::endl;
		// const
		for (size_type i = 0; i < size + 3; ++i)
		{
			try
			{
				const_reference cv = cc.at(i);
				std::cout << "const v&:" << cv << "|";
			}
			catch(const ns::out_of_range& e)
			{
				std::cout << "Good exception" << '\n';
			}
			catch(...)
			{
				std::cout << "test_at(): wrong exception";
			}
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
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;
		size_type size = 10;
		Container c = fill_n<Container>(size);
		const Container cc = fill_n<Container>(size);
		for (size_type i = 0; i < size; ++i)
		{
			reference v = c[i];
			const_reference cv = cc[i];
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
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;
		size_type size = 3;
		Container c = fill_n<Container>(size);
		reference v = c.front();
		const Container cc = fill_n<Container>(size);
		const_reference cv = cc.front();
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
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;
		for (size_type size = 1; size < 15; ++size)
		{
			Container c = fill_n<Container>(size);
			reference v = c.back();
			const Container cc = fill_n<Container>(size);
			const_reference cv = cc.back();
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
		typedef typename Container::const_pointer const_pointer;
		size_type size = 3;
		Container c = fill_n<Container>(size);
		pointer p = c.data();
		const Container cc = fill_n<Container>(size);
		const_pointer cp = cc.data();
		assert(p == &c.front());
		assert(cp == &cc.front());
	}
};

template <typename Container>
struct test_top
{
	static void run()
	{
		std::cout << "===== Test: top() =====" << std::endl;
		typedef typename Container::size_type size_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;
		size_type size = 15;
		for (size_type i = 1; i < size; ++i)
		{
			Container c = fill_n<Container>(i);
			reference v = c.top();
			const Container cc = fill_n<Container>(i);
			const_reference cv = cc.top();
			std::cout << "v&:"<< v << "| const v&:" << cv << "||";
		}
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
	RUN_IF(has_top, test_top, Container);
}

#endif