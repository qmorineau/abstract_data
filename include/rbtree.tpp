#ifndef RBTREE_TPP
#define RBTREE_TPP

namespace ft
{
	namespace detail
	{
		// ======================
		//	Construct / Destruct
		// ======================

		template <class T, class Compare, class Allocator>
		rbtree<T,Compare,Allocator>::rbtree(const Allocator& alloc, const Compare& comp)
			:	_alloc(alloc),
				_node_alloc(alloc),
				_comp(comp),
				_root(0),
				_sentinel(0),
				_size(0)
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

		template <class T, class Compare, class Allocator>
		rbtree<T,Compare,Allocator>::rbtree(const rbtree& x)
			:	_alloc(x._alloc),
				_node_alloc(x._node_alloc),
				_comp(x._comp),
				_root(0),
				_sentinel(0),
				_size(0)
		{
			try
			{
				init_sentinel();
				insert(x.begin(), x.end());
			}
			catch(...)
			{
				destroy_all();
				throw;
			}
		}

		template <class T, class Compare, class Allocator>
		rbtree<T,Compare,Allocator>::~rbtree()
		{
			destroy_all();
		}

		// =====================
		//	    Assignement
		// =====================

		template <class T, class Compare, class Allocator>
		rbtree<T,Compare,Allocator>&
		rbtree<T,Compare,Allocator>::operator=(const rbtree& x)
		{
			if (this != &x)
			{
				clear();
				insert(x.begin(), x.end());
			}
			(void) x;
			// todo
		}

		template <class T, class Compare, class Allocator>
		typename rbtree<T,Compare,Allocator>::allocator_type
		rbtree<T,Compare,Allocator>::get_allocator() const
		{
			return _alloc;
		}

		// =====================
		//	     Iterators
		// =====================

		template <class T, class Compare, class Allocator>
		typename rbtree<T,Compare,Allocator>::iterator
		rbtree<T,Compare,Allocator>::begin()
		{
			// Complexity: O(1)
			return iterator(_sentinel->left, _sentinel);
		}

		template <class T, class Compare, class Allocator>
		typename rbtree<T,Compare,Allocator>::const_iterator
		rbtree<T,Compare,Allocator>::begin() const
		{
			// Complexity: O(1)
			return const_iterator(_sentinel->left, _sentinel);
		}

		template <class T, class Compare, class Allocator>
		typename rbtree<T,Compare,Allocator>::iterator
		rbtree<T,Compare,Allocator>::end()
		{
			// Complexity: O(1)
			return iterator(_sentinel, _sentinel);
		}

		template <class T, class Compare, class Allocator>
		typename rbtree<T,Compare,Allocator>::const_iterator	
		rbtree<T,Compare,Allocator>::end() const
		{
			// Complexity: O(1)
			return const_iterator(_sentinel, _sentinel);
		}

		template <class T, class Compare, class Allocator>
		typename rbtree<T,Compare,Allocator>::reverse_iterator
		rbtree<T,Compare,Allocator>::rbegin()
		{
			// Complexity: O(1)
			return reverse_iterator(end());
		}

		template <class T, class Compare, class Allocator>
		typename rbtree<T,Compare,Allocator>::const_reverse_iterator
		rbtree<T,Compare,Allocator>::rbegin() const
		{
			// Complexity: O(1)
			return const_reverse_iterator(end());
		}

		template <class T, class Compare, class Allocator>
		typename rbtree<T,Compare,Allocator>::reverse_iterator
		rbtree<T,Compare,Allocator>::rend()
		{
			// Complexity: O(1)
			return reverse_iterator(begin());
		}

		template <class T, class Compare, class Allocator>
		typename rbtree<T,Compare,Allocator>::const_reverse_iterator
		rbtree<T,Compare,Allocator>::rend() const
		{
			// Complexity: O(1)
			return const_reverse_iterator(begin());
		}

		// ====================
		//	     Capacity
		// ====================

		template <class T, class Compare, class Allocator>
		bool
		rbtree<T,Compare,Allocator>::empty() const
		{
			// Complexity: O(1)
			return (_size == 0);
		}

		template <class T, class Compare, class Allocator>
		typename rbtree<T,Compare,Allocator>::size_type
		rbtree<T,Compare,Allocator>::size() const
		{
			// Complexity: O(1)
			return _size;
		}

		template <class T, class Compare, class Allocator>
		typename rbtree<T,Compare,Allocator>::size_type
		rbtree<T,Compare,Allocator>::max_size() const
		{
			// Complexity: O(1)
			return _alloc.max_size();
		}

		// =====================
		//	     Modifiers
		// =====================

		template <class T, class Compare, class Allocator>
		typename rbtree<T,Compare,Allocator>::iterator
		rbtree<T,Compare,Allocator>::insert(iterator pos, const T& value)
		{
			// todo
		}

		template <class T, class Compare, class Allocator>
		template <class InputIterator>
		void 
		rbtree<T,Compare,Allocator>::insert(InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type*)
		{
			insert_dispatch(first, last, typename iterator_traits<InputIterator>::iterator_category());
		}

		template <class T, class Compare, class Allocator>
		void 
		rbtree<T,Compare,Allocator>::insert(const T& value)
		{
			node_pointer node = new_node(value);
			node_pointer curr = _root;
			node_pointer parent = 0;

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
			++_size;
			fix_insert(node);
			update_sentinelle(node);
		}

		template <class T, class Compare, class Allocator>
		void
		rbtree<T,Compare,Allocator>::clear()
		{
			clear_sub_tree(_root);
			_root = _sentinel;
			_sentinel->left = _sentinel;
			_sentinel->right = _sentinel;
		}

		// =====================
		//	  Private-Members
		// =====================

