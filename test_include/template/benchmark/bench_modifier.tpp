#ifndef BENCH_MODIFIER_TPP
#define BENCH_MODIFIER_TPP

template <class C>
struct bench_push_front
{
	static void run(const std::string& name)
    {
		typedef typename C::value_type value_type;
        {
            TimerAccum t(name + "::push_front() empty");
            for (int i = 0; i < 100000; ++i)
            {
                value_type value = generate_value<C>(i);
                C c;
				do_not_optimize(&c);
                Accum a(*t);
                c.push_front(value);
				touch(c);
				clobber();
            }
        }
        {
            value_type value = generate_value<C>(67);
            C c;
			do_not_optimize(&c);
            Timer t(name + "::push_front()");
            for (int i = 0; i < 100000; ++i)
			{
                c.push_front(value);
				touch(c);
				clobber();
			}
        }
    }
};

template <class C>
struct bench_pop_front
{
	static void run(const std::string& name)
    {
        size_t size = 1000;
        {
            TimerAccum t(name + "::pop_front() empty");
            for (size_t i = 0; i < size; ++i)
            {
                C c = fill_n<C>(1);
				do_not_optimize(&c);
                Accum a(*t);
                c.pop_front();
				touch(c);
				clobber();
            }
        }
        {
            C c = fill_n<C>(size);
			do_not_optimize(&c);
            Timer t(name + "::pop_front() full");
            for (size_t i = 0; i < size; ++i)
			{
                c.pop_front();
				touch(c);
				clobber();
			}
        }
    }
};

template <class C>
struct bench_push_back
{
	static void run(const std::string& name)
    {
		typedef typename C::value_type value_type;
        {
            TimerAccum t(name + "::push_back() empty");
            for (int i = 0; i < 100000; ++i)
            {
                value_type value = generate_value<C>(i);
                C c;
				do_not_optimize(&c);
                Accum a(*t);
                c.push_back(value);
				touch(c);
				clobber();
            }
        }
        {
            value_type value = generate_value<C>(67);
            C c;
			do_not_optimize(&c);
            Timer t(name + "::push_back()");
            for (int i = 0; i < 100000; ++i)
			{
                c.push_back(value);
				touch(c);
				clobber();
			}
        }
    }
};

template <class C>
struct bench_pop_back
{
	static void run(const std::string& name)
    {
        {
            TimerAccum t(name + "::pop_back() empty");
            for (int i = 0; i < 100000; ++i)
            {
                C c = fill_n<C>(1);
				do_not_optimize(&c);
                Accum a(*t);
                c.pop_back();
				touch(c);
				clobber();
            }
        }
        {
            size_t size = 100000;
            C c = fill_n<C>(size);
			do_not_optimize(&c);
            Timer t(name + "::pop_back() full");
            for (size_t i = 0; i < size; ++i)
			{
                c.pop_back();
				touch(c);
				clobber();
			}
        }
    }
};

template <class C>
struct bench_insert_value
{
	static void run(const std::string& name)
    {
		typedef typename C::iterator iterator;
		typename C::value_type value = generate_value<C>(42);
		{
			TimerAccum t(name + "::insert(pos, value) empty");
			for (int i = 0; i < 100000; ++i)
			{
				C c;
				do_not_optimize(&c);
				iterator it = c.begin();
				Accum a(*t);
				c.insert(it, value);
				touch(c);
				clobber();
			}
		}
		{
			C c;
			do_not_optimize(&c);
			TimerAccum t(name + "::insert(pos, value)");
			for (int i = 0; i < 100000; ++i)
			{
				iterator it = c.end();
				Accum a(*t);
				c.insert(it, value);
				touch(c);
				clobber();
			}
		}
    }
};

template <class C>
struct bench_insert_n_value
{
	static void run(const std::string& name)
    {
		typedef typename C::iterator iterator;
		typename C::size_type size = 1000;
		typename C::value_type value = generate_value<C>(42);
        {
			TimerAccum t(name + "::insert(pos, n, value) empty");
			for (int i = 0; i < 1000; ++i)
			{
				C c;
				do_not_optimize(&c);
				iterator it = c.begin();
				Accum a(*t);
				c.insert(it, size, value);
				touch(c);
				clobber();
			}
		}
		{
			C c;
			do_not_optimize(&c);
			TimerAccum t(name + "::insert(pos, n, value)");
			for (int i = 0; i < 1000; ++i)
			{
				iterator it = c.end();
				Accum a(*t);
				c.insert(it, size, value);
				touch(c);
				clobber();
			}
		}
    }
};

