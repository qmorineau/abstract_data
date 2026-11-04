#ifndef RED_BLACK_TREE_TPP
#define RED_BLACK_TREE_TPP

namespace ft
{
	namespace detail
	{
		// ======================
		//	     TreeNode
		// ======================

		template <typename T>
		tree_node<T>::tree_node(node_color c, T v) :
			value(v),
			color(c),
			left(0),
			right(0),
			parent(0)
		{
		}

		// ======================
		//	    RedBlackTree
		// ======================

		// ======================
		//	      public
		// ======================

		template <class T, class Allocator, class Compare>
		red_black_tree<T, Allocator, Compare>::red_black_tree(const Allocator& alloc, const Compare& comp)
			:	_alloc(alloc),
				_node_alloc(alloc),
				_comp(comp),
				_root(0),
				_sentinel(0)
		{
			try
			{
				init_sentinel();
			}
			catch(...)
			{
				destroy_all();
				throw;
			}
		}

		template <class T, class Allocator, class Compare>
		red_black_tree<T, Allocator, Compare>::~red_black_tree()
		{
			destroy_all();
		}

		template <class T, class Allocator, class Compare>
		void 
		red_black_tree<T, Allocator, Compare>::insert(const T& value)
		{
			tree_node<T>* node = new_node(value);
			tree_node<T>* curr = _root;
			tree_node<T>* parent = 0;
			// searching insert position
			while (curr != _sentinel)
			{
				parent = curr;
				if (_comp(value, curr->value))
					curr = curr->left;
				else
					curr = curr->right;
			}
			// insertion
			node->parent = parent;
			if (!parent)
				_root = node;
			else if (_comp(value, parent->value))
				parent->left = node;
			else
				parent->right = node;
			fix_insert(node);
		}

		// ======================
		//	      private
		// ======================

		template <class T, class Allocator, class Compare>
		void
		red_black_tree<T, Allocator, Compare>::rotate_left(tree_node<T>* x)
		{
			tree_node<T>* y = x->right;
			x->right = y->left;
			if (y->left != _sentinel)
				y->left->parent = x;
			y->parent = x->parent;
			if (!x->parent)
				_root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
		}

		template <class T, class Allocator, class Compare>
		void 
		red_black_tree<T, Allocator, Compare>::rotate_right(tree_node<T>* y)
		{
			tree_node<T>* x = y->left;
			y->left = x->right;
			if (x->right != _sentinel)
				x->right->parent = y;
			x->parent = y->parent;
			if (!y->parent)
				_root = x;
			else if (y == y->parent->right)
				y->parent->right = x;
			else
				y->parent->left = x;
			x->right = y;
			y->parent = x;
		}

		template <class T, class Allocator, class Compare>
		void
		red_black_tree<T, Allocator, Compare>::fix_insert(tree_node<T>* z)
		{
			// Case: Parent is red, needing adjustment
			while (z->parent && z->parent->color == RED)
			{
				tree_node<T>* y = 0;
				if (z->parent == z->parent->parent->left)
				{
					y = z->parent->parent->right; // uncle node
					if (y->color == RED)
					{
						// Case 2: both parent and uncle are red
						z->parent->color = BLACK;
						y->color = BLACK;
						z->parent->parent->color = RED;
						z = z->parent->parent; //recursion upward
					}
					else
					{
						// Case 3: parent is red, uncle is black, and z is a right child
						if (z == z->parent->right)
						{
							z = z->parent;
							rotate_left(z);
						}
						// Case 3: left rotation done, recolor and rotate
						z->parent->color = BLACK;
						z->parent->parent->color = RED;
						rotate_right(z->parent->parent); // right rotate to fix violation
					}
				}
				else
				{
					// symmetric cass for when z's parent is the right child
					y = z->parent->parent->left;
					if (y->color == RED)
					{
						// Case 2: both parent and uncle are red
						z->parent->color = BLACK;
						y->color = BLACK;
						z->parent->parent->color = RED;
						z = z->parent->parent; //recursion upward
					}
					else
					{
						// Case 3: parent is red, uncle is black, and z is a left child
						if (z == z->parent->left)
						{
							z = z->parent;
							rotate_right(z);
						}
						// Case 3: left rotation done, recolor and rotate
						z->parent->color = BLACK;
						z->parent->parent->color = RED;
						rotate_left(z->parent->parent); // right rotate to fix violation
					}
				}
			}
			// Case 1: Root is always black after insertion fix
			_root->color = BLACK;
		}