		template <class T, class Compare, class Allocator>
		template <class InputIt>
		void
		rbtree<T,Compare,Allocator>::insert_dispatch(InputIt first, InputIt last, input_iterator_tag)
		{
			vector<T, Allocator> tmp;
			for (; first != last; ++first)
				tmp.push_back(*first);
			insert_dispatch(tmp.begin(), tmp.end(), forward_iterator_tag());
		}

		template <class T, class Compare, class Allocator>
		template <class ForwardIt>
		void
		rbtree<T,Compare,Allocator>::insert_dispatch(ForwardIt first, ForwardIt last, forward_iterator_tag)
		{
			while (first != last)
			{
				insert(*first);
				++first;
			}
		}

		template <class T, class Compare, class Allocator>
		void
		rbtree<T,Compare,Allocator>::rotate_left(node_pointer x)
		{
			node_pointer y = x->right;
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

		template <class T, class Compare, class Allocator>
		void 
		rbtree<T,Compare,Allocator>::rotate_right(node_pointer y)
		{
			node_pointer x = y->left;
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

		template <class T, class Compare, class Allocator>
		void
		rbtree<T,Compare,Allocator>::fix_insert(node_pointer z)
		{
			// Case: Parent is red, needing adjustment
			while (z->parent && z->parent->color == RED)
			{
				node_pointer y = 0;
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

		template <class T, class Compare, class Allocator>
		void
		rbtree<T,Compare,Allocator>::transplant(node_pointer u, node_pointer v)
		{
			if (!u->parent)
				_root = v;
			else if (u == u->parent.left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}

		template <class T, class Compare, class Allocator>
		void
		rbtree<T,Compare,Allocator>::delete_data(T value)
		{
			node_pointer z = search(_root, value);
			if (z == _sentinel)
				return ;
			node_pointer x = 0;
			node_pointer y = z;
			node_color y_base_color = y->color;
			if (z->left == _sentinel)
			{
				node_pointer x = z->right;
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

		template <class T, class Compare, class Allocator>
		void
		rbtree<T,Compare,Allocator>::fix_delete(node_pointer x)
		{
			while (x != _root && x->color == BLACK)
			{
				node_pointer w = 0;
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

		template <class T, class Compare, class Allocator>
		typename rbtree<T,Compare,Allocator>::node_pointer
		rbtree<T,Compare,Allocator>::search(node_pointer node, T value)
		{
			if (node == _sentinel || value)
				return node;
			if (_comp(value, node->value))
				return search(node->left, value);
			return search(node->right, value);
		}

		template <class T, class Compare, class Allocator>
		typename rbtree<T,Compare,Allocator>::node_pointer
		rbtree<T,Compare,Allocator>::minimum(node_pointer node)
		{
			while (node->left != _sentinel)
				node = node->left;
			return node;
		}

		// ======================
		//	      Utils
		// ======================

		template <class T, class Compare, class Allocator>
		void
		rbtree<T,Compare,Allocator>::destroy_all()
		{
			clear();
			if (_sentinel)
			{
				_alloc.destroy(&_sentinel->value);
				_node_alloc.deallocate(_sentinel, 1);
				_sentinel = 0;
			}
		}

		template <class T, class Compare, class Allocator>
		void
		rbtree<T,Compare,Allocator>::clear_sub_tree(node_pointer subtree)
		{
			if (!subtree || subtree == _sentinel)
				return ;
			clear_sub_tree(subtree->left);
			clear_sub_tree(subtree->right);
			_alloc.destroy(&subtree->value);
			_node_alloc.deallocate(subtree, 1);
			--_size;
		}

		template <class T, class Compare, class Allocator>
		void
		rbtree<T,Compare,Allocator>::update_sentinelle(node_pointer new_node)
		{
			if (_size == 1)
			{
				_sentinel->left = new_node;
				_sentinel->right = new_node;
			}
			else if (_comp(new_node->value, _sentinel->left->value))
				_sentinel->left = new_node;
			else if (_comp(_sentinel->right->value, new_node->value))
				_sentinel->right = new_node;
		}

		template <class T, class Compare, class Allocator>
		typename rbtree<T,Compare,Allocator>::node_pointer
		rbtree<T,Compare,Allocator>::new_node(const T& value)
		{
			node_pointer tmp = _node_alloc.allocate(1);
			detail::MemoryGuard<rbtree_node<T>, node_allocator> guard(_node_alloc);
			guard.push(tmp, 1);
			tmp->left = _sentinel;
			tmp->right = _sentinel;
			tmp->parent = 0;
			tmp->color = RED;
			_alloc.construct(&tmp->value, value);
			guard.release();
			return tmp;
		}

		template <class T, class Compare, class Allocator>
		void
		rbtree<T,Compare,Allocator>::init_sentinel()
		{
			node_pointer tmp = _node_alloc.allocate(1);
			tmp->left = 0;
			tmp->right = 0;
			tmp->parent = 0;
			tmp->color = BLACK;
			_sentinel = tmp;
			_root = _sentinel;
		}

		template <class T, class Compare, class Allocator>
		bool
		rbtree<T,Compare,Allocator>::is_valid_tree() const
		{
			vector<size_t> black_counts;
			queue<node_pointer> q;
			queue<node_pointer> leafs;
			if (_sentinel->color != BLACK)
				return false;
			if (_root != _sentinel)
				q.push(_root);
			else
				return true;
			while (!q.empty())
			{
				node_pointer node = q.front();
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
				node_pointer node = leafs.front();
				leafs.pop();
				size_t	black_node_count = 1;
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
			for (size_t i = 1; i < black_counts.size(); ++i)
			{
				if (black_counts[0] != black_counts[i])
					return false;
			}
			return true;
		}
	}
}

#endif