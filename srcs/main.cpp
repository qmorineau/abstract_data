#include "exception.hpp"
#include <exception>
#include <iostream>

#ifdef STD
	namespace test = std;
	# define NAMESPACE_NAME "std"
#else
	namespace test = ft;
	# define NAMESPACE_NAME "ft"
#endif

int main()
{
	std::cout << "===== Testing " << NAMESPACE_NAME << "::containers =====" << std::endl;
	try
	{
		throw test::exception();
	}
	catch(const test::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
