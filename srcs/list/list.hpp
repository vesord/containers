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

template<class T, class Alloc = ft::allocator<T> >
class List {

public:

	typedef T value_type;
	typedef Alloc allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
//	typedef BIDERECTIONAL_ITERATOR iterator
//	typedef CONST_BIDERECTIONAL_ITERATOR const_iterator
//	typedef reverse_iterator<iterator> reverse_iterator;
//	typedef reverse_iterator<const_iterator> const_reverse_iterator;
//	typedef iterator_traits<iterator>::difference_type difference_type;
//	typedef ??? size_type;

private:


};

#endif
