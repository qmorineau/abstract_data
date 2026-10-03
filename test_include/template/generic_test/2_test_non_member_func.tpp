#ifndef TEST_NON_MEMBER_FUNC_TPP
#define TEST_NON_MEMBER_FUNC_TPP

/*
	operator==
	operator!=
	operator<=
	operator<
	operator>=
	operator>
	std::swap
*/

template <typename Container>
struct test_is_equal
{
	static void run()
	{
		std::cout << "===== Test: operator== =====" << std::endl;
	}
};

template <typename Container>
struct test_is_different
{
	static void run()
	{
		std::cout << "===== Test: operator!= =====" << std::endl;
		// to do
	}
};

template <typename Container>
struct test_is_greater_equal
{
	static void run()
	{
		std::cout << "===== Test: operate>= =====" << std::endl;
		// to do
	}
};

template <typename Container>
struct test_is_greater
{
	static void run()
	{
		std::cout << "===== Test: operator> =====" << std::endl;
		// to do
	}
};

template <typename Container>
struct test_is_lesser_equal
{
	static void run()
	{
		std::cout << "===== Test: operator<= =====" << std::endl;
		// to do
	}
};

template <typename Container>
struct test_is_lesser
{
	static void run()
	{
		std::cout << "===== Test: operator< =====" << std::endl;
		// to do
	}
};

template <typename Container>
struct test_swap_specialization
{
	static void run()
	{
		std::cout << "===== Test: std::swap() =====" << std::endl;
		// to do
	}
};

template <typename Container>
void test_non_member_func()
{
	std::cout << "=======================================" << std::endl 
	<< "===== Non Member Func" << std::endl
	<< "=======================================" << std::endl;
	RUN_IF(has_is_equal_operator, test_is_equal, Container);
	RUN_IF(has_is_different_operator, test_is_different, Container);
	RUN_IF(has_is_lesser_equal_operator, test_is_lesser_equal, Container);
	RUN_IF(has_is_lesser_operator, test_is_lesser, Container);
	RUN_IF(has_is_greater_equal_operator, test_is_greater_equal, Container);
	RUN_IF(has_is_greater_operator, test_is_greater, Container);
	RUN_IF(has_swap_specialization, test_swap_specialization, Container);
}

#endif