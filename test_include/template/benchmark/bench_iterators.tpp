#ifndef BENCH_ITERATORS_TPP
#define BENCH_ITERATORS_TPP

template <class C>
struct bench_begin
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_rbegin
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_end
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_rend
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
void bench_iterators(const std::string& name)
{
	RUN_BENCH_IF(has_begin, bench_begin, C, name);
	RUN_BENCH_IF(has_rbegin, bench_rbegin, C, name);
	RUN_BENCH_IF(has_end, bench_end, C, name);
	RUN_BENCH_IF(has_rend, bench_rend, C, name);
}

#endif