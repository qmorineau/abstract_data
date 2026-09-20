#include <vector>
#include <iostream>

#include "exception.hpp"
#include "string.hpp"
#include "vector.hpp"

#ifdef STD
	namespace nm = std;
	# define NAMESPACE_NAME "std"
#else
	namespace nm = ft;
	# define NAMESPACE_NAME "ft"
#endif

template <typename T>
void test_type(std::string name)
{
	nm::vector<T> test;
	std::cout << "Testing \"" << name << "\": " << &test << std::endl;
}

void test_vector_type()
{
	std::cout << "===== Test: " << NAMESPACE_NAME << "::vector template type =====" << std::endl;
	test_type<int>("int");
	test_type<unsigned int>("unsigned int");
	test_type<float>("float");
	test_type<double>("double");
	test_type<ft::size_t>("size_t");
	test_type<long>("long");
	test_type<std::string>("string");
	test_type<char>("char");
	test_type<const char*>("const char*");
}

void test_vector_at()
{
	std::cout << "===== Test: " << NAMESPACE_NAME << "::vector.at() =====" << std::endl;
	nm::vector<int> test;
	test.push_back(1);
	try
	{
		int& i = test.at(0);
		const int& j = test.at(0);
		std::cout << "&=" << i << ", " << "const& = " << j << std::endl;
		i++;
		std::cout << "&=" << i << ", " << "const& = " << j << std::endl;
		std::cout << test.at(1) << std::endl;
	}
	catch(const nm::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void test_vector_front()
{
	std::cout << "===== Test: " << NAMESPACE_NAME << "::vector.front() =====" << std::endl;
	nm::vector<int> test;
	test.push_back(19);
	test.push_back(42);
	int& i = test.front();
	const int& j = test.front();
	std::cout << "&=" << i << ", " << "const& = " << j << std::endl;
	i++;
	std::cout << "&=" << i << ", " << "const& = " << j << std::endl;
	std::cout << test.front() << std::endl;
}

void test_vector_back()
{
	std::cout << "===== Test: " << NAMESPACE_NAME << "::vector.back() =====" << std::endl;
	nm::vector<int> test;
	test.push_back(19);
	test.push_back(42);
	int& i = test.back();
	const int& j = test.back();
	std::cout << "&=" << i << ", " << "const& = " << j << std::endl;
	i++;
	std::cout << "&=" << i << ", " << "const& = " << j << std::endl;
	std::cout << test.back() << std::endl;
}

void test_capacity()
{
	std::cout << "===== Test: " << NAMESPACE_NAME << "::vector.capacity() =====" << std::endl;
	nm::vector<int> test;
	for (int i = 0; i <= 17; i++)
	{
		std::cout << "Capacity = " << test.capacity() << ": ";
		for (size_t j = 0; j < test.size(); j++)
		{
			if (j != 0)
				std::cout << ", ";
			std::cout << test[j];
		}
		std::cout << std::endl;
		test.push_back(i);
	}
}

void test_push_back()
{
	std::cout << "===== Test: " << NAMESPACE_NAME << "::vector.push_back() =====" << std::endl;
	nm::vector<int> test;
	for (int i = 0; i <= 17; i++)
	{
		test.push_back(i);
		std::cout << test[test.size() - 1];
	}
	std::cout << std::endl;
}

void test_pop_back()
{
	std::cout << "===== Test: " << NAMESPACE_NAME << "::vector.pop_back() =====" << std::endl;
	nm::vector<std::string> test;
	for (int i = 0; i <= 17; i++)
	{
		test.push_back("this is a long string to force heap allocation, at least 30 chars");
		std::cout << test.size();
	}
	std::cout << std::endl;
	for (int i = 0; i <= 17; i++)
	{
		std::cout << test.size();
		test.pop_back();
	}
	std::cout << std::endl;
}

void test_vector()
{
	// test_vector_type();
	// test_vector_at();
	// test_vector_front();	
	// test_vector_back();
	// test_capacity();
	// test_push_back();
	// test_pop_back();
}