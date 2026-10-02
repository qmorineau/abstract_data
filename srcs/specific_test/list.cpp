#include "test.hpp"

void test_list()
{
	ns::list<int> test;
	for (int i = 0; i < 10; ++i)
	{
		// test.insert(test.begin(), i);
		test.push_back(i);
	}
	for (ns::list<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << "list: " << *it << std::endl;
}