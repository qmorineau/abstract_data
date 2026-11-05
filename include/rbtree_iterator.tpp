#ifndef RBTREE_ITERATOR_TPP
#define RBTREE_ITERATOR_TPP

namespace ft
{
	namespace detail
	{
		// ========================
		//      List Iterator
		// ========================

		// ====== Construct / Destruct ======

		template <class T, class Pointer, class Reference>
		rbtree_iterator<T, Pointer, Reference>::rbtree_iterator(void)
			: _current(0), _null(0)
		{}

		template <class T, class Pointer, class Reference>
		rbtree_iterator<T, Pointer, Reference>::rbtree_iterator(rbtree_node<T>* n, rbtree_node<T>* sentinelle)
			: _current(n), _null(sentinelle)
		{}

		template <class T, class Pointer, class Reference>
		template <class T2, class Pointer2, class Reference2>
		rbtree_iterator<T, Pointer, Reference>::rbtree_iterator(const rbtree_iterator<T2, Pointer2, Reference2>& other)
			: _current(other._current), _null(other._null)
		{}

		template <class T, class Pointer, class Reference>
		rbtree_iterator<T, Pointer, Reference>::~rbtree_iterator()
		{}

		template <class T, class Pointer, class Reference>
		rbtree_iterator<T, Pointer, Reference>&
		rbtree_iterator<T, Pointer, Reference>::operator=(const rbtree_iterator& other)
		{
			if (this != &other)
			{
				_current = other._current;
				_null = other._null;
			}
			return *this;
		}

		// ====== base() ======
		template <class T, class Pointer, class Reference>
		rbtree_node<T>*
		rbtree_iterator<T, Pointer, Reference>::base(void) const
		{
			return _current;
		}

		// ====== Input Iterator ======

		template <class T, class Pointer, class Reference>
		typename rbtree_iterator<T, Pointer, Reference>::reference
		rbtree_iterator<T, Pointer, Reference>::operator*(void) const
		{
			return _current->value;
		}

		template <class T, class Pointer, class Reference>
		typename rbtree_iterator<T, Pointer, Reference>::pointer
		rbtree_iterator<T, Pointer, Reference>::operator->(void) const
		{
			return &_current->value;
		}

		// ====== Bidirectional Iterator ======

		template <class T, class Pointer, class Reference>
		rbtree_iterator<T, Pointer, Reference>&
		rbtree_iterator<T, Pointer, Reference>::operator++(void)
		{
			if (_current->right != _null)
			{
				_current = _current->right;
				while (_current->left != _null)
					_current = _current->left;
			}
			else
			{
				rbtree_node<T>*	old = _current;
				_current = _current->parent;
				while (_current->right == old)
				{
					old = _current;
					_current = _current->parent;
				}
			}
			return *this;
		}

		template <class T, class Pointer, class Reference>
		rbtree_iterator<T, Pointer, Reference>
		rbtree_iterator<T, Pointer, Reference>::operator++(int)
		{
			rbtree_iterator tmp(_current, _null);
			++(*this);
			return tmp;
		}

		template <class T, class Pointer, class Reference>
		rbtree_iterator<T, Pointer, Reference>&
		rbtree_iterator<T, Pointer, Reference>::operator--(void)
		{
			if (_current->left != _null)
			{
				_current = _current->left;
				while (_current->right != _null)
					_current = _current->right;
			}
			else
			{
				rbtree_node<T>*	old = _current;
				_current = _current->parent;
				while (_current->left == old)
				{
					old = _current;
					_current = _current->parent;
				}
			}
			return *this;
		}

		template <class T, class Pointer, class Reference>
		rbtree_iterator<T, Pointer, Reference>
		rbtree_iterator<T, Pointer, Reference>::operator--(int)
		{
			rbtree_iterator tmp(_current, _null);
			--(*this);
			return tmp;
		}

		// ====== Non-Members ======

		template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
		bool
		operator==(const rbtree_iterator<T, Pointer1, Reference1>& x, const rbtree_iterator<T, Pointer2, Reference2>& y)
		{
			return x.base() == y.base();
		}
		
		template <class T, class Pointer1, class Reference1, class Pointer2, class Reference2>
		bool
		operator!=(const rbtree_iterator<T, Pointer1, Reference1>& x, const rbtree_iterator<T, Pointer2, Reference2>& y)
		{
			return x.base() != y.base();
		}
	}
}

#endif
