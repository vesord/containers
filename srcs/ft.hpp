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
	// delete this

	template <class T, class Alloc = std::allocator<T> >
	class list;
	template <class T, class Alloc>
	void swap (ft::list<T,Alloc>& x, ft::list<T,Alloc>& y);
	//list 10k and resize to 5
	// make const iterators const

	template < class T, class Alloc = std::allocator<T> >
	class vector;
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
	// make const iterators const
	// implement comparations

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
	class map;
	// hide debug
	// make const iterators const

}

#endif
