
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
#include "container_modifier.hpp"
#include "container_traits.hpp"
#include "testing_classes.hpp"

#ifdef STD
	namespace ns = std;
	# define NAMESPACE_NAME "std"
#else
	namespace ns = ft;
	# define NAMESPACE_NAME "ft"
#endif

// Specific Test
void test_exceptions();
void test_iterators();
void test_vector();
void test_deque();
void test_list();

// Container Type
template <template <typename, typename> class Container>
void test_sequence_container();
template <template <typename, typename, typename, typename> class Container>
void test_associative_container();
template <template <typename, typename> class Container>
void test_container_adaptor();

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
void test_non_member_func();

// Helper to fill container
template <typename Container>
Container fill_n(std::size_t n);
template <typename Container>
typename Container::value_type generate_value(std::size_t n);

#include "template/generic_test/value_generator.tpp"

#include "template/generic_test/2_test_common_func.tpp"
#include "template/generic_test/2_test_capacity_func.tpp"
#include "template/generic_test/2_test_element_access_func.tpp"
#include "template/generic_test/2_test_iterators_func.tpp"
#include "template/generic_test/2_test_modifiers_func.tpp"
#include "template/generic_test/2_test_non_member_func.tpp"

#include "template/generic_test/1_test_sequence_container.tpp"
#include "template/generic_test/1_test_associative_container.tpp"
#include "template/generic_test/1_test_container_adaptator.tpp"

#endif