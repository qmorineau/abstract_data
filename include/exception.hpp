#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>

namespace ft
{
	class exception
	{
		public:
			exception() throw() {};
			exception(const exception&) throw() {};
			exception& operator=(const exception&) throw() {return *this;};
			virtual ~exception() throw() {};
			virtual const char* what() const throw() {return "ft::exception";};
	};
}

#endif	