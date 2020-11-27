/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:04:26 by matrus            #+#    #+#             */
/*   Updated: 2020/11/27 15:04:28 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

// TODO: read for explicit

namespace ft {

template <class T, class Container = vector<T> >
class stack {

public:

	typedef T value_type;
	typedef Container container_type;
	typedef size_t size_type;

	explicit stack (const container_type& ctnr = container_type()) : _ctnr(ctnr) {}

	bool empty() const { return _ctnr.empty(); }
	size_type size() const { return _ctnr.size(); }
	value_type& top() { return _ctnr.back(); }
	const value_type& top() const { return _ctnr.back(); }
	void push (const value_type& val) { _ctnr.push_back(val); }
	void pop() { _ctnr.pop_back(); }

private:

	container_type _ctnr;

	template <class U, class Cont >
	friend bool operator == (const ft::stack<U, Cont> &, const ft::stack<U,Cont> &);

	template <class U, class Cont>
	friend bool operator!=(const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs);

	template <class U, class Cont>
	friend bool operator<(const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs);

	template <class U, class Cont>
	friend bool operator<=(const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs);

	template <class U, class Cont>
	friend bool operator>(const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs);

	template <class U, class Cont>
	friend bool operator>=(const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs);

};

template <class T, class Container >
bool operator == (const stack<T, Container> & lhs, const stack<T,Container> & rhs) {
	return lhs._ctnr == rhs._ctnr;
}

template <class T, class Container>
bool operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
	return lhs._ctnr.operator!=(rhs);
}

template <class T, class Container>
bool operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
	return lhs._ctnr.operator<(rhs);
}

template <class T, class Container>
bool operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
	return lhs._ctnr.operator<=(rhs);
}

template <class T, class Container>
bool operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
	return lhs._ctnr.operator>(rhs);
}

template <class T, class Container>
bool operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
	return lhs._ctnr.operator>=(rhs);
}

} // namespace ft

#endif