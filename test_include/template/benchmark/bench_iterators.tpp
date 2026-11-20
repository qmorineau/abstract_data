#ifndef BENCH_ITERATORS_TPP
#define BENCH_ITERATORS_TPP

template <class C>
struct bench_begin
{
	static void run(const std::string& name)
    {
		typedef typename C::iterator iterator;
		typedef typename C::const_iterator const_iterator;
		C c_empty;
		do_not_optimize(&c_empty);
		C c_full = fill_n<C>(1000);
		do_not_optimize(&c_full);
		size_t size = 1000;
        {
            TimerAccum t(name + "::begin() empty");
			do
			{
				{
					Accum acc(*t);
					for (size_t i = 0; i < size; ++i)
					{
						iterator it = c_empty.begin();
						do_not_optimize(&it);
					}
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
		{
			TimerAccum t(name + "::begin() full");
			do
			{
				{
					Accum acc(*t);
					for (size_t i = 0; i < size; ++i)
					{
						iterator it = c_full.begin();
						do_not_optimize(&it);
					}
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
		}
		{
            TimerAccum t(name + "::begin() const empty");
			do
			{
				{
					Accum acc(*t);
					for (size_t i = 0; i < size; ++i)
					{
						const_iterator it = c_empty.begin();
						do_not_optimize(&it);
					}
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
		{
			TimerAccum t(name + "::begin() const full");
			do
			{
				{
					Accum acc(*t);
					for (size_t i = 0; i < size; ++i)
					{
						const_iterator it = c_full.begin();
						do_not_optimize(&it);
					}
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
		}
	}
};

template <class C>
struct bench_rbegin
{
	static void run(const std::string& name)
	{
		typedef typename C::reverse_iterator reverse_iterator;
		typedef typename C::const_reverse_iterator const_reverse_iterator;
		C c_empty;
		do_not_optimize(&c_empty);
		C c_full = fill_n<C>(1000);
		do_not_optimize(&c_full);
		size_t size = 1000;
        {
            TimerAccum t(name + "::rbegin() empty");
			do
			{
				{
					Accum acc(*t);
					for (size_t i = 0; i < size; ++i)
					{
						reverse_iterator it = c_empty.rbegin();
						do_not_optimize(&it);
					}
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
		{
			TimerAccum t(name + "::rbegin() full");
			do
			{
				{
					Accum acc(*t);
					for (size_t i = 0; i < size; ++i)
					{
						reverse_iterator it = c_full.rbegin();
						do_not_optimize(&it);
					}
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
		}
		{
            TimerAccum t(name + "::rbegin() const empty");
			do
			{
				{
					Accum acc(*t);
					for (size_t i = 0; i < size; ++i)
					{
						const_reverse_iterator it = c_empty.rbegin();
						do_not_optimize(&it);
					}
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
		{
			TimerAccum t(name + "::rbegin() const full");
			do
			{
				{
					Accum acc(*t);
					for (size_t i = 0; i < size; ++i)
					{
						const_reverse_iterator it = c_full.rbegin();
						do_not_optimize(&it);
					}
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
		}
	}
};

template <class C>
struct bench_end
{
	static void run(const std::string& name)
    {
		typedef typename C::iterator iterator;
		typedef typename C::const_iterator const_iterator;
		C c_empty;
		do_not_optimize(&c_empty);
		C c_full = fill_n<C>(1000);
		do_not_optimize(&c_full);
		size_t size = 1000;
        {
            TimerAccum t(name + "::end() empty");
			do
			{
				{
					Accum acc(*t);
					for (size_t i = 0; i < size; ++i)
					{
						iterator it = c_empty.end();
						do_not_optimize(&it);
					}
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
		{
			TimerAccum t(name + "::end() full");
			do
			{
				{
					Accum acc(*t);
					for (size_t i = 0; i < size; ++i)
					{
						iterator it = c_full.end();
						do_not_optimize(&it);
					}
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
		}
		{
            TimerAccum t(name + "::end() const empty");
			do
			{
				{
					Accum acc(*t);
					for (size_t i = 0; i < size; ++i)
					{
						const_iterator it = c_empty.end();
						do_not_optimize(&it);
					}
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
		{
			TimerAccum t(name + "::end() const full");
			do
			{
				{
					Accum acc(*t);
					for (size_t i = 0; i < size; ++i)
					{
						const_iterator it = c_full.end();
						do_not_optimize(&it);
					}
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
		}
	}
};

template <class C>
struct bench_rend
{
	static void run(const std::string& name)
    {
		typedef typename C::reverse_iterator reverse_iterator;
		typedef typename C::const_reverse_iterator const_reverse_iterator;
		C c_empty;
		do_not_optimize(&c_empty);
		C c_full = fill_n<C>(1000);
		do_not_optimize(&c_full);
		size_t size = 1000;
        {
            TimerAccum t(name + "::rend() empty");
			do
			{
				{
					Accum acc(*t);
					for (size_t i = 0; i < size; ++i)
					{
						reverse_iterator it = c_empty.rend();
						do_not_optimize(&it);
					}
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
		{
			TimerAccum t(name + "::rend() full");
			do
			{
				{
					Accum acc(*t);
					for (size_t i = 0; i < size; ++i)
					{
						reverse_iterator it = c_full.rend();
						do_not_optimize(&it);
					}
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
		}
		{
            TimerAccum t(name + "::rend() const empty");
			do
			{
				{
					Accum acc(*t);
					for (size_t i = 0; i < size; ++i)
					{
						const_reverse_iterator it = c_empty.rend();
						do_not_optimize(&it);
					}
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
		{
			TimerAccum t(name + "::rend() const full");
			do
			{
				{
					Accum acc(*t);
					for (size_t i = 0; i < size; ++i)
					{
						const_reverse_iterator it = c_full.rend();
						do_not_optimize(&it);
					}
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
		}
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