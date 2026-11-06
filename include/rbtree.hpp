#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <memory>

#include "rbtree_iterator.hpp"
#include "rbtree_node.hpp"
#include "guards.hpp"
#include "functional.hpp"
#include "vector.hpp"
#include "queue.hpp"

namespace ft
{
	namespace detail
	{
		template <class T, class Compare = less<T>, class Allocator = std::allocator<T> >
		class rbtree
		{
			public:
				// types
				typedef T					value_type;
				typedef size_t				size_type;
				typedef ptrdiff_t			difference_type;
				typedef Allocator			allocator_type;
				typedef rbtree_node<T>*		node_pointer;

				typedef typename Allocator::reference			reference;
				typedef typename Allocator::const_reference		const_reference;
				typedef typename Allocator::pointer				pointer;
				typedef typename Allocator::const_pointer		const_pointer;

				typedef rbtree_iterator<T>						iterator;
				typedef rbtree_iterator<T, const T*, const T&>	const_iterator;
				typedef ft::reverse_iterator<iterator>			reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
				// construct/copy/destroy:
				rbtree(const Allocator& = Allocator(), const Compare& = Compare());
				rbtree(const rbtree& x);
				~rbtree();
				rbtree& operator=(const rbtree& x);
				allocator_type get_allocator() const;
				// iterators:
				iterator				begin();
				const_iterator			begin() const;
				iterator				end();
				const_iterator			end() const;
				reverse_iterator		rbegin();
				const_reverse_iterator	rbegin() const;
				reverse_iterator 		rend();
				const_reverse_iterator	rend() const;
				// capacity:
				bool		empty() const;
				size_t		size() const;
				size_type	max_size() const;
				// modifier:
				iterator	insert(const T& value);
				iterator	insert(iterator pos, const T& value);
				template <class InputIterator>
				void		insert(InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0);
				void clear();
				// operations
				iterator		lower_bound(const value_type& x);
				const_iterator	lower_bound(const value_type& x) const;
				iterator		upper_bound(const value_type& x);
				const_iterator	upper_bound(const value_type& x) const;
			private:
				typedef typename Allocator::template rebind<rbtree_node<T> >::other	node_allocator;

				Allocator			_alloc;
				node_allocator		_node_alloc;
				Compare				_comp;

				node_pointer 		_root;
				node_pointer 		_sentinel;
				size_type			_size;

				void rotate_left(node_pointer x);
				void rotate_right(node_pointer y);
				void fix_insert(node_pointer z);
				void transplant(node_pointer u, node_pointer v);
				void delete_data(T value);
				void fix_delete(node_pointer x);
				node_pointer search(node_pointer node, T value);
				node_pointer minimum(node_pointer node);
				// utils
				template <class InputIt>
				void insert_dispatch(InputIt first, InputIt last, input_iterator_tag);
				template <class ForwardIt>
				void insert_dispatch(ForwardIt first, ForwardIt last, forward_iterator_tag);
				void			destroy_all();
				void			clear_sub_tree(node_pointer subtree);
				void			update_sentinel(node_pointer new_node);
				node_pointer	new_node(const T& value);
				void			init_sentinel();
				bool			is_valid_tree() const;
			public:
				void print() const
				{
					std::cout << "is valid: " << (is_valid_tree() == true ? "true" : "false") << std::endl;
					queue<node_pointer> q;
					q.push(_root);
					while (!q.empty())
					{
						int level = q.size();
						for (int i = 0; i < level; ++i)
						{
							node_pointer n = q.front();
							q.pop();
							print_node(n);
							if (n != _sentinel)
							{
								q.push(n->left);
								q.push(n->right);
							}
							std::cout << " ";
						}
						std::cout << std::endl;
					}
					std::cout << std::endl;
				}
				void print_node(node_pointer n) const
				{
					if (n != _sentinel)
						std::cout << (n->color == RED ? "R" : "B") << n->value.first << ":" << n->value.second;
					else
						std::cout << "null";
				}
		};
	}
}

#include "rbtree.tpp"

#endif