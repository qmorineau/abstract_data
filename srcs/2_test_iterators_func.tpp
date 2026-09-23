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

}

template <typename Container>
static void test_rbegin()
{

}

template <typename Container>
static void test_end()
{

}

template <typename Container>
static void test_rend()
{

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
			std::cerr << "IteratorModifier not mananged" << std::endl;
			break;
	}
}

template <typename Container>
void test_iterators_func()
{
	test_modifier<Container>(MOD_BEGIN);
	test_modifier<Container>(MOD_RBEGIN);
	test_modifier<Container>(MOD_END);
	test_modifier<Container>(MOD_REND);
}