#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft
{
	// enable_if
	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	// is_integer
	// template<class T>
	// struct is_integral : std::bool_constant<
	// requires (T t, T* p, void (*f)(T)) // T* parameter excludes reference types
	// {
	//     reinterpret_cast<T>(t); // Exclude class types
	//     f(0); // Exclude enumeration types
	//     p + t; // Exclude everything not yet excluded but integral types
	// }> {};
}

#endif