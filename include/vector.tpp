#include "vector.hpp"

namespace ft
{
	// ======================
	//	Construct / Destruct
	// ======================

	template <class T, class Allocator>
	ft::vector<T, Allocator>::vector(const Allocator& alloc) 
	{
		_data = 0;
		_size = 0;
		_allocator = alloc;
		_capacity = 0;
	}

	template <class T, class Allocator>
	ft::vector<T, Allocator>::vector(size_type n, const T& value, const Allocator& alloc)
	{
		// to do
	}

	template <class T, class Allocator>
	template <class InputIterator>
	ft::vector<T, Allocator>::vector(InputIterator first, InputIterator last, const Allocator& alloc)
	{
		// to do
	}

	template <class T, class Allocator>
	ft::vector<T, Allocator>::vector(const vector<T,Allocator>& x)
	{
		// to do
	}

	template <class T, class Allocator>
	ft::vector<T, Allocator>::~vector()
	{
		// to do
	}

	// =====================
	//	    Assignement
	// =====================

	template <class T, class Allocator>
	vector<T,Allocator>&
	ft::vector<T, Allocator>::operator=(const vector<T,Allocator>& x)
	{
		// to do
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void
	ft::vector<T, Allocator>::assign(InputIterator first, InputIterator last)
	{
		// to do
	}

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::assign(size_type n, const T& u)
	{
		// to do
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::allocator_type
	ft::vector<T, Allocator>::get_allocator() const
	{
		return _allocator;
	}

	// =====================
	//	     Iterators
	// =====================	

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::iterator
	ft::vector<T, Allocator>::begin()
	{
		return iterator(_data);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_iterator
	ft::vector<T, Allocator>::begin() const
	{
		// to do
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::iterator
	ft::vector<T, Allocator>::end()
	{
		// to do
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_iterator
	ft::vector<T, Allocator>::end() const
	{
		// to do
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::reverse_iterator
	ft::vector<T, Allocator>::rbegin()
	{
		// to do
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_reverse_iterator
	ft::vector<T, Allocator>::rbegin() const
	{
		// to do
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::reverse_iterator
	ft::vector<T, Allocator>::rend()
	{
		// to do
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_reverse_iterator
	ft::vector<T, Allocator>::rend() const
	{
		// to do
	}

	// ====================
	//	     Capacity
	// ====================

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::size_type 
	ft::vector<T, Allocator>::size() const
	{
		return _size;
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::size_type
	ft::vector<T, Allocator>::max_size() const
	{
		return _size; // to do
	}

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::resize(size_type sz, T c)
	{
		// to do
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::size_type
	ft::vector<T, Allocator>::capacity() const
	{
		return _capacity;
	}

	template <class T, class Allocator>
	bool
	ft::vector<T, Allocator>::empty() const
	{
		return _size == 0;
	}

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::reserve(size_type n)
	{
		_data = _allocator.allocate(n); // to do
	}

	// ======================
	//	   Element Access
	// ======================

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::reference
	ft::vector<T, Allocator>::operator[](size_type n)
	{
		return *(_data + n);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_reference
	ft::vector<T, Allocator>::operator[](size_type n) const
	{
		return *(_data + n);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_reference
	ft::vector<T, Allocator>::at(size_type n) const
	{
		range_check(n);
		return *(_data + n);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::reference
	ft::vector<T, Allocator>::at(size_type n)
	{
		range_check(n);
		return *(_data + n);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::reference
	ft::vector<T, Allocator>::front()
	{
		return *_data;
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_reference
	ft::vector<T, Allocator>::front() const
	{
		return *_data;
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::reference
	ft::vector<T, Allocator>::back()
	{
		return *(_data + _size - 1);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_reference
	ft::vector<T, Allocator>::back() const
	{
		return *(_data + _size - 1);
	}

	// =====================
	//	     Modifiers
	// =====================

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::push_back(const T& x)
	{
		if (_capacity <= _size)
		_data = _allocator.allocate(_size + 1);
		_allocator.construct(_data + _size, x);
		_size++;
	}

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::pop_back()
	{
		// to do
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::iterator
	ft::vector<T, Allocator>::insert(iterator position, const T& x)
	{
		// to do
	}

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::insert(iterator position, size_type n, const T& x)
	{
		// to do
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void
	ft::vector<T, Allocator>::insert(iterator position,
		InputIterator first, InputIterator last)
	{
		// to do
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::iterator
	ft::vector<T, Allocator>::erase(iterator position)
	{
		// to do
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::iterator
	ft::vector<T, Allocator>::erase(iterator first, iterator last)
	{
		// to do
	}

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::swap(vector<T,Allocator>&)
	{
		// to do
	}

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::clear()
	{
		// to do
	}

	// =====================
	//	  Private-Members
	// =====================

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::range_check(size_type n)
	{
		if (n >= this->size())
		{
			std::string error("ft::vector::range_check: n (which is " + ft::to_string(n)
				+ ") >= this->size() (which is " + ft::to_string(this->size()) + ")");
			throw ft::runtime_error(error);
		}
	}

	// =====================
	//	    Non-Members
	// =====================

	template <class T, class Allocator>
	bool
	operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return false; // to do
	}

	template <class T, class Allocator>
	bool
	operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return false; // to do
	}

	template <class T, class Allocator>
	bool
	operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return false; // to do
	}

	template <class T, class Allocator>
	bool
	operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return false; // to do
	}

	template <class T, class Allocator>
	bool
	operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return false; // to do
	}
	
	template <class T, class Allocator>
	bool
	operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return false; // to do
	}
	
	// ======================
	//	  Specialized Algo
	// ======================

	template <class T, class Allocator>
	void
	swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
	{
	
	}
}