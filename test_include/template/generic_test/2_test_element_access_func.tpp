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
static void test_at()
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

template <typename Container>
static void test_operator_square_bracket()
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

template <typename Container>
static void test_front()
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

template <typename Container>
static void test_back()
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

template <typename Container>
static void test_data()
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

template <typename Container>
static void test_modifier(ElementAccessModifier modifier)
{
	switch (modifier)
	{
		case MOD_AT:
			if (container_traits<Container>::has_at)
				test_at<Container>();
			break;
		case MOD_OPERATOR_SQUARE_BRACKET:
			if (container_traits<Container>::has_operator_square_bracket)
				test_operator_square_bracket<Container>();
			break;
		case MOD_FRONT:
			if (container_traits<Container>::has_front)
				test_front<Container>();
			break;
		case MOD_BACK:
			if (container_traits<Container>::has_back)
				test_back<Container>();
			break;
		case MOD_DATA:
			if (container_traits<Container>::has_data)
				test_data<Container>();
			break;
		default:
			std::cerr << "ElementAccessModifier not managed" << std::endl;
			break;
	}
}

template <typename Container>
void test_element_access_func()
{
	std::cout << "=======================================" << std::endl 
	<< "===== Element Access Func" << std::endl
	<< "=======================================" << std::endl;
	test_modifier<Container>(MOD_AT);
	test_modifier<Container>(MOD_OPERATOR_SQUARE_BRACKET);
	test_modifier<Container>(MOD_FRONT);
	test_modifier<Container>(MOD_BACK);
	test_modifier<Container>(MOD_DATA);
}

#endif