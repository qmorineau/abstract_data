
#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include <sys/time.h>

#include <algorithm>
#include <exception>
#include <stdexcept>
#include <vector>
#include <deque>
#include <list>

#include "vector.hpp"
#include "deque.hpp"
#include "list.hpp"
#include "stdexcept.hpp"

#ifdef STD
	namespace ns = std;
	# define NAMESPACE_NAME "std"
#else
	namespace ns = ft;
	# define NAMESPACE_NAME "ft"
#endif

class Timer
{
	public:
		Timer(const std::string& label) : _label(label)
		{
			gettimeofday(&_start, NULL);
		}
		~Timer()
		{
			struct timeval end;
			gettimeofday(&end, NULL);

			long seconds = end.tv_sec - _start.tv_sec;
			long useconds = end.tv_usec - _start.tv_usec;
			long elasped = seconds * 1000000 + useconds;
			std::cerr << _label << ": " << elasped << " useconds"<< std::endl;
		}
	private:
		std::string _label;
		static struct timeval _start;
};

class Foo
{
	struct Bar
	{
		int i;
		int* j;
		size_t k;
		long h;
		std::string str;
	};
	public:
		Foo();
		Foo(int i);
		Foo(const Foo&);
		Foo& operator=(const Foo&);
		~Foo();
		int		data() const;
	private:
		Bar*	_allocated_ptr;
		int		_n;
};
std::ostream& operator<<(std::ostream& out_stream, const Foo& f);

// test types
enum TestType
{
	TYPE_INT
	// stdstring
	// class that throw except after x copy
	// foo class
};

// modifiers
enum CommonModifier
{
	MOD_CONSTRUCTOR,
	MOD_DESTRUCTOR,
	MOD_COPY_CONSTRUCTOR,
	MOD_COPY_OPERATOR,
	MOD_ASSIGN,
	MOD_GET_ALLOCATOR
};
enum ElementAccessModifier
{
	MOD_AT,
	MOD_OPERATOR_SQUARE_BRACKET,
	MOD_FRONT,
	MOD_BACK,
	MOD_DATA
};
enum IteratorModifier
{
	MOD_BEGIN,
	MOD_RBEGIN,
	MOD_END,
	MOD_REND
};
enum CapacityModifier
{
	MOD_EMPTY,
	MOD_SIZE,
	MOD_MAX_SIZE,
	MOD_RESERVE,
	MOD_CAPACITY
};
enum ModifiersFuncModifier
{
	MOD_CLEAR,
	MOD_INSERT,
	MOD_ERASE,
	MOD_PUSH_BACK,
	MOD_POP_BACK,
	MOD_RESIZE,
	MOD_SWAP
};
enum NonMemberModifier
{
	MOD_IS_EQUAL,
	MOD_IS_DIFFERENT,
	MOD_IS_LESSER_EQUAL,
	MOD_IS_LESSER,
	MOD_IS_GREATER_EQUAL,
	MOD_IS_GREATER,
	MOD_SWAP_SPECIALIZATION
};

// container traits (func)
struct container_traits_default
{
	enum
	{
		// common
		has_copy_constructor = 0,
		has_copy_operator = 0,
		has_assign = 0,
		has_get_allocator = 0,
		// element access
		has_at = 0,
		has_operator_square_bracket = 0,
		has_front = 0,
		has_back = 0,
		has_data = 0,
		// iterators
		has_begin = 0,
		has_rbegin = 0,
		has_end = 0,
		has_rend = 0,
		// capacity
		has_empty = 0,
		has_size = 0,
		has_max_size = 0,
		has_reserve = 0,
		has_capacity = 0,
		// modifiers
		has_clear = 0,
		has_insert = 0,
		has_erase = 0,
		has_push_front = 0,
		has_pop_front = 0,
		has_push_back = 0,
		has_pop_back = 0,
		has_resize = 0,
		has_swap = 0,
		// non member
		has_is_equal_operator = 0,
		has_is_different_operator = 0,
		has_is_lesser_equal_operator = 0,
		has_is_lesser_operator = 0,
		has_is_greater_equal_operator = 0,
		has_is_greater_operator = 0,
		has_swap_specialization = 0
	};
};

template <typename Container>
struct container_traits : container_traits_default
{
};

template <typename T, typename Alloc>
struct container_traits<ns::vector<T, Alloc> > : container_traits_default
{
	enum
	{
		// common
		has_copy_constructor = 1,
		has_copy_operator = 1,
		has_assign = 1,
		has_get_allocator = 1,
		// element access
		has_at = 1,
		has_operator_square_bracket = 1,
		has_front = 1,
		has_back = 1,
		has_data = 1,
		// iterators
		has_begin = 1,
		has_rbegin = 1,
		has_end = 1,
		has_rend = 1,
		// capacity
		has_empty = 1,
		has_size = 1,
		has_max_size = 1,
		has_reserve = 1,
		has_capacity = 1,
		// modifiers
		has_clear = 1,
		has_insert = 1,
		has_erase = 1,
		has_push_back = 1,
		has_pop_back = 1,
		has_resize = 1,
		has_swap = 1,
		// non member
		has_is_equal_operator = 1,
		has_is_different_operator = 1,
		has_is_lesser_operator = 1,
		has_is_greater_operator = 1,
		has_is_lesser_equal_operator = 1,
		has_is_greater_equal_operator = 1,
		has_swap_specialization = 1
	};
};

template <typename T, typename Alloc>
struct container_traits<ns::deque<T, Alloc> > : container_traits_default
{
	enum
	{
		// common
		has_copy_constructor = 1,
		has_copy_operator = 1,
		has_assign = 1,
		has_get_allocator = 1,
		// element access
		has_at = 1,
		has_operator_square_bracket = 1,
		has_front = 1,
		has_back = 1,
		// iterators
		has_begin = 1,
		has_rbegin = 1,
		has_end = 1,
		has_rend = 1,
		// capacity
		has_empty = 1,
		has_size = 1,
		has_max_size = 1,
		// modifiers
		has_clear = 1,
		has_insert = 1,
		has_erase = 1,
		has_push_back = 1,
		has_pop_back = 1,
		has_resize = 1,
		has_swap = 1,
		// non member
		has_is_equal_operator = 1,
		has_is_different_operator = 1,
		has_is_lesser_operator = 1,
		has_is_greater_operator = 1,
		has_is_lesser_equal_operator = 1,
		has_is_greater_equal_operator = 1,
		has_swap_specialization = 1
	};
};

// define traits for each container
// template <typename Key, typename T, typename Compare, typename Alloc>
// struct container_traits<nm::map<Key, Compare, Alloc>
// {
// 	enum
// 	{
// 		has_begin = 1,
// 		has_rbegin = 1,
// 		has_end = 1,
// 		has_rend = 1,
// 		has_push_back = 1
// 		// [...]
// 	};
// };

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
void fill_n(Container& c, std::size_t n);
template <typename Container>
typename Container::value_type generate_value(std::size_t n);

#include "generic_test/value_generator.tpp"

#include "generic_test/2_test_common_func.tpp"
#include "generic_test/2_test_capacity_func.tpp"
#include "generic_test/2_test_element_access_func.tpp"
#include "generic_test/2_test_iterators_func.tpp"
#include "generic_test/2_test_modifiers_func.tpp"
#include "generic_test/2_test_non_member_func.tpp"

#include "generic_test/1_test_sequence_container.tpp"
#include "generic_test/1_test_associative_container.tpp"
#include "generic_test/1_test_container_adaptator.tpp"

#endif