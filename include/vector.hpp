#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

template <class T, class Allocator = std::allocator<T>>
class vector
{
	public:
		vector();
		~vector();
		operator=()
		assign();
		get_allocator();
		// element access
		at();
		operator[]();
		front();
		back();
		data();
		// iterators
		begin();
		end();
		rbegin();
		rend();
		// capacity
		empty();
		size();
		max_size();
		reserve();
		capacity();
		shrink_to_fit(); // pas sur
		// modifiers
		clear();
		insert();
		erase();
		push_back();
		pop_back();
		resize();
		swap();
		// non member
		static operator==();
		static operator!=();
		static operator<();
		static operator<=();
		static operator>();
		static operator>=();
		// std::swap(std::list) pas sur de ca
	private:
		// member type
		// T			value_type;
		// Allocator	allocator_type;
		// size_t		size_type;
};

#endif