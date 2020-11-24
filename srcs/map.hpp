/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:10:07 by matrus            #+#    #+#             */
/*   Updated: 2020/11/22 14:10:08 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "iterator.hpp"
#include <stdexcept>
#include <iostream>

#define RED_NODE_OUTPUT(x)  "\x1b[31;1m" + (x) + "\x1b[0m"
#include <queue>
#include <iomanip>
#include <sstream>

template < class G, class U >
std::ostream & operator<<(std::ostream & o, std::pair<G, U> p) {
	o << p.first << " => " << p.second;
	return o;
}

template <class Key, class T, class Compare, class Alloc>
class ft::map {

public:
	class iterator;
	class const_iterator;
	class reverse_iterator;
	class const_reverse_iterator;

	typedef Key key_type;
	typedef T mapped_type;
	typedef std::pair<const key_type, mapped_type> value_type;
	typedef Compare key_compare;
	typedef Alloc allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;

class value_compare : public std::binary_function<value_type, value_type, bool>
{
protected:
	Compare comp;
	value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
public:
	typedef bool result_type;
	typedef value_type first_argument_type;
	typedef value_type second_argument_type;
	bool operator() (const value_type& x, const value_type& y) const
	{
		return comp(x.first, y.first);
	}
};

private:

public: // DELETE THIS PUBLIC!!!
	typedef struct	_s_tree_node {
		value_type			*data;
		struct _s_tree_node	*left;
		struct _s_tree_node	*right;
		struct _s_tree_node	*parent;
		bool				color;
	}				_t_node;

private:

	typedef typename allocator_type::template rebind<_t_node>::other allocator_rebind;
	allocator_rebind	_alloc_rebind;
	allocator_type		_alloc;
	Compare				_comp;

	_t_node		*_root;
	_t_node		*_begin_node;
	_t_node		*_end_node;
	size_type	_size;

	static const bool	_color_black = false;
	static const bool	_color_red = true;

public:

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

		_t_node* getPtr() const { return _ptr; }

	private:
		_t_node* _ptr;
	};

	/*** DEBUG ***/

	_t_node* _returnRoot() {
		return _root;
	}


	/*** CONSTRUCTION ***/ // we should init comp and alloc
	explicit map (const key_compare& comp = key_compare(),
				  const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _root(nullptr), _size(0) {
		_begin_node = _createEmptyNode();
		_end_node = _createEmptyNode();
	}

	template <class InputIterator>
	map (InputIterator first, InputIterator last,
		 const key_compare& comp = key_compare(),
		 const allocator_type& alloc = allocator_type());

	map (const map& x);

	/*** DESTRUCTION ***/
	// DONT FORGET ABOUT DESTRUCTION
	 ~map() {};

	 /*** ASSIGNATION ***/

	 map& operator= (const map& x);

	 /*** ITERATORS ***/

	 /*
	  * if map is empty() begin and end should point on the same node
	  */

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;

	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;

	/*** CAPACITY ***/

	bool empty() const;
	size_type size() const;
	size_type max_size() const;

	/*** ELEMENT ACCEESS ***/

	mapped_type& operator[] (const key_type& k);

	/*** MODIFIERS ***/

	void	insert_test(const value_type& val) {
		_root = _treeInsert(_root, val);
	}

	std::pair<iterator,bool> insert (const value_type& val) {
		std::pair<_t_node*, bool> ret;

		ret = std::make_pair(_root, false);
		ret = _tree_insert(ret, val);
		_root = ret.first;
		if (ret.second)
			_size += 1;
		return ret;
	}
	iterator insert (iterator position, const value_type& val);
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last);

	void erase (iterator position);
	size_type erase (const key_type& k);
	void erase (iterator first, iterator last);

	void swap (map& x);

	void clear();

	/*** OBSERVERS ***/

	key_compare key_comp() const;
	value_compare value_comp() const;

	/*** OPERATIONS ***/

	iterator find (const key_type& k);
	const_iterator find (const key_type& k) const;

	size_type count (const key_type& k) const;

	iterator lower_bound (const key_type& k);
	const_iterator lower_bound (const key_type& k) const;
	iterator upper_bound (const key_type& k);
	const_iterator upper_bound (const key_type& k) const;

	std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
	std::pair<iterator,iterator>             equal_range (const key_type& k);



	/*** DEBUG ***/

	void	_dPrintStrangeTreeLine(int width, _t_node* curNode) {
		std::stringstream ss;
		std::string str;

		std::cout.width(width);
		if (curNode && curNode->data) {
			ss << *(curNode->data);
			str = ss.str();
			if (curNode->color) {
				str = RED_NODE_OUTPUT(ss.str());
				width += 11;
			}
			std::cout << std::setw(width) << str ;
		}
		else if (curNode)
			std::cout << "__edge__";
		else
			std::cout << "__null__";
	}

	void	_dPrintStrangeTree(_t_node* const root)
	{
		std::queue<ft::map<char, int>::_t_node *> q;
		ft::map<char, int>::_t_node * curNode;
		bool printTime;
		int onLine = 1;
		int needToPrint = 1;
		int widthSt = 128;
		int width;

		q.push(root);
		while (!q.empty()) {
			curNode = q.front();
			q.pop();
			printTime = onLine == needToPrint;
			width = printTime ? (widthSt / onLine / 2) : (widthSt / onLine);
			_dPrintStrangeTreeLine(width, curNode);
			--needToPrint;
			if (curNode) {
				q.push(curNode->left);
				q.push(curNode->right);
			}
			else {
				q.push(nullptr);
				q.push(nullptr);
			}
			if (needToPrint == 0) {
				onLine *= 2;
				needToPrint = onLine;
				std::cout << std::endl;
			}
			if (onLine == 16)
				break;
		}
		std::cout << std::endl;
		std::cout << std::setfill('.') << std::setw(120) << " " << std::endl;
		std::cout.fill(' ');
		std::cout << std::endl;
	}

