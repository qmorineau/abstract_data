#include "test.hpp"

template <class C>
static void bench_unit(const std::string name)
{
	bench_common<C>(name);
	bench_element_access<C>(name);
	bench_modifier<C>(name);
	bench_non_member<C>(name);
}

template <template <typename, typename> class Container>
void benchmark_type(std::string name)
{
	bench_unit<Container<int, std::allocator<int> > >(name + "<int>");
	bench_unit<Container<std::string, std::allocator<std::string> > >(name + "<std::string>");
	bench_unit<Container<Foo, std::allocator<Foo> > >(name + "<Foo>");
	std::cout << std::endl;
}

int main()
{
	benchmark_type<ns::vector>("vector");
	benchmark_type<ns::list>("list");
}