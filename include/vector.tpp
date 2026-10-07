#ifndef VECTOR_TPP
#define VECTOR_TPP

namespace ft
{
	// ======================
	//	Construct / Destruct
	// ======================

	template <class T, class Allocator>
	ft::vector<T, Allocator>::vector(const Allocator& alloc)
		: _data(0), _size(0), _allocator(alloc), _capacity(0)
	{}

	template <class T, class Allocator>
	ft::vector<T, Allocator>::vector(size_type n, const T& value, const Allocator& alloc)
		: _data(0), _size(0), _allocator(alloc), _capacity(0)
	{
		try
		{
			assign(n, value);
		}
		catch(...)
		{
			destroy_all();
			throw ;
		}
	}

	template <class T, class Allocator>
	template <class InputIterator>
	ft::vector<T, Allocator>::vector(InputIterator first, InputIterator last, const Allocator& alloc, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
		: _data(0), _size(0), _allocator(alloc), _capacity(0)
	{
		try
		{
			assign(first, last);
		}
		catch(...)
		{
			destroy_all();
			throw ;
		}
	}

	template <class T, class Allocator>
	ft::vector<T, Allocator>::vector(const vector<T,Allocator>& x)
		: _data(0), _size(0), _allocator(x._allocator), _capacity(0)
	{
		try
		{
			assign(x.begin(), x.end());
		}
		catch(...)
		{
			destroy_all();
			throw ;
		}
	}

	template <class T, class Allocator>
	ft::vector<T, Allocator>::~vector()
	{
		destroy_all();
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
			assign(x.begin(), x.end());
		}
		return *this;
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void
	ft::vector<T, Allocator>::assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
	{
		clear();
		insert(begin(), first, last);
	}
	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::assign(size_type n, const T& u)
	{
		T value = u;
		clear();
		if (n > _capacity)
			reserve(n);
		for (size_type i = 0; i < n; ++i)
		{
			_allocator.construct(_data + i, value);
			++_size;
		}
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
		return const_reverse_iterator(begin());
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
			while (_size < sz)
			{
				_allocator.construct(_data + _size, c);
				++_size;
			}
		}
		else
		{
			for (size_type i = sz; i < _size; ++i)
				_allocator.destroy(_data + i);
			_size = sz;
		}
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
			size_type i = 0;
			try
			{
				for (; i < _size; ++i)
					_allocator.construct(tmp + i, _data[i]);
			}
			catch(...)
			{
				for (size_type j = 0; j < i; ++j)
					_allocator.destroy(tmp + j);
				_allocator.deallocate(tmp, n);
				throw;
			}
			for (size_type j = 0; j < _size; ++j)
				_allocator.destroy(_data + j);
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
		T value = x;
		if (_capacity <= _size)
		{
			size_type new_size;
			if (_capacity == 0)
				new_size = 1;
			else
				new_size = _capacity * 2;
			reserve(new_size);
		}
		_allocator.construct(_data + _size, value);
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
		insert(begin() + pos, 1, x);
		return begin() + pos;
	}

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::insert(iterator position, size_type n, const T& x)
	{
		if (!n)
			return ;
		size_type old_size = _size;
		T value = x;
		size_type pos = static_cast<size_type>(position - begin());
		if (_capacity < _size + n)
		{
			if (_capacity * 2 < _size + n)
				reserve(_size + n);
			else
				reserve(_capacity * 2);
		}
		for (size_type i = old_size; i > pos; --i)
		{
			_allocator.construct(_data + i - 1 + n, _data[i - 1]);
			_allocator.destroy(_data + i - 1);
		}
		_size = pos;
		size_type i = 0;
		try
		{
			for (; i < n; ++i)
				_allocator.construct(_data + pos + i, value);
		}
		catch(...)
		{
			for (size_type j = 0; j < i; ++j)
				_allocator.destroy(_data + pos + j);
			for (size_type k = pos + n; k < old_size + n; ++k)
				_allocator.destroy(_data + k);
			throw ;
		}
		_size = old_size + n;
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void
	ft::vector<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
	{
		insert_dispatch(position, first, last, typename iterator_traits<InputIterator>::iterator_category());
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::iterator
	ft::vector<T, Allocator>::erase(iterator position)
	{
		return erase(position, position + 1);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::iterator
	ft::vector<T, Allocator>::erase(iterator first, iterator last)
	{
		iterator ret = first;
		for (iterator it = last; it != end(); ++it, ++first)
			*first = *it;
		for (iterator it = first; it != end(); ++it)
			_allocator.destroy(&*it);
		_size -= (last - ret);
		return ret;
	}

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::swap(vector<T,Allocator>&other)
	{
		if (this != &other)
		{
			ft::swap(_data, other._data);
			ft::swap(_size, other._size);
			ft::swap(_allocator, other._allocator);
			ft::swap(_capacity, other._capacity);
		}
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
	ft::vector<T, Allocator>::range_check(size_type n) const
	{
		if (n >= this->size())
			throw_out_of_range(n);
	}

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::throw_out_of_range(size_type n) const
	{
		throw ft::out_of_range(
			std::string("vector::range_check: n (which is "
			+ ft::to_string(n)
			+ ") >= this->size() (which is "
			+ ft::to_string(this->size()) + ")")
		);
	}

	template <class T, class Allocator>
	template <class InputIt>
	void
	ft::vector<T, Allocator>::insert_dispatch(iterator pos, InputIt first, InputIt last, input_iterator_tag)
	{
		vector<T, Allocator> tmp;
		for (; first != last; ++first)
			tmp.push_back(*first);
		insert_dispatch(pos, tmp.begin(), tmp.end(), forward_iterator_tag());
	}
	
	template <class T, class Allocator>
	template <class ForwardIt>
	void
	ft::vector<T, Allocator>::insert_dispatch(iterator pos, ForwardIt first, ForwardIt last, forward_iterator_tag)
	{
		size_type n = ft::distance(first, last);
		if (!n)
			return ;
		size_type dist = static_cast<size_type>(pos - begin());
		size_type old_size = _size;
		if (_capacity < old_size + n)
		{
			if (_capacity * 2 < _size + n)
				reserve(_size + n);
			else
				reserve(_capacity * 2);
		}
		for (size_type i = _size; i > dist; --i)
		{
			_allocator.construct(_data + i - 1 + n, _data[i - 1]);
			_allocator.destroy(_data + i - 1);
		}
		_size = dist;
		size_type i = 0;
		try
		{
			for (; i < n; ++i, ++first)
				_allocator.construct(_data + dist + i, *first);
		}
		catch(...)
		{
			for (size_type j = 0; j < i; ++j)
				_allocator.destroy(_data + dist + j);
			for (size_type k = dist + n; k < old_size + n; ++k)
				_allocator.destroy(_data + k);
			throw ;
		}
		_size = old_size + n;
	}

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::destroy_all()
	{
		clear();
		if (_capacity)
		{
			_allocator.deallocate(_data, _capacity);
			_data = 0;
			_capacity = 0;
		}
	}

	// =====================
	//	    Non-Members
	// =====================

	template <class T, class Allocator>
	bool
	operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		if (x.size() != y.size())
			return false;
		typedef typename vector<T,Allocator>::const_iterator const_iterator;
		const_iterator itx = x.begin();
		const_iterator ity = y.begin();
		for (; itx != x.end() && ity != y.end(); ++itx, ++ity)
		{
			if (!(*itx == *ity))
				return false;
		}
		return true;
	}

	template <class T, class Allocator>
	bool
	operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return !(x == y);
	}

	template <class T, class Allocator>
	bool
	operator<(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class T, class Allocator>
	bool
	operator>(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return (y < x);
	}

	template <class T, class Allocator>
	bool
	operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return !(x < y);
	}
	
	template <class T, class Allocator>
	bool
	operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return !(y < x);
	}
	
	// ======================
	//	  Specialized Algo
	// ======================

	template <class T, class Allocator>
	void
	swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
	{
		x.swap(y);
	}
}

#endif