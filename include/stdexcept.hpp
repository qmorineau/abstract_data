#ifndef STDEXCEPT_HPP
#define STDEXCEPT_HPP

#include <string>

#include "exception.hpp"

namespace ft
{
	namespace detail
	{
		class msg_exception : public ft::exception
		{
			public:
				explicit msg_exception(const std::string& msg) : _msg(msg) {};
				msg_exception(const msg_exception& other) : ft::exception(other), _msg(other._msg) {};
				msg_exception& operator=(const msg_exception& other)
				{
					if (this != &other)
					{
						ft::exception::operator=(other);
						_msg = other._msg;
					}
					return *this;
				}
				virtual const char* what() const throw() {return _msg.c_str();};
				virtual ~msg_exception() throw() {};
			protected:
				std::string _msg;
		};
	}

	class logic_error : public ft::detail::msg_exception
	{
		public:
			explicit logic_error(const std::string& what_arg) : ft::detail::msg_exception(what_arg) {};
	};

	class runtime_error : public ft::detail::msg_exception
	{
		public:
			explicit runtime_error(const std::string& what_arg) : ft::detail::msg_exception(what_arg) {};
	};

	class length_error : public ft::logic_error
	{
		public:
			explicit length_error(const std::string& what_arg) : ft::logic_error(what_arg) {};
	};
}

#endif