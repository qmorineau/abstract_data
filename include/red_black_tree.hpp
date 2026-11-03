#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <memory>

#include "guards.hpp"
#include "functional.hpp"
#include "queue.hpp"

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

			tree_node(node_color c = RED, T v = 0);
		};

		template <class T, class Allocator = std::allocator<T>, class Compare = ft::less<T> >
		class red_black_tree
		{
			public:
				red_black_tree(const Allocator& = Allocator(), const Compare& = ft::less<T>());
				~red_black_tree();
				void insert(const T& value);
			private:
				typedef typename Allocator::template rebind<tree_node<T> >::other	node_allocator;

				Allocator			_alloc;
				node_allocator		_node_alloc;
				const Compare&		_comp;

				tree_node<T>* 		_root;
				tree_node<T>* 		_sentinel;

				void rotate_left(tree_node<T>* x);
				void rotate_right(tree_node<T>* y);
				void fix_insert(tree_node<T>* z);
				void transplant(tree_node<T>* u, tree_node<T>* v);
				void delete_data(T value);
				void fix_delete(tree_node<T>* x);
				tree_node<T>* search(tree_node<T>* node, T value);
				tree_node<T>* minimum(tree_node<T>* node);
				// utils
				tree_node<T>*	new_node(const T& value);
				void			destroy_all();
				void			init_sentinel();
				bool			is_valid_tree() const;
			public:
				void print() const
				{
					ft::queue<tree_node<T>*> q;
					q.push(_root);
					while (!q.empty())
					{
						int level = q.size();
						for (int i = 0; i < level; ++i)
						{
							tree_node<T>* n = q.front();
							q.pop();
							print_node(n);
							if (n)
							{
								q.push(n->left);
								q.push(n->right);
							}
							std::cout << " ";
						}
						std::cout << std::endl;
					}
				}
				void print_node(tree_node<T>* n) const
				{
					if (n)
						std::cout << (n->color == RED ? "R" : "B") << n->value;
					else
						std::cout << "null";
				}
		};
	}
}

#include "red_black_tree.tpp"

#endif