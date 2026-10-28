#ifndef TEST_ITERATOR_FUNC_TPP
#define TEST_ITERATOR_FUNC_TPP

/*
	Functions managed:
	- begin()
	- end()
	- rbegin()
	- rend()
*/

template <typename Container>
struct test_begin
{
	static void run()
	{
		std::cout << "===== Test: begin() =====" << std::endl;
		typedef typename Container::size_type size_type;
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		size_type size = 5;
		Container c = fill_n<Container>(size);
		iterator it = c.begin();
		const_iterator cit = c.begin();
		std::cout << *it << "|" << *cit << "|" << (it == cit) << std::endl;
	}
};

template <typename Container>
struct test_rbegin
{
	static void run()
	{
		std::cout << "===== Test: rbegin() =====" << std::endl;
		typedef typename Container::size_type size_type;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;
		size_type size = 5;
		Container c = fill_n<Container>(size);
		reverse_iterator it = c.rbegin();
		const_reverse_iterator cit = c.rbegin();
		std::cout << *it << "|" << *cit << "|" << (it == cit) << std::endl;
	}
};

template <typename Container>
struct test_end
{
	static void run()
	{
		std::cout << "===== Test: end() =====" << std::endl;
		typedef typename Container::size_type size_type;
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		size_type size = 5;
		Container c = fill_n<Container>(size);
		iterator it = c.end();
		const_iterator cit = c.end();
		std::cout << (it == c.end()) << "|" << (cit == c.end()) << "|" << (it == cit) << std::endl;
	}
};

template <typename Container>
struct test_rend
{
	static void run()
	{
		std::cout << "===== Test: rend() =====" << std::endl;
		typedef typename Container::size_type size_type;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;
		size_type size = 5;
		Container c = fill_n<Container>(size);
		reverse_iterator it = c.rend();
		const_reverse_iterator cit = c.rend();
		std::cout << (it == c.rend()) << "|" << (cit == c.rend()) << "|" << (it == cit) << std::endl;
	}
};

template <typename Container>
void test_iterators_func()
{
	std::cout << "=======================================" << std::endl 
	<< "===== Iterators Func" << std::endl
	<< "=======================================" << std::endl;
	RUN_IF(has_begin, test_begin, Container);
	RUN_IF(has_rbegin, test_rbegin, Container);
	RUN_IF(has_end, test_end, Container);
	RUN_IF(has_rend, test_rend, Container);
}

#endif