#ifndef HELPER_HPP
#define HELPER_HPP

#include <string>
#include <iostream>
#include <sstream>

#include "testing_classes.hpp"

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
struct fill_dispatch
{
	static Container fill(size_t n)
	{
		typedef typename Container::value_type value_type;
		NoThrowScope guard;

		std::vector<value_type> v;
		for (std::size_t i = 0; i < n; ++i)
			v.push_back(value_generator<value_type>::make(static_cast<int>(i * 10)));
		return Container(v.begin(), v.end());
	}
};

template <typename T, typename Container>
struct fill_dispatch<ns::stack<T, Container> >
{
	static ns::stack<T, Container> fill(size_t n)
	{
		NoThrowScope guard;
		ns::stack<T, Container> result;

		for (std::size_t i = 0; i < n; ++i)
			result.push(value_generator<T>::make(static_cast<int>(i * 10)));
		return result;
	}
};

template <typename T, typename Container>
struct fill_dispatch<ns::queue<T, Container> >
{
	static ns::queue<T, Container> fill(size_t n)
	{
		NoThrowScope guard;
		ns::queue<T, Container> result;

		for (std::size_t i = 0; i < n; ++i)
			result.push(value_generator<T>::make(static_cast<int>(i * 10)));
		return result;
	}
};

template <typename Container>
Container fill_n(size_t n)
{
	return fill_dispatch<Container>::fill(n);
}


template <typename Container>
typename Container::value_type generate_value(size_t n)
{
	typedef typename Container::value_type value_type;
	NoThrowScope guard;

	return value_generator<value_type>::make(static_cast<int>(n));
}

template <typename Container>
void print(Container& c)
{
	typename Container::iterator it = c.begin();
	for (; it != c.end(); ++it)
		std::cout << *it << "|";
	std::cout << std::endl;
}

#endif