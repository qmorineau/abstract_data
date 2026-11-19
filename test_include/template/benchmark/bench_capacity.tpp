#ifndef BENCH_CAPACITY_TPP
#define BENCH_CAPACITY_TPP

template <class C>
struct bench_empty
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_size
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_max_size
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_resize
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_reserve
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_capacity_func
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
void bench_capacity(const std::string& name)
{
	RUN_BENCH_IF(has_empty, bench_empty, C, name);
	RUN_BENCH_IF(has_size, bench_size, C, name);
	RUN_BENCH_IF(has_max_size, bench_max_size, C, name);
	RUN_BENCH_IF(has_resize, bench_resize, C, name);
	RUN_BENCH_IF(has_reserve, bench_reserve, C, name);
	RUN_BENCH_IF(has_capacity, bench_capacity_func, C, name);
}

#endif