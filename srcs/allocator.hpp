/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:02:52 by matrus            #+#    #+#             */
/*   Updated: 2020/11/09 16:02:54 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include "ft.hpp"
#include <limits>

template <>
class ft::allocator<void> {
public:
	typedef void* pointer;
	typedef const void* const_pointer;
	typedef void value_type;
	template <class U> struct rebind { typedef allocator<U> other; };
};

template < class T>
class ft::allocator {

public:

	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef const T* const_pointer;
	typedef const T& const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	template <class Type> struct rebind {
		typedef allocator<Type> other;
	};

	/*** CONSTRUCTION ***/
	allocator() throw() { };
	allocator (const allocator& alloc) throw();
	template< class U >
		allocator (const allocator<U>& alloc) throw() { *this = alloc; };

	/*** DESTRUCTION ***/
	~allocator () throw() { };

	pointer address ( reference x ) const { return &x; };
	const_pointer address ( const_reference x ) const { return &x; };

	pointer allocate (size_type n, allocator<void>::const_pointer hint=0) const { // TODO: find out hint?
		static_cast<void>(hint);
		return static_cast<pointer>(::operator new (sizeof(value_type) * n));						// TODO: should we use n times allocation?
	};

	void deallocate (pointer p, size_type n) {
		static_cast<void>(n);
		::operator delete (p); // TODO: check if one delete or delete n times?
	}

	size_type max_size() const throw() {
		return std::numeric_limits<size_type>::max() / sizeof(value_type);
	};

	void construct ( pointer p, const_reference val ) {
		new (static_cast<void*>(p)) value_type (val);
	};

	void destroy (pointer p) {
		p->~value_type();
	};

private:

};



#endif
