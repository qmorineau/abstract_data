#ifndef TESTING_CLASSES_HPP
#define TESTING_CLASSES_HPP

#include <iterator>
#include <string>
#include <sstream>
#include <istream>
#include <iostream>

template <class T>
T new_value(size_t n);

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
		void	setData(int value)									{_n = value;}
	private:
		Bar*	_allocated_ptr;
		int		_n;
};
std::ostream& operator<<(std::ostream& out_stream, const Foo& f);
std::istream& operator>>(std::istream& input_stream, Foo& t);

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

		bool	operator==(const Throwing& other) const	{return _n == other._n;}
		bool	operator<(const Throwing& other) const	{return _n < other._n;}
		bool	operator>(const Throwing& other) const	{return _n > other._n;}
		int		data() const {return _n;}
		void	setData(int value) {_n = value;}
	private:
		int _n;
};
std::ostream& operator<<(std::ostream& out_stream, const Throwing& t);
std::istream& operator>>(std::istream& input_stream, Throwing& t);

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

// Input Iterator Testing
template <class T>
class test_input_iterator : public std::iterator<std::input_iterator_tag, T, std::ptrdiff_t, T*, T&>
{
	public:
		typedef T*						pointer;
		typedef T						reference;
		typedef T 						value_type;
		typedef std::ptrdiff_t			difference_type;
		typedef std::input_iterator_tag	iterator_category;

		static void reset(const std::string& content)
		{
			s_stream.clear();
			s_stream.str(content);
			advance();
		}

		test_input_iterator() : _end(true) {}
		explicit test_input_iterator(bool) : _end(false) {}

		reference operator*(void) const			{return new_value<T>(s_cur);}
		pointer operator->(void) const			{advance();}
		test_input_iterator& operator++(void)	{advance(); return *this;}
		test_input_iterator operator++(int)		{advance();}
		bool operator==(const test_input_iterator& other)
		{
			return at_end() == other.at_end();
		}
		bool operator!=(const test_input_iterator& other)
		{
			return !(*this == other);
		}
	private:
		static void advance()	{s_valid = static_cast<bool>(s_stream >> s_cur);}
		bool	at_end() const	{return _end || !s_valid;}

		bool	_end;

		static std::istringstream	s_stream;
		static int					s_cur;
		static bool					s_valid;
};
template <typename T> std::istringstream test_input_iterator<T>::s_stream;
template <typename T> int                test_input_iterator<T>::s_cur = 0;
template <typename T> bool               test_input_iterator<T>::s_valid = false;

#endif