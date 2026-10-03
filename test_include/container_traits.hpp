#ifndef CONTAINER_TRAITS_HPP
#define CONTAINER_TRAITS_HPP

#include <vector>
#include <deque>
#include <list>

#include <set>
#include <map>

#include <stack>
#include <queue>

#include "vector.hpp"
#include "deque.hpp"
#include "list.hpp"

#ifdef STD
	namespace ns = std;
	# define NAMESPACE_NAME "std"
#else
	namespace ns = ft;
	# define NAMESPACE_NAME "ft"
#endif

// container traits (func)
struct container_traits_default
{
	enum
	{
		// common
		has_constructor_destructor = 1,
		has_copy_constructor = 1,
		has_copy_operator = 1,
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
		has_erase_key = 0,
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

template <typename T, typename Alloc>
struct container_traits<ns::list<T, Alloc> > : container_traits_default
{
	enum
	{
		// common
		has_assign = 1,
		has_get_allocator = 1,
		// element access
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
		has_push_front = 1,
		has_pop_front = 1,
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

#endif