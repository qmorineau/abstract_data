#include "test.hpp"

template <class T>
static void print_queue(ns::queue<T> q)
{
	std::cout << "print_queue: size: " << q.size() << ": ";
	while (!q.empty())
	{
		std::cout << q.front() << "|";
		q.pop();
	}
	std::cout << std::endl;
}

static void test_queue_push()
{
	std::cout << "===== Test: queue.push() =====" << std::endl;
	int size = 42;
	ns::queue<int> s = fill_n<ns::queue<int> >(1);
	print_queue(s);
	for (int i = 0; i < size; ++i)
	{
		s.push(i * 10);
		print_queue(s);
	}
}

static void test_queue_pop()
{
	std::cout << "===== Test: queue.pop() =====" << std::endl;
	ns::queue<int> s = fill_n<ns::queue<int> >(42);
	print_queue(s);
	while (!s.empty())
	{
		s.pop();
		print_queue(s);
	}
}

void test_queue()
{
	std::cout << "=======================================" << std::endl 
	<< "Testing ::queue" << std::endl
	<< "=======================================" << std::endl;
	test_queue_push();
	test_queue_pop();
}