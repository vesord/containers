/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:43:21 by matrus            #+#    #+#             */
/*   Updated: 2020/11/09 15:43:26 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include "allocator.hpp"
#include "iterator.hpp"

template< class T, class Alloc = ft::allocator<T> >
class ft::list {

public:

	/*** INTERNAL TYPES ***/
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

private:

	typedef struct	_s_node
	{
		struct _s_node*	_next;
		struct _s_node*	_prev;
		value_type *	_data;
	}				_t_node;
	_t_node *		_begin_node;
	_t_node *		_end_node;

public:

	typedef typename allocator_type::template rebind<_t_node>::other allocator_rebind;
	allocator_rebind _alloc_rebind;
	allocator_type	 _alloc;

public:

	/*** ITERATORS ***/

class iterator : public ft::iterator<std::bidirectional_iterator_tag, value_type> {

	public:
		iterator() : _ptr( nullptr ) { }
		~iterator() { }

		iterator( iterator const & it ) { *this = it; }
		iterator( _t_node * node ) { this->_ptr = node; }

		iterator & operator=( iterator const & rhs ) {
			if (this != &rhs)
				_ptr = rhs._ptr;
			return *this;
		}

		iterator & operator++() { this->_ptr = this->_ptr->_next; return *this; }
		iterator operator++(int) { iterator tmp = *this; this->operator++(); return tmp; }

		bool operator==( iterator const & rhs ) const { return this->_ptr == rhs._ptr; }
		bool operator==( const_iterator const & rhs ) const { return this->_ptr == rhs.getPtr(); }
		bool operator!=( iterator const & rhs ) const { return this->_ptr != rhs._ptr; }
		bool operator!=( const_iterator const & rhs ) const { return this->_ptr != rhs.getPtr(); }

		value_type & operator*() const { return *this->_ptr->_data; }
		value_type * operator->() const { return this->_ptr->_data; }

		iterator & operator--() { this->_ptr = _ptr->_prev; return *this; }
		iterator operator--(int) { iterator tmp = *this; this->operator--(); return tmp; }

		_t_node* getPtr() const { return _ptr; }

	private:
		_t_node* _ptr;
	};

class const_iterator : public ft::iterator<std::bidirectional_iterator_tag, value_type>
	{

	public:
		const_iterator() { this->_ptr = nullptr; }
		~const_iterator() { }

		const_iterator( const_iterator const & it ) { *this = it; }
		const_iterator( iterator const & it ) { *this = it; }
		const_iterator( _t_node * node ) { this->_ptr = node; }

		const_iterator & operator=( const_iterator const & rhs ) {
			if (this != &rhs)
				_ptr = rhs._ptr;
			return *this;
		}

		const_iterator & operator=( iterator const & rhs ) {
			_ptr = rhs.getPtr();
			return *this;
		}

		const_iterator & operator++() { this->_ptr = _ptr->_next; return *this; }
		const_iterator operator++(int) { const_iterator tmp = *this; this->operator++(); return tmp; }

		bool operator==( const_iterator const & rhs ) const { return this->_ptr == rhs._ptr; }
		bool operator==( iterator const & rhs ) const { return this->_ptr == rhs.getPtr(); }
		bool operator!=( const_iterator const & rhs ) const { return this->_ptr != rhs._ptr; }
		bool operator!=( iterator const & rhs ) const { return this->_ptr != rhs.getPtr(); }

		value_type const & operator*() const { return *this->_ptr->_data; }
		value_type const * operator->() const { return this->_ptr->_data; }

		const_iterator & operator--() { this->_ptr = _ptr->_prev; return *this; }
		const_iterator operator--(int) { const_iterator tmp = *this; this->operator--(); return tmp; }

		_t_node* getPtr() const { return _ptr; }

	private:
		_t_node *_ptr;
	};

