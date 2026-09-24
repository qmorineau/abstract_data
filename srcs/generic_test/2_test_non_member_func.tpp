#include "../test.hpp"

/*
	operator==
	operator!=
	operator<=
	operator<
	operator>=
	operator>
	std::swap
*/

template <typename Container>
static void test_is_equal()
{
	std::cout << "===== Test: operator== =====" << std::endl;
	Timer t("operator==");
	// to do
}

template <typename Container>
static void test_is_different()
{
	std::cout << "===== Test: operator!= =====" << std::endl;
	Timer t("operator!=");
	// to do
}

template <typename Container>
static void test_is_greater_equal()
{
	std::cout << "===== Test: operate>= =====" << std::endl;
	Timer t("operate>=");
	// to do
}

template <typename Container>
static void test_is_greater()
{
	std::cout << "===== Test: operator> =====" << std::endl;
	Timer t("operator>");
	// to do
}

template <typename Container>
static void test_is_lesser_equal()
{
	std::cout << "===== Test: operator<= =====" << std::endl;
	Timer t("operator<=");
	// to do
}

template <typename Container>
static void test_is_lesser()
{
	std::cout << "===== Test: operator< =====" << std::endl;
	Timer t("operator<");
	// to do
}

template <typename Container>
static void test_swap_specialization()
{
	std::cout << "===== Test: std::swap() =====" << std::endl;
	Timer t("std::swap()");
	// to do
}

template <typename Container>
static void test_modifier(NonMemberModifier modifier)
{
	switch (modifier)
	{
		case MOD_CLEAR:
			if (container_traits<Container>::has_is_equal_operator)
				test_is_equal<Container>();
			break;
		case MOD_INSERT:
			if (container_traits<Container>::has_is_different_operator)
				test_is_different<Container>();
			break;
		case MOD_ERASE:
			if (container_traits<Container>::has_is_lesser_equal_operator)
				test_is_lesser_equal<Container>();
			break;
		case MOD_PUSH_BACK:
			if (container_traits<Container>::has_is_lesser_operator)
				test_is_lesser<Container>();
			break;
		case MOD_POP_BACK:
			if (container_traits<Container>::has_is_greater_equal_operator)
				test_is_greater_equal<Container>();
			break;
		case MOD_RESIZE:
			if (container_traits<Container>::has_is_greater_operator)
				test_is_greater<Container>();
			break;
		case MOD_SWAP:
			if (container_traits<Container>::has_swap_specialization)
				test_swap_specialization<Container>();
			break;
		default:
			std::cerr << "ModifierFuncModifier not managed" << std::endl;
			break;
	}
}

template <typename Container>
void test_non_member_func()
{
	std::cout << "=======================================" << std::endl 
	<< "===== Non Member Func" << std::endl
	<< "=======================================" << std::endl;
	test_modifier<Container>(MOD_IS_EQUAL);
	test_modifier<Container>(MOD_IS_DIFFERENT);
	test_modifier<Container>(MOD_IS_LESSER_EQUAL);
	test_modifier<Container>(MOD_IS_LESSER);
	test_modifier<Container>(MOD_IS_GREATER_EQUAL);
	test_modifier<Container>(MOD_IS_GREATER);
	test_modifier<Container>(MOD_SWAP_SPECIALIZATION);
}