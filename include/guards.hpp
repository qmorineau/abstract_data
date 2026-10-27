#ifndef GUARDS_HPP
#define GUARDS_HPP

#include "cstddef.hpp"

namespace ft
{
	namespace detail
	{
		template <typename T, typename Allocator>
		class MemoryGuard
		{
			public:
				typedef ft::size_t size_type;

				MemoryGuard(Allocator& a);
				~MemoryGuard();
				void push(T* p, size_type size);
				void release();
			private:
				Allocator&		_allocator;
				T*				_pointer;
				size_type	_size;
				bool			_active;

				MemoryGuard(const MemoryGuard&);
				MemoryGuard& operator=(const MemoryGuard&);
		};

		template <typename T, typename Allocator, class ForwardIterator>
		class ChunkGuard
		{
			public:
				typedef ft::size_t size_type;

				ChunkGuard(Allocator& a, ForwardIterator begin, size_type chunk_size);
				~ChunkGuard();
				void push();
				void release();
			private:
				Allocator&		_allocator;
				ForwardIterator	_iterator;
				const size_type	_chunk_size;
				size_type		_allocated;
				bool			_active;

				ChunkGuard(const ChunkGuard&);
				ChunkGuard& operator=(const ChunkGuard&);
		};

		template <typename T, typename Allocator, class ForwardIterator>
		class ConstructGuard
		{
			public:
				typedef typename ft::size_t size_type;
				ConstructGuard(Allocator& a, ForwardIterator begin);
				~ConstructGuard();
				void push();
				void release();
			private:
				Allocator&		_allocator;
				ForwardIterator	_iterator;
				size_type		_size;
				bool			_active;

				ConstructGuard(const ConstructGuard&);
				ConstructGuard& operator=(const ConstructGuard&);
		};
	}
}

#include "guards.tpp"

#endif