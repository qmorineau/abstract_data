#include "test.hpp"

void test_min()
{
	std::cout << "==== ::min(a, b) =====" << std::endl;
	std::cout << ns::min(1, 2) << "|" << ns::min(4, 3) << std::endl;
	std::cout << "==== ::min(a, b, comp) =====" << std::endl;
	std::cout << ns::min(1, 2, std::less<int>()) << "|" << ns::min(4, 3, std::less<int>()) << std::endl;
}

void test_max()
{
	std::cout << "==== ::max(a, b) =====" << std::endl;
	std::cout << ns::max(1, 2) << "|" << ns::max(4, 3) << std::endl;
	std::cout << "==== ::max(a, b, comp) =====" << std::endl;
	std::cout << ns::max(1, 2, std::greater<int>()) << "|" << ns::max(4, 3, std::greater<int>()) << std::endl;
}

void test_helpers()
{
	test_min();
	test_max();
}