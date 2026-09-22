#ifndef STDEXCEPT_HPP
#define STDEXCEPT_HPP

#include <string>

#include "exception.hpp"

namespace ft
{
	class logic_error : public ft::exception
	{
		public:
			explicit logic_error(const std::string& what_arg) : ft::exception() {_str = std::string(" what():  " + what_arg);};
			logic_error(const char* what_arg) : ft::exception() {_str = what_arg;};
			logic_error(const logic_error& other) throw() : ft::exception(other) {};
			logic_error& operator=(const logic_error& other) throw()
			{
				if (this != &other)
					_str = other._str;
				return *this;
			}
	};

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

	class length_error : public ft::exception
	{
		public:
			length_error(const std::string& what_arg) : ft::exception() {_str = what_arg;};
			length_error(const char* what_arg) : ft::exception() {_str = what_arg;};
			length_error(const length_error& other) throw() : ft::exception(other) {};
			length_error& operator=(const length_error& other) throw()
			{
				if (this != &other)
					_str = other._str;
				return *this;
			}
	};
}

#endif