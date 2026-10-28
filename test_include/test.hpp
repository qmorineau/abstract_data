
#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

#include <algorithm>
#include <exception>
#include <stdexcept>

#include "stdexcept.hpp"

#include "benchmark.hpp"
#include "container_traits.hpp"
#include "testing_classes.hpp"
#include "helper.hpp"

#ifdef STD
	namespace ns = std;
	# define NAMESPACE_NAME "std"
#else
	namespace ns = ft;
	# define NAMESPACE_NAME "ft"
#endif

template <typename T>	struct is_throwing				{static const bool value = false;};
template <>				struct is_throwing<Throwing>	{static const bool value = true;};

template <typename Runner, bool Sweep>
struct sweep_runner
{
	static void run() {Runner::run();}
};

template <typename Runner>
struct sweep_runner<Runner, true>
{
	static void run()
	{
		SilenceScope mute;
		for (std::size_t k = 0; k < 100; ++k)
		{
			ThrowingCounter::reset(k);
			try
			{
				Runner::run();			
			}
			catch(const ThrowingException&)
			{
			}
		}
	}
};

template <bool Enabled, template <typename> class Test, typename C>
struct run_if
{
    static void run()
	{
		sweep_runner<Test<C>, is_throwing<typename C::value_type>::value>::run(); 
	}
};

template <template <typename> class Test, typename C>
struct run_if<false, Test, C>
{
    static void run() { std::cout << "(skipped)" << std::endl; }
};

#define RUN_IF(trait, test, C) run_if<container_traits<C>::trait, test, C>::run()

// Specific Test
void test_exceptions();
void test_iterators();
void test_helpers();
void test_vector();
void test_list();
void test_deque();
void test_stack();
void test_queue();
void test_priority_queue();

// Container Type
template <template <typename, typename> class Container>
void test_sequence_container(std::string name);
template <template <typename, typename, typename, typename> class Container>
void test_associative_container();
template <template <typename, typename> class Container>
void test_container_adaptor(std::string name, container_adaptator c);

// Category of generic test
template <typename Container>
void test_common_func();
template <typename Container>
void test_element_access_func();
template <typename Container>
void test_iterators_func();
template <typename Container>
void test_capacity_func();
template <typename Container>
void test_modifiers_func();
template <typename Container>
void test_operations_func();
template <typename Container>
void test_non_member_func();

// Helper
template <typename Container>
Container fill_n(size_t n);
template <typename Container>
typename Container::value_type generate_value(size_t n);
template <typename Container>
void print(Container& c);

#include "template/generic_test/2_test_common_func.tpp"
#include "template/generic_test/2_test_capacity_func.tpp"
#include "template/generic_test/2_test_element_access_func.tpp"
#include "template/generic_test/2_test_iterators_func.tpp"
#include "template/generic_test/2_test_modifiers_func.tpp"
#include "template/generic_test/2_test_operations_func.tpp"
#include "template/generic_test/2_test_non_member_func.tpp"

#include "template/generic_test/1_test_sequence_container.tpp"
#include "template/generic_test/1_test_associative_container.tpp"
#include "template/generic_test/1_test_container_adaptator.tpp"

#endif