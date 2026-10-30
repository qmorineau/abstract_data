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
		tree_node<T>::tree_node() :
			value(0),
			color(RED)
		{
			tree_node<T>* null_ptr = static_cast<tree_node<T>*>(0);
			left = null_ptr;
			right = null_ptr;
			parent = null_ptr;
		}

		template <typename T>
		tree_node<T>::tree_node(node_color c, T v) :
			value(v),
			color(c)
		{
			tree_node<T>* null_ptr = static_cast<tree_node<T>*>(0);
			left = null_ptr;
			right = null_ptr;
			parent = null_ptr;
		}

		// ======================
		//	    RedBlackTree
		// ======================

		template <class T, class Allocator>
		red_black_tree<T, Allocator>::red_black_tree(const Allocator& alloc) : _alloc(alloc)
		{
			tree_node<T>* null_ptr = static_cast<tree_node<T>*>(0);
			_root = null_ptr;
			_sentinel = null_ptr;

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

		template <class T, class Allocator>
		red_black_tree<T, Allocator>::~red_black_tree()
		{
			destroy_all();
		}

		template <class T, class Allocator>
		void
		red_black_tree<T, Allocator>::leftRotate(tree_node<T>* x)
		{
			(void) x;
			// todo
		}

		template <class T, class Allocator>
		void 
		red_black_tree<T, Allocator>::rightRotate(tree_node<T>* x)
		{
			(void) x;
			// todo
		}

		template <class T, class Allocator>
		void
		red_black_tree<T, Allocator>::init_sentinel()
		{
			tree_node<T>* tmp = _node_alloc.allocate(1);
			tree_node<T>* null_ptr = static_cast<tree_node<T>*>(0);
			_sentinel = tmp;
			_sentinel->left = null_ptr;
			_sentinel->right = null_ptr;
			_sentinel->color = RED;
			std::cout << "sentinel:" << std::endl;
			print_node(_sentinel);
		}

		template <class T, class Allocator>
		void
		red_black_tree<T, Allocator>::destroy_all()
		{
			// todo
			if (_sentinel)
				_node_alloc.deallocate(_sentinel, 1);
		}

		template <class T, class Allocator>
		bool
		red_black_tree<T, Allocator>::is_valid_tree() const
		{
			return false;
			// todo
		}
	}
}

#endif