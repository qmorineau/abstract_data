#ifndef BENCH_OBSERVERS_TPP
#define BENCH_OBSERVERS_TPP

template <class C>
struct bench_key_comp
{
	static void run(const std::string& name)
    {
		typedef typename C::key_compare key_compare;

		C c;
		do_not_optimize(&c);
		size_t size = 1000;
        {
            TimerAccum t(name + "::key_comp()");
			do
			{
				{
					Accum acc(*t);
					for (size_t i = 0; i < size; ++i)
					{
						key_compare ret = c.key_comp();
						do_not_optimize(&ret);
					}
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
	}
};

template <class C>
struct bench_value_comp
{
	static void run(const std::string& name)
    {
		typedef typename C::value_compare value_compare;

		C c;
		do_not_optimize(&c);
		size_t size = 1000;
        {
            TimerAccum t(name + "::value_comp()");
			do
			{
				{
					Accum acc(*t);
					for (size_t i = 0; i < size; ++i)
					{
						value_compare ret = c.value_comp();
						do_not_optimize(&ret);
					}
				}
				t.addIterations(size);
			} while (!t.isEnoughTime());
        }
	}
};

template <class C>
void bench_observers(const std::string& name)
{
	RUN_BENCH_IF(has_key_comp, bench_key_comp, C, name);
	RUN_BENCH_IF(has_value_comp, bench_value_comp, C, name);
}

#endif