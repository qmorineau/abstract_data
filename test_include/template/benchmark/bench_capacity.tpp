#ifndef BENCH_CAPACITY_TPP
#define BENCH_CAPACITY_TPP

template <class C>
struct bench_empty
{
	static void run(const std::string& name)
    {
		{
			C c;
			do_not_optimize(&c);
	        TimerAccum t(name + "::empty() empty");
			do
			{
				size_t iter = 1000;
				{
					Accum acc(*t);
					for (size_t i = 0; i < iter; ++i)
					{
						bool ret = c.empty();
						do_not_optimize(&ret);
						clobber();
					}
				}
				t.addIterations(iter);
			} while (!t.isEnoughTime());
		}
		{
			C c = fill_n<C>(1000);
			do_not_optimize(&c);
	        TimerAccum t(name + "::empty() full");
			do
			{
				size_t iter = 1000;
				{
					Accum acc(*t);
					for (size_t i = 0; i < iter; ++i)
					{
						bool ret = c.empty();
						do_not_optimize(&ret);
						clobber();
					}
				}
				t.addIterations(iter);
			} while (!t.isEnoughTime());
		}
	}
};

template <class C>
struct bench_size
{
	static void run(const std::string& name)
    {
        typedef typename C::size_type size_type;
		{
			C c;
			do_not_optimize(&c);
	        TimerAccum t(name + "::size() empty");
			do
			{
				size_t iter = 1000;
				{
					Accum acc(*t);
					for (size_t i = 0; i < iter; ++i)
					{
						size_type ret = c.size();
						do_not_optimize(&ret);
						clobber();
					}
				}
				t.addIterations(iter);
			} while (!t.isEnoughTime());
		}
		{
			C c = fill_n<C>(12345);
			do_not_optimize(&c);
	        TimerAccum t(name + "::size() full");
			do
			{
				size_t iter = 1000;
				{
					Accum acc(*t);
					for (size_t i = 0; i < iter; ++i)
					{
						size_type ret = c.size();
						do_not_optimize(&ret);
						clobber();
					}
				}
				t.addIterations(iter);
			} while (!t.isEnoughTime());
		}
	}
};

template <class C>
struct bench_max_size
{
	static void run(const std::string& name)
    {
		typedef typename C::size_type size_type;
        C c;
		do_not_optimize(&c);
        TimerAccum t(name + "::max_size()");
		do
		{
			size_t iter = 1000;
			{
				Accum acc(*t);
				for (size_t i = 0; i < iter; ++i)
				{
					size_type ret = c.max_size();
					do_not_optimize(&ret);
					clobber();
				}
			}
			t.addIterations(iter);
		} while (!t.isEnoughTime());
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
		typedef typename C::size_type size_type;
		{
	        C c;
			do_not_optimize(&c);
	        TimerAccum t(name + "::capacity() empty");
			do
			{
				size_t iter = 1000;
				{
					Accum acc(*t);
					for (size_t i = 0; i < iter; ++i)
					{
						size_type ret = c.capacity();
						do_not_optimize(&ret);
						clobber();
					}
				}
				t.addIterations(iter);
			} while (!t.isEnoughTime());
		}
        {
			C c = fill_n<C>(1000);
			do_not_optimize(&c);
	        TimerAccum t(name + "::capacity() full");
			do
			{
				size_t iter = 1000;
				{
					Accum acc(*t);
					for (size_t i = 0; i < iter; ++i)
					{
						size_type ret = c.capacity();
						do_not_optimize(&ret);
						clobber();
					}
				}
				t.addIterations(iter);
			} while (!t.isEnoughTime());
		}
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