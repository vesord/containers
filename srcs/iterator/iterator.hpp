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

namespace ft {

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template<class T, class It>
struct _has_iterator_category_convertible_to
: public std::integral_constant<bool, std::is_convertible<T, It>::value > {};

template<class T>
struct _is_input_iterator
: public ft::_has_iterator_category_convertible_to<T, input_iterator_tag> {};

template <class Category,		// iterator::iterator_category
	class T,					// iterator::value_type
	class Distance = ptrdiff_t,	// iterator::difference_type
	class Pointer = T*,			// iterator::pointer
	class Reference = T& >		// iterator::reference
class iterator : public Category {
public:
	typedef T value_type;
	typedef Distance difference_type;
	typedef Pointer pointer;
	typedef Reference reference;
	typedef Category iterator_category;
};

template<class Iter>
class reverse_iterator : public ft::iterator<
	typename Iter::iterator_category,
	typename Iter::value_type,
	typename Iter::difference_type,
	typename Iter::pointer,
	typename Iter::reference> {};

} // namespace ft

#endif
