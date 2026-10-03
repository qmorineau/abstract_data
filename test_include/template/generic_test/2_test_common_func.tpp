#ifndef TEST_COMMON_FUNC_TPP
#define TEST_COMMON_FUNC_TPP

/*
	Functions managed:
	- constructors()
	- destructors()
	- operator=()
	- assign()
	- get_allocator()
*/

template <typename Container>
struct test_constructor_destructor
{
	static void run()
	{
		std::cout << "===== Test: Default Constructor / Destructor =====" << std::endl;
		Container a;
	}
};

template <typename Container>
struct test_copy_constructor
{
	static void run()
	{
		std::cout << "===== Test: Copy Constructor =====" << std::endl;
		Container a;
		Container b(a);
		if (container_traits<Container>::has_is_equal_operator)
			std::cout << (a == b) << std::endl;
	}
};

template <typename Container>
struct test_copy_operator
{
	static void run()
	{
		std::cout << "===== Test: operator= =====" << std::endl;
		Container a;
		Container b = a;
		if (container_traits<Container>::has_is_equal_operator)
			std::cout << (a == b) << std::endl;
	}
};

template <typename Container>
struct test_assign_it
{
	static void run()
	{
		std::cout << "===== Test: assign(InputIt first, InputIt last) =====" << std::endl;
		typedef typename Container::size_type size_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::iterator iterator;
		std::vector<value_type> v;
		for (size_t i = 0; i < 100; ++i)
			v.push_back(generate_value<std::vector<value_type> >(i));

		Container c;
		c.assign(v.begin(), v.end());
		size_type i = 0;
		for (iterator it = c.begin(); it != c.end(); ++it, ++i)
			assert(*it == v[i]);
		assert(i == v.size());
	}
};

template <typename Container>
struct test_assign_value
{
		static void run()
	{
		std::cout << "===== Test: assign(size_type count, const T& value) =====" << std::endl;
		Container c;
		typedef typename Container::size_type size_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::iterator iterator;
		value_type v = generate_value<Container>(67);
		size_type count = 67;

		c.assign(count, v);
		size_type i = 0;
		for (iterator it = c.begin(); it != c.end(); ++it, ++i)
			assert(*it == v);
		assert(i == count);
	}
};

template <typename Container>
struct test_get_allocator
{
	static void run()
	{
		std::cout << "===== Test: get_allocator() =====" << std::endl;
		Container c;
		typename Container::allocator_type alloc = c.get_allocator();
	}
};

template <typename Container>
void test_common_func()
{
	std::cout << "=======================================" << std::endl 
	<< "===== Common Func" << std::endl
	<< "=======================================" << std::endl;
	RUN_IF(has_constructor_destructor, test_constructor_destructor, Container);
	RUN_IF(has_copy_constructor, test_copy_constructor, Container);
	RUN_IF(has_copy_operator, test_copy_operator, Container);
	RUN_IF(has_assign, test_assign_it, Container);
	RUN_IF(has_assign, test_assign_value, Container);
	RUN_IF(has_get_allocator, test_get_allocator, Container);
}

#endif