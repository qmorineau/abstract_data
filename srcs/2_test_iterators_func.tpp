#include "test.hpp"

/*
	Functions managed:
	- begin()
	- end()
	- rbegin()
	- rend()
*/

template <typename Container>
static void test_begin()
{
	std::cout << "===== Test: begin() =====" << std::endl;
	Timer t("begin()");
	// to do
}

template <typename Container>
static void test_rbegin()
{
	std::cout << "===== Test: rbegin() =====" << std::endl;
	Timer t("rbegin()");
	// to do
}

template <typename Container>
static void test_end()
{
	std::cout << "===== Test: end() =====" << std::endl;
	Timer t("end()");
	// to do
}

template <typename Container>
static void test_rend()
{
	std::cout << "===== Test: rend() =====" << std::endl;
	Timer t("rend()");
	// to do
}

template <typename Container>
static void test_modifier(IteratorModifier modifier)
{
	switch (modifier)
	{
		case MOD_BEGIN:
			if (container_traits<Container>::has_begin)
				test_begin<Container>();
			break;
		case MOD_RBEGIN:
			if (container_traits<Container>::has_rbegin)
				test_rbegin<Container>();
			break;
		case MOD_END:
			if (container_traits<Container>::has_end)
				test_end<Container>();
			break;
		case MOD_REND:
			if (container_traits<Container>::has_rend)
				test_rend<Container>();
			break;
		default:
			std::cerr << "IteratorModifier not managed" << std::endl;
			break;
	}
}

template <typename Container>
void test_iterators_func()
{
	std::cout << "=======================================" << std::endl 
	<< "===== Iterators Func" << std::endl
	<< "=======================================" << std::endl;
	test_modifier<Container>(MOD_BEGIN);
	test_modifier<Container>(MOD_RBEGIN);
	test_modifier<Container>(MOD_END);
	test_modifier<Container>(MOD_REND);
}