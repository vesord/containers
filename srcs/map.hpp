/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:10:07 by matrus            #+#    #+#             */
/*   Updated: 2020/11/22 14:10:08 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "iterator.hpp"
#include <stdexcept>
#include <iostream>

template <class Key, class T, class Compare, class Alloc>
class ft::map {

public:
	class iterator;
	class const_iterator;
	class reverse_iterator;
	class const_reverse_iterator;

	typedef Key key_type;
	typedef T mapped_type;
	typedef std::pair<const key_type, mapped_type> value_type;
	typedef Compare key_compare;
	typedef Alloc allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;

class value_compare : public std::binary_function<value_type, value_type, bool>
{
protected:
	Compare comp;
	value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
public:
	typedef bool result_type;
	typedef value_type first_argument_type;
	typedef value_type second_argument_type;
	bool operator() (const value_type& x, const value_type& y) const
	{
		return comp(x.first, y.first);
	}
};

private:

	typedef typename allocator_type::template rebind<pointer>::other allocator_rebind;
	allocator_rebind _alloc_rebind;
	allocator_type	 _alloc;

public:

	/*** CONSTRUCTION ***/ // we should init comp and alloc
	explicit map (const key_compare& comp = key_compare(),
				  const allocator_type& alloc = allocator_type());

	template <class InputIterator>
	map (InputIterator first, InputIterator last,
		 const key_compare& comp = key_compare(),
		 const allocator_type& alloc = allocator_type());

	map (const map& x);

	/*** DESTRUCTION ***/

	 ~map();

	 /*** ASSIGNATION ***/

	 map& operator= (const map& x);

	 /*** ITERATORS ***/

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;

	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;

	/*** CAPACITY ***/

	bool empty() const;
	size_type size() const;
	size_type max_size() const;

	/*** ELEMENT ACCEESS ***/

	mapped_type& operator[] (const key_type& k);

	/*** MODIFIERS ***/

	std::pair<iterator,bool> insert (const value_type& val);
	iterator insert (iterator position, const value_type& val);
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last);

	void erase (iterator position);
	size_type erase (const key_type& k);
	void erase (iterator first, iterator last);

	void swap (map& x);

	void clear();

	/*** OBSERVERS ***/

	key_compare key_comp() const;
	value_compare value_comp() const;

	/*** OPERATIONS ***/

	iterator find (const key_type& k);
	const_iterator find (const key_type& k) const;

	size_type count (const key_type& k) const;

	iterator lower_bound (const key_type& k);
	const_iterator lower_bound (const key_type& k) const;
	iterator upper_bound (const key_type& k);
	const_iterator upper_bound (const key_type& k) const;

	std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
	std::pair<iterator,iterator>             equal_range (const key_type& k);

private:

};

#endif
