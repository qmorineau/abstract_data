#ifndef BENCH_OBSERVERS_TPP
#define BENCH_OBSERVERS_TPP

template <class C>
struct bench_key_comp
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
struct bench_value_comp
{
	static void run(const std::string& name)
    {
        (void) name;
		// todo
	}
};

template <class C>
void bench_observers(const std::string& name)
{
	RUN_BENCH_IF(has_key_comp, bench_key_comp, C, name);
	RUN_BENCH_IF(has_value_comp, bench_value_comp, C, name);
}

#endif