#include "exception.hpp"
#include <exception>
#include <iostream>

int main()
{
	try
	{
		throw ft::exception();
	}
	catch(const ft::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		throw std::exception();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