		template <class T, class Allocator, class Compare>
		void
		red_black_tree<T, Allocator, Compare>::transplant(tree_node<T>* u, tree_node<T>* v)
		{
			if (!u->parent)
				_root = v;
			else if (u == u->parent.left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}

		template <class T, class Allocator, class Compare>
		void
		red_black_tree<T, Allocator, Compare>::delete_data(T value)
		{
			tree_node<T>* z = search(_root, value);
			if (z == _sentinel)
				return ;
			tree_node<T>* x = 0;
			tree_node<T>* y = z;
			node_color y_base_color = y->color;
			if (z->left == _sentinel)
			{
				tree_node<T>* x = z->right;
				transplant();
			}
			else if (z->right == _sentinel)
			{
				x = z->right;
				transplant(z, z->left);
			}
			else
			{
				y = minimum(z->right);
				y_base_color = y->color;
				x = y->right;
				if (y->parent == z)
					x.parent = y;
				else
				{
					transplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				transplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			if (y_base_color == BLACK)
				fix_delete(x);
		}

		template <class T, class Allocator, class Compare>
		void
		red_black_tree<T, Allocator, Compare>::fix_delete(tree_node<T>* x)
		{
			while (x != _root && x->color == BLACK)
			{
				tree_node<T>* w = 0;
				if (x == x->parent->left)
				{
					w = x->parent->right; // sibling node
					if (w->color == RED)
					{
						// Case 1: sibling is red
						w->color = BLACK;
						x->parent->color = RED;
						rotate_left(x->parent);
						w = x->parent->right;
					}
					if (w->left->color == BLACK && w->right->color == BLACK)
					{
						w->color = RED;
						x = x->parent; // Move up the tree
					}
					else
					{
						if (w->right->color == BLACK)
						{
							// Case 3: sibling is black, left child is red, right is black
							w->left->color = BLACK;
							w->color = RED;
							rotate_right(w);
							w = x->parent->right;
						}
						// Case 3: Right child of sibling is red
						w.color = x->parent->color;
						x->parent->color = BLACK;
						w->right->color = BLACK;
						rotate_left(x->parent);
						x = _root;
					}
				}
				else
				{
					// symmetric cases for when x is the right child
					w = x->parent->left;
					if (w->color == RED)
					{
						// Case 1: sibling is red
						w->color = BLACK;
						x->parent->color = RED;
						rotate_right(x->parent);
						w = x->parent->left;
					}
					if (w->left->color == BLACK && w->left->color == BLACK)
					{
						w->color = RED;
						x = x->parent; // Move up the tree
					}
					else
					{
						if (w->right->color == BLACK)
						{
							// Case 3: sibling is black, left child is red, right is black
							w->left->color = BLACK;
							w->color = RED;
							rotate_left(w);
							w = x->parent->left;
						}
						// Case 3: Right child of sibling is red
						w.color = x->parent->color;
						x->parent->color = BLACK;
						w->right->color = BLACK;
						rotate_right(x->parent);
						x = _root;
					}
				}
			}
			x->color = BLACK;
		}

		template <class T, class Allocator, class Compare>
		tree_node<T>*
		red_black_tree<T, Allocator, Compare>::search(tree_node<T>* node, T value)
		{
			if (node == _sentinel || value)
				return node;
			if (_comp(value, node->value))
				return search(node->left, value);
			return search(node->right, value);
		}

		template <class T, class Allocator, class Compare>
		tree_node<T>*
		red_black_tree<T, Allocator, Compare>::minimum(tree_node<T>* node)
		{
			while (node->left != _sentinel)
				node = node->left;
			return node;
		}

		// ======================
		//	      Utils
		// ======================

		template <class T, class Allocator, class Compare>
		tree_node<T>*
		red_black_tree<T, Allocator, Compare>::new_node(const T& value)
		{
			tree_node<T>* tmp = _node_alloc.allocate(1);
			detail::MemoryGuard<tree_node<T>, node_allocator> guard(_node_alloc);
			guard.push(tmp, 1);
			tmp->left = _sentinel;
			tmp->right = _sentinel;
			tmp->parent = 0;
			tmp->color = RED;
			_alloc.construct(&tmp->value, value);
			guard.release();
			return tmp;
		}

		template <class T, class Allocator, class Compare>
		void
		red_black_tree<T, Allocator, Compare>::init_sentinel()
		{
			tree_node<T>* tmp = _node_alloc.allocate(1);
			tmp->left = 0;
			tmp->right = 0;
			tmp->parent = 0;
			tmp->value = 0;
			tmp->color = BLACK;
			_sentinel = tmp;
			_root = _sentinel;
		}

		template <class T, class Allocator, class Compare>
		void
		red_black_tree<T, Allocator, Compare>::destroy_all()
		{
			ft::queue<tree_node<T>*> q;
			if (_root != _sentinel)
				q.push(_root);
			while (!q.empty())
			{
				int level = q.size();
				for (int i = 0; i < level; ++i)
				{
					tree_node<T>* node = q.front();
					if (node->left != _sentinel)
						q.push(node->left);
					if (node->right != _sentinel)
						q.push(node->right);
					_alloc.destroy(&node->value);
					_node_alloc.deallocate(node, 1);
					q.pop();
				}
			}
			_root = 0;
			if (_sentinel)
			{
				_node_alloc.deallocate(_sentinel, 1);
				_sentinel = 0;
			}
		}

		template <class T, class Allocator, class Compare>
		bool
		red_black_tree<T, Allocator, Compare>::is_valid_tree() const
		{
			ft::vector<ft::size_t> black_counts;
			ft::queue<tree_node<T>*> q;
			ft::queue<tree_node<T>*> leafs;
			if (_sentinel->color != BLACK)
				return false;
			if (_root != _sentinel)
				q.push(_root);
			else
				return true;
			while (!q.empty())
			{
				tree_node<T>* node = q.front();
				q.pop();
				if (node->left != _sentinel)
					q.push(node->left);
				if (node->right != _sentinel)
					q.push(node->right);
				if (node->left == _sentinel || node->right == _sentinel)
					leafs.push(node);
			}
			while (!leafs.empty())
			{
				tree_node<T>* node = leafs.front();
				leafs.pop();
				ft::size_t	black_node_count = 1;
				while (true)
				{
					if (node->color == BLACK)
						++black_node_count;
					if (node == _root)
					{
						black_counts.push_back(black_node_count);
						break;
					}
					if (node->color == RED && node->parent->color == RED)
						return false;
					node = node->parent;
				}
			}
			for (ft::size_t i = 1; i < black_counts.size(); ++i)
			{
				if (black_counts[0] != black_counts[i])
					return false;
			}
			return true;
		}
	}
}

#endif