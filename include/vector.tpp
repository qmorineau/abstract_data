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
	{
		// Complexity: O(1);
	}

	template <class T, class Allocator>
	ft::vector<T, Allocator>::vector(size_type n, const T& value, const Allocator& alloc)
		: _data(0), _size(0), _allocator(alloc), _capacity(0)
	{
		// Complexity: O(n);
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
		/*
			N = distance(first, last)
			InputIt => copy constructor of T: O(N), reallocation: O(log N);
			ForwardIt => copy constructor of T called N times, no reallocation
		*/
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
		// Complexity: O(x.size())
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
		// Complexity: O(size())
		destroy_all();
	}

	// =====================
	//	    Assignement
	// =====================

	template <class T, class Allocator>
	vector<T,Allocator>&
	ft::vector<T, Allocator>::operator=(const vector<T,Allocator>& x)
	{
		// Complexity: O(size())
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
		// Complexity: O(distance(first, last))
		assign_dispatch(first, last, typename iterator_traits<InputIterator>::iterator_category());
	}
	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::assign(size_type n, const T& u)
	{
		// Complexity: O(n)
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
		// Complexity: O(1)
		return _allocator;
	}

	// =====================
	//	     Iterators
	// =====================

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::iterator
	ft::vector<T, Allocator>::begin()
	{
		// Complexity: O(1)
		return iterator(_data);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_iterator
	ft::vector<T, Allocator>::begin() const
	{
		// Complexity: O(1)
		return const_iterator(_data);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::iterator
	ft::vector<T, Allocator>::end()
	{
		// Complexity: O(1)
		return iterator(_data + _size);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_iterator
	ft::vector<T, Allocator>::end() const
	{
		// Complexity: O(1)
		return const_iterator(_data + _size);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::reverse_iterator
	ft::vector<T, Allocator>::rbegin()
	{
		// Complexity: O(1)
		return reverse_iterator(end());
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_reverse_iterator
	ft::vector<T, Allocator>::rbegin() const
	{
		// Complexity: O(1)
		return const_reverse_iterator(end());
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::reverse_iterator
	ft::vector<T, Allocator>::rend()
	{
		// Complexity: O(1)
		return reverse_iterator(begin());
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_reverse_iterator
	ft::vector<T, Allocator>::rend() const
	{
		// Complexity: O(1)
		return const_reverse_iterator(begin());
	}

	// ====================
	//	     Capacity
	// ====================

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::size_type 
	ft::vector<T, Allocator>::size() const
	{
		// Complexity: O(1)
		return _size;
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::size_type
	ft::vector<T, Allocator>::max_size() const
	{
		// Complexity: O(1)
		return _allocator.max_size();
	}

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::resize(size_type sz, T c)
	{
		// Complexity: O(abs(size - sz)) or more if reallocation (capacity is less than sz)
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
		// Complexity: O(1)
		return _capacity;
	}

	template <class T, class Allocator>
	bool
	ft::vector<T, Allocator>::empty() const
	{
		// Complexity: O(1)
		return _size == 0;
	}

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::reserve(size_type n)
	{
		// Complexity: at most O(size())
		if (n > max_size())
			throw ft::length_error("vector::reserve");
		if (n > _capacity)
		{

			T* tmp = _allocator.allocate(n);
			detail::MemoryGuard<T, Allocator>				mg(_allocator);
			mg.push(tmp, n);
			detail::ConstructGuard<T, Allocator, iterator>	cg(_allocator, iterator(tmp));
			for (size_type i = 0; i < _size; ++i)
			{
				_allocator.construct(tmp + i, _data[i]);
				cg.push();
			}
			cg.release();
			mg.release();

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
		// Complexity: O(1)
		return *(_data + n);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_reference
	ft::vector<T, Allocator>::operator[](size_type n) const
	{
		// Complexity: O(1)
		return *(_data + n);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_reference
	ft::vector<T, Allocator>::at(size_type n) const
	{
		// Complexity: O(1)
		range_check(n);
		return *(_data + n);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::reference
	ft::vector<T, Allocator>::at(size_type n)
	{
		// Complexity: O(1)
		range_check(n);
		return *(_data + n);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::reference
	ft::vector<T, Allocator>::front()
	{
		// Complexity: O(1)
		return *_data;
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_reference
	ft::vector<T, Allocator>::front() const
	{
		// Complexity: O(1)
		return *_data;
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::reference
	ft::vector<T, Allocator>::back()
	{
		// Complexity: O(1)
		return *(_data + _size - 1);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_reference
	ft::vector<T, Allocator>::back() const
	{
		// Complexity: O(1)
		return *(_data + _size - 1);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::pointer
	ft::vector<T, Allocator>::data()
	{
		// Complexity: O(1)
		return _data;
	}
	
	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::const_pointer
	ft::vector<T, Allocator>::data() const
	{
		// Complexity: O(1)
		return _data;
	}

	// =====================
	//	     Modifiers
	// =====================

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::push_back(const T& x)
	{
		// Complexity: amortized O(1)
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
		// Complexity: O(1)
		if (_size)
			_allocator.destroy(_data + --_size);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::iterator
	ft::vector<T, Allocator>::insert(iterator position, const T& x)
	{
		// Complexity: O(1 + (end() - pos))
		size_type pos = static_cast<size_type>(position - begin());
		insert(begin() + pos, 1, x);
		return begin() + pos;
	}

	template <class T, class Allocator>
	void
	ft::vector<T, Allocator>::insert(iterator position, size_type n, const T& x)
	{
		// Complexity: O(n + (end() - pos))
		if (!n)
			return ;
		size_type old_size = _size;
		T value = x;
		size_type pos = static_cast<size_type>(position - begin());
		if (_capacity < _size + n)
			reserve(_capacity * 2 < _size + n ? _size + n : _capacity * 2);
		detail::ConstructGuard<T, Allocator, reverse_iterator>
			tail(_allocator, reverse_iterator(_data + old_size + n));
		for (size_type i = old_size; i > pos; --i)
		{
			_allocator.construct(_data + i - 1 + n, _data[i - 1]);
			tail.push();
			_allocator.destroy(_data + i - 1);
			--_size;
		}
		detail::ConstructGuard<T, Allocator, iterator>
			fill(_allocator, iterator(_data + pos));
		for (size_type i = 0; i < n; ++i)
		{
			_allocator.construct(_data + pos + i, value);
			fill.push();
		}
		fill.release();
		tail.release();
		_size = old_size + n;
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void
	ft::vector<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
	{
		// Complexity: O(distance(first, last) + (end() - pos))
		insert_dispatch(position, first, last, typename iterator_traits<InputIterator>::iterator_category());
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::iterator
	ft::vector<T, Allocator>::erase(iterator position)
	{
		/*
			n1 = element to erase
			n2 = element after the erased elements
			Complexity:
				destructor: O(n1)
				assignement: O(n2)
		*/
		return erase(position, position + 1);
	}

	template <class T, class Allocator>
	typename ft::vector<T, Allocator>::iterator
	ft::vector<T, Allocator>::erase(iterator first, iterator last)
	{
		/*
			n1 = element to erase
			n2 = element after the erased elements
			Complexity:
				destructor: O(n1)
				assignement: O(n2)
		*/
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
	ft::vector<T, Allocator>::swap(vector<T,Allocator>& other)
	{
		// Complexity: O(1)
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
		// Complexity: O(size())
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
		detail::ConstructGuard<T, Allocator, reverse_iterator>
			tail(_allocator, reverse_iterator(_data + old_size + n));
		for (size_type i = _size; i > dist; --i)
		{
			_allocator.construct(_data + i - 1 + n, _data[i - 1]);
			tail.push();
			_allocator.destroy(_data + i - 1);
			--_size;
		}
		detail::ConstructGuard<T, Allocator, iterator>
			fill(_allocator, iterator(_data + dist));
		for (size_type i = 0; i < n; ++i, ++first)
		{
			_allocator.construct(_data + dist + i, *first);
			fill.push();
		}
		fill.release();
		tail.release();
		_size = old_size + n;
	}

	template <class T, class Allocator>
	template <class InputIt>
	void
	ft::vector<T, Allocator>::assign_dispatch(InputIt first, InputIt last, input_iterator_tag)
	{
		vector<T, Allocator> tmp;
		for (; first != last; ++first)
			tmp.push_back(*first);
		assign_dispatch(tmp.begin(), tmp.end(), forward_iterator_tag());
	}

	template <class T, class Allocator>
	template <class ForwardIt>
	void
	ft::vector<T, Allocator>::assign_dispatch(ForwardIt first, ForwardIt last, forward_iterator_tag)
	{
		size_type new_size = ft::distance(first, last);
		if (_capacity < new_size)
		{
			if (new_size > max_size())
				throw ft::length_error("vector::assign");
			T* tmp = _allocator.allocate(new_size);
			detail::MemoryGuard<T, Allocator>				mg(_allocator);
			mg.push(tmp, new_size);
			detail::ConstructGuard<T, Allocator, iterator>	cg(_allocator, iterator(tmp));
			for (size_type i = 0; i < new_size; ++i, ++first)
			{
				_allocator.construct(tmp + i, *first);
				cg.push();
			}
			cg.release();
			mg.release();
			destroy_all();
			_capacity = new_size;
			_data = tmp;
		}
		else if (new_size > _size)
		{
			size_type i = 0;
			for (; i < _size; ++i, ++first)
				_data[i] = *first;
			for (; i < new_size; ++i)
			{
				_allocator.construct(_data + i, *first++);
				++_size;
			}
		}
		else
		{
			size_type i = 0;
			for (; i < new_size; ++i, ++first)
				_data[i] = *first;
			for (; i < _size; ++i)
				_allocator.destroy(_data + i);
		}
		_size = new_size;
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
		/*
			Complexity:
				x.size() != y.size(): O(1)
				else: O(size())
		*/
		if (x.size() != y.size())
			return false;
		typedef typename vector<T,Allocator>::const_iterator const_iterator;
		const_iterator itx = x.begin();
		const_iterator ity = y.begin();
		const_iterator x_end = x.end();
		const_iterator y_end = y.end();
		for (; itx != x_end && ity != y_end; ++itx, ++ity)
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
		/*
			Complexity:
				x.size() != y.size(): O(1)
				else: O(size())
		*/
		return !(x == y);
	}

	template <class T, class Allocator>
	bool
	operator<(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		// Complexity: O(size())
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class T, class Allocator>
	bool
	operator>(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		// Complexity: O(size())
		return (y < x);
	}

	template <class T, class Allocator>
	bool
	operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		// Complexity: O(size())
		return !(x < y);
	}
	
	template <class T, class Allocator>
	bool
	operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		// Complexity: O(size())
		return !(y < x);
	}
	
	// ======================
	//	  Specialized Algo
	// ======================

	template <class T, class Allocator>
	void
	swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
	{
		// Complexity: O(1)
		x.swap(y);
	}
}

#endif