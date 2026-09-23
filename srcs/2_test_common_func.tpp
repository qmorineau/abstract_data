#include "test.hpp"

/*
	Functions managed:
	- constructors()
	- destructors()
	- operator=()
	- assign()
	- get_allocator()
*/

template <typename Container>
static void test_constructors()
{
	// todo
}

template <typename Container>
static void test_destructors()
{
	// todo
}

template <typename Container>
static void test_copy_constructor()
{
	// todo
}

template <typename Container>
static void test_copy_operator()
{
	// todo
}

template <typename Container>
static void test_assign()
{
	// todo
}

template <typename Container>
static void test_get_allocator()
{
	// todo
}

template <typename Container>
static void test_modifier(CommonModifier modifier)
{
	switch (modifier)
	{
		case MOD_CONSTRUCTOR:
			if (container_traits<Container>::has_begin)
				test_constructors<Container>();
			break;
		case MOD_DESTRUCTOR:
			if (container_traits<Container>::has_rbegin)
				test_destructors<Container>();
			break;
		case MOD_COPY_CONSTRUCTOR:
			if (container_traits<Container>::has_end)
				test_copy_constructor<Container>();
			break;
		case MOD_COPY_OPERATOR:
			if (container_traits<Container>::has_rend)
				test_copy_operator<Container>();
			break;
		case MOD_ASSIGN:
			if (container_traits<Container>::has_rend)
				test_assign<Container>();
			break;
		case MOD_GET_ALLOCATOR:
			if (container_traits<Container>::has_rend)
				test_get_allocator<Container>();
			break;
		default:
			std::cerr << "CommonModifier not mananged" << std::endl;
			break;
	}
}

template <typename Container>
void test_common_func()
{
	std::cout << "=|=|= Common Func =|=|=" << std::endl;
	test_modifier<Container>(MOD_BEGIN);
	test_modifier<Container>(MOD_RBEGIN);
	test_modifier<Container>(MOD_END);
	test_modifier<Container>(MOD_REND);
}