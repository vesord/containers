/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:41:50 by matrus            #+#    #+#             */
/*   Updated: 2020/11/18 13:41:52 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "allocator.hpp"
#include "iterator.hpp"

template< class T, class Alloc = ft::allocator<T> >
class ft::vector {

public:
	class iterator;
	class const_iterator;
	class reverse_iterator;
	class const_reverse_iterator;
	typedef T value_type;
	typedef Alloc allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;

private:

	// Some internal stuff

public:

	typedef typename allocator_type::template rebind<pointer>::other allocator_rebind;
	allocator_rebind _alloc_rebind;
	allocator_type	 _alloc;

	/*** ITERATORS ***/


	typedef ptrdiff_t difference_type;
	typedef size_t size_type;

	/*** CONSTRUCTION ***/

	explicit vector (const allocator_type& alloc = allocator_type());
	explicit vector (size_type n, const value_type& val = value_type(),
					 const allocator_type& alloc = allocator_type());
	template <class InputIterator>
	vector (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type());
	vector (const vector& x);

	/*** DESTRUCTION ***/

	~vector();

	/*** ASSIGNATION ***/

	vector& operator= (const vector& x); // if throws container in valid state

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

	size_type size() const; // no throw
	size_type max_size() const; // no throw
	void resize (size_type n, value_type val = value_type()); // if throws container still in a valid state
	size_type capacity() const; // no throw
	bool empty() const; // no throw
	void reserve (size_type n); // throws length_error, bad_alloc

	/*** ELEMENT ACCESS ***/

	reference operator[] (size_type n); // if n > size undefined behavior
	const_reference operator[] (size_type n) const; // if n > size undefined behavior
	reference at (size_type n); // throws out_of_bounds
	const_reference at (size_type n) const; // throws out_of_bounds
	reference front(); // if empty() undefined behaviour
	const_reference front() const; // if empty() undefined behaviour
	reference back(); // if empty() undefined behaviour
	const_reference back() const; // if empty() undefined behaviour

	/*** MODIFIERS ***/

	template <class InputIterator>
	void assign (InputIterator first, InputIterator last); // if throws container in a valid state
	void assign (size_type n, const value_type& val); // if throws container in a valid state
	void push_back (const value_type& val); // throws bad_alloc
	void pop_back(); // no throw

	iterator insert (iterator position, const value_type& val); // if throws container in a valid state
	void insert (iterator position, size_type n, const value_type& val); // if throws container in a valid state
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last); // if throws container in a valid state

	iterator erase (iterator position); // no throw
	iterator erase (iterator first, iterator last); // no throw

	void swap (vector& x); // no throw
	void clear(); // no throw

};

#endif
