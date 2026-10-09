#ifndef BENCH_COMMON_TPP
#define BENCH_COMMON_TPP

template <class C>
struct bench_constructor_destructor
{
	static void run(const std::string& name)
    {
         Timer t (name + " default constructor");
        for (int i = 0; i < 1000000; ++i)
        {
            C c;
            do_not_optimize(&c);
            clobber();
        }
    }
};

template <class C>
struct bench_copy_constructor
{
	static void run(const std::string& name)
    {
        C to_copy = fill_n<C>(1500);
        Timer t (name + " copy constructor");
        for (int i = 0; i < 1000; ++i)
        {
            C tmp(to_copy);
            touch_all(tmp);
        }
    }
};

template <class C>
struct bench_copy_operator
{
	static void run(const std::string& name)
    {
        C to_copy = fill_n<C>(1500);
        C dest;
		do_not_optimize(&dest);
        Timer t (name + "::operator=");
        for (int i = 0; i < 1000; ++i)
        {
            dest = to_copy;
            touch_all(dest);
        }
    }
};

template <class C>
struct bench_assign_value
{
	static void run(const std::string& name)
    {
        typename C::size_type size = 150;
        typename C::value_type value = generate_value<C>(12345);        
        TimerAccum t(name + "::assign(size n, value)");
        for (int i = 0; i < 10000; ++i)
        {
            C c;
			do_not_optimize(&c);
            Accum a(*t);
            c.assign(size, value);
            clobber();
        }
    }
};

template <class C>
struct bench_assign_it
{
	static void run(const std::string& name)
    {
        typedef typename C::value_type value_type;
        std::vector<value_type> v = fill_n<std::vector<value_type> >(100);
        TimerAccum t(name + "::assign(first, last)");
        for (int i = 0; i < 10000; ++i)
        {
            C c;
            do_not_optimize(&c);
            Accum a(*t);
            c.assign(v.begin(), v.end());
            clobber();
        }
    }
};

template <class C>
struct bench_get_allocator
{
	static void run(const std::string& name)
    {
        C c;
		do_not_optimize(&c);
        Timer t(name + "::get_allocator");
        for (int i = 0; i < 1000; ++i)
        {
            do_not_optimize(&c.get_allocator());
            clobber();
        }
    }
};

template <class C>
void bench_common(const std::string& name)
{
    RUN_BENCH_IF(has_constructor_destructor, bench_constructor_destructor, C, name);
    RUN_BENCH_IF(has_copy_constructor, bench_copy_constructor, C, name);
    RUN_BENCH_IF(has_copy_operator, bench_copy_operator, C, name);
    RUN_BENCH_IF(has_assign, bench_assign_value, C, name);
    RUN_BENCH_IF(has_assign, bench_assign_it, C, name);
    RUN_BENCH_IF(has_get_allocator, bench_copy_operator, C, name);
}

#endif