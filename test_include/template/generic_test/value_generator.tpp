#ifndef VALUE_GENERATOR_TPP
#define VALUE_GENERATOR_TPP

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
Container fill_n(std::size_t n)
{
	typedef typename Container::value_type value_type;
	std::vector<value_type> v;
	for (std::size_t i = 0; i < n; ++i)
		v.push_back(value_generator<value_type>::make(static_cast<int>(i)));
	return Container(v.begin(), v.end());
}

template <typename Container>
typename Container::value_type generate_value(std::size_t n)
{
	typedef typename Container::value_type value_type;
	return value_generator<value_type>::make(static_cast<int>(n));
}

#endif