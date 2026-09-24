#include "../test.hpp"

/*
	clear
	insert
	erase
	push_back
	pop_back
	resize
	swap
*/

template <typename Container>
static void test_clear()
{
	std::cout << "===== Test: clear() =====" << std::endl;
	Timer t("clear()");
	// to do
}

template <typename Container>
static void test_insert()
{
	std::cout << "===== Test: insert() =====" << std::endl;
	Timer t("insert()");
	// to do
}

template <typename Container>
static void test_erase()
{
	std::cout << "===== Test: erase() =====" << std::endl;
	Timer t("erase()");
	// to do
}

template <typename Container>
static void test_push_back()
{
	std::cout << "===== Test: push_back() =====" << std::endl;
	Timer t("push_back()");
	Container c;
	for (std::size_t i = 0; i < 150; ++i)
	{
		c.push_back(generate_value<Container>(i));
		std::cout << *c.rbegin() << "|";
	}
	std::cout << std::endl;
}

template <typename Container>
static void test_pop_back()
{
	std::cout << "===== Test: pop_back() =====" << std::endl;
	Timer t("pop_back()");
	typedef typename Container::size_type size_type;
	size_type size = 150;
	Container c;
	fill_n(c, size);
	for (size_type i = 0; i < size - 1; ++i)
	{
		c.pop_back();
		std::cout << *c.rbegin() << "|";
	}
	std::cout << std::endl;
}

template <typename Container>
static void test_resize()
{
	std::cout << "===== Test: resize() =====" << std::endl;
	Timer t("resize()");
	// to do
}

template <typename Container>
static void test_swap()
{
	std::cout << "===== Test: swap() =====" << std::endl;
	Timer t("swap()");
	// to do
}

template <typename Container>
static void test_modifier(ModifiersFuncModifier modifier)
{
	switch (modifier)
	{
		case MOD_CLEAR:
			if (container_traits<Container>::has_clear)
				test_clear<Container>();
			break;
		case MOD_INSERT:
			if (container_traits<Container>::has_insert)
				test_insert<Container>();
			break;
		case MOD_ERASE:
			if (container_traits<Container>::has_erase)
				test_erase<Container>();
			break;
		case MOD_PUSH_BACK:
			if (container_traits<Container>::has_push_back)
				test_push_back<Container>();
			break;
		case MOD_POP_BACK:
			if (container_traits<Container>::has_pop_back)
				test_pop_back<Container>();
			break;
		case MOD_RESIZE:
			if (container_traits<Container>::has_resize)
				test_resize<Container>();
			break;
		case MOD_SWAP:
			if (container_traits<Container>::has_swap)
				test_swap<Container>();
			break;
		default:
			std::cerr << "ModifierFuncModifier not managed" << std::endl;
			break;
	}
}

template <typename Container>
void test_modifiers_func()
{
	std::cout << "=======================================" << std::endl 
	<< "===== Modifiers Func" << std::endl
	<< "=======================================" << std::endl;
	test_modifier<Container>(MOD_CLEAR);
	test_modifier<Container>(MOD_INSERT);
	test_modifier<Container>(MOD_ERASE);
	test_modifier<Container>(MOD_PUSH_BACK);
	test_modifier<Container>(MOD_POP_BACK);
	test_modifier<Container>(MOD_RESIZE);
	test_modifier<Container>(MOD_SWAP);
}