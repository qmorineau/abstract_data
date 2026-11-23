#ifndef TEST_INPUT_ITERATORS_FUNC_TPP
#define TEST_INPUT_ITERATORS_FUNC_TPP

template <class input_it>
static input_it init(int test = -1)
{
	if (test == 0)
	{
		input_it::reset("");
		return input_it(true);
	}
	else if (test == 1)
	{
		input_it::reset("19");
		return input_it(true);
	}
	else
	{
		input_it::reset("420 410 400 390 380 370 360 350 340 330");
		return input_it(true);
	}
}

template <typename Container>
struct input_test_constructor_it
{
	static void run()
	{
		std::cout << "===== InputIt Test: constructor(InputIt first, InputIt last) =====" << std::endl;
		typedef typename Container::value_type	value_type;
		typedef test_input_iterator<value_type>	input_it;

		for (int i = 0; i < 3; ++i)
		{
			input_it first = init<input_it>(i);
			input_it last;

			Container c(first, last);
			print(c);
			std::cout << std::endl;
		}
	}
};

template <typename Container>
struct input_test_assign_it
{
	static void run()
	{
		std::cout << "===== InputIt Test: assign(InputIt first, InputIt last) =====" << std::endl;
		typedef typename Container::value_type value_type;
		typedef test_input_iterator<value_type>	input_it;

		for (int i = 0; i < 3; ++i)
		{
			input_it first = init<input_it>(i);
			input_it last;

			Container c;
			c.assign(first, last);
			print(c);
			std::cout << std::endl;
		}
	}
};

template <typename Container>
struct input_test_insert_it
{
	static void run()
	{
		std::cout << "===== InputIt Test: insert(it pos, InputIt first, InputIt last) =====" << std::endl;
		typedef typename Container::value_type value_type;
		typedef test_input_iterator<value_type>	input_it;

		for (int i = 0; i < 3; ++i)
		{
			input_it first = init<input_it>(i);
			input_it last;

			Container c;
			c.insert(c.begin(), first, last);
			print(c);
			std::cout << std::endl;
		}
	}
};

// template <typename Container>
// struct input_map_test_insert_it
// {
// 	static void run()
// 	{
// 		std::cout << "===== InputIt Test: insert(it pos, InputIt first, InputIt last) =====" << std::endl;
// 		typedef typename Container::value_type value_type;
// 		std::istringstream stream;
// 		fill_input_stream(stream);

// 		std::istream_iterator<value_type> first(stream);
// 		std::istream_iterator<value_type> last;

// 		Container c;
// 		c.insert(c.begin(), first, last);
// 		print(c);
// 	}
// };

template <typename Container>
void test_input_iterators_func()
{
	std::cout << "=======================================" << std::endl 
	<< "===== Input Iterators Func" << std::endl
	<< "=======================================" << std::endl;
	RUN_IF(has_constructor_it, input_test_constructor_it, Container);
	RUN_IF(has_assign, input_test_assign_it, Container);
	RUN_IF(has_insert, input_test_insert_it, Container);
	// todo
	// RUN_IF(has_map_insert, input_test_insert_it, Container);
}

#endif