#ifndef TEST_INPUT_ITERATORS_FUNC_TPP
#define TEST_INPUT_ITERATORS_FUNC_TPP

static void fill_input_stream(std::istringstream& stream, int test = -1)
{
	if (test == 0)
		stream.str("");
	else if (test == 1)
		stream.str("19");
	else
		stream.str("42 41 40 39 38 37 36 35 34 33");
	stream.clear();
}

template <typename Container>
struct input_test_constructor_it
{
	static void run()
	{
		std::cout << "===== InputIt Test: constructor(InputIt first, InputIt last) =====" << std::endl;
		typedef typename Container::value_type value_type;

		for (int i = 0; i < 3; ++i)
		{
			std::istringstream stream;
			fill_input_stream(stream, i);

			std::istream_iterator<value_type> first(stream);
			std::istream_iterator<value_type> last;

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

		for (int i = 0; i < 3; ++i)
		{
			std::istringstream stream;
			fill_input_stream(stream, i);

			std::istream_iterator<value_type> first(stream);
			std::istream_iterator<value_type> last;

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

		for (int i = 0; i < 3; ++i)
		{
			std::istringstream stream;
			fill_input_stream(stream, i);

			std::istream_iterator<value_type> first(stream);
			std::istream_iterator<value_type> last;

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