#ifndef RBTREE_NODE_HPP
#define RBTREE_NODE_HPP

namespace ft
{
	namespace detail
	{
		enum node_color
		{
			RED,
			BLACK
		};

		template <typename T>
		struct rbtree_node
		{
			node_color	color;
			T			value;
			rbtree_node*	left;
			rbtree_node*	right;
			rbtree_node*	parent;

			rbtree_node(node_color c = RED, T v = 0) :
				value(v),
				color(c),
				left(0),
				right(0),
				parent(0)
			{}
		};
	}
}

#endif