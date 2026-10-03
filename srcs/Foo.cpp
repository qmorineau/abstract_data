#include "testing_classes.hpp"

std::ostream& operator<<(std::ostream& out_stream, const Foo& f)
{
	(void) f;
	out_stream << "Foo" << f.data();
	return out_stream;
}

bool operator==(const Foo& x, const Foo& y)
{
	return x.data() == y.data();
}