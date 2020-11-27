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
	// delete this

//	template <class T, class Alloc = std::allocator<T> >
//	class list;
//	template <class T, class Alloc>
//	void swap (ft::list<T,Alloc>& x, ft::list<T,Alloc>& y);

//	template < class T, class Alloc = std::allocator<T> >
//	class vector;
//	template <class T, class Alloc>
//	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);


	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
	class map;
	// hide debug
	// make const iterators const

}

#endif
