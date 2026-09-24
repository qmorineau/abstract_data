#include "../test.hpp"

template <typename T>
struct value_generator
{
    static T make(int i) { return T(i); }
};

template <>
struct value_generator<std::string>
{
    static std::string make(int i)
	{
		std::ostringstream oss;
		oss << "val" << i;
		return oss.str();
	}
};

template <typename Container>
void fill_n(Container& c, std::size_t n)
{
	typedef typename Container::value_type value_type;
	for (std::size_t i = 0; i < n; ++i)
		c.push_back(value_generator<value_type>::make(static_cast<int>(i)));
}

template <typename Container>
typename Container::value_type generate_value(std::size_t n)
{
	typedef typename Container::value_type value_type;
	return value_generator<value_type>::make(static_cast<int>(n));
}