private:

	/*** TREE ***/

	_t_node *_createEmptyNode() {
		_t_node *newNode = _alloc_rebind.allocate(1);
		newNode->color = _color_black;
		newNode->right = nullptr;
		newNode->left = nullptr;
		newNode->parent = nullptr;
		newNode->data = nullptr;
		return newNode;
	}

	_t_node *_createNode(_t_node *parent, const value_type & val, bool color) {
		_t_node *newNode = _alloc_rebind.allocate(1);
		newNode->color = color;
		newNode->right = nullptr;
		newNode->left = nullptr;
		newNode->parent = parent;
		newNode->data = _alloc.allocate(1);
		_alloc.construct(newNode->data, val);
		return newNode;
	}

	bool	_isRed(_t_node* h) {
		if (h == nullptr)
			return _color_black;
		return h->color == _color_red;
	}

	_t_node*	_rotateLeft(_t_node* h) {
		h->right->parent = h->parent;
		h->parent = h->right;
		if (h->right->left) h->right->left->parent = h;
		_t_node *tmp = h->right->left;
		h->right->left = h;
		h->right = tmp;
		h->parent->color = h->color;
		h->color = _color_red;
		if (h == _root)
			_root = h->parent;
		return h->parent;
	}

	_t_node*	_rotateRight(_t_node* h) {
		h->left->parent = h->parent;
		h->parent = h->left;
		if (h->left->right) h->left->right->parent = h;
		_t_node *tmp = h->left->right;
		h->left->right = h;
		h->left = tmp;
		h->parent->color = h->color;
		h->color = _color_red;
		if (h == _root)
			_root = h->parent;
		return h->parent;
	}

	void	_invertColors(_t_node* h) {
		h->right->color = !h->right->color;
		h->left->color = !h->left->color;
		h->color = !h->color;
	}

	_t_node	*_fixUp(_t_node* h) {
		if (h->right && _isRed(h->right))
			h = _rotateLeft(h);
		if (h->left && h->left->left && _isRed(h->left) && _isRed(h->left->left))
			h = _rotateRight(h);
		if (h->left && h->right && _isRed(h->left) && _isRed(h->right))
			_invertColors(h);
		if (h == _root && _root->color == _color_red)
			_root->color = _color_black;
		return h;
	}

//	_t_node	*_fixUp(_t_node* h) {
//		std::cout << "fixUP" << std::endl;
//		_dPrintStrangeTree(h);
//		if (h->right && _isRed(h->right))
//			h = _rotateLeft(h);
//		std::cout << "fixUP" << std::endl;
//		_dPrintStrangeTree(h);
//		std::cout << "root" << std::endl;
//		_dPrintStrangeTree(_root);
//		if (h->left && h->left->left && _isRed(h->left) && _isRed(h->left->left))
//			h = _rotateRight(h);
//		std::cout << "fixUP" << std::endl;
//		_dPrintStrangeTree(h);
//		if (h->left && h->right && _isRed(h->left) && _isRed(h->right))
//			_invertColors(h);
//		std::cout << "fixUP" << std::endl;
//		_dPrintStrangeTree(h);
//		if (h == _root && _root->color == _color_red)
//			_root->color = _color_black;
//		std::cout << "fixUP" << std::endl;
//		_dPrintStrangeTree(h);
//		return h;
//	}

	_t_node *_treeInsert(_t_node *h, const value_type & val) {
//		std::pair<_t_node*, bool> ret;
		_t_node *tmp;

		if (_root == nullptr) {
			_root = _createNode(nullptr, val, _color_black);
			_root->left = _begin_node;
			_root->right = _end_node;
			_begin_node->parent = _root;
			_end_node->parent = _root;
			return _root;
		}

		bool less = _comp(val.first, h->data->first);
		bool greater = _comp(h->data->first, val.first);

		if (!less && !greater) {
			return h; // do not make node, just return this (h.first, false)
		}

		if (less && (h->left == nullptr || h->left == _begin_node)) {
			tmp = _createNode(h, val, _color_red);
			if (h->left == _begin_node) {
				tmp->left = _begin_node;
				_begin_node->parent = tmp;
			}
			h->left = tmp;
		}
		else if (greater && (h->right == nullptr || h->right == _end_node)) {
			tmp = _createNode(h, val, _color_red);
			if (h->right == _end_node) {
				tmp->right = _end_node;
				_end_node->parent = tmp;
			}
			h->right = tmp;
		}
		else if (less) {
			h->left = _treeInsert(h->left, val);
		}
		else {
			h->right = _treeInsert(h->right, val);
		}
		h = _fixUp(h);
		return h;// here we should return h and true or false
	}

};

#endif
