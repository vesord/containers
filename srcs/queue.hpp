/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:01:40 by matrus            #+#    #+#             */
/*   Updated: 2020/11/27 19:01:41 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "list.hpp"

namespace ft {

template <class T, class Container = list<T> >
class queue {

public:

	typedef T value_type;
	typedef Container container_type;
	typedef size_t size_type;

	explicit queue (const container_type& ctnr = container_type()) : _ctnr(ctnr) {}

	bool empty() const { return _ctnr.empty(); }
	size_type size() const { return _ctnr.size(); }

	value_type& front() { return _ctnr.front(); }
	const value_type& front() const { return _ctnr.front(); }
	value_type& back() { return _ctnr.back(); }
	const value_type& back() const { return _ctnr.back(); }

	void push (const value_type& val) { _ctnr.push_back(val); }
	void pop() { _ctnr.pop_front(); }
	
private:

	container_type _ctnr;
	
	template <class U, class Cont>
	friend bool operator== (const queue<U,Cont>& lhs, const queue<U,Cont>& rhs);
	
	template <class U, class Cont>
	friend bool operator!= (const queue<U,Cont>& lhs, const queue<U,Cont>& rhs);
	
	template <class U, class Cont>
	friend bool operator<  (const queue<U,Cont>& lhs, const queue<U,Cont>& rhs);

	template <class U, class Cont>
	friend bool operator<= (const queue<U,Cont>& lhs, const queue<U,Cont>& rhs);

	template <class U, class Cont>
	friend bool operator>  (const queue<U,Cont>& lhs, const queue<U,Cont>& rhs);

	template <class U, class Cont>
	friend bool operator>= (const queue<U,Cont>& lhs, const queue<U,Cont>& rhs);
	
};

	template <class T, class Container>
	bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return lhs._ctnr == rhs._ctnr;
	}

	template <class T, class Container>
	bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return lhs._ctnr != rhs._ctnr;
	}

	template <class T, class Container>
	bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return lhs._ctnr < rhs._ctnr;
	}

	template <class T, class Container>
	bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return lhs._ctnr <= rhs._ctnr;
	}

	template <class T, class Container>
	bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return lhs._ctnr > rhs._ctnr;
	}

	template <class T, class Container>
	bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return lhs._ctnr >= rhs._ctnr;
	}

} // namespace ft

#endif