class reverse_iterator : public ft::reverse_iterator<list::iterator>
	{
		template<class U, class A> friend class list;
		friend class const_reverse_iterator;

	public:
		reverse_iterator() { this->_ptr = nullptr; }
		~reverse_iterator() { }

		reverse_iterator( reverse_iterator const & it ) { *this = it; }
		reverse_iterator( _t_node * node ) { this->_ptr = node; }

		reverse_iterator & operator=( reverse_iterator const & rhs ) {
			if (this != &rhs)
				_ptr = rhs._ptr;
			return *this;
		}

		reverse_iterator & operator++() { this->_ptr = _ptr->_prev; return *this; }
		reverse_iterator operator++(int) { reverse_iterator tmp = *this; this->operator++(); return tmp; }

		bool operator==( reverse_iterator const & rhs ) const { return this->_ptr == rhs._ptr; }
		bool operator==( const_reverse_iterator const & rhs ) const { return this->_ptr == rhs.getPtr(); }
		bool operator!=( reverse_iterator const & rhs ) const { return this->_ptr != rhs._ptr; }
		bool operator!=( const_reverse_iterator const & rhs ) const { return this->_ptr != rhs.getPtr(); }

		value_type & operator*() const { return *this->_ptr->_data; }
		value_type * operator->() const { return this->_ptr->_data; }

		reverse_iterator & operator--() { this->_ptr = _ptr->_next; return *this; }
		reverse_iterator operator--(int) { reverse_iterator tmp = *this; this->operator--(); return tmp; }

		_t_node* getPtr() const { return _ptr; }

	private:
		_t_node *_ptr;
	};

