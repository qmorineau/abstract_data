#include "test.hpp"

template <class C, typename T>
static void bench_push_back_empty(std::string type)
{
	TimerAccum t(type + ": push_back_empty");
	for (int i = 0; i < 100000; ++i)
	{
		C c;
		Accum a(t.total());
		c.push_back(generate_value<C>(i));
	}
}

template <class C, typename T>
static void bench_push_back(std::string type)
{
	Timer t(type + ": push_back");
	C c;
	for (int i = 0; i < 100000; ++i)
		c.push_back(generate_value<C>(i));
}

template <typename T>
static void bench_vector(std::string type)
{
	bench_push_back_empty<ns::vector<T>, T>("vector<" + type + ">");
	bench_push_back<ns::vector<T>, T>("vector<" + type + ">");
}

void benchmark()
{
	bench_vector<int>("int");
	bench_vector<std::string>("std::string");
	bench_vector<Foo>("Foo");
}