#include "test.hpp"

template <class C>
struct bench_push_back_empty
{
	static void run(const std::string& name)
    {
		TimerAccum t(name + ": push_back_empty");
		for (int i = 0; i < 100000; ++i)
		{
			C c;
			Accum a(t.total());
			c.push_back(generate_value<C>(i));
		}
	}
};

template <class C>
struct bench_push_back
{
	static void run(const std::string& name)
    {
		Timer t(name + ": push_back");
		C c;
		for (int i = 0; i < 100000; ++i)
			c.push_back(generate_value<C>(i));
	}
};

template <class C>
struct bench_pop_back_full
{
	static void run(const std::string& name)
    {
		size_t size = 100000;
		C c = fill_n<C>(size);
		Timer t(name + ": pop_back_full");
		for (size_t i = 0; i < size; ++i)
		{
			c.pop_back();
		}
	}
};

template <class C>
struct bench_pop_back
{
	static void run(const std::string& name)
    {
		TimerAccum t(name + ": pop_back_empty");
		for (int i = 0; i < 100000; ++i)
		{
			C c = fill_n<C>(1);
			Accum a(t.total());
			c.pop_back();
		}
	}
};

template <class C>
static void bench_unit(const std::string name)
{
	RUN_BENCH_IF(has_push_back, bench_push_back, C, name);
	RUN_BENCH_IF(has_push_back, bench_push_back_empty, C, name);
	RUN_BENCH_IF(has_pop_back, bench_pop_back, C, name);
	RUN_BENCH_IF(has_pop_back, bench_pop_back_full, C, name);
}

template <template <typename, typename> class Container>
void benchmark_type(std::string name)
{
	bench_unit<Container<int, std::allocator<int> > >(name + "<int>");
	bench_unit<Container<std::string, std::allocator<std::string> > >(name + "<std::string>");
	bench_unit<Container<Foo, std::allocator<Foo> > >(name + "<Foo>");
	std::cout << std::endl;
}

void benchmark()
{
	benchmark_type<ns::vector>("vector");
	benchmark_type<ns::list>("list");
}