#ifndef DEQUE_CHUNK
#define DEQUE_CHUNK

#include "cstddef.hpp"

namespace ft
{
	const ft::size_t CHUNK_SIZE = 4;

	template<typename T>
	struct Chunk
	{
		T data[CHUNK_SIZE];
	};
}

#endif