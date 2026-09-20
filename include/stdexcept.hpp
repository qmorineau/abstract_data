#ifndef STDEXCEPT_HPP
#define STDEXCEPT_HPP

#include <string>

#include "exception.hpp"

namespace ft
{
	class runtime_error : public ft::exception
	{
		public:
			runtime_error(const std::string& what_arg) : ft::exception() {_str = what_arg;};
			runtime_error(const char* what_arg) : ft::exception() {_str = what_arg;};
			runtime_error(const runtime_error& other) throw() : ft::exception(other) {};
			runtime_error& operator=(const runtime_error& other) throw()
			{
				if (this != &other)
					_str = other._str;
				return *this;
			}
	};
}

#endif