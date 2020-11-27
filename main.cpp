//#include <iostream>
#include <vector>
#include <list>
#include "list.hpp"
#include "vector.hpp"
#include "map.hpp"

#include <map>
#include <string>

//typedef struct strange_tree {
//	int					data;
//	struct strange_tree	*left;
//	struct strange_tree	*right;
//	struct strange_tree	*parent;
//	bool				color;
//}	t_ref_tree;

//t_ref_tree &rotRight(t_ref_tree & h) {
//	t_ref_tree *x = h.right;
//	h.right = x->left;
//	x->left = &h;
//	x->color;
//	return h;
//}
//
//class StrangeIterator {
//public:
//	StrangeIterator();
//	~StrangeIterator();
//	StrangeIterator( t_ref_tree & ptr) : _ref(ptr) {}
//
//private:
//	strange_tree & _ref;
//
//};

int main ()
{
//	t_ref_tree *leftPtr = new t_ref_tree;
//	t_ref_tree *rightPtr = new t_ref_tree;
//	t_ref_tree *rootPtr = new t_ref_tree;
//	rootPtr->data = 1;
//	rootPtr->left = leftPtr;
//	rootPtr->right = leftPtr;
//	rootPtr->parent = nullptr;
//
//	leftPtr->data = 2;
//	leftPtr->left = nullptr;
//	leftPtr->right = nullptr;
//	leftPtr->parent = rootPtr;
//
//	rightPtr->data = 3;
//	rightPtr->left = nullptr;
//	rightPtr->right = nullptr;
//	rightPtr->parent = rootPtr;
//
//	StrangeIterator itRoot(*rootPtr);
//	StrangeIterator itLeft(*leftPtr);
//	StrangeIterator itRight(*rightPtr);
//
//	t_ref_tree & root = *rootPtr;









//	std::map<char,int> mymap;
//	std::map<char,int>::iterator it = mymap.begin();
//	std::map<char,int>::iterator ite = mymap.end();
//
//	mymap.insert(std::make_pair('b', 123));
//	mymap.insert(std::make_pair('d', 123));
//	mymap.insert(std::make_pair('e', 123));
//	mymap.insert(std::make_pair('f', 123));
//	mymap.insert(std::make_pair('g', 123));
//
//	mymap.erase(mymap.begin(), mymap.end());




	ft::map<char, int> ftmap;
	ft::map<std::string, int> ftmapstr;
	ft::map<char,int>::iterator it;

	ftmap.insert(std::make_pair('a', 123));
	ftmap.insert(std::make_pair('b', 123));
	ftmap.insert(std::make_pair('c', 123));
	ftmap.insert(std::make_pair('d', 123));
	ftmap.insert(std::make_pair('e', 123));
	ftmap.insert(std::make_pair('f', 123));
	ftmap.insert(std::make_pair('g', 123));
	ftmap.insert(std::make_pair('h', 123));
	ftmap.insert(std::make_pair('j', 123));
	ftmap.insert(std::make_pair('k', 123));

	ftmap._dPrintStrangeTree();

	it = ftmap.find('c');
	std::cout << "before " << it->first << std::endl;
	ftmap.erase(ftmap.find('b'));

	std::cout << "after " << it->first << std::endl;
	ftmap._dPrintStrangeTree();

//	std::cout << it->first << std::endl;
//	ftmap.insert(std::make_pair('h', 123));

//	ftmap.erase('c');
//	ftmap._dPrintStrangeTree();

//	for (int i = 0; i < 11; ++i) {
//		ftmapstr.insert(std::make_pair(std::to_string(i), i));
//		ftmapstr._dPrintStrangeTree();
//	}

//	ft::map<char, int>::_t_node *root;
//
//	root = ftmap._returnRoot();
//
//	printStrangeTree(root);

	return 0;
}


// TRUE MAIN

/*int main()
{
//	ft::list<int> ftList;
//	for (int i = 0; i < 10; ++i)
//		ftList.push_front(i);
//
//	typedef ft::list<int>::const_iterator (ft::list<int>::* foo1)() const;
//	foo1 objFoo = &ft::list<int>::begin;
//
//	ft::list<int>::const_iterator fIt = (ftList.*objFoo)();


*//*	LIST COMPILES	*//*

	ft::list<std::string> f;

	f.push_back("It ");
	f.push_back("compiles ");
	f.push_back("successfully! ");
	f.push_back("Go ");
	f.push_back("check ");
	f.push_back("unit ");
	f.push_back("tests!");

	ft::list<std::string>::iterator it;
	ft::list<std::string>::iterator ite = f.end();
	for (it = f.begin(); it != ite; ++it) {
		std::cout << *it;
	}

*//*	VECTOR COMPILES	*//*
	ft::vector<int> v;
	std::vector<std::string> s;
	s.push_back(std::to_string(1));
	s.push_back(std::to_string(2));
//	s.push_back(std::to_string(3));
//	std::vector<int>::iterator its = ++s.begin();

//	s.clear();
	std::cout << s.size() << std::endl;
	std::cout << s.capacity() << std::endl;
//	s.push_front(3);
}*/
