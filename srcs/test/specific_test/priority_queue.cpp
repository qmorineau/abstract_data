#include "test.hpp"

template <class C>
static void print_priority_queue(C q)
{
	std::cout << "print_priority_queue: size: " << q.size() << ": ";
	while (!q.empty())
	{
		std::cout << q.top() << "|";
		q.pop();
	}
	std::cout << std::endl;
}

template <class C, class U, class Comp>
static void test_priority_queue_constructor()
{
	std::cout << "===== Test: priority_queue() =====" << std::endl;
	{
		C c;
		print_priority_queue(c);
	}
	{
		U u = fill_n<U>(15);
		C c(Comp(), u);
		print_priority_queue(c);
	}
	{
		C copy = fill_n<C>(19);
		C c(copy);
		print_priority_queue(c);
	}
	std::cout << std::endl;
}

template <class C>
static void test_priority_queue_constructor_it()
{
	std::cout << "===== Test: priority_queue(first it, last it) =====" << std::endl;
	// todo
	std::cout << std::endl;
}

template <class C>
static void test_priority_queue_empty()
{
	std::cout << "===== Test: priority_queue.empty() =====" << std::endl;
	C c;
	for (int i = 0; i < 19; ++i)
	{
		if (i % 2)
			c.push(generate_value<C>(15));
		std::cout << c.empty() << "|";
		if ((i % 3 || i % 2) && !c.empty())
			c.pop();
		std::cout << c.empty() << "|";
	}
	std::cout << std::endl;
	while (!c.empty())
	{
		c.pop();
		std::cout << c.empty() << "|";
	}
	std::cout << std::endl;
}

template <class C>
static void test_priority_queue_size()
{
	std::cout << "===== Test: priority_queue.size() =====" << std::endl;
	C c;
	for (int i = 0; i < 150; ++i)
	{
		std::cout << c.size() << "|";
		c.push(generate_value<C>(i * 42));
		std::cout << c.size() << "||";
	}
	print_priority_queue(c);
	std::cout << std::endl;
}

template <class C>
static void test_priority_queue_top()
{
	std::cout << "===== Test: priority_queue.top() =====" << std::endl;
	for (int i = 0; i < 150; ++i)
	{
		{
			C c;
			c.push(generate_value<C>(i));
			std::cout << c.top() << "|";
			c.push(generate_value<C>(i + 1));
			std::cout << c.top() << "||";
		}
		{
			C c;
			c.push(generate_value<C>(i));
			std::cout << c.top() << "|";
			c.push(generate_value<C>(i - 1));
			std::cout << c.top() << "|||";
		}
	}
	std::cout << std::endl;
}

template <class C>
static void test_priority_queue_push()
{
	std::cout << "===== Test: priority_queue.push() =====" << std::endl;
	C c;
	for (int i = 0; i < 150; ++i)
	{
		std::cout << "bef" << c.size() << "|";
		c.push(generate_value<C>(i));
		std::cout << "aft" << c.size() << "||";
	}
	std::cout << std::endl;
}

template <class C>
static void test_priority_queue_pop()
{
	std::cout << "===== Test: priority_queue.pop() =====" << std::endl;
	std::cout << std::endl;
}

template <class C, class U, class Comp>
static void test_priority_queue_functions(std::string name)
{
	std::cout << "=======================================" << std::endl 
	<< "Testing " + name << std::endl
	<< "=======================================" << std::endl;
	test_priority_queue_constructor<C, U, Comp>();
	test_priority_queue_constructor_it<C>();
	test_priority_queue_empty<C>();
	test_priority_queue_size<C>();
	test_priority_queue_top<C>();
	test_priority_queue_push<C>();
	test_priority_queue_pop<C>();
}

template <template <typename, typename> class U,
	template <typename> class Comp,
	template <typename, typename, typename> class C,
	typename T>
static void test_priority_queue_types_unit(std::string underlying_cont, std::string comparator, std::string type)
{
	std::string name("priority_queue");
	name.append(type);
	name.append(underlying_cont);
	name.append(type);
	name.append(comparator);
	test_priority_queue_functions<
		C <T, U<T, std::allocator<T> >, Comp<T> >,
		U<T, std::allocator<T> >,
		Comp<T> >(name);
}

template <template <typename, typename> class U,
	template <typename> class Comp,
	template <typename, typename, typename> class C>
static void test_priority_queue_types(std::string underlying_cont, std::string comparator)
{
	test_priority_queue_types_unit<U, Comp, C, int>(underlying_cont, comparator, "<int>");
	test_priority_queue_types_unit<U, Comp, C, std::string>(underlying_cont, comparator, "<std::string>");
	test_priority_queue_types_unit<U, Comp, C, Foo>(underlying_cont, comparator, "<Foo>");
}

template <template <typename> class Comp,
	template <typename, typename, typename> class C>
void test_priority_queue_container(std::string comp)
{
	test_priority_queue_types<ns::vector, Comp, C>("ns::vector", comp);
	test_priority_queue_types<ns::deque, Comp, C>("ns::deque", comp);
}

void test_priority_queue()
{
	std::cout << "=======================================" << std::endl 
	<< "Testing ::priority_queue" << std::endl
	<< "=======================================" << std::endl;
	test_priority_queue_container<std::less, ns::priority_queue>("std::less");
	test_priority_queue_container<std::greater, ns::priority_queue>("std::greater");
}