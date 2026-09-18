#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>

namespace ft
{
	class exception
	{
		public:
			exception() throw() : _str("ft::exception") {};
			exception(const exception& other) throw() : _str(other._str) {};
			exception& operator=(const exception& other) throw()
			{
				if (this != &other)
				{
					_str = other._str;
				}
				return *this;
			};
			virtual ~exception() throw() {};
			virtual const char* what() const throw() {return _str.c_str();};
		private:
			std::string	_str;
	};
}

#endif	