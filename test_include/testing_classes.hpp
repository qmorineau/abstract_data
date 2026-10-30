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
		Foo() : _allocated_ptr(NULL), _n(67)						{_allocated_ptr = new Bar();}
		Foo(int i) : _allocated_ptr(NULL), _n(i)					{_allocated_ptr = new Bar();}
		Foo(const Foo& other) : _allocated_ptr(NULL), _n(other._n)	{(void) other;_allocated_ptr = new Bar();}
		Foo& operator=(const Foo& other)							{if (this != &other) {_n = other._n;} return *this;}
		bool operator<(const Foo& other) const						{return _n < other._n;}
		bool operator>(const Foo& other) const						{return _n > other._n;}
		bool operator==(const Foo& other) const						{return _n == other._n;}
		~Foo()														{if (_allocated_ptr) {delete _allocated_ptr;}}
		int		data() const 										{return _n;}
	private:
		Bar*	_allocated_ptr;
		int		_n;
};
std::ostream& operator<<(std::ostream& out_stream, const Foo& f);

// SilenceScope

struct NullBuff : std::streambuf
{
	int overflow(int c) {return c;}
};

struct SilenceScope
{
	NullBuff nb;
	std::streambuf* old;
	SilenceScope() : old(std::cout.rdbuf(&nb)) {}
	~SilenceScope() {std::cout.rdbuf(old);};
};

// Throwing class and helpers class

struct ThrowingException : std::runtime_error
{
    ThrowingException() : std::runtime_error("Throwing: limit reached") {}
};

struct ThrowingCounter
{
	static std::size_t	count;
	static std::size_t	limit;
	static bool			enabled;

	static void reset(std::size_t l)
	{
		count = 0;
		limit = l;
	}
	static void tick()
	{
		if (!enabled)
			return;
		if (++count > limit)
		{
			count = 0;
			throw ThrowingException();
		}
	}
};

class NoThrowScope
{
	public:
		NoThrowScope() : previous(ThrowingCounter::enabled) {ThrowingCounter::enabled = false;}
		~NoThrowScope() 									{ThrowingCounter::enabled = previous;}
	private:
		bool previous;
};

struct Throwing
{
	public:
		Throwing(int i = 0) : _n(i) 					{ThrowingCounter::tick();}
		Throwing(const Throwing& other) : _n(other._n)	{ThrowingCounter::tick();}
		Throwing& operator=(const Throwing&)			{ThrowingCounter::tick(); return *this;}
		~Throwing() {}

		bool	operator==(const Throwing& other) const	{return _n == other._n;};
		bool	operator<(const Throwing& other) const	{return _n < other._n;};
		int		data() const {return _n;}
	private:
		int _n;
};
std::ostream& operator<<(std::ostream& out_stream, const Throwing& t);

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