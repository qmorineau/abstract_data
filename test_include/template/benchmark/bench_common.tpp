#ifndef BENCH_COMMON_TPP
#define BENCH_COMMON_TPP

template <class C>
struct bench_constructor_destructor
{
	static void run(const std::string& name)
    {
        TimerAccum t(name + " default constructor");
		do
		{
			size_t size = 10000;
			for (size_t i = 0; i < size; ++i)
			{
				Accum acc(*t);
				C c;
				do_not_optimize(&c);
				clobber();
			}
			t.addIterations(size);
		} while (!t.isEnoughTime());
    }
};

template <class C>
struct bench_copy_constructor
{
	static void run(const std::string& name)
    {
        C to_copy = fill_n<C>(1000);
		TimerAccum t(name + " copy constructor");
		do
		{
			size_t size = 10;
			for (size_t i = 0; i < size; ++i)
			{
				Accum acc(*t);
				C tmp(to_copy);
            	touch_all(tmp);
			}
			t.addIterations(size);
		} while (!t.isEnoughTime());
    }
};

template <class C>
struct bench_copy_operator
{
	static void run(const std::string& name)
    {
        TimerAccum t(name + "::operator=");
		C to_copy = fill_n<C>(1500);
		C dest;
		do_not_optimize(&dest);
		do
		{
			size_t size = 10;
			for (size_t i = 0; i < size; ++i)
			{
				Accum acc(*t);
				dest = to_copy;
				touch_all(dest);
			}
			t.addIterations(size);
		} while (!t.isEnoughTime());
    }
};

template <class C>
struct bench_assign_value
{
	static void run(const std::string& name)
    {
        typename C::size_type size_type = 150;
        typename C::value_type value = generate_value<C>(12345);        
        TimerAccum t(name + "::assign(size n, value)");
		do
		{
			size_t size = 100;
			for (size_t i = 0; i < size; ++i)
			{
				C c;
				do_not_optimize(&c);
				{
					Accum acc(*t);
					c.assign(size_type, value);
				}
				clobber();
			}
			t.addIterations(size);
		} while (!t.isEnoughTime());
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
		do
		{
			size_t size = 100;
			for (size_t i = 0; i < size; ++i)
			{
				C c;
				do_not_optimize(&c);
				Accum acc(*t);
				c.assign(v.begin(), v.end());
				clobber();
			}
			t.addIterations(size);
		} while (!t.isEnoughTime());
    }
};

template <class C>
struct bench_get_allocator
{
	static void run(const std::string& name)
    {
        C c;
		do_not_optimize(&c);
        TimerAccum t(name + "::get_allocator");
		do
		{
			size_t size = 100;
			for (size_t i = 0; i < size; ++i)
			{
				Accum acc(*t);
				typename C::allocator_type a = c.get_allocator();
				do_not_optimize(&a);
				clobber();
			}
			t.addIterations(size);
		} while (!t.isEnoughTime());
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
    RUN_BENCH_IF(has_get_allocator, bench_get_allocator, C, name);
}

#endif