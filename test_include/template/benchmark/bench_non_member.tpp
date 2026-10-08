#ifndef BENCH_NON_MEMBER
#define BENCH_NON_MEMBER

template <class C>
struct bench_is_equal
{
	static void run(const std::string& name)
    {
        (void) name;
    }
};

template <class C>
struct bench_is_different
{
	static void run(const std::string& name)
    {
        (void) name;
    }
};

template <class C>
struct bench_is_lesser
{
	static void run(const std::string& name)
    {
        (void) name;
    }
};

template <class C>
struct bench_is_lesser_equal
{
	static void run(const std::string& name)
    {
        (void) name;
    }
};

template <class C>
struct bench_is_greater
{
	static void run(const std::string& name)
    {
        (void) name;
    }
};

template <class C>
struct bench_is_greater_equal
{
	static void run(const std::string& name)
    {
        (void) name;
    }
};

template <class C>
struct bench_std_swap_specialization
{
	static void run(const std::string& name)
    {
        (void) name;
    }
};

template <class C>
void bench_non_member(const std::string& name)
{
    RUN_BENCH_IF(has_is_equal_operator, bench_is_equal, C, name);
    RUN_BENCH_IF(has_is_different_operator, bench_is_different, C, name);
    RUN_BENCH_IF(has_is_lesser_equal_operator, bench_is_lesser, C, name);
    RUN_BENCH_IF(has_is_lesser_operator, bench_is_lesser_equal, C, name);
    RUN_BENCH_IF(has_is_greater_equal_operator, bench_is_greater, C, name);
    RUN_BENCH_IF(has_is_greater_operator, bench_is_greater_equal, C, name);
    RUN_BENCH_IF(has_swap_specialization, bench_std_swap_specialization, C, name);
}

#endif