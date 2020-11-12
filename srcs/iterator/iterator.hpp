/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 09:56:26 by matrus            #+#    #+#             */
/*   Updated: 2020/11/10 09:56:28 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "ft.hpp"

struct input_iterator_tag { };
struct output_iterator_tag { };
struct forward_iterator_tag : public input_iterator_tag { };
struct bidirectional_iterator_tag : public forward_iterator_tag { };
struct random_access_iterator_tag : public bidirectional_iterator_tag { };

template <class Category, class T, class Distance,
	class Pointer, class Reference>
class ft::iterator {
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
protected:
	void *				_ptr;
};

template< class Iter >
class ft::reverse_iterator : public ft::iterator<
	typename ft::iterator_traits<Iter>::iterator_category,
	typename ft::iterator_traits<Iter>::value_type,
	typename ft::iterator_traits<Iter>::difference_type,
	typename ft::iterator_traits<Iter>::pointer,
	typename ft::iterator_traits<Iter>::reference > { };

#endif