template <class C>
struct bench_insert_it
{
	static void run(const std::string& name)
    {
		typedef typename C::iterator iterator;
		typedef typename C::size_type size_type;
		typedef typename C::value_type value_type;
		typedef typename std::vector<value_type>::iterator v_iterator;
		size_type size = 1000;
        std::vector<value_type> v = fill_n<std::vector<value_type> >(size);
		v_iterator first = v.begin();
		v_iterator last = v.end();
        {
			TimerAccum t(name + "::insert(pos, it first, it last) empty");
			for (size_type i = 0; i < size; ++i)
			{
				C c;
				do_not_optimize(&c);
				iterator it = c.begin();
				Accum a(*t);
				c.insert(it, first, last);
				touch(c);
				clobber();
			}
		}
		{
			C c;
			do_not_optimize(&c);
			TimerAccum t(name + "::insert(pos, it first, it last)");
			for (size_type i = 0; i < size; ++i)
			{
				iterator it = c.end();
				Accum a(*t);
				c.insert(it, first, last);
				touch(c);
				clobber();
			}
		}
    }
};

template <class C>
struct bench_erase_pos
{
	static void run(const std::string& name)
    {
		typedef typename C::iterator iterator;
		size_t size = 1000;
		C c = fill_n<C>(size);
		do_not_optimize(&c);
		TimerAccum t(name + "::erase(pos)");
		for (size_t i = 0; i < size; ++i)
		{
			iterator it = c.begin();
			Accum a(*t);
			c.erase(it);
			touch(c);
			clobber();
		}
    }
};

template <class C>
struct bench_erase_it
{
	static void run(const std::string& name)
    {
		typedef typename C::iterator iterator;
        size_t size = 1000;
		TimerAccum t(name + "::erase(it first, it last)");
		for (size_t i = 0; i < size; ++i)
		{
			C c = fill_n<C>(size);
			do_not_optimize(&c);
			iterator first = c.begin();
			iterator last = c.end();
			Accum a(*t);
			c.erase(first, last);
			touch(c);
			clobber();
		}
    }
};

template <class C>
struct bench_swap
{
	static void run(const std::string& name)
    {
		C a = fill_n<C>(1000);
		C b = fill_n<C>(1001);
		do_not_optimize(&a);
		do_not_optimize(&b);
		Timer t(name + "::swap(Container)");
		for (int i = 0; i < 100000; ++i)
		{
			a.swap(b);
			touch(a);
			touch(b);
			clobber();
		}
    }
};

template <class C>
struct bench_clear
{
	static void run(const std::string& name)
    {
		TimerAccum t(name + "::clear()");
		for (int i = 0; i < 1000; ++i)
		{
	        C c = fill_n<C>(1000);
			do_not_optimize(&c);
			Accum a(*t);
			c.clear();
			touch(c);
			clobber();
		}
    }
};

template <class C>
void bench_modifier(const std::string& name)
{
    RUN_BENCH_IF(has_push_front, bench_push_front, C, name);
    RUN_BENCH_IF(has_pop_front, bench_pop_front, C, name);
    RUN_BENCH_IF(has_push_back, bench_push_back, C, name);
    RUN_BENCH_IF(has_pop_back, bench_pop_back, C, name);
    RUN_BENCH_IF(has_insert, bench_insert_value, C, name);
    RUN_BENCH_IF(has_insert, bench_insert_n_value, C, name);
    RUN_BENCH_IF(has_insert, bench_insert_it, C, name);
    RUN_BENCH_IF(has_erase, bench_erase_pos, C, name);
    RUN_BENCH_IF(has_erase, bench_erase_it, C, name);
    RUN_BENCH_IF(has_swap, bench_swap, C, name);
    RUN_BENCH_IF(has_clear, bench_clear, C, name);
}

#endif