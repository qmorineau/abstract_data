#include <vector>
#include <iostream>

#include "string.hpp"
#include "vector.hpp"

#ifdef STD
	namespace nm = std;
	# define NAMESPACE_NAME "std"
#else
	namespace nm = ft;
	# define NAMESPACE_NAME "ft"
#endif

const char* allocatedStr = "this is a long string to force heap allocation, at least 30 chars";

template <class T>
static void print_vector(nm::vector<T>& v, size_t start, size_t end)
{
	std::cout << "print: ";
	for (size_t i = start; i < end; i++)
	{
		if (i != start)
			std::cout << " / ";
		std::cout << v[i];
	}
	std::cout << std::endl << "capacity = " << v.capacity() << ", size = " << v.size() << std::endl;
}

template <typename T>
static void test_type(std::string name)
{
	nm::vector<T> test;
	std::cout << "Testing \"" << name << "\": " << &test << std::endl;
}

static void test_vector_type()
{
	std::cout << "===== Test: vector template type =====" << std::endl;
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

static void test_vector_at()
{
	std::cout << "===== Test: vector.at() =====" << std::endl;
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

static void test_vector_front()
{
	std::cout << "===== Test: vector.front() =====" << std::endl;
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

static void test_vector_back()
{
	std::cout << "===== Test: vector.back() =====" << std::endl;
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

static void test_capacity()
{
	std::cout << "===== Test: vector.capacity() =====" << std::endl;
	nm::vector<int> test;
	for (int i = 0; i <= 17; i++)
	{
		std::cout << "Capacity = " << test.capacity() << ": ";
		print_vector(test, 0, test.size());
		test.push_back(i);
	}
}

static void test_push_back()
{
	std::cout << "===== Test: vector.push_back() =====" << std::endl;
	nm::vector<int> test;
	for (int i = 0; i <= 17; i++)
	{
		test.push_back(i);
		print_vector(test, 0, test.size());
	}
}

static void test_pop_back()
{
	std::cout << "===== Test: vector.pop_back() =====" << std::endl;
	nm::vector<std::string> test;
	for (int i = 0; i <= 17; i++)
	{
		test.push_back(std::string(allocatedStr));
		if (i != 0)
			std::cout << " / ";
		std::cout << "s=" << test.size();
	}
	std::cout << std::endl;
	for (int i = 0; i <= 17; i++)
	{
		if (i != 0)
			std::cout << " / ";
		std::cout << "s=" << test.size();
		test.pop_back();
	}
	std::cout << std::endl;
}

static void test_reserve()
{
	std::cout << "===== Test: vector.reserve() =====" << std::endl;
	nm::vector<std::string> test;
	test.reserve(0);
	test.push_back(std::string(allocatedStr));
	test.reserve(6);
	print_vector(test, 0, test.size());
	for (size_t i = 1; i <= 6 ; i++)
		test.push_back(std::string(allocatedStr));
	std::cout << "capacity = " << test.capacity() << std::endl;
	test.reserve(1);
	std::cout << "capacity = " << test.capacity() << std::endl;
	try
	{
		test.reserve(test.max_size());
	}
	catch(const std::bad_alloc& e)
	{
		std::cout << e.what() << '\n';
	}
	catch(const nm::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

template <class Container, typename T>
static void test_resize_unit(Container& c, T arg)
{
	std::cout << "=== resize() ===" << std::endl;
	try
	{
		std::cout << c.size() << "|" << c.capacity() << "|";
		print_vector(c, 0, c.size());
		c.resize(arg);
		std::cout << c.size() << "|" << c.capacity() << "|";
		print_vector(c, 0, c.size());
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

static void test_resize()
{
	std::cout << "===== Test: vector.resize() =====" << std::endl;
	nm::vector<std::string> emptyVector;
	nm::vector<int>	vector;
	// vector.resize(10, 67);
	for (int i = 0; i < 10; ++i)
		vector.push_back(i);
	test_resize_unit(emptyVector, 0);
	test_resize_unit(emptyVector, 150);
	test_resize_unit(vector, 0);
	test_resize_unit(vector, 5);
	test_resize_unit(vector, 10);
	test_resize_unit(vector, 25);
}

static void test_empty()
{
	std::cout << "===== Test: vector.empty() =====" << std::endl;
	nm::vector<std::string> test;
	std::cout << "empty = " << test.empty() << std::endl;
	test.push_back(std::string(allocatedStr));	
	std::cout << "empty = " << test.empty() << std::endl;
	test.push_back(std::string(allocatedStr));
	std::cout << "empty = " << test.empty() << std::endl;
	test.pop_back();
	std::cout << "empty = " << test.empty() << std::endl;
	test.pop_back();
	std::cout << "empty = " << test.empty() << std::endl;
}

template <typename T>
static void test_type_max_size(std::string name)
{
	nm::vector<T> v;
	std::cout << "vector<" << name << ">.max_size() = " << v.max_size() << std::endl;
}

static void test_max_size()
{
	test_type_max_size<int>("int");
	test_type_max_size<std::string>("std::string");
	test_type_max_size<std::vector<int> >("std::vector<int>");
	test_type_max_size<double>("double");
	test_type_max_size<char>("char");
}

void test()
{
	nm::vector<int> test;
	try
	{
		test.reserve(test.max_size());
	}
	catch(const nm::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	// for (int i = 0; i < 10; ++i)
	// 	test.push_back(i * 10);
	// std::cout << "capacity = " << test.capacity() << std::endl;
	// // test.assign(17, 67);
	// test.resize(18);
	// std::cout << "capacity = " << test.capacity() << std::endl;
	// for (size_t i = 0; i < test.size(); ++i)
	// 	std::cout << test[i] << "|";
	// std::cout << std::endl << "size = " << test.size() << std::endl;
}

static void test_vector_assign()
{
	std::cout << "===== Test: vector.assign(n, value) =====" << std::endl;
	nm::vector<int> test;
	test.assign(10, 67);
	print_vector(test, 0, test.size());
	test.assign(5, 19);
	print_vector(test, 0, test.size());
	test.assign(15, 42);
	print_vector(test, 0, test.size());
}

static void test_vector_assign_it()
{
	nm::vector<int> test;
	nm::vector<int> toust;
	for (int i = 0; i < 10; ++i)
		test.push_back(i * 10);
	print_vector(test, 0, test.size());
	nm::vector<int> test2;
	test2.assign(test.begin() + 1, test.end() - 1);
	print_vector(test2, 0, test2.size());
	try
	{
		test2.assign(toust.begin(), test.begin());
		print_vector(test2, 0, test2.size());
	}
	catch(const nm::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void test_vector()
{
	std::vector<int> test;
	test.push_back(1);
	std::cout << test.data() << std::endl;
	return; 
	std::cout << "=======================================" << std::endl 
	<< "Testing " << NAMESPACE_NAME << "::vector" << std::endl
	<< "=======================================" << std::endl;
	test_vector_assign();
	test_vector_assign_it();
	test_vector_type();
	test_vector_at();
	test_vector_front();	
	test_vector_back();
	test_capacity();
	test_push_back();
	test_pop_back();
	test_resize();
	test_reserve();
	test_empty();
	test_max_size();
}