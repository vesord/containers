/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:43:21 by matrus            #+#    #+#             */
/*   Updated: 2020/11/09 15:43:26 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include "allocator.hpp"
#include "iterator.hpp"

template<class T, class Alloc = ft::allocator<T> >
class list {

public:

	/*** INTERNAL TYPES ***/
	typedef T value_type;
	typedef Alloc allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef ft::iterator<bidirectional_iterator_tag, value_type> iterator;
	typedef const ft::iterator<bidirectional_iterator_tag, value_type> const_iterator;
	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
	typedef difference_type size_type;

	/*** CONSTRUCTION ***/
	explicit list (const allocator_type& alloc = allocator_type());
	explicit list (size_type n, const value_type& val = value_type(),
				   const allocator_type& alloc = allocator_type());
	template <class InputIterator>
	list (InputIterator first, InputIterator last,
		  const allocator_type& alloc = allocator_type());
	list (const list& x);

	/*** DESTRUCTION ***/
	~list();

	/*** ASSIGNATION ***/
	list& operator= (const list& x);

	/*** ITERATORS ***/
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

	/*** CAPACITY ***/
	bool empty() const;
	size_type size() const;
	size_type max_size() const {
		return std::numeric_limits<size_type>::max() / sizeof(value_type);
	}

	/*** ELEMENT ACCESS ***/
	reference front();
	const_reference front() const;
	reference back();
	const_reference back() const;

	/*** MODIFIERS ***/
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last);
	void assign (size_type n, const value_type& val);

	void push_front (const value_type& val);
	void pop_front();
	void push_back (const value_type& val);
	void pop_back();

	iterator insert (iterator position, const value_type& val);
	void insert (iterator position, size_type n, const value_type& val);
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last);

	iterator erase (iterator position);
	iterator erase (iterator first, iterator last);

	void swap (list& x);

	void resize (size_type n, value_type val = value_type());

	void clear();

	/*** OPERATIONS ***/
	void splice (iterator position, list& x);
	void splice (iterator position, list& x, iterator i);
	void splice (iterator position, list& x, iterator first, iterator last);

	void remove (const value_type& val);

	template <class Predicate>
	void remove_if (Predicate pred);

	void unique();
	template <class BinaryPredicate>
	void unique (BinaryPredicate binary_pred);

	void merge (list& x);
	template <class Compare>
	void merge (list& x, Compare comp);

	void sort();
	template <class Compare>
	void sort (Compare comp);

	void reverse();

private:


};

#endif
