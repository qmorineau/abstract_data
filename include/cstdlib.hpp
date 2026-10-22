#ifndef CSTDLIB_HPP
#define CSTDLIB_HPP

namespace ft
{
	inline int abs(int num)
	{
		if (num < 0)
			return -num;
		return num;
	}
	inline long abs(long num)
	{
		if (num < 0)
			return -num;
		return num;
	}
}

#endif