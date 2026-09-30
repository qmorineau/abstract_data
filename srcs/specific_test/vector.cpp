#include "test.hpp"

const char* allocatedStr = "this is a long string to force heap allocation, at least 30 chars";
//print
template <class T>
static void print_vector(ns::vector<T>& v)
{
	std::cout << "print_vector: ";
	for (typename ns::vector<T>::iterator it = v.begin(); it != v.end(); ++it)
	{
		if (it != v.begin())
			std::cout << " / ";
		std::cout << *it;
	}
	std::cout << std::endl << "capacity = " << v.capacity() << ", size = " << v.size() << std::endl;
}
//type
template <typename T>
static void test_type(std::string name)
{
	std::cout << "type tested: \"" << name << "\"" << std::endl;
	ns::vector<T> test;
	(void) test;
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
//assign
static void test_vector_assign_it()
{
	std::cout << "===== Test: vector.assign(it first, it last) =====" << std::endl;
	Timer t("assign_it(it first, it last)");
	ns::vector<int> test;
	ns::vector<int> toust;
	for (int i = 0; i < 10; ++i)
		test.push_back(i * 10);
	print_vector(test);
	ns::vector<int> test2;
	test2.assign(test.begin() + 1, test.end() - 1);
	print_vector(test2);
}
static void test_vector_assign_n_value()
{
	std::cout << "===== Test: vector.assign(n, value) =====" << std::endl;
	Timer t("assign_it(n, value)");
	ns::vector<int> test;
	test.assign(10, 67);
	print_vector(test);
	test.assign(5, 19);
	print_vector(test);
	test.assign(15, 42);
	print_vector(test);
}
static void test_vector_assign()
{
	test_vector_assign_n_value();
	test_vector_assign_it();
}
//resize
template <class Container, typename T>
static void test_resize_unit(Container& c, T arg)
{
	std::cout << "=== resize() ===" << std::endl;
	Timer t("resize()");
	try
	{
		print_vector(c);
		c.resize(arg);
		print_vector(c);
	}
	catch(const std::length_error& e)
	{
		std::cout << e.what() << '\n';
	}
	catch(const ns::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}
static void test_vector_resize()
{
	std::cout << "===== Test: vector.resize() =====" << std::endl;
	ns::vector<std::string> emptyVector;
	ns::vector<int>	vector;
	for (int i = 0; i < 10; ++i)
		vector.push_back(i);
	test_resize_unit(emptyVector, 0);
	test_resize_unit(emptyVector, 150);
	test_resize_unit(emptyVector, emptyVector.max_size() + 1);
	test_resize_unit(vector, 0);
	test_resize_unit(vector, 5);
	test_resize_unit(vector, 10);
	test_resize_unit(vector, 25);
	test_resize_unit(vector, vector.max_size() + 1);
}
//max size
template <typename T>
static void test_type_max_size(std::string name)
{
	ns::vector<T> v;
	std::cout << "*: could be different, implement dependant => " << "vector<" << name << ">.max_size() = " << v.max_size() << std::endl;
}
static void test_vector_max_size()
{
	std::cout << "===== Test: vector.max_size()* =====" << std::endl;
	Timer t("max_size()");
	test_type_max_size<int>("int");
	test_type_max_size<float>("float");
	test_type_max_size<std::string>("std::string");
	test_type_max_size<Foo>("Foo");
	test_type_max_size<double>("double");
	test_type_max_size<size_t>("size_t");
	test_type_max_size<short>("short");
	test_type_max_size<unsigned long>("unsigned long");
	test_type_max_size<long>("long");
	test_type_max_size<unsigned int>("unsigned int");
}
//capacity
static void test_vector_capacity()
{
	std::cout << "===== Test: vector.capacity() =====" << std::endl;
	Timer t("capacity()");
	ns::vector<int> test;
	for (int i = 0; i <= 1026; i++)
	{
		std::cout << test.capacity() << " " << test.size() << " | ";
		test.push_back(i);
	}
	std::cout << std::endl;
}
//data
static void test_vector_data()
{
	std::cout << "===== Test: vector.data() =====" << std::endl;
	Timer t("data()");
	ns::vector<int> test;
	std::cout << test.data() << "|";
	test.push_back(42);
	std::cout << (test.data() != 0) << "|";
	test.pop_back();
	std::cout << test.data() << std::endl;
}
//pop_back
static void test_vector_pop_back()
{
	std::cout << "===== Test: vector.pop_back() =====" << std::endl;
	Timer t("pop_back()");
	ns::vector<int> test;
	for (int i = 0; i < 10; ++i)
		test.push_back(i);
	for (int i = 0; i < 12; ++i)
	{
		test.pop_back();
		print_vector(test);
	}
}
// reserve
static void test_vector_reserve()
{
	std::cout << "===== Test: vector.reserve() =====" << std::endl;
	Timer t("reserve()");
	ns::vector<std::string> test;
	test.reserve(0);
	test.push_back(std::string(allocatedStr));
	test.reserve(6);
	print_vector(test);
	for (size_t i = 1; i <= 6 ; i++)
	{
		test.push_back(std::string(allocatedStr));
		std::cout << "capacity = " << test.capacity() << std::endl;
	}
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
	catch(const ns::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}
//empty
static void test_vector_empty()
{
	std::cout << "===== Test: vector.empty() =====" << std::endl;
	Timer t("empty()");
	ns::vector<std::string> test;
	std::cout << test.empty() << "|";
	test.push_back(std::string(allocatedStr));	
	std::cout << test.empty() << "|";
	test.push_back(std::string(allocatedStr));
	std::cout << test.empty() << "|";
	test.pop_back();
	std::cout << test.empty() << "|";
	test.pop_back();
	std::cout << test.empty() << std::endl;
}
//insert
static void test_insert_value()
{
	std::cout << "===== Test: vector.insert(it pos, value) =====" << std::endl;
	Timer t("insert(it pos, value)");
	ns::vector<int> test;
	test.insert(test.end(), 67);
	print_vector(test);
	test.insert(test.begin(), 42);
	print_vector(test);
	test.insert(--test.end(), 19);
	print_vector(test);
	test.insert(--test.begin(), 1024);
	print_vector(test);
}
static void test_insert_n_value()
{
	std::cout << "===== Test: vector.insert(it pos, n, value) =====" << std::endl;
	Timer t("insert(it pos, n, value)");
	ns::vector<int> test;
	test.insert(test.end(), 2, 67);
	print_vector(test);
	test.insert(test.begin(), 10, 42);
	print_vector(test);
	test.insert(test.end(), 7, 19);
	print_vector(test);
	test.insert(test.begin(), 5, 1024);
	print_vector(test);
}
static void test_insert_it()
{
	std::cout << "===== Test: vector.insert(it pos, it first, it last) =====" << std::endl;
	Timer t("insert(it pos, it first, it last)");
	ns::vector<int> test;
	for (int i = 0; i < 1024; ++i)
		test.push_back(i);
	print_vector(test);
}
static void test_vector_insert()
{
	test_insert_value();
	test_insert_n_value();
	test_insert_it();
}
// erase
static void test_erase_pos()
{
	std::cout << "===== Test: vector.erase(it pos) =====" << std::endl;
	Timer t("erase(it pos)");
	ns::vector<int> test;
	for (int i = 0; i < 120; ++i)
		test.push_back(i);
	print_vector(test);
	test.erase(test.begin());
	print_vector(test);
	test.erase(++test.begin());
	print_vector(test);
}
static void test_erase_it()
{
	std::cout << "===== Test: vector.erase(it first, it last) =====" << std::endl;
	Timer t("erase(it first, it last)");
	ns::vector<int> test;
	for (int i = 0; i < 120; ++i)
		test.push_back(i);
	print_vector(test);
	
	// ns::vector<int> test;
	// for (int i = 0; i < 15; ++i)
	// 	test.push_back(i);
	// print_vector(test);
	// test.erase(test.end());
	// print_vector(test);
	// ns::vector<int> test2(test);
	// print_vector(test2);
	// test2.erase(test2.begin(), test2.end());
	// print_vector(test2);
}
static void test_vector_erase()
{
	test_erase_pos();
	test_erase_it();
}
//clear
static void test_vector_clear()
{
}

void test_vector()
{
	std::cout << "=======================================" << std::endl 
	<< "Testing " << NAMESPACE_NAME << "::vector" << std::endl
	<< "=======================================" << std::endl;
	Timer t("vector");
	test_vector_type();
	test_vector_assign();
	test_vector_resize();
	test_vector_max_size();
	test_vector_capacity();
	test_vector_empty();
	test_vector_reserve();
	test_vector_data();
	test_vector_pop_back();
	test_vector_insert();
	test_vector_erase();
	test_vector_clear();
}