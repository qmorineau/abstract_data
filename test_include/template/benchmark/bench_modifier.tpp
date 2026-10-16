#ifndef BENCH_MODIFIER_TPP
#define BENCH_MODIFIER_TPP

template <class C>
struct bench_push_front
{
	static void run(const std::string& name)
    {
		typedef typename C::value_type value_type;
		size_t size = 1000;
        {
            TimerAccum t(name + "::push_front() empty");
			do
			{
				for (size_t i = 0; i < size; ++i)
				{
					value_type value = generate_value<C>(i);
					C c;
					do_not_optimize(&c);
					{
						Accum acc(*t);
						c.push_front(value);
					}
					touch(c);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
        {
            value_type value = generate_value<C>(67);
            C c;
			do_not_optimize(&c);
            TimerAccum t(name + "::push_front()");
			do
			{
				for (size_t i = 0; i < size; ++i)
				{
					{
						Accum acc(*t);
						c.push_front(value);
					}
					touch(c);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
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
			do
			{
				for (size_t i = 0; i < size; ++i)
				{
					C c = fill_n<C>(1);
					do_not_optimize(&c);
					{
						Accum acc(*t);
						c.pop_front();
					}
					touch(c);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
        {
            TimerAccum t(name + "::pop_front() full");
			do
			{
	            C c = fill_n<C>(size);
				do_not_optimize(&c);
				for (size_t i = 0; i < size; ++i)
				{
					{
						Accum acc(*t);
						c.pop_front();
					}
					touch(c);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
    }
};

template <class C>
struct bench_push_back
{
	static void run(const std::string& name)
    {
		typedef typename C::value_type value_type;
		size_t size = 1000;
        {
            TimerAccum t(name + "::push_back() empty");
			do
			{
				for (size_t i = 0; i < size; ++i)
				{
					value_type value = generate_value<C>(i);
					C c;
					do_not_optimize(&c);
					{
						Accum acc(*t);
						c.push_back(value);
					}
					touch(c);
					clobber();
				}
				t.addIterations(size);
			}
			while (!t.isEnoughTime());
        }
        {
            value_type value = generate_value<C>(67);
            C c;
			do_not_optimize(&c);
            TimerAccum t(name + "::push_back()");
			do
			{
				for (size_t i = 0; i < size; ++i)
				{
					{
						Accum acc(*t);
						c.push_back(value);
					}
					touch(c);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
    }
};

template <class C>
struct bench_pop_back
{
	static void run(const std::string& name)
    {
		size_t size = 1000;
        {
            TimerAccum t(name + "::pop_back() empty");
			do
			{
				for (size_t i = 0; i < size; ++i)
				{
					C c = fill_n<C>(1);
					do_not_optimize(&c);
					{
						Accum acc(*t);
						c.pop_back();
					}
					touch(c);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
        {
            TimerAccum t(name + "::pop_back() full");
			do
			{
				C c = fill_n<C>(size);
				do_not_optimize(&c);
				for (size_t i = 0; i < size; ++i)
				{
					{
						Accum acc(*t);
						c.pop_back();
					}
					touch(c);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
    }
};

template <class C>
struct bench_insert_value
{
	static void run(const std::string& name)
    {
		typedef typename C::iterator iterator;
		size_t size = 1000;
		typename C::value_type value = generate_value<C>(42);
		{
			TimerAccum t(name + "::insert(pos, value) empty");
			do
			{
				for (size_t i = 0; i < size; ++i)
				{
					C c;
					do_not_optimize(&c);
					iterator it = c.begin();
					{
						Accum acc(*t);
						c.insert(it, value);
					}
					touch(c);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
		}
		{
			C c;
			do_not_optimize(&c);
			TimerAccum t(name + "::insert(pos, value)");
			do
			{
				for (size_t i = 0; i < size; ++i)
				{
					iterator it = c.end();
					{
						Accum acc(*t);
						c.insert(it, value);
					}
					touch(c);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
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
			do
			{
				for (size_t i = 0; i < size; ++i)
				{
					C c;
					do_not_optimize(&c);
					iterator it = c.begin();
					{
						Accum acc(*t);
						c.insert(it, size, value);
					}
					touch(c);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
		}
		{
			C c;
			do_not_optimize(&c);
			TimerAccum t(name + "::insert(pos, n, value)");
			do
			{
				for (size_t i = 0; i < size; ++i)
				{
					iterator it = c.end();
					{
						Accum acc(*t);
						c.insert(it, size, value);
					}
					touch(c);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
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
			do
			{
				for (size_type i = 0; i < size; ++i)
				{
					C c;
					do_not_optimize(&c);
					iterator it = c.begin();
					{
						Accum acc(*t);
						c.insert(it, first, last);
					}
					touch(c);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
		}
		{
			C c;
			do_not_optimize(&c);
			TimerAccum t(name + "::insert(pos, it first, it last)");
			do
			{
				for (size_type i = 0; i < size; ++i)
				{
					iterator it = c.end();
					{
						Accum acc(*t);
						c.insert(it, first, last);
					}
					touch(c);
					clobber();
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
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
		TimerAccum t(name + "::erase(pos)");
		do
		{
			C c = fill_n<C>(size);
			do_not_optimize(&c);
			for (size_t i = 1; i < size; ++i)
			{
				iterator it = c.begin();
				{
					Accum acc(*t);
					c.erase(it);
				}
				touch(c);
				clobber();
			}
			t.addIterations(size);
		} while (!t.isEnoughTime());
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
		do
		{
			for (size_t i = 1; i < size; ++i)
			{
				C c = fill_n<C>(size);
				do_not_optimize(&c);
				iterator first = c.begin();
				iterator last = c.end();
				{
					Accum acc(*t);
					c.erase(first, last);
				}
				touch(c);
				clobber();
			}
			t.addIterations(size);
		} while (!t.isEnoughTime());
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
		TimerAccum t(name + "::swap(Container)");
		size_t size = 1000;
		do
		{
			for (size_t i = 0; i < size; ++i)
			{
				{
					Accum acc(*t);
					a.swap(b);
				}
				touch(a);
				touch(b);
				clobber();
			}
			t.addIterations(size);
		} while (!t.isEnoughTime());
    }
};

template <class C>
struct bench_clear
{
	static void run(const std::string& name)
    {
		TimerAccum t(name + "::clear()");
		size_t size = 1000;
		do
		{
			for (size_t i = 0; i < size; ++i)
			{
				C c = fill_n<C>(1000);
				do_not_optimize(&c);
				{
					Accum acc(*t);
					c.clear();
				}
				touch(c);
				clobber();
			}
			t.addIterations(size);
		} while (!t.isEnoughTime());
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