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

	template<bool B, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if <true, T> { typedef T type; };

	template <class T> class allocator;

	template < class T, class Alloc > class list;

}

#endif