class const_reverse_iterator : public ft::reverse_iterator<list::iterator>
	{
		template<class U, class A> friend class list;

	public:
		const_reverse_iterator() { this->_ptr = nullptr; }
		~const_reverse_iterator() { }

		const_reverse_iterator( const_reverse_iterator const & it ) { *this = it; }
		const_reverse_iterator( reverse_iterator const & it ) { *this = it; }
		const_reverse_iterator( _t_node * node ) { this->_ptr = node; }

		const_reverse_iterator & operator=( const_reverse_iterator const & rhs ) {
			if (this != &rhs)
				_ptr = rhs.getPtr();
			return *this;
		}

		const_reverse_iterator & operator=( reverse_iterator const & rhs ) {
			_ptr = rhs._ptr;
			return *this;
		}

		const_reverse_iterator & operator++() { this->_ptr = _ptr->_prev; return *this; }
		const_reverse_iterator operator++(int) { const_reverse_iterator tmp = *this; this->operator++(); return tmp; }

		bool operator==( const_reverse_iterator const & rhs ) const { return this->_ptr == rhs._ptr; }
		bool operator==( reverse_iterator const & rhs ) const { return this->_ptr == rhs.getPtr(); }
		bool operator!=( const_reverse_iterator const & rhs ) const { return this->_ptr != rhs._ptr; }
		bool operator!=( reverse_iterator const & rhs ) const { return this->_ptr != rhs.getPtr(); }

		value_type & operator*() const { return *this->_ptr->_data; }
		value_type * operator->() const { return this->_ptr->_data; }

		const_reverse_iterator & operator--() { this->_ptr = _ptr->_next; return *this; }
		const_reverse_iterator operator--(int) { const_reverse_iterator tmp = *this; this->operator--(); return tmp; }

		_t_node* getPtr() const { return _ptr; }

	private:
		_t_node *_ptr;
	};

	typedef ptrdiff_t difference_type;
	typedef size_t size_type;

	/*** CONSTRUCTION ***/
	explicit list (const allocator_type& alloc = allocator_type()) : _size( 0 ) {
		_createEndNode(alloc);
		_begin_node = _end_node;
		_size = 0;
	}
	template <class InputIterator>
	list (InputIterator first, InputIterator last,
		  const allocator_type& alloc = allocator_type(),
		  typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) : _size( 0 ) {
		_createEndNode(alloc);
		_begin_node = _end_node;
		for (; first != last; ++first) {
			push_back(*first);
		}
	}
	explicit list (size_type n, const value_type& val = value_type(),
				   const allocator_type& alloc = allocator_type()) : _size( 0 ) {
		_createEndNode(alloc);
		_begin_node = _end_node;
		for (size_type size = 0; size < n; ++size)
			push_front(val);
	}
	list (const list& x) : _size( 0 ) {
		_createEndNode();
		_begin_node = _end_node;
		//there should be get allocator, but our list doesn't have one
		*this = x;
	}

	/*** DESTRUCTION ***/
	~list() {
		this->clear();
		_alloc.deallocate(this->_end_node->_data, 1);
		_alloc_rebind.deallocate(this->_end_node, 1);
	};

	/*** ASSIGNATION ***/
	list& operator= (const list& x) {
		if ( this == &x )
			return *this;
		clear();
		const_iterator ite = x.end();
		for (const_iterator it = x.begin(); it != ite; ++it)
			push_back(*it);
		return *this;
	};

	/*** ITERATORS ***/
	iterator begin() { return iterator(_begin_node); }
	const_iterator begin() const { return const_iterator(_begin_node); }
	iterator end() { return iterator(_end_node); }
	const_iterator end() const { return const_iterator(_end_node); }
	reverse_iterator rbegin() { return reverse_iterator(_end_node->_prev); }
	const_reverse_iterator rbegin() const { return const_reverse_iterator(_end_node->_prev); }
	reverse_iterator rend() { return reverse_iterator(_begin_node->_prev); }
	const_reverse_iterator rend() const { return const_reverse_iterator(_begin_node->_prev); }

	/*** CAPACITY ***/
	bool empty() const { return this->_begin_node == this->_end_node; };
	size_type size() const { return this->_size; }
	size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(value_type); }

	/*** ELEMENT ACCESS ***/
	reference front() { return *this->_begin_node->_data; };
	const_reference front() const { return *this->_begin_node->_data; };
	reference back() { return *this->_end_node->_prev->_data; };
	const_reference back() const { return *this->_end_node->_prev->_data; };;

	/*** MODIFIERS ***/
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last,
			  typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0)
			  {
		clear();
		for (; first != last; ++first) {
			push_back(*first);
		}
	};
	void assign (size_type n, const value_type& val) {
		clear();
		for (; n > 0; --n) {
			push_back(val);
		}
	}

	void push_front (const value_type& val) {
		_t_node *node = _createNode(val, this->_begin_node, this->_end_node);
		this->_begin_node->_prev = node;
		this->_begin_node = node;
		_end_node->_next = _begin_node;
		this->_size += 1;
	};
	void pop_front() {
		_end_node->_next = _begin_node->_next;
		_begin_node->_next->_prev = _end_node;
		_destroyNode(_begin_node);
		_begin_node = _end_node->_next;
		if (_size == 1) {
			_changeBeginNode(_end_node, _end_node);
		}
		_size -= 1;
	}
	void push_back (const value_type& val) {
		_t_node *node = _createNode(val, _end_node, _end_node->_prev);
		_end_node->_prev->_next = node;
		_end_node->_prev = node;
		if (_size == 0) {
			_changeBeginNode(node, node);
		}
		_size += 1;
	};
	void pop_back() {
		_t_node *back = _end_node->_prev;
		_end_node->_prev->_prev->_next = _end_node;
		_end_node->_prev = _end_node->_prev->_prev;
		if (_size == 1) {
			_changeBeginNode(_end_node, _end_node);
		}
		_destroyNode(back);
		_size -= 1;
	}

	iterator insert (iterator position, const value_type& val) {
		_t_node* node = _createNode(val, position.getPtr(), position.getPtr()->_prev);
		position.getPtr()->_prev->_next = node;
		position.getPtr()->_prev = node;
		if (position == begin()) {
			_changeBeginNode(node, _end_node->_prev);
		}
		if (_size == 0) {
			_changeBeginNode(node, node);
		}
		_size += 1;
		return iterator(node);
	}
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last,
				 typename ft::enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
		for(; first != last; ++first) {
			insert(position, *first);
		}
	}
	void insert (iterator position, size_type n, const value_type& val) {
		for (; n > 0; --n) {
			insert(position, val);
		}
	}

	iterator erase (iterator position) {
		_t_node	*toDestroy = position.getPtr();
		position.getPtr()->_prev->_next = position.getPtr()->_next;
		position.getPtr()->_next->_prev = position.getPtr()->_prev;
		if (position == begin()) {
			_changeBeginNode(position.getPtr()->_next, _end_node->_prev);
		}
		if (_size == 1) {
			_changeBeginNode(_end_node, _end_node);
		}
		++position;
		_destroyNode(toDestroy);
		_size--;
		return (position);
	}
	iterator erase (iterator first, iterator last) {
		for (; first != last;)
			first = erase(first);
		return (first);
	}

	void swap (list& x) {
		_t_node *tmp;
		tmp = this->_begin_node;
		this->_begin_node = x._begin_node;
		x._begin_node = tmp;

		tmp = this->_end_node;
		this->_end_node = x._end_node;
		x._end_node = tmp;

		size_type tmpSize;
		tmpSize = this->_size;
		this->_size = x._size;
		x._size = tmpSize;
	};

	void resize (size_type n, value_type val = value_type()) {
		for (; n > _size; ) {
			push_back(val);
		}
		for (; n < _size; ) {
			erase(iterator(_end_node->_prev));
		}
	};

	void clear() {
		for (; 0 < _size; --_size) {
			_t_node* tmp = _begin_node;
			_begin_node = _begin_node->_next;
			_destroyNode(tmp);
		}
		_begin_node = _end_node;
		_end_node->_next = _end_node;
		_end_node->_prev = _end_node;
	}

	/*** OPERATIONS ***/
	void splice (iterator position, list& x) {
		position.getPtr()->_prev->_next = x.begin().getPtr();
		x.begin().getPtr()->_prev = position.getPtr()->_prev;

		position.getPtr()->_prev = x._end_node->_prev;
		x._end_node->_prev->_next = position.getPtr();

		if (position == begin()) {
			_changeBeginNode(x.begin().getPtr(), _size == 0 ? x.end().getPtr()->_prev : _end_node->_prev);
		}

		x.end().getPtr()->_prev = x.end().getPtr();
		x.end().getPtr()->_next = x.end().getPtr();
		x._begin_node = x._end_node;

		this->_size += x._size;
		x._size = 0;
	}
	void splice (iterator position, list& x, iterator i) {
		if (i == x.begin()) {
			x._begin_node = i.getPtr()->_next;
			x._end_node->_next = x._begin_node;
			if (x._size == 1)
				x._end_node->_prev = x._end_node;
		}

		i.getPtr()->_prev->_next = i.getPtr()->_next;
		i.getPtr()->_next->_prev = i.getPtr()->_prev;

		position.getPtr()->_prev->_next = i.getPtr();
		i.getPtr()->_prev = position.getPtr()->_prev;

		if (position == begin()) {
			_changeBeginNode(i.getPtr(), _size == 0 ? i.getPtr() : _end_node->_prev);
		}

		i.getPtr()->_next = position.getPtr();
		position.getPtr()->_prev = i.getPtr();

		this->_size += 1;
		x._size -= 1;
	};
	void splice (iterator position, list& x, iterator first, iterator last) {
		iterator tmp;

		for (; first != last; ) {
			tmp = first++;
			splice(position, x, tmp);
		}
	}

	void remove (const value_type& val) {
		iterator it;
		iterator ite = end();
		iterator tmp;

		for (it = begin(); it != ite;) {
			tmp = it++;
			if (*tmp == val) {
				if (tmp == begin()) {
					_begin_node = _begin_node->_next;
					_end_node->_next = _begin_node;
				}
				if (tmp == --end()) {
					_end_node->_prev->_prev->_next = _end_node;
					_end_node->_prev = _end_node->_prev->_prev;
				}
				tmp.getPtr()->_prev->_next = tmp.getPtr()->_next;
				tmp.getPtr()->_next->_prev = tmp.getPtr()->_prev;
				_destroyNode(tmp.getPtr());
				_size -= 1;
			}
		}
	}
	template <class Predicate>
	void remove_if (Predicate pred) {
		iterator it;
		iterator ite = end();
		iterator tmp;

		for (it = begin(); it != ite;) {
			tmp = it++;
			if (pred(*tmp)) {
				if (tmp == begin()) {
					_begin_node = _begin_node->_next;
					_end_node->_next = _begin_node;
				}
				if (tmp == --end()) {
					_end_node->_prev->_prev->_next = _end_node;
					_end_node->_prev = _end_node->_prev->_prev;
				}
				tmp.getPtr()->_prev->_next = tmp.getPtr()->_next;
				tmp.getPtr()->_next->_prev = tmp.getPtr()->_prev;
				_destroyNode(tmp.getPtr());
				_size -= 1;
			}
		}
	}

	void unique() {
		unique(_equal());
	}
	template <class BinaryPredicate>
	void unique (BinaryPredicate binary_pred) {
		iterator itFirst = begin();
		iterator itSecond = ++begin();
		iterator ite = end();

		while (itSecond != ite) {
			if (binary_pred(*itFirst, *itSecond)) {
				itSecond = erase(itSecond);
				continue;
			}
			++itFirst;
			++itSecond;
		}
	}

