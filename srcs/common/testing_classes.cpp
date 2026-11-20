#include "testing_classes.hpp"

std::ostream& operator<<(std::ostream& out_stream, const Foo& f)
{
	out_stream << "Foo" << f.data();
	return out_stream;
}

std::istream& operator>>(std::istream& input_stream, Foo& f)
{
	int value;
	if (input_stream >> value)
		f.data();
	return input_stream;
}

std::ostream& operator<<(std::ostream& out_stream, const Throwing& t)
{
	out_stream << "Throwing" << t.data();
	return out_stream;
}

std::istream& operator>>(std::istream& input_stream, Throwing& t)
{
	int value;
	if (input_stream >> value)
		t.data();
	return input_stream;
}