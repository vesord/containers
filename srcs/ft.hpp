/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:15:28 by matrus            #+#    #+#             */
/*   Updated: 2020/11/09 16:15:29 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HPP
#define FT_HPP

#include <cstddef>

namespace ft {

	template <class T> class allocator;

	template <class Category,		// iterator::iterator_category
		class T,					// iterator::value_type
		class Distance = ptrdiff_t,	// iterator::difference_type
		class Pointer = T*,			// iterator::pointer
		class Reference = T&		// iterator::reference
	> class iterator;

	template< class Iter >
	struct iterator_traits;

	template< class Iter >
	class reverse_iterator;

	template < class T, class Alloc > class list;

}

#endif
