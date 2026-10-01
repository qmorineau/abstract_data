#ifndef VECTOR_TPP
#define VECTOR_TPP

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
				_allocator.construct(tmp + i, _data[i]);
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
			reserve(new_size);VECTOR_TPP
VECTOR_TPP
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
		if (!n)
			return ;
		T value = x;
		if (_capacity < _size + n)
		{
			if (_capacity * 2 < _size + n)
				reserve(_size + n);
			else
				reserve(_capacity * 2);
		}
		size_type pos = static_cast<size_type>(position - begin());
		for (size_type i = _size; i > pos; --i)
		{
			_allocator.construct(_data + i - 1 + n, _data[i - 1]);
			_allocator.destroy(_data + i - 1);
		}
		for (size_type i = 0; i < n; ++i)
			_allocator.construct(_data + pos + i, value);
		_size += n;
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void
	ft::vector<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
	{
		vector src(first, last);
		size_type n = src.size();
		size_type pos = static_cast<size_type>(position - begin());
		if (!n)
			return ;
		if (_capacity < _size + n)
		{
			if (_capacity * 2 < _size + n)
				reserve(_size + n);
			else
				reserve(_capacity * 2);
		}
		for (size_type i = _size; i > pos; --i)
		{
			_allocator.construct(_data + i - 1 + n, _data[i - 1]);
			_allocator.destroy(_data + i - 1);
		}
		for (size_type i = 0; i < n; ++i)
			_allocator.construct(_data + pos + i, src[i]);
		_size += n;
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::iterator
	ft::vector<T, Allocator>::erase(iterator position)
	{
		size_type pos = position - begin();
		_allocator.destroy(_data + pos);
		for (; pos + 1 < _size; ++pos)
		{
			_allocator.construct(_data + pos, _data[pos + 1]);
			_allocator.destroy(_data + pos + 1);
		}
		_size--;
		return position;
		// check return
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::iterator
	ft::vector<T, Allocator>::erase(iterator first, iterator last)
	{
		size_type erase_begin = first - begin();
		size_type erase_end = last - begin();
		size_type diff = erase_end - erase_begin;
		for (size_type tmp = erase_begin; tmp <= erase_end; ++tmp)
			_allocator.destroy(_data + tmp);
		for (; erase_end < _size; ++erase_end, ++erase_begin)
		{
			_allocator.destroy(_data + erase_end);
			_allocator.construct(_data + erase_begin, _data[erase_end]);
		}
		_size -= diff;
		return end();
		// check return
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
	ft::vector<T, Allocator>::range_check(size_type n)
	{
		if (n >= this->size())
		{
			std::string msg("vector::range_check: n (which is "
				+ ft::to_string(n)
				+ ") >= this->size() (which is "
				+ ft::to_string(this->size()) + ")");
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
		typedef typename vector<T,Allocator>::iterator iterator;
		iterator itx = x.begin();
		iterator ity = y.begin();
		for (; itx != x.end() && ity != y.end(); ++itx, ++ity)
		{
			if (!(itx == ity))
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
	operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class T, class Allocator>
	bool
	operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
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