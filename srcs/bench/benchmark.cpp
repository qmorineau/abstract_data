#include "test.hpp"

template <class C>
static void bench_unit(const std::string name)
{
	bench_common<C>(name);
	bench_element_access<C>(name);
	bench_iterators<C>(name);
	bench_capacity<C>(name);
	bench_observers<C>(name);
	bench_operations<C>(name);
	bench_modifier<C>(name);
	bench_non_member<C>(name);
}

// Sequence

template <template <typename, typename> class Container>
static void benchmark_sequence_container(std::string name)
{
	bench_unit<Container<int, std::allocator<int> > >(name + "<int>");
	bench_unit<Container<std::string, std::allocator<std::string> > >(name + "<std::string>");
	bench_unit<Container<Foo, std::allocator<Foo> > >(name + "<Foo>");
	std::cout << std::endl;
}

// Adaptator

// template <template <typename, typename, typename> class Container, class T, class C>
// static void benchmark_container_adaptator_comp_type(std::string name, std::string type, std::string container)
// {
// 	std::string c_name = name + "<" + type + "," + container;
// 	bench_unit<Container<T, C, std::less<T> >(c_name + ",std::less<" + type + ">>");
// 	bench_unit<Container<T, C, std::greater<T> >(c_name + ",std::greater<" + type + ">>");
// }

// template <template <typename, typename, typename> class Container, class T>
// static void benchmark_container_adaptator_container_type(std::string name, std::string type)
// {
// 	benchmark_container_adaptator_comp_type<Container, T, std::vector<T> >(name, type, "std::vector<" + type + ">");
// 	benchmark_container_adaptator_comp_type<Container, T, std::deque<T> >(name, type, "std::deque<" + type + ">");
// }

// template <template <typename, typename, typename> class Container>
// static void benchmark_container_adaptator(std::string name)
// {
// 	benchmark_container_adaptator_container_type<Container, int>(name, "int");
// 	benchmark_container_adaptator_container_type<Container, std::string>(name, "std::string");
// 	benchmark_container_adaptator_container_type<Container, Foo>(name, "Foo");
// }

// template <template <typename, typename> class Container>
// static void benchmark_container_adaptator(std::string name, container_adaptator c)
// {
// 	if (c == STACK || c == QUEUE)
// 	{
// 		std::string container = "deque";
// 		bench_unit<Container<int, ns::deque<int> > >(name + "<int, " + container + "<int>>");
// 		bench_unit<Container<std::string, ns::deque<std::string> > >(name + "<std::string, " + container + "<std::string>>");
// 		bench_unit<Container<Foo, ns::deque<Foo> > >(name + "<Foo, " + container + "<Foo>>");

// 		container = "list";
// 		bench_unit<Container<int, ns::list<int> > >(name + "<int, " + container + "<int>>");
// 		bench_unit<Container<std::string, ns::list<std::string> > >(name + "<std::string, " + container + "<std::string>>");
// 		bench_unit<Container<Foo, ns::list<Foo> > >(name + "<Foo, " + container + "<Foo>>");
// 	}
// 	if (c == STACK)
// 	{
// 		std::string container = "vector";
// 		bench_unit<Container<int, ns::vector<int> > >(name + "<int, " + container + "<int>>");
// 		bench_unit<Container<std::string, ns::vector<std::string> > >(name + "<std::string, " + container + "<std::string>>");
// 		bench_unit<Container<Foo, ns::vector<Foo> > >(name + "<Foo, " + container + "<Foo>>");
// 	}
// }

// Associative

template <template <typename, typename, typename, typename> class Container, typename K, typename V>
static void benchmark_associative_container_value_type(std::string& name, std::string& key, std::string value)
{
	bench_unit<Container<K,V,std::less<K>,std::allocator<ns::pair<const K,V> > > >(name + "<" + key + "," + value + ",std::less<pair<" + key + "," + value + "> > >");
	bench_unit<Container<K,V,std::greater<K>,std::allocator<ns::pair<const K,V> > > >(name + "<" + key + "," + value + ",std::greater<pair<" + key + "," + value + "> > >");
}

template <template <typename, typename, typename, typename> class Container, typename K>
static void benchmark_associative_container_key_type(std::string& name, std::string key)
{
	benchmark_associative_container_value_type<Container, K, int>(name, key, "int");
	benchmark_associative_container_value_type<Container, K, std::string>(name, key, "std::string");
	benchmark_associative_container_value_type<Container, K, Foo>(name, key, "Foo");
}

template <template <typename, typename, typename, typename> class Container>
void benchmark_associative_container(std::string name)
{
	benchmark_associative_container_key_type<Container, int>(name, "int");
	benchmark_associative_container_key_type<Container, std::string>(name, "std::string");
	benchmark_associative_container_key_type<Container, Foo>(name, "Foo");
}

// Main

std::size_t ThrowingCounter::count = 0;
std::size_t ThrowingCounter::limit = 0;
bool		ThrowingCounter::enabled = true;

int main()
{
	benchmark_sequence_container<ns::vector>("vector");
	benchmark_sequence_container<ns::list>("list");
	benchmark_sequence_container<ns::deque>("deque");
	
	// benchmark_container_adaptator<ns::stack>("stack", STACK);
	// benchmark_container_adaptator<ns::queue>("queue", QUEUE);
	// benchmark_container_adaptator<ns::priority_queue>("priority_queue");

	benchmark_associative_container<ns::map>("map");
	// benchmark_associative_container<ns::multimap>("multimap");
	// benchmark_associative_container<ns::set>("set");
	// benchmark_associative_container<ns::multiset>("multiset");
}