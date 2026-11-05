#ifndef DEQUE_POSITION_HPP
#define DEQUE_POSITION_HPP

#include "cstddef.hpp"

namespace ft
{
	namespace detail
	{
	    struct deque_position
	    {
	        size_t map_index;
	        size_t offset;
	        deque_position() : map_index(0), offset(0) {};
	        deque_position(size_t m, size_t o) : map_index(m), offset(o) {};
	    };
	}
}

#endif