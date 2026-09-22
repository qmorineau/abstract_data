#include <iostream>

#ifdef STD
	# define NAMESPACE_NAME "std"
#else
	# define NAMESPACE_NAME "ft"
#endif

void test_exception();
void test_vector();
void test_iterators();

int main()
{
	std::cout << "=======================================" << std::endl 
	<< "Testing " << NAMESPACE_NAME << "::containers" << std::endl
	<< "=======================================" << std::endl;
	test_exception();
	// test_vector();
	// test_iterators();
	return (0);
}
