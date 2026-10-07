#include "test.hpp"

template <class E>
static void testing(const E& exception, std::string name)
{
	try
	{
		std::cout << "Test exception " << name << " :" << std::endl; 
		throw exception;
	}
	catch(const ft::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void test_exceptions()
{
	std::cout << "=======================================" << std::endl 
	<< "Testing " << NAMESPACE_NAME << "::exceptions" << std::endl
	<< "=======================================" << std::endl;
	testing(ns::exception(), std::string("exception"));
	testing(ns::logic_error("logic_error testing"), std::string("logic_error"));
	testing(ns::runtime_error("runtime_error testing"), std::string("runtime_error"));
	testing(ns::length_error("length_error testing"), std::string("runtime_error"));
}