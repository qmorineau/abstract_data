#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

namespace ft
{
	template<typename T>
	struct Node
	{
		T		value;
		Node	*next;
		Node	*prev;
	};
}

#endif