#ifndef RBTREE_HELPERS_HPP
#define RBTREE_HELPERS_HPP

#include "rbtree_node.hpp"

namespace ft
{
	namespace detail
	{
		template <typename T>
		static rbtree_node<T>* minimum(rbtree_node<T>* n, rbtree_node<T>* nil)
		{
			while (n->left != nil)
				n = n->left;
			return n;
		}

		template <typename T>
		static rbtree_node<T>* maximum(rbtree_node<T>* n, rbtree_node<T>* nil)
		{
			while (n->right != nil)
				n = n->right;
			return n;
		}

		template <typename T>
		static rbtree_node<T>* prev(rbtree_node<T>* n, rbtree_node<T>* nil)
		{
			if (n == nil)
				n = n->right;	
			else if (n->left != nil)
			{
				n = n->left;
				while (n->right != nil)
					n = n->right;
			}
			else
			{
				rbtree_node<T>*	old = n;
				n = n->parent;
				while (n && n->left == old)
				{
					old = n;
					n = n->parent;
				}
				if (!n)
					n = nil;
			}
			return n;
		}

		template <typename T>
		static rbtree_node<T>* next(rbtree_node<T>* n, rbtree_node<T>* nil)
		{
			if (n->right != nil)
			{
				n = n->right;
				while (n->left != nil)
					n = n->left;
			}
			else
			{
				rbtree_node<T>*	old = n;
				n = n->parent;
				while (n && n->right == old)
				{
					old = n;
					n = n->parent;
				}
				if (!n)
					n = nil;
			}
			return n;
		}
	}
}
#endif