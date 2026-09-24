#include "test.hpp"

Foo::Foo() : _allocated_ptr(NULL), _n(67)
{
	_allocated_ptr = new Bar();
}

Foo::Foo(int i) : _allocated_ptr(NULL), _n(i)
{
	_allocated_ptr = new Bar();
}

Foo::Foo(const Foo& other) : _allocated_ptr(NULL), _n(other._n)
{
	(void) other;
	_allocated_ptr = new Bar();
}

Foo& Foo::operator=(const Foo& other)
{
	if (this != &other)
	{
		_n = other._n;
	}
	return *this;
}

Foo::~Foo()
{
	if (_allocated_ptr)	
		delete _allocated_ptr;
}

int Foo::data() const {return _n;}

std::ostream& operator<<(std::ostream& out_stream, const Foo& f)
{
	(void) f;
	out_stream << "Foo" << f.data();
	return out_stream;
}