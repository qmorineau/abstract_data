#include "vector.hpp"

namespace ft
{
	// ======================
	//	Construct / Destruct
	// ======================

	template <class T, class Allocator>
	ft::vector<T, Allocator>::vector(const Allocator& alloc) : _data(0), _size(0), _allocator(alloc), _capacity(0)
	{
	}

	template <class T, class Allocator>
	ft::vector<T, Allocator>::vector(size_type n, const T& value, const Allocator& alloc) : _data(0), _size(0), _allocator(alloc), _capacity(0)
	{
		assign(n, value);
	}

	template <class T, class Allocator>
	template <class InputIterator>
	ft::vector<T, Allocator>::vector(InputIterator first, InputIterator last, const Allocator& alloc, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*) : _data(0), _size(0), _allocator(alloc), _capacity(0)
	{
		assign(first, last);
	}

	template <class T, class Allocator>
	ft::vector<T, Allocator>::vector(const vector<T,Allocator>& x) : _data(0), _size(0), _allocator(x._allocator), _capacity(0)
	{
		assign(x.begin(), x.end());
	}

	template <class T, class Allocator>
	ft::vector<T, Allocator>::~vector()
	{
		for (size_type i = 0; i < _size; i++)
			_allocator.destroy(_data + i);
		if (_capacity)
			_allocator.deallocate(_data, _capacity);
	}

	// =====================
	//	    Assignement
	// =====================

	template <class T, class Allocator>
	vector<T,Allocator>&
	ft::vector<T, Allocator>::operator=(const vector<T,Allocator>& x)
	{
		if (this != &x)
		{
			clear();
			if (_capacity != x._capacity)
			{
				T* tmp = _allocator.allocate(x._capacity);
				_allocator.deallocate(_data, _capacity);
				_data = tmp;
				_capacity = x._capacity;
			}
			assign(x.begin(), x.end());
		}
		return *this;
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void
	ft::vector<T, Allocator>::assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
	{
		if (static_cast<size_type>(last - first) > max_size())
			throw ft::length_error("cannot create ft::vector larger than max_size()");
		reserve(last - first);
		size_type i;
		for (i = 0; first != last; ++first, ++i)
			_allocator.construct(_data + i, *first);
		_size = i;
	}
	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::assign(size_type n, const T& u)
	{
		if (n > _capacity)
			reserve(n);
		for (size_type i = 0; i < _capacity; ++i)
		{
			if (i > _size && i > n)
				break;
			if (i < _size)
				_allocator.destroy(_data + i);
			_allocator.construct(_data + i, u);
		}
		_size = n;
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
		return const_iterator(_data);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::iterator
	ft::vector<T, Allocator>::end()
	{
		return iterator(_data + _size);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_iterator
	ft::vector<T, Allocator>::end() const
	{
		return const_iterator(_data + _size);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::reverse_iterator
	ft::vector<T, Allocator>::rbegin()
	{
		return reverse_iterator(end());
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_reverse_iterator
	ft::vector<T, Allocator>::rbegin() const
	{
		return const_reverse_iterator(end());
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::reverse_iterator
	ft::vector<T, Allocator>::rend()
	{
		return reverse_iterator(begin());
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_reverse_iterator
	ft::vector<T, Allocator>::rend() const
	{
		return const_reverse_iterator(*begin());
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
		return _allocator.max_size();
	}

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::resize(size_type sz, T c)
	{
		if (sz > _capacity)
			reserve(sz);
		if (sz > _size)
		{
			for (size_type i = _size; i < sz; ++i)
				_allocator.construct(_data + i, c);
		}
		else
		{
			for (size_type i = sz; i < _size; ++i)
				_allocator.destroy(_data + i);
		}
		_size = sz;
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
		if (n > max_size())
			throw ft::length_error("vector::reserve");
		if (n > _capacity)
		{
			T* tmp = _allocator.allocate(n);
			for (size_type i = 0; i < _size; i++)
			{
				_allocator.construct(tmp + i, *(_data + i));
				_allocator.destroy(_data + i);
			}
			if (_capacity)
				_allocator.deallocate(_data, _capacity);
			_data = tmp;
			_capacity = n;
		}
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

	template <class T, class Allocator>
	T*
	ft::vector<T, Allocator>::data()
	{
		return _data;
	}
	
	template <class T, class Allocator>
	const T*
	ft::vector<T, Allocator>::data() const
	{
		return _data;
	}

	// =====================
	//	     Modifiers
	// =====================

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::push_back(const T& x)
	{
		if (_capacity <= _size)
		{
			size_type new_size;
			if (_capacity == 0)
				new_size = 1;
			else
				new_size = _capacity * 2;
			reserve(new_size);
		}
		_allocator.construct(_data + _size, x);
		_size++;
	}

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::pop_back()
	{
		if (_size)
			_allocator.destroy(_data + --_size);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::iterator
	ft::vector<T, Allocator>::insert(iterator position, const T& x)
	{
		size_type pos = static_cast<size_type>(position - begin());
		insert(position, 1, x);
		return begin() + pos;
	}

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::insert(iterator position, size_type n, const T& x)
	{
		vector tmp(position, end());
		size_type pos = static_cast<size_type>(position - begin());
		if (_capacity < _size + n)
		{
			if (_capacity * 2 < _size + n)
				reserve(_size + n);
			else
				reserve(_capacity * 2);
		}
		for (size_type i = 0; i < n; ++i)
			_allocator.construct(_data + pos + i, x);
		if (!tmp.empty())
			insert(iterator(begin() + pos + n), tmp.begin(), tmp.end()--);
		_size += n;
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void
	ft::vector<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
	{
		size_type n = last - first;
		vector tmp(position, end());
		size_type pos = static_cast<size_type>(position - begin());
		if (_capacity < _size + n)
		{
			if (_capacity * 2 < _size + n)
				reserve(_size + n);
			else
				reserve(_capacity * 2);
		}
		for (; first != last; ++first)
			_allocator.construct(_data + pos++, *first);
		for (iterator it = tmp.begin(); it != tmp.end(); ++it)
			_allocator.construct(_data + pos++, *it);
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
		for (size_type i = 0; i < _size; i++)
			_allocator.destroy(_data + i);
		_size = 0;
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
			std::string msg("vector::range_check: n (which is " + ft::to_string(n)
				+ ") >= this->size() (which is " + ft::to_string(this->size()) + ")");
			throw ft::out_of_range(msg);
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