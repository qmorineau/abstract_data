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
struct test_constructor
{
	static void run()
	{
		std::cout << "===== Test: Default Constructor =====" << std::endl;
		Container a;
	}
};

template <typename Container>
struct test_destructor
{
	static void run()
	{
		std::cout << "===== Test: Default Destructor =====" << std::endl;
		Container* a = new Container();
		delete a;
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
	}
};

template <typename Container>
static void test_assign_it()
{
		std::cout << "===== Test: assign(InputIt first, InputIt last) =====" << std::endl;
}

template <typename Container>
static void test_assign_value()
{
		std::cout << "===== Test: assign(size_type count, const T& value) =====" << std::endl;
}

template <typename Container>
struct test_assign
{
	static void run()
	{
		test_assign_value<Container>();
		test_assign_it<Container>();
	}
};

template <typename Container>
struct test_get_allocator
{
	static void run()
	{
		std::cout << "===== Test: get_allocator() =====" << std::endl;
		typedef typename Container::allocator_type allocator_type;
		Container c;
		allocator_type alloc = c.get_allocator();
	}
};

template <typename Container>
void test_common_func()
{
	std::cout << "=======================================" << std::endl 
	<< "===== Common Func" << std::endl
	<< "=======================================" << std::endl;
	RUN_IF(has_constructor, test_constructor, Container);
	RUN_IF(has_destructor, test_destructor, Container);
	RUN_IF(has_copy_constructor, test_copy_constructor, Container);
	RUN_IF(has_copy_operator, test_copy_operator, Container);
	RUN_IF(has_assign, test_assign, Container);
	RUN_IF(has_get_allocator, test_get_allocator, Container);
}

#endif