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
		bool operator<(const Foo& other) const
		{
			return _n < other._n;
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

// Predicate

template <typename T>
struct PredEqualTo
{
	T value;
	PredEqualTo(T v) : value(v) {};
	bool operator()(T v) const {return v == value;};
};

template <typename T>
struct PredLesserThan
{
	T value;
	PredLesserThan(T v) : value(v) {};
	bool operator()(T v) const {return v < value;};
};

// Binary Predicate

template <typename T>
struct BinaryPredEqualTo
{
	BinaryPredEqualTo() {};
	bool operator()(T v1, T v2) const {return v1 == v2;};
};

template <typename T>
struct BinaryPredGreaterThan
{
	BinaryPredGreaterThan() {};
	bool operator()(T v1, T v2) const {return v1 > v2;};
};

#endif