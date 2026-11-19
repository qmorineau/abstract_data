#ifndef TEST_OPERATIONS_FUNC_TPP
#define TEST_OPERATIONS_FUNC_TPP

/*
	splice
	merge
	remove
	reverse
	unique
	sort
*/

template <typename Container>
struct test_splice_list
{
	static void run()
	{
		std::cout << "===== Test: splice(it pos, list) =====" << std::endl;
		// Container c1 = fill_n<Container>(15);
		// Container c2 = fill_n<Container>(7);
		// todo
	}
};

template <typename Container>
struct test_splice_elem
{
	static void run()
	{
		std::cout << "===== Test: splice(it pos, list, it elem) =====" << std::endl;
		// todo
	}
};

template <typename Container>
struct test_splice_it
{
	static void run()
	{
		std::cout << "===== Test: splice(it pos, list, it first, it last) =====" << std::endl;
		// todo
	}
};

template <typename Container>
struct test_merge
{
	static void run()
	{
		std::cout << "===== Test: merge(list) =====" << std::endl;
		// todo
	}
};

template <typename Container>
struct test_merge_comp
{
	static void run()
	{
		std::cout << "===== Test: merge(list, comp) =====" << std::endl;
		// todo
	}
};


template <typename Container>
struct test_remove
{
	static void run()
	{
		std::cout << "===== Test: remove(const T& value) =====" << std::endl;
		// todo
	}
};

template <typename Container>
struct test_remove_if
{
	static void run()
	{
		std::cout << "===== Test: remove(Predicate pred) =====" << std::endl;
		// todo
	}
};

template <typename Container>
struct test_reverse
{
	static void run()
	{
		std::cout << "===== Test: reverse() =====" << std::endl;
		// todo
	}
};

template <typename Container>
struct test_unique
{
	static void run()
	{
		std::cout << "===== Test: unique() =====" << std::endl;
		// todo
	}
};

template <typename Container>
struct test_unique_pred
{
	static void run()
	{
		std::cout << "===== Test: unique(BinaryPredicate pred) =====" << std::endl;
		// todo
	}
};

template <typename Container>
struct test_sort
{
	static void run()
	{
		std::cout << "===== Test: sort() =====" << std::endl;
		// todo
	}
};

template <typename Container>
struct test_sort_comp
{
	static void run()
	{
		std::cout << "===== Test: sort(Compare comp) =====" << std::endl;
		// todo
	}
};

template <typename Container>
struct test_find
{
	static void run()
	{
		std::cout << "===== Test: iterator find(const key_type& x) =====" << std::endl;
		// todo
		std::cout << "===== Test: const_iterator find(const key_type& x) const =====" << std::endl;
		// todo
	}
};

template <typename Container>
struct test_count
{
	static void run()
	{
		std::cout << "===== Test: count(const key_type& x) =====" << std::endl;
		// todo
	}
};

template <typename Container>
struct test_lower_bound
{
	static void run()
	{
		std::cout << "===== Test: iterator lower_bound(const key_type& x) =====" << std::endl;
		// todo
		std::cout << "===== Test: const_iterator lower_bound(const key_type& x) const =====" << std::endl;
		// todo
	}
};

template <typename Container>
struct test_upper_bound
{
	static void run()
	{
		std::cout << "===== Test: iterator upper_bound(const key_type& x) =====" << std::endl;
		// todo
		std::cout << "===== Test: const_iterator upper_bound(const key_type& x) const =====" << std::endl;
		// todo
	}
};

template <typename Container>
struct test_equal_range
{
	static void run()
	{
		std::cout << "===== Test: pair<iterator,iterator> equal_range(const key_type& x) =====" << std::endl;
		// todo
		std::cout << "===== Test: pair<const_iterator,const_iterator> equal_range(const key_type& x) const =====" << std::endl;
		// todo
	}
};

template <typename Container>
void test_operations_func()
{
	std::cout << "=======================================" << std::endl 
	<< "===== Operations Func" << std::endl
	<< "=======================================" << std::endl;
	RUN_IF(has_splice, test_splice_list, Container);
	RUN_IF(has_splice, test_splice_elem, Container);
	RUN_IF(has_splice, test_splice_it, Container);
	RUN_IF(has_merge, test_merge, Container);
	RUN_IF(has_merge, test_merge_comp, Container);
	RUN_IF(has_remove, test_remove, Container);
	RUN_IF(has_remove_if, test_remove_if, Container);
	RUN_IF(has_reverse, test_reverse, Container);
	RUN_IF(has_unique, test_unique, Container);
	RUN_IF(has_unique, test_unique_pred, Container);
	RUN_IF(has_sort, test_sort, Container);
	RUN_IF(has_sort, test_sort_comp, Container);
	RUN_IF(has_find, test_find, Container);
	RUN_IF(has_count, test_count, Container);
	RUN_IF(has_lower_bound, test_lower_bound, Container);
	RUN_IF(has_upper_bound, test_upper_bound, Container);
	RUN_IF(has_equal_range, test_equal_range, Container);
}

#endif