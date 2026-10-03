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
		Container c = fill_n<Container>(25);
		assert(c.begin() != c.end());
		c.clear();
		assert(c.begin() == c.end());
	}
};

template <typename Container>
struct test_insert_value
{
	static void run()
	{
		std::cout << "===== Test: insert(const_it pos, const T& value) =====" << std::endl;
		typedef typename Container::iterator iterator;
		Container c = fill_n<Container>(150);
		typename Container::value_type value = generate_value<Container>(6767);
		iterator it = c.insert(c.begin(), value);
		std::cout << "it=" << std::distance(c.begin(), it) << "|";
		print(c);
		it = c.insert(c.end(), value);
		std::cout << "it=" << std::distance(c.begin(), it) << "|";
		print(c);
		it = c.begin();
		std::advance(it, 42);
		it = c.insert(it, value);
		std::cout << "it=" << std::distance(c.begin(), it) << "|";
		print(c);
	}
};

template <typename Container>
struct test_insert_n_value
{
	static void run()
	{
		std::cout << "===== Test: insert(const_it pos, size_type count, const T& value) =====" << std::endl;
		typedef typename Container::size_type size_type;
		typedef typename Container::iterator iterator;
		size_type n = 22;
		Container c = fill_n<Container>(150);
		typename Container::value_type value = generate_value<Container>(6767);
		c.insert(c.begin(), n, value);
		print(c);
		n = 19;
		c.insert(c.end(), n, value);
		print(c);
		n = 12;
		iterator it = c.begin();
		std::advance(it, 42);
		c.insert(it, n, value);
		print(c);
	}
};

template <typename Container>
struct test_insert_it
{
	static void run()
	{
		std::cout << "===== Test: insert(const_it pos, InputIt first, InputIt last) =====" << std::endl;
		typedef typename Container::value_type value_type;
		typedef typename Container::iterator iterator;
		std::vector<value_type> v = fill_n<std::vector<value_type> >(15);
		Container c = fill_n<Container>(150);
		c.insert(c.begin(), v.begin(), v.end());
		print(c);
		c.insert(c.end(), v.begin(), v.end());
		print(c);
		iterator it = c.begin();
		std::advance(it, 42);
		c.insert(it, v.begin(), v.end());
		print(c);
	}
};

template <typename Container>
struct test_erase_pos
{
	static void run()
	{
		std::cout << "===== Test: erase(iterator pos) =====" << std::endl;
		typedef typename Container::iterator iterator;

		Container c = fill_n<Container>(15);
		iterator it;
		print<Container>(c);
		it = c.erase(c.begin());
		std::cout << "it=" << std::distance(c.begin(), it) << "|";
		print<Container>(c);
		it = c.begin();
		std::advance(it, 5);
		it = c.erase(it);
		std::cout << "it=" << std::distance(c.begin(), it) << "|";
		print<Container>(c);
		it = c.begin();
		std::advance(it, 12);
		it = c.erase(it);
		std::cout << "it=" << std::distance(c.begin(), it) << "|";
		print<Container>(c);
	}
};

template <typename Container>
struct test_erase_it
{
	static void run()
	{
		std::cout << "===== Test: erase(iterator first, iterator last) =====" << std::endl;
		typedef typename Container::iterator iterator;		

		Container c = fill_n<Container>(150);
		iterator it;
		iterator first;
		iterator last;
		print<Container>(c);
		last = c.begin();
		std::advance(last, 19);
		it = c.erase(c.begin(), last);
		std::cout << "it=" << std::distance(c.begin(), it) << "|";
		print<Container>(c);
		first = c.begin();
		std::advance(first, 34);
		last = c.begin();
		std::advance(last, 51);
		it = c.erase(first, last);
		std::cout << "it=" << std::distance(c.begin(), it) << "|";
		print<Container>(c);
		first = c.begin();
		std::advance(first, 97);
		it = c.erase(first, c.end());
		std::cout << "it=" << std::distance(c.begin(), it) << "|";
		print<Container>(c);
	}
};

template <typename Container>
struct test_erase_key
{
	static void run()
	{
		std::cout << "===== Test: erase(key) =====" << std::endl;
		// to do
		assert(true == false);
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
		assert(true == false);
	}
};

template <typename Container>
struct test_swap
{
	static void run()
	{
		std::cout << "===== Test: swap() =====" << std::endl;
		typedef typename Container::value_type value_type;
		std::vector<value_type> v1 = fill_n<std::vector<value_type> >(67);
		std::vector<value_type> v2;
		for (typename Container::size_type i = 0; i < 100; ++i)
			v2.push_back(generate_value<std::vector<value_type> >(67));
		Container a(v1.begin(), v1.end());
		Container b(v2.begin(), v2.end());
		Container c(a);
		Container d(b);
		assert(a == c);
		assert(b == d);
		c.swap(d);
		assert(a == d);
		assert(b == c);
	}
};

template <typename Container>
void test_modifiers_func()
{
	std::cout << "=======================================" << std::endl 
	<< "===== Modifiers Func" << std::endl
	<< "=======================================" << std::endl;
	RUN_IF(has_clear, test_clear, Container);
	RUN_IF(has_insert, test_insert_value, Container);
	RUN_IF(has_insert, test_insert_n_value, Container);
	RUN_IF(has_insert, test_insert_it, Container);
	RUN_IF(has_erase, test_erase_pos, Container);
	RUN_IF(has_erase, test_erase_it, Container);
	RUN_IF(has_erase_key, test_erase_key, Container);
	RUN_IF(has_push_back, test_push_back, Container);
	RUN_IF(has_pop_back, test_pop_back, Container);
	// RUN_IF(has_resize, test_resize, Container);
	RUN_IF(has_swap, test_swap, Container);
}

#endif