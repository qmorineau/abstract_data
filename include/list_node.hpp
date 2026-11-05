#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

namespace ft
{
	namespace detail
	{
		template<typename T>
		struct list_node
		{
			T		value;
			list_node	*next;
			list_node	*prev;
		};
	}
}

#endif