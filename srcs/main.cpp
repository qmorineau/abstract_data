#include <iostream>

#ifdef STD
	# define NAMESPACE_NAME "std"
#else
	# define NAMESPACE_NAME "ft"
#endif

void test_exception();
void test_vector();

int main()
{
	std::cout << "=======================================" << std::endl 
	<< "Testing " << NAMESPACE_NAME << "::containers" << std::endl
	<< "=======================================" << std::endl;
	// test_exception();
	test_vector();
	return (0);
}
