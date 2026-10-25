#include "testing_classes.hpp"

std::ostream& operator<<(std::ostream& out_stream, const Foo& f)
{
	out_stream << "Foo" << f.data();
	return out_stream;
}

std::ostream& operator<<(std::ostream& out_stream, const Throwing& t)
{
	out_stream << "Throwing" << t.data();
	return out_stream;
}