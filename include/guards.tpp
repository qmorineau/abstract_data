#ifndef GUARDS_TPP
#define GUARDS_TPP

// MemoryGuard

template <typename T, typename Allocator>
ft::detail::MemoryGuard<T, Allocator>::MemoryGuard(Allocator& a)
	: _allocator(a), _pointer(static_cast<T*>(0)), _size(0), _active(false)
{}

template <typename T, typename Allocator>
ft::detail::MemoryGuard<T, Allocator>::~MemoryGuard()
{
	if (!_active)
		return;
	_allocator.deallocate(_pointer, _size);
}

template <typename T, typename Allocator>
void
ft::detail::MemoryGuard<T, Allocator>::push(T* p, size_type size)
{
	_active = true;
	_pointer = p;
	_size = size;
}


template <typename T, typename Allocator>
void
ft::detail::MemoryGuard<T, Allocator>::release()
{
	_active = false;
	_pointer = static_cast<T*>(0);
	_size = 0;
}

// ChunkGuard

template <typename T, typename Allocator, class ForwardIterator>
ft::detail::ChunkGuard<T, Allocator, ForwardIterator>::ChunkGuard(Allocator& a, ForwardIterator begin, size_type memory_size)
	: _allocator(a), _iterator(begin), _size(memory_size), _allocated(0), _active(true)
{}

template <typename T, typename Allocator, class ForwardIterator>
ft::detail::ChunkGuard<T, Allocator, ForwardIterator>::~ChunkGuard()
{
	if (!_active)
		return;
	for (size_type i = 0; i < _allocated; ++i, ++_iterator)
	{
		_allocator.deallocate(*_iterator, _size);
		*_iterator = static_cast<T>(0);
	}
}

template <typename T, typename Allocator, class ForwardIterator>
void
ft::detail::ChunkGuard<T, Allocator, ForwardIterator>::push()
{
	++_allocated;
}

template <typename T, typename Allocator, class ForwardIterator>
void
ft::detail::ChunkGuard<T, Allocator, ForwardIterator>::release()
{
	_active = false;
}

// ConstructGuard

template <typename T, typename Allocator, class ForwardIterator>
ft::detail::ConstructGuard<T, Allocator, ForwardIterator>::ConstructGuard(Allocator& a, ForwardIterator begin)
	: _allocator(a), _iterator(begin), _size(0), _active(true)
{}

template <typename T, typename Allocator, class ForwardIterator>
ft::detail::ConstructGuard<T, Allocator, ForwardIterator>::~ConstructGuard()
{
	if (!_active)
		return;
	for (size_type i = 0; i < _size; ++i, ++_iterator)
		_allocator.destroy(&*_iterator);
}

template <typename T, typename Allocator, class ForwardIterator>
void
ft::detail::ConstructGuard<T, Allocator, ForwardIterator>::push()
{
	++_size;
}

template <typename T, typename Allocator, class ForwardIterator>
void
ft::detail::ConstructGuard<T, Allocator, ForwardIterator>::release()
{
	_active = false;
}

#endif