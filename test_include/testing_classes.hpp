#ifndef TESTING_CLASSES_HPP
#define TESTING_CLASSES_HPP

#include <string>
#include <iostream>

class Foo
{
	struct Bar
	{
		int i;
		int* j;
		size_t k;
		long h;
		std::string str;
	};
	public:
		Foo() : _allocated_ptr(NULL), _n(67)
		{
			_allocated_ptr = new Bar();
		}
		Foo(int i) : _allocated_ptr(NULL), _n(i)
		{
			_allocated_ptr = new Bar();
		}
		Foo(const Foo& other) : _allocated_ptr(NULL), _n(other._n)
		{
			(void) other;
			_allocated_ptr = new Bar();
		}
		Foo& operator=(const Foo& other)
		{
			if (this != &other)
				_n = other._n;
			return *this;
		}
		~Foo()
		{
			if (_allocated_ptr)
				delete _allocated_ptr;
		}
		int		data() const {return _n;}
	private:
		Bar*	_allocated_ptr;
		int		_n;
};

std::ostream& operator<<(std::ostream& out_stream, const Foo& f);
bool operator==(const Foo& x, const Foo& y);

#endif