#ifndef BENCH_OPERATIONS_TPP
#define BENCH_OPERATIONS_TPP

template <class C>
struct bench_splice_list
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_splice_elem
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_splice_it
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_merge
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_merge_comp
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_remove
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_remove_if
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_reverse
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_unique
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_unique_pred
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};


template <class C>
struct bench_sort
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_sort_comp
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_find
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_count
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_lower_bound
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_upper_bound
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_equal_range
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
void bench_operations(const std::string& name)
{
	RUN_BENCH_IF(has_splice, bench_splice_list, C, name);
	RUN_BENCH_IF(has_splice, bench_splice_elem, C, name);
	RUN_BENCH_IF(has_splice, bench_splice_it, C, name);
	RUN_BENCH_IF(has_merge, bench_merge, C, name);
	RUN_BENCH_IF(has_merge, bench_merge_comp, C, name);
	RUN_BENCH_IF(has_remove, bench_remove, C, name);
	RUN_BENCH_IF(has_remove_if, bench_remove_if, C, name);
	RUN_BENCH_IF(has_reverse, bench_reverse, C, name);
	RUN_BENCH_IF(has_unique, bench_unique, C, name);
	RUN_BENCH_IF(has_unique, bench_unique_pred, C, name);
	RUN_BENCH_IF(has_sort, bench_sort, C, name);
	RUN_BENCH_IF(has_sort, bench_sort_comp, C, name);
	RUN_BENCH_IF(has_find, bench_find, C, name);
	RUN_BENCH_IF(has_count, bench_count, C, name);
	RUN_BENCH_IF(has_lower_bound, bench_lower_bound, C, name);
	RUN_BENCH_IF(has_upper_bound, bench_upper_bound, C, name);
	RUN_BENCH_IF(has_equal_range, bench_equal_range, C, name);
}

#endif