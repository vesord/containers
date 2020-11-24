/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:41:50 by matrus            #+#    #+#             */
/*   Updated: 2020/11/18 13:41:52 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "iterator.hpp"
#include <stdexcept>
#include <iostream>

template< class T, class Alloc >
class ft::vector {

public:
	class iterator;
	class const_iterator;
	class reverse_iterator;
	class const_reverse_iterator;
	typedef T value_type;
	typedef Alloc allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;

private:

	size_type	_size;
	size_type 	_capacity;
	pointer 	_end_elem;

	typedef typename allocator_type::template rebind<pointer>::other allocator_rebind;
	allocator_rebind _alloc_rebind;
	allocator_type	 _alloc;

public:
	/*** ITERATORS ***/

	class iterator : public ft::iterator<std::random_access_iterator_tag, value_type> {

	public:
		iterator() : _ptr( nullptr ) { }
		~iterator() { }

		iterator( iterator const & it ) { *this = it; }
		iterator( pointer ptr ) { this->_ptr = ptr; }

		iterator & operator=( iterator const & rhs ) {
			if (this != &rhs)
				_ptr = rhs._ptr;
			return *this;
		}

		iterator & operator++() { this->_ptr += 1; return *this; }
		iterator & operator--() { this->_ptr -= 1; return *this; }

		iterator operator++(int) { iterator tmp = *this; this->operator++(); return tmp; }
		iterator operator--(int) { iterator tmp = *this; this->operator--(); return tmp; }

		iterator operator+( difference_type const & rhs ) const { return iterator(_ptr + rhs); }
		iterator operator-( difference_type const & rhs ) const { return iterator(_ptr - rhs); }
		iterator operator+=( difference_type const & rhs ) { _ptr += rhs; return *this; };
		iterator operator-=( difference_type const & rhs ) { _ptr -= rhs; return *this; };

		bool operator==( iterator const & rhs ) const { return this->_ptr == rhs._ptr; }
		bool operator!=( iterator const & rhs ) const { return this->_ptr != rhs._ptr; }
		bool operator<=( iterator const & rhs ) const { return this->_ptr <= rhs._ptr; }
		bool operator>=( iterator const & rhs ) const { return this->_ptr >= rhs._ptr; }
		bool  operator<( iterator const & rhs ) const { return this->_ptr  < rhs._ptr; }
		bool  operator>( iterator const & rhs ) const { return this->_ptr  > rhs._ptr; }

		bool operator==( const_iterator const & rhs ) const { return this->_ptr == rhs.getPtr(); }
		bool operator!=( const_iterator const & rhs ) const { return this->_ptr != rhs.getPtr(); }
		bool operator<=( const_iterator const & rhs ) const { return this->_ptr <= rhs.getPtr(); }
		bool operator>=( const_iterator const & rhs ) const { return this->_ptr >= rhs.getPtr(); }
		bool  operator<( const_iterator const & rhs ) const { return this->_ptr  < rhs.getPtr(); }
		bool  operator>( const_iterator const & rhs ) const { return this->_ptr  > rhs.getPtr(); }

		value_type & operator[]( difference_type const & i ) const { return *(this->_ptr + i); }
		value_type & operator*() const { return *this->_ptr; }
		value_type * operator->() const { return this->_ptr; }

		pointer getPtr() const { return _ptr; }

	private:
		pointer _ptr;
	};

	class const_iterator : public ft::iterator<std::bidirectional_iterator_tag, value_type>
	{

	public:
		const_iterator() { this->_ptr = nullptr; }
		~const_iterator() { }

		const_iterator( const_iterator const & it ) { *this = it; }
		const_iterator( iterator const & it ) { *this = it; }
		const_iterator( pointer ptr ) { this->_ptr = ptr; }

		const_iterator & operator=( const_iterator const & rhs ) {
			if (this != &rhs)
				_ptr = rhs._ptr;
			return *this;
		}

		const_iterator & operator=( iterator const & rhs ) {
			_ptr = rhs.getPtr();
			return *this;
		}

		const_iterator & operator++() { this->_ptr += 1; return *this; }
		const_iterator & operator--() { this->_ptr -= 1; return *this; }

		const_iterator operator++(int) { const_iterator tmp = *this; this->operator++(); return tmp; }
		const_iterator operator--(int) { const_iterator tmp = *this; this->operator--(); return tmp; }

		const_iterator operator+( difference_type const & rhs ) const { return const_iterator(_ptr + rhs); }
		const_iterator operator-( difference_type const & rhs ) const { return const_iterator(_ptr - rhs); }
		const_iterator operator+=( difference_type const & rhs ) { _ptr += rhs; return *this; };
		const_iterator operator-=( difference_type const & rhs ) { _ptr -= rhs; return *this; };

		bool operator==( const_iterator const & rhs ) const { return this->_ptr == rhs._ptr; }
		bool operator!=( const_iterator const & rhs ) const { return this->_ptr != rhs._ptr; }
		bool operator<=( const_iterator const & rhs ) const { return this->_ptr <= rhs._ptr; }
		bool operator>=( const_iterator const & rhs ) const { return this->_ptr >= rhs._ptr; }
		bool  operator<( const_iterator const & rhs ) const { return this->_ptr < rhs._ptr; }
		bool  operator>( const_iterator const & rhs ) const { return this->_ptr > rhs._ptr; }

		bool operator==( iterator const & rhs ) const { return this->_ptr == rhs.getPtr(); }
		bool operator!=( iterator const & rhs ) const { return this->_ptr != rhs.getPtr(); }
		bool operator<=( iterator const & rhs ) const { return this->_ptr <= rhs.getPtr(); }
		bool operator>=( iterator const & rhs ) const { return this->_ptr >= rhs.getPtr(); }
		bool  operator<( iterator const & rhs ) const { return this->_ptr  < rhs.getPtr(); }
		bool  operator>( iterator const & rhs ) const { return this->_ptr  > rhs.getPtr(); }

		value_type const & operator[]( difference_type const & i ) const { return *(this->_ptr + i); }
		value_type const & operator*() const { return *this->_ptr; }
		value_type const * operator->() const { return this->_ptr; }

		pointer getPtr() const { return _ptr; }

	private:
		pointer _ptr;
	};

	class reverse_iterator : public ft::reverse_iterator<vector::iterator>
	{
		template<class U, class A> friend class list;
		friend class const_reverse_iterator;

	public:
		reverse_iterator() { this->_ptr = nullptr; }
		~reverse_iterator() { }

		reverse_iterator( reverse_iterator const & it ) { *this = it; }
		reverse_iterator( pointer ptr ) { this->_ptr = ptr; }

		reverse_iterator & operator=( reverse_iterator const & rhs ) {
			if (this != &rhs)
				_ptr = rhs._ptr;
			return *this;
		}

		reverse_iterator & operator++() { this->_ptr -= 1; return *this; }
		reverse_iterator & operator--() { this->_ptr += 1; return *this; }
		reverse_iterator operator++(int) { reverse_iterator tmp = *this; this->operator++(); return tmp; }
		reverse_iterator operator--(int) { reverse_iterator tmp = *this; this->operator--(); return tmp; }

		reverse_iterator operator+( difference_type const & rhs ) const { return reverse_iterator(_ptr - rhs); }
		reverse_iterator operator-( difference_type const & rhs ) const { return reverse_iterator(_ptr + rhs); }
		reverse_iterator operator+=( difference_type const & rhs ) { _ptr -= rhs; return *this; };
		reverse_iterator operator-=( difference_type const & rhs ) { _ptr += rhs; return *this; };

		bool operator==( reverse_iterator const & rhs ) const { return this->_ptr == rhs._ptr; }
		bool operator!=( reverse_iterator const & rhs ) const { return this->_ptr != rhs._ptr; }
		bool operator<=( reverse_iterator const & rhs ) const { return this->_ptr >= rhs._ptr; }
		bool operator>=( reverse_iterator const & rhs ) const { return this->_ptr <= rhs._ptr; }
		bool  operator<( reverse_iterator const & rhs ) const { return this->_ptr >  rhs._ptr; }
		bool  operator>( reverse_iterator const & rhs ) const { return this->_ptr <  rhs._ptr; }

		bool operator==( const_reverse_iterator const & rhs ) const { return this->_ptr == rhs.getPtr(); }
		bool operator!=( const_reverse_iterator const & rhs ) const { return this->_ptr != rhs.getPtr(); }
		bool operator<=( const_reverse_iterator const & rhs ) const { return this->_ptr >= rhs.getPtr(); }
		bool operator>=( const_reverse_iterator const & rhs ) const { return this->_ptr <= rhs.getPtr(); }
		bool  operator<( const_reverse_iterator const & rhs ) const { return this->_ptr >  rhs.getPtr(); }
		bool  operator>( const_reverse_iterator const & rhs ) const { return this->_ptr <  rhs.getPtr(); }

		value_type & operator[]( difference_type const & i ) const { return *(this->_ptr - i); }
		value_type & operator*() const { return *this->_ptr; }
		value_type * operator->() const { return this->_ptr; }

		pointer getPtr() const { return _ptr; }

	private:
		pointer _ptr;
	};

	class const_reverse_iterator : public ft::reverse_iterator<vector::iterator>
	{
		template<class U, class A> friend class list;

	public:
		const_reverse_iterator() { this->_ptr = nullptr; }
		~const_reverse_iterator() { }

		const_reverse_iterator( const_reverse_iterator const & it ) { *this = it; }
		const_reverse_iterator( reverse_iterator const & it ) { *this = it; }
		const_reverse_iterator( pointer node ) { this->_ptr = node; }

		const_reverse_iterator & operator=( const_reverse_iterator const & rhs ) {
			if (this != &rhs)
				_ptr = rhs.getPtr();
			return *this;
		}

		const_reverse_iterator & operator=( reverse_iterator const & rhs ) {
			_ptr = rhs._ptr;
			return *this;
		}

		const_reverse_iterator & operator++() { this->_ptr -= 1; return *this; }
		const_reverse_iterator & operator--() { this->_ptr += 1; return *this; }
		const_reverse_iterator operator++(int) { const_reverse_iterator tmp = *this; this->operator++(); return tmp; }
		const_reverse_iterator operator--(int) { const_reverse_iterator tmp = *this; this->operator--(); return tmp; }

		const_reverse_iterator operator+( difference_type const & rhs ) const { return reverse_iterator(_ptr - rhs); }
		const_reverse_iterator operator-( difference_type const & rhs ) const { return reverse_iterator(_ptr + rhs); }
		const_reverse_iterator operator+=( difference_type const & rhs ) { _ptr -= rhs; return *this; };
		const_reverse_iterator operator-=( difference_type const & rhs ) { _ptr += rhs; return *this; };

		bool operator==( const_reverse_iterator const & rhs ) const { return this->_ptr == rhs._ptr; }
		bool operator!=( const_reverse_iterator const & rhs ) const { return this->_ptr != rhs._ptr; }
		bool operator<=( const_reverse_iterator const & rhs ) const { return this->_ptr >= rhs._ptr; }
		bool operator>=( const_reverse_iterator const & rhs ) const { return this->_ptr <= rhs._ptr; }
		bool  operator<( const_reverse_iterator const & rhs ) const { return this->_ptr >  rhs._ptr; }
		bool  operator>( const_reverse_iterator const & rhs ) const { return this->_ptr <  rhs._ptr; }

		bool operator==( reverse_iterator const & rhs ) const { return this->_ptr == rhs.getPtr(); }
		bool operator!=( reverse_iterator const & rhs ) const { return this->_ptr != rhs.getPtr(); }
		bool operator<=( reverse_iterator const & rhs ) const { return this->_ptr >= rhs.getPtr(); }
		bool operator>=( reverse_iterator const & rhs ) const { return this->_ptr <= rhs.getPtr(); }
		bool  operator<( reverse_iterator const & rhs ) const { return this->_ptr >  rhs.getPtr(); }
		bool  operator>( reverse_iterator const & rhs ) const { return this->_ptr <  rhs.getPtr(); }

		value_type const & operator[]( difference_type const & i ) const { return *(this->_ptr - i); }
		value_type const & operator*() const { return *this->_ptr; }
		value_type const * operator->() const { return this->_ptr; }

		pointer getPtr() const { return _ptr; }

	private:
		pointer _ptr;
	};

	/*** CONSTRUCTION ***/

	explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc) {
		static_cast<void>(alloc);
		_end_elem = nullptr;
	}
	explicit vector (size_type n, const value_type& val = value_type(),
					 const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc) {
		_end_elem = _alloc.allocate(n);
		pointer ptr = _end_elem;
		for (; n > 0; --n) {
			_alloc.construct(ptr++, val);
		}
		_end_elem = ptr;
	}
	template <class InputIterator>
	vector (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) : _size(0), _capacity(0), _alloc(alloc) {
		InputIterator	ibegin = first;
		size_type		size = 0;
		while (ibegin != last) {
			++ibegin;
			++size;
		}
		_end_elem = _alloc.allocate(size);
		pointer ptr = _end_elem;
		while (first != last) {
			_alloc.construct(ptr++, *first++);
		}
		_end_elem = ptr;
		_size = size;
		_capacity = _size;
	}
	vector (const vector& x) : _size(x._size), _capacity(x._capacity), _alloc(x._alloc) {
		_end_elem = _alloc.allocate(_capacity);
		pointer ptr = _end_elem;
		pointer ptrx = x.begin().getPtr();
		for (size_type i = 0; i < _size; ++i) {
			_alloc.construct(ptr++, *ptrx++);
		}
		_end_elem = ptr;
	}

	/*** DESTRUCTION ***/

	~vector() { _full_clear(); }

	/*** ASSIGNATION ***/

	vector& operator=(const vector& x) { // if throws container in valid state
		clear();
		insert(begin(), x.begin(), x.end());
		return *this;
	}

	/*** ITERATORS ***/

	iterator begin() { return iterator(_end_elem - _size); }
	iterator end() { return iterator(_end_elem); }
	const_iterator begin() const  { return const_iterator(_end_elem - _size); }
	const_iterator end() const { return const_iterator(_end_elem); }

	reverse_iterator rbegin() { return reverse_iterator(_end_elem - 1); }
	reverse_iterator rend() { return reverse_iterator(_end_elem - _size - 1); }
	const_reverse_iterator rbegin() const { return const_reverse_iterator(_end_elem - 1); }
	const_reverse_iterator rend() const { return const_reverse_iterator(_end_elem - _size - 1); }

	/*** CAPACITY ***/

	size_type size() const { return this->_size; }
	size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(ft::vector<value_type>); }
	void resize (size_type n, value_type val = value_type()) {
		if (n > _size)
			insert(end(), n - _size, val);
		if (n < _size)
			erase(iterator(end().getPtr() - (_size - n)), end());
	}
	size_type capacity() const { return this->_capacity; }
	bool empty() const { return _size == 0; }
	void reserve (size_type n) {
		if (n > max_size())
			throw std::length_error("can not reserve more then max_size() elements");
		if (n < _capacity)
			return ;
		_reallocate(n);
	}; // throws length_error, bad_alloc

	/*** ELEMENT ACCESS ***/

	reference operator[] (size_type n) {
		return *(_end_elem - _size + static_cast<difference_type>(n));
	} 						// if n > size undefined behavior
	const_reference operator[] (size_type n) const {
		return *(_end_elem - _size + static_cast<difference_type>(n));
	}			// if n > size undefined behavior
	reference at (size_type n) {
		if (n < 0 || n >= _size)
			throw std::out_of_range("index out of range");
		return this->operator[](n);
	}								// throws out_of_bounds
	const_reference at (size_type n) const {
		if (n < 0 || n >= _size)
			throw std::out_of_range("index out of range");
		return this->operator[](n);
	};					// throws out_of_bounds
	reference front() { return *(_end_elem - _size); }				// if empty() undefined behaviour
	const_reference front() const { return *(_end_elem - _size); }	// if empty() undefined behaviour
	reference back() { return *(_end_elem - 1); }					// if empty() undefined behaviour
	const_reference back() const { return *(_end_elem - 1); }		// if empty() undefined behaviour

	/*** MODIFIERS ***/

	template <class InputIterator>
	void assign (InputIterator first, InputIterator last,
			  typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
		clear();
		insert(begin(), first, last);
	}
	void assign (size_type n, const value_type& val) {
		clear();
		insert(begin(), n, val);
	}
	void push_back (const value_type& val) {
		insert(end(), val);
	}
	void pop_back() {
		erase(--end());
	}

	iterator insert (iterator position, const value_type& val) {
		pointer curPosPtr = position.getPtr();
		if (_size + 1 > _capacity) {
			difference_type offset = _end_elem - curPosPtr;
			_reallocate(_capacity * 2);
			curPosPtr = _end_elem - offset;
		}
		std::memmove(curPosPtr + 1, curPosPtr,
			   static_cast<size_t>(abs(_end_elem - curPosPtr)) * sizeof(value_type));
		_alloc.construct(curPosPtr, val);
		_end_elem += 1;
		_size += 1;
		return iterator(curPosPtr);
	}
	void insert (iterator position, size_type n, const value_type& val) {
		std::cout << "1" << std::endl;
		pointer curPosPtr = position.getPtr();
		if (_size + n > _capacity) {
			difference_type offset = _end_elem - curPosPtr;
			_reallocate((_size + n) * 2);
			curPosPtr = _end_elem - offset;
		}
		std::cout << "1" << std::endl;
		std::memmove(curPosPtr + n, curPosPtr,
			   static_cast<size_t>(abs(_end_elem - curPosPtr)) * sizeof(value_type));
		std::cout << "1" << std::endl;
		for (size_type i = 0; i < n; ++i) {
			_alloc.construct(&curPosPtr[i], val);
		}
		_end_elem += n;
		_size += n;
	}
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last,
				 typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
		for(; first != last; ++first) {
			position = insert(position, *first);
			++position;
		}
	}

	iterator erase (iterator position) {
		pointer erasePosPtr = position.getPtr();
		_alloc.destroy(erasePosPtr);
		std::memmove(erasePosPtr, erasePosPtr + 1,
			   static_cast<size_t>(abs(_end_elem - erasePosPtr)) * sizeof(value_type));
		_size -= 1;
		_end_elem -= 1;
		return (erasePosPtr);
	}
	iterator erase (iterator first, iterator last) {
		for(; first != last; ) {
			erase(--last);
		}
		return last;
	}

	void swap (vector& x); // no throw
	void clear() {
		pointer ptr = _end_elem;
		for (size_type i = 0; i < _size; ++i) {
			_alloc.destroy(--ptr);
		}
		_size = 0;
		_end_elem = ptr;
	}

