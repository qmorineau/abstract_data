#ifndef STRING_HPP
#define STRING_HPP

#include <string>

namespace ft
{
	template <class T>
	static std::string to_string(T value)
	{
		if (value == 0)
			return std::string("0");
		bool neg = (value < 0);
		std::string res;
		T n = value;
		while (n != 0)
		{
			T digit = n % 10;
			if (digit < 0)
				digit = -digit;
			res.insert(res.begin(), static_cast<char>('0' + digit));
			n /= 10;
		}
		if (neg)
			res.insert(res.begin(), '-');
		return res;
	}
}

#endif