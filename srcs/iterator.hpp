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

	template<bool B, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if <true, T> { typedef T type; };

	template<class Category,			// iterator::iterator_category
		class T,						// iterator::value_type
		class Distance = ptrdiff_t,		// iterator::difference_type
		class Pointer = T *,			// iterator::pointer
		class Reference = T &>			// iterator::reference
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

}
#endif
