#ifndef TEST_OBSERVERS_FUNC_TPP
#define TEST_OBSERVERS_FUNC_TPP

template <typename Container>
struct test_key_comp
{
	static void run()
	{
		std::cout << "===== Test: key_comp() =====" << std::endl;
	}
};

template <typename Container>
struct test_value_comp
{
	static void run()
	{
		std::cout << "===== Test: value_comp() =====" << std::endl;
	}
};

template <typename Container>
void test_observers_func()
{
	std::cout << "=======================================" << std::endl 
	<< "===== Observers Func" << std::endl
	<< "=======================================" << std::endl;
	RUN_IF(has_key_comp, test_key_comp, Container);
	RUN_IF(has_value_comp, test_value_comp, Container);
}

#endif