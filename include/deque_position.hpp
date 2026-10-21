#ifndef DEQUE_POSITION_HPP
#define DEQUE_POSITION_HPP

#include "cstddef.hpp"

namespace ft
{
    struct deque_position
    {
        ft::size_t map_index;
        ft::size_t offset;
        deque_position() : map_index(0), offset(0) {};
        deque_position(ft::size_t m, ft::size_t o) : map_index(m), offset(o) {};
    };
}

#endif