#ifndef RBTREE_TPP
#define RBTREE_TPP

namespace ft
{
	namespace detail
	{
		// ======================
		//	Construct / Destruct
		// ======================

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::rbtree(const Compare& comp, const Allocator& alloc)
			:	_alloc(alloc),
				_node_alloc(alloc),
				_comp(comp),
				_root(0),
				_sentinel(0),
				_size(0)
		{
			// Complexity: O(1)
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

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::rbtree(const rbtree& x)
			:	_alloc(x._alloc),
				_node_alloc(x._node_alloc),
				_comp(x._comp),
				_root(0),
				_sentinel(0),
				_size(x._size)
		{
			// Complexity: O(x.size())
			try
			{
				init_sentinel();
				_root = clone_subtree(x._root, 0, x._sentinel);
			}
			catch(...)
			{
				destroy_all();
				throw;
			}
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::~rbtree()
		{
			// Complexity: O(size());
			destroy_all();
		}

		// =====================
		//	    Assignement
		// =====================

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		rbtree<Key,T,KeyOfValue,Compare,Allocator>&
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::operator=(const rbtree& x)
		{
			// Complexity: O(size() + x.size());
			if (this != &x)
			{
				clear();
				_root = clone_subtree(x._root, 0, x._sentinel);
			}
			return *this;
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::allocator_type
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::get_allocator() const
		{
			// Complexity: O(1);
			return _alloc;
		}

		// =====================
		//	     Iterators
		// =====================

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::iterator
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::begin()
		{
			// Complexity: O(1)
			return iterator(_sentinel->left, _sentinel);
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::const_iterator
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::begin() const
		{
			// Complexity: O(1)
			return const_iterator(_sentinel->left, _sentinel);
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::iterator
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::end()
		{
			// Complexity: O(1)
			return iterator(_sentinel, _sentinel);
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::const_iterator	
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::end() const
		{
			// Complexity: O(1)
			return const_iterator(_sentinel, _sentinel);
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::reverse_iterator
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::rbegin()
		{
			// Complexity: O(1)
			return reverse_iterator(end());
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::const_reverse_iterator
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::rbegin() const
		{
			// Complexity: O(1)
			return const_reverse_iterator(end());
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::reverse_iterator
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::rend()
		{
			// Complexity: O(1)
			return reverse_iterator(begin());
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::const_reverse_iterator
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::rend() const
		{
			// Complexity: O(1)
			return const_reverse_iterator(begin());
		}

		// ====================
		//	     Capacity
		// ====================

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		bool
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::empty() const
		{
			// Complexity: O(1)
			return (_size == 0);
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::size_type
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::size() const
		{
			// Complexity: O(1)
			return _size;
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::size_type
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::max_size() const
		{
			// Complexity: O(1)
			return ft::min(_alloc.max_size(), _node_alloc.max_size());
		}

		// ====================
		//	  Element Access
		// ====================

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::reference
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::at(const Key& key)
		{
			// Complexity: O(log(size()))
			node_pointer node = search(_root, key);
			if (node == _sentinel)
				throw ft::out_of_range("rbtree::at");
			return node->value;
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::const_reference
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::at(const Key& key) const
		{
			// Complexity: O(log(size()))
			node_pointer node = search(_root, key);
			if (node == _sentinel)
				throw ft::out_of_range("rbtree::at");
			return node->value;
		}

		// =====================
		//	     Modifiers
		// =====================

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		pair<typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::iterator, bool>
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::insert_unique(const T& value)
		{
			// Complexity: O(log(size()));
			const Key& key = _key_of(value);
			node_pointer curr = _root;
			node_pointer parent = 0;
			bool go_left = false;

			// searching insert position
			while (curr != _sentinel)
			{
				parent = curr;
				if (_comp(key, _key_of(curr->value)))
				{
					go_left = true;
					curr = curr->left;
				}
				else if (_comp(_key_of(curr->value), key))
				{
					go_left = false;
					curr = curr->right;
				}
				else
					return ft::make_pair(iterator(curr, _sentinel), false);
			}
			// insertion
			node_pointer node = new_node(value);
			node->parent = parent;
			if (!parent)
				_root = node;
			else if (go_left)
				parent->left = node;
			else
				parent->right = node;
			++_size;
			fix_insert(node);
			update_sentinel(node);
			return ft::make_pair(iterator(node, _sentinel), true);
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		pair<typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::iterator, bool>
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::insert_multi(const T& value)
		{
			// Complexity: O(log(size()));
			const Key& key = _key_of(value);
			node_pointer node = new_node(value);
			node_pointer curr = _root;
			node_pointer parent = 0;

			// searching insert position
			while (curr != _sentinel)
			{
				parent = curr;
				if (_comp(key, _key_of(curr->value)))
					curr = curr->left;
				else
					curr = curr->right;
			}
			// insertion
			node->parent = parent;
			if (!parent)
				_root = node;
			else if (_comp(key, _key_of(parent->value)))
				parent->left = node;
			else
				parent->right = node;
			++_size;
			fix_insert(node);
			update_sentinel(node);
			return pair<iterator, bool>(iterator(node, _sentinel), true);
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::iterator
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::insert_unique(iterator pos, const T& value)
		{
			/*
			Complexity: 
				insertion in position:	amortized O(1)
				else:					O(log(size()))
			*/
			if (_root == _sentinel)
				return insert_unique(value).first;

			const Key& key = _key_of(value);
			node_pointer	hint = pos.base();
			node_pointer	before = prev(hint, _sentinel);
			node_pointer	parent;
			bool			go_left;

			if (before == _sentinel)
			{
				if (!_comp(key, _key_of(hint->value)))
					return insert_unique(value).first;
				parent = hint;
				go_left = true;
			}
			else
			{
				if (!_comp(_key_of(before->value), key) || (hint != _sentinel && !_comp(key, _key_of(hint->value))))
					return insert_unique(value).first;
				if (before->right == _sentinel)
				{
					parent = before;
					go_left = false;
				}
				else
				{
					parent = hint;
					go_left = true;
				}
			}
			node_pointer node = new_node(value);
			node->parent = parent;
			if (go_left)
				parent->left = node;
			else
				parent->right = node;
			++_size;
			fix_insert(node);
			update_sentinel(node);
			return iterator(node, _sentinel);
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::iterator
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::insert_multi(iterator pos, const T& value)
		{
			/*
			Complexity: 
				insertion in position:	amortized O(1)
				else:					O(log(size()))
			*/
			if (_root == _sentinel)
				return insert_unique(value).first;

			const Key& key = _key_of(value);
			node_pointer	hint = pos.base();
			node_pointer	before = prev(hint, _sentinel);
			node_pointer	parent;
			bool			go_left;

			if (before == _sentinel)
			{
				if (!_comp(key, _key_of(hint->value)))
					return insert_multi(value).first;
				parent = hint;
				go_left = true;
			}
			else
			{
				if (!_comp(_key_of(before->value), key) || (hint != _sentinel && !_comp(key, _key_of(hint->value))))
					return insert_multi(value).first;
				if (before->right == _sentinel)
				{
					parent = before;
					go_left = false;
				}
				else
				{
					parent = hint;
					go_left = true;
				}
			}
			node_pointer node = new_node(value);
			node->parent = parent;
			if (go_left)
				parent->left = node;
			else
				parent->right = node;
			++_size;
			fix_insert(node);
			update_sentinel(node);
			return iterator(node, _sentinel);
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		void
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::erase(iterator position)
		{
			// Complexity: amortized O(1)
			node_pointer ptr = position.base();
			delete_data(ptr);
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::size_type
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::erase(const Key& x)
		{
			// Complexity: O(log(size()) + count(x))
			size_type removed_nodes = 0;
			while (true)
			{
				node_pointer to_delete = search(_root, x);
				if (to_delete == _sentinel)
					return removed_nodes;
				delete_data(to_delete);
				++removed_nodes;
			}
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		void
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::erase(iterator first, iterator last)
		{
			// Complexity: O(log(size()) + distance(first, last))
			while (first != last)
			{
				node_pointer ptr = first.base();
				++first;
				delete_data(ptr);
			}
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		void
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::swap(rbtree& other)
		{
			// Complexity: O(size());
			if (this != &other)
			{
				ft::swap(_alloc, other._alloc);
				ft::swap(_node_alloc, other._node_alloc);
				ft::swap(_comp, other._comp);
				ft::swap(_key_of, other._key_of);

				ft::swap(_root, other._root);
				ft::swap(_sentinel, other._sentinel);
				ft::swap(_size, other._size);
			}
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		void
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::clear()
		{
			// Complexity: O(size());
			clear_sub_tree(_root);
			_root = _sentinel;
			_sentinel->left = _sentinel;
			_sentinel->right = _sentinel;
		}

		// =====================
		//	    Observers
		// =====================

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		Compare
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::key_comp() const
		{
			// Complexity: O(1);
			return _comp;
		}

		// =====================
		//	    Operations
		// =====================

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::iterator
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::find(const Key& x)
		{
			// Complexity: O(log(size()))
			return iterator(search(_root, x), _sentinel);
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::const_iterator
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::find(const Key& x) const
		{
			// Complexity: O(log(size()))
			return const_iterator(search(_root, x), _sentinel);
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::size_type
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::count(const Key& x) const
		{
			// Complexity: O(log(size()) + element found)
			pair<const_iterator, const_iterator> range = equal_range(x);
			size_type count = 0;
			while (range->first != range->second)
			{
				++count;
				++range->first;
			}
			return count;
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::iterator
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::lower_bound(const Key& x)
		{
			// Complexity: O(log(size()))
			node_pointer curr = _root;
			node_pointer res = _sentinel;
			while (true)
			{
				if (curr == _sentinel)
					break;
				if (!_comp(_key_of(curr->value), x))
				{
					res = curr;
					curr = curr->left;
				}
				else
					curr = curr->right;
			}
			return iterator(res, _sentinel);
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::const_iterator
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::lower_bound(const Key& x) const
		{
			// Complexity: O(log(size()))
			node_pointer curr = _root;
			node_pointer res = _sentinel;
			while (true)
			{
				if (curr == _sentinel)
					break;
				if (_comp(x, _key_of(curr->value)))
				{
					res = curr;
					curr = curr->left;
				}
				else
					curr = curr->right;
			}
			return const_iterator(res, _sentinel);
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::iterator
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::upper_bound(const Key& x)
		{
			// Complexity: O(log(size()))
			node_pointer curr = _root;
			node_pointer res = _sentinel;
			while (true)
			{
				if (curr == _sentinel)
					break;
				if (!_comp(x, _key_of(curr->value)))
				{
					res = curr;
					curr = curr->left;
				}
				else
					curr = curr->right;
			}
			return iterator(res, _sentinel);
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::const_iterator
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::upper_bound(const Key& x) const
		{
			// Complexity: O(log(size()))
			node_pointer curr = _root;
			node_pointer res = _sentinel;
			while (true)
			{
				if (curr == _sentinel)
					break;
				if (!_comp(x, _key_of(curr->value)))
				{
					res = curr;
					curr = curr->left;
				}
				else
					curr = curr->right;
			}
			return const_iterator(res, _sentinel);
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		pair<typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::iterator,
			typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::iterator>
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::equal_range(const Key& x)
		{
			// Complexity: O(log(size()))
			return ft::make_pair(lower_bound(x), upper_bound(x));
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		pair<typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::const_iterator,
			typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::const_iterator>
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::equal_range(const Key& x) const
		{
			// Complexity: O(log(size()))
			return ft::make_pair(lower_bound(x), upper_bound(x));
		}

		// =====================
		//	  Private-Members
		// =====================

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		void
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::rotate_left(node_pointer x)
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

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		void 
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::rotate_right(node_pointer y)
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

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		void
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::fix_insert(node_pointer z)
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
					// symmetric cases for when z's parent is the right child
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

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		void
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::transplant(node_pointer u, node_pointer v)
		{
			if (!u->parent)
				_root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		void
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::delete_data(node_pointer& z)
		{
			if (z == _sentinel)
				return ;
			node_pointer x = 0;
			node_pointer y = z;
			node_color y_base_color = y->color;
			if (z->left == _sentinel)
			{
				x = z->right;
				transplant(z, z->right);
			}
			else if (z->right == _sentinel)
			{
				x = z->left;
				transplant(z, z->left);
			}
			else
			{
				y = minimum(z->right, _sentinel);
				y_base_color = y->color;
				x = y->right;
				if (y->parent == z)
					x->parent = y;
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
			_alloc.destroy(&z->value);
			_node_alloc.deallocate(z, 1);
			--_size;
			update_sentinel();
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		void
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::fix_delete(node_pointer x)
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
						w->color = x->parent->color;
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
					if (w->left->color == BLACK && w->right->color == BLACK)
					{
						w->color = RED;
						x = x->parent; // Move up the tree
					}
					else
					{
						if (w->left->color == BLACK)
						{
							// Case 3: sibling is black, left child is black, right is red
							w->right->color = BLACK;
							w->color = RED;
							rotate_left(w);
							w = x->parent->left;
						}
						// Case 3: Right child of sibling is red
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->right->color = BLACK;
						rotate_right(x->parent);
						x = _root;
					}
				}
			}
			x->color = BLACK;
			_sentinel->color = BLACK;
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::node_pointer
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::search(node_pointer node, const Key& key) const
		{
			// Complexity: O(log(N))
			if (node == _sentinel || _key_of(node->value) == key)
				return node;
			if (_comp(key, _key_of(node->value)))
				return search(node->left, key);
			return search(node->right, key);
		}

		// ======================
		//	      Utils
		// ======================

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::node_pointer
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::clone_subtree(node_pointer src, node_pointer parent, node_pointer nill)
		{
			// N = number of element in src tree
			// Complexity: O(N)
			if (src == nill)
				return _sentinel;
			node_pointer node = new_node(src->value);
			detail::MemoryGuard<node_type, node_allocator> node_guard(_node_alloc);
			node_guard.push(node, sizeof(node_type));
			detail::ConstructGuard<T, Allocator, iterator> construct_guard(_alloc, iterator(node, _sentinel));
			construct_guard.push();
			node->parent = parent;

			detail::MemoryGuard<node_type, node_allocator> left_guard(_node_alloc);
			node->left = clone_subtree(src->left, src, nill);
			left_guard.push(node->left, sizeof(node_type));

			node->right = clone_subtree(src->right, src, nill);

			left_guard.release();
			construct_guard.release();
			node_guard.release();
			return node;
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		void
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::destroy_all()
		{
			// Complexity: O(size())
			clear();
			if (_sentinel)
			{
				_node_alloc.deallocate(_sentinel, 1);
				_sentinel = 0;
				_root = 0;
			}
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		void
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::clear_sub_tree(node_pointer subtree)
		{
			// Complexity: O(subtree.size())
			if (!subtree || subtree == _sentinel)
				return ;
			clear_sub_tree(subtree->left);
			clear_sub_tree(subtree->right);
			_alloc.destroy(&subtree->value);
			_node_alloc.deallocate(subtree, 1);
			--_size;
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		void
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::update_sentinel(node_pointer new_node)
		{
			// Complexity: O(1)
			if (_size == 1)
			{
				_sentinel->left = new_node;
				_sentinel->right = new_node;
			}
			else if (_comp(_key_of(new_node->value), _key_of(_sentinel->left->value)))
				_sentinel->left = new_node;
			else if (_comp(_key_of(_sentinel->right->value), _key_of(new_node->value)))
				_sentinel->right = new_node;
			else if (_size == 0)
			{
				_sentinel->left = _sentinel;
				_sentinel->right = _sentinel;
			}
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		void
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::update_sentinel()
		{
			// Complexity: O(1)
			node_pointer tmp = _root;
			while (tmp != _sentinel && tmp->left != _sentinel)
				tmp = tmp->left;
			_sentinel->left = tmp;
			tmp = _root;
			while (tmp != _sentinel && tmp->right != _sentinel)
				tmp = tmp->right;
			_sentinel->right = tmp;
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		typename rbtree<Key,T,KeyOfValue,Compare,Allocator>::node_pointer
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::new_node(const T& value)
		{
			// Complexity: O(1)
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

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		void
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::init_sentinel()
		{
			// Complexity: O(1)
			node_pointer tmp = _node_alloc.allocate(1);
			tmp->left = tmp;
			tmp->right = tmp;
			tmp->parent = 0;
			tmp->color = BLACK;
			_sentinel = tmp;
			_root = _sentinel;
		}

		template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
		bool
		rbtree<Key,T,KeyOfValue,Compare,Allocator>::is_valid_tree() const
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