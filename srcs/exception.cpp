#include <iostream>
#include <string>

#include "exception.hpp"
#include "stdexcept.hpp"

#ifdef STD
	namespace nm = std;
	# define NAMESPACE_NAME "std"
#else
	namespace nm = ft;
	# define NAMESPACE_NAME "ft"
#endif

template <class E>
static void testing(const E& exception, std::string name)
{
	try
	{
		std::cout << "Test exception " << name << " :" << std::endl; 
		throw exception;
	}
	catch(const nm::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}

void test_exception()
{
	testing(nm::exception(), std::string(NAMESPACE_NAME).append("::exception"));
	testing(nm::runtime_error("runtime error testing"), std::string(NAMESPACE_NAME).append("::runtime_error"));
}