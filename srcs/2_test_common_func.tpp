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
	std::cout << "===== Test: Default Constructor =====" << std::endl;
	Timer t("constructor");
	Container a;
}

template <typename Container>
static void test_destructors()
{
	std::cout << "===== Test: Default Destructor =====" << std::endl;
	Timer t("destructor");
	Container* a = new Container();
	delete a;
}

template <typename Container>
static void test_copy_constructor()
{
	std::cout << "===== Test: Copy Constructor =====" << std::endl;
	Timer t("copy constructor");
	Container a;
	Container b(a);
}

template <typename Container>
static void test_copy_operator()
{
	std::cout << "===== Test: operator= =====" << std::endl;
	Timer t("operator=");
	Container a;
	Container b = a;
}

template <typename Container>
static void test_assign_it()
{
	std::cout << "===== Test: assign(InputIt first, InputIt last) =====" << std::endl;
	Timer t("assign(first, last)");
}

template <typename Container>
static void test_assign_value()
{
	std::cout << "===== Test: assign(size_type count, const T& value) =====" << std::endl;
	Timer t("assign(count, value)");
}

template <typename Container>
static void test_assign()
{
	test_assign_value<Container>();
	test_assign_it<Container>();
}

template <typename Container>
static void test_get_allocator()
{
	std::cout << "===== Test: get_allocator() =====" << std::endl;
	Timer t("get_allocator()");
	typedef typename Container::allocator_type allocator_type;
	Container c;
	allocator_type alloc = c.get_allocator();
}

template <typename Container>
static void test_modifier(CommonModifier modifier)
{
	switch (modifier)
	{
		case MOD_CONSTRUCTOR:
			test_constructors<Container>();
			break;
		case MOD_DESTRUCTOR:
			test_destructors<Container>();
			break;
		case MOD_COPY_CONSTRUCTOR:
			if (container_traits<Container>::has_copy_constructor)
				test_copy_constructor<Container>();
			break;
		case MOD_COPY_OPERATOR:
			if (container_traits<Container>::has_copy_operator)
				test_copy_operator<Container>();
			break;
		case MOD_ASSIGN:
			if (container_traits<Container>::has_assign)
				test_assign<Container>();
			break;
		case MOD_GET_ALLOCATOR:
			if (container_traits<Container>::has_get_allocator)
				test_get_allocator<Container>();
			break;
		default:
			std::cout << "CommonModifier not managed" << std::endl;
			break;
	}
}

template <typename Container>
void test_common_func()
{
	std::cout << "=======================================" << std::endl 
	<< "===== Common Func" << std::endl
	<< "=======================================" << std::endl;
	test_modifier<Container>(MOD_CONSTRUCTOR);
	test_modifier<Container>(MOD_DESTRUCTOR);
	test_modifier<Container>(MOD_COPY_CONSTRUCTOR);
	test_modifier<Container>(MOD_COPY_OPERATOR);
	test_modifier<Container>(MOD_ASSIGN);
	test_modifier<Container>(MOD_GET_ALLOCATOR);
}