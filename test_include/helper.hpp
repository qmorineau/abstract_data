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

template <class K, class V>
struct value_generator<ns::pair<const K, V> >
{
	static ns::pair<const K, V> make(int i)
	{
		return ns::pair<const K, V>(value_generator<K>::make(i / 10), value_generator<V>::make(i));
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

template <class T>
T new_value(size_t n)
{
	NoThrowScope guard;

	return value_generator<T>::make(static_cast<int>(n));
}

template <typename T>
struct dispatch_print
{
	static void print(const T& value)
	{
		std::cout << value;
	}
};

template <typename T1, typename T2>
struct dispatch_print<ns::pair<T1, T2> >
{
	static void print(const ns::pair<T1, T2>& value)
	{
		std::cout << "\"" << value.first << "\"->\"" << value.second << "\"";
	}
};

template <typename T>
void print_value(const T& v)
{
	dispatch_print<T>::print(v);	
}

template <typename Container>
void print(Container& c)
{
	typename Container::iterator it = c.begin();
	for (; it != c.end(); ++it)
	{
		dispatch_print<typename Container::value_type>::print(*it);
		std::cout << "|";
	}
	std::cout << "size:" << c.size() << std::endl;
}

#endif