private:

	void	_full_clear() {
		clear();
		_alloc.deallocate(_end_elem, _size);
		_capacity = 0;
		_end_elem = nullptr;
	}

	void	_reallocate(size_type n) {
		if (n == 0)
			n = 1;
		pointer newV = _alloc.allocate(n);
		pointer begin = _end_elem - _size;
		size_type i;
		for (i = 0; i < _size; ++i) {
			_alloc.construct(&newV[i], begin[i]);
		}
		_full_clear();
		_capacity = n;
		_size = i;
		_end_elem = &newV[i];
	}
};

template <class T, class Alloc>
void ft::swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
	x.swap(y);
}

template <class T, class Alloc>
bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	if (lhs.size() != rhs.size())
		return false;

	typename ft::vector<T, Alloc>::const_iterator itl = lhs.begin();
	typename ft::vector<T, Alloc>::const_iterator itle = lhs.end();
	typename ft::vector<T, Alloc>::const_iterator itr = rhs.begin();
	typename ft::vector<T, Alloc>::const_iterator itre = rhs.end();

	for (; itl != itle; ++itl) {
		if ( itr == itre || *itl != *itr)
			return false;
		++itr;
	}
	return true;
}

template <class T, class Alloc>
bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

template <class T, class Alloc>
bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	typename ft::vector<T, Alloc>::const_iterator itl = lhs.begin();
	typename ft::vector<T, Alloc>::const_iterator itle = lhs.end();
	typename ft::vector<T, Alloc>::const_iterator itr = rhs.begin();
	typename ft::vector<T, Alloc>::const_iterator itre = rhs.end();

	for (; itl != itle; ++itl, ++itr) {
		if (itr == itre)
			return false;
		if (*itl < *itr)
			return true;
	}
	if (itr != itre)
		return true;
	return false;
}

template <class T, class Alloc>
bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

template <class T, class Alloc>
bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

template <class T, class Alloc>
bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

#endif