//	void merge (list& x);
//	template <class Compare>
//	void merge (list& x, Compare comp);
	void sort() {
		sort(_less());
	}
	template <class Compare>
	void sort (Compare comp) {
		iterator iFirst;
		iterator iSecond;
		iterator iEnd = this->end();

		while (iEnd != ++begin()) {
			iFirst = begin();
			iSecond = ++begin();
			while (iSecond != iEnd) {
				if (!comp(*iFirst, *iSecond)) {
					_swapNodes(iFirst, iSecond);
				}
				++iFirst;
				++iSecond;
			}
			iEnd = iFirst;
		}
	}

//	void reverse();

private:

	size_type		_size;

	void	_createEndNode(const allocator_type& alloc = allocator_type()) {
		_end_node = _alloc_rebind.allocate(1);
		_end_node->_next = _end_node;
		_end_node->_prev = _end_node;
		_end_node->_data = alloc.allocate(1);
	}

	void	_destroyNode( _t_node* node ) {
		_alloc.destroy(node->_data);
		_alloc.deallocate(node->_data, 1);
		_alloc_rebind.deallocate(node, 1);
	}

	_t_node*	_createNode(const value_type& val,
					   _t_node* next = nullptr, _t_node* prev = nullptr,
					   allocator_type alloc = allocator_type()) {
		_t_node* node = _alloc_rebind.allocate(1);
		node->_prev = prev;
		node->_next = next;
		node->_data = alloc.allocate(1);
		alloc.construct(node->_data, val);
		return node;
	}

	void	_changeBeginNode(_t_node *newBegin, _t_node *endPrev) {
		_begin_node = newBegin;
		_end_node->_next = newBegin;
		_end_node->_prev = endPrev;
	}

	/*
	 * Swap nodes. Changes link to _begin_node accordingly. Swaps iterators.
	 */

	void	_swapNodes(iterator & it1, iterator & it2) {
		_t_node *n1 = it1.getPtr();
		_t_node *n2 = it2.getPtr();
		_t_node *tmp;

		tmp = n1->_prev;
		n1->_prev = n2;
		n1->_next = n2->_next;
		n1->_next->_prev = n1;

		n2->_prev = tmp;
		n2->_next = n1;
		n2->_prev->_next = n2;

		if (it1 == begin()) {
			_changeBeginNode(it2.getPtr(), it2 == --end() ? it1.getPtr() : _end_node->_prev);
		}

		iterator itmp = it1;
		it1 = it2;
		it2 = itmp;
	}

	struct _less {
		bool operator()(value_type const & _x, value_type const & _y) { return _x < _y; }
	};

	struct _equal {
		bool operator()(value_type const & _x, value_type const & _y) { return _x == _y; }
	};
};

#endif
