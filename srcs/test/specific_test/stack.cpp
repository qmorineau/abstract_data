#include "test.hpp"

template <class T>
static void print_stack(ns::stack<T> s)
{
	std::cout << "print_stack: size: " << s.size() << ": ";
	while (!s.empty())
	{
		std::cout << s.top() << "|";
		s.pop();
	}
	std::cout << std::endl;
}

static void test_stack_push()
{
	std::cout << "===== Test: stack.push() =====" << std::endl;
	int size = 42;
	ns::stack<int> s = fill_n<ns::stack<int> >(1);
	print_stack(s);
	for (int i = 0; i < size; ++i)
	{
		s.push(i * 10);
		print_stack(s);
	}
}

static void test_stack_pop()
{
	std::cout << "===== Test: stack.pop() =====" << std::endl;
	ns::stack<int> s = fill_n<ns::stack<int> >(42);
	print_stack(s);
	while (!s.empty())
	{
		s.pop();
		print_stack(s);
	}
}

void test_stack()
{
	std::cout << "=======================================" << std::endl 
	<< "Testing ::stack" << std::endl
	<< "=======================================" << std::endl;
	test_stack_push();
	test_stack_pop();
}