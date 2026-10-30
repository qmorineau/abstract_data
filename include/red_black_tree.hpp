#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <memory>

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
		struct tree_node
		{
			node_color	color;
			T			value;
			tree_node*	left;
			tree_node*	right;
			tree_node*	parent;

			tree_node();
			tree_node(node_color c, T v);
		};

		template <class T, class Allocator = std::allocator<T> >
		class red_black_tree
		{
			public:
				red_black_tree(const Allocator& = Allocator());
				~red_black_tree();
				void leftRotate(tree_node<T>* x);
				void rightRotate(tree_node<T>* x);
			private:
				typedef typename Allocator::template rebind<tree_node<T> >::other	node_allocator;

				tree_node<T>* 		_root;
				tree_node<T>* 		_sentinel;
				node_allocator		_node_alloc;
				const Allocator&	_alloc;

				void destroy_all();
				void init_sentinel();
				bool is_valid_tree() const;
				void print()
				{

				}
				void print_node(tree_node<T>* n)
				{
					std::cout << "print node:" << std::endl;
					std::cout << "	value:" << n->value << std::endl;
					std::cout << "	left:" << n->left << std::endl;
					std::cout << "	right:" << n->right << std::endl;
					std::cout << "	color = " << (n->color == RED ? "red" : "black") << std::endl;
				}
		};
	}
}

#include "red_black_tree.tpp"

#endif