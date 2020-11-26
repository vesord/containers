//#include <iostream>
#include <vector>
#include <list>
#include "list.hpp"
#include "vector.hpp"
#include "map.hpp"

#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <iomanip>
#include <queue>

// map::lower_bound/upper_bound
#include <iostream>
#include <map>

//template < class T, class U >
//std::ostream & operator<<(std::ostream & o, std::pair<T, U> p) {
//	o << p.first << " => " << p.second;
//	return o;
//}
//
//void	printStrangeTreeLine(int width, ft::map<char, int>::_t_node* curNode) {
//	std::stringstream ss;
//	std::string str;
//
//	std::cout.width(width);
//	if (curNode && curNode->data) {
//		ss << *(curNode->data);
//		str = ss.str();
//		if (curNode->color) {
//			str = RED_NODE_OUTPUT(ss.str());
//			width += 11;
//		}
//		std::cout << std::setw(width) << str ;
//	}
//	else if (curNode)
//		std::cout << "__edge__";
//	else
//		std::cout << "__null__";
//}
//
//void	printStrangeTree(ft::map<char, int>::_t_node* root)
//{
//	std::queue<ft::map<char, int>::_t_node *> q;
//	ft::map<char, int>::_t_node * curNode;
//	bool printTime;
//	int onLine = 1;
//	int needToPrint = 1;
//	int widthSt = 128;
//	int width;
//
//	q.push(root);
//	while (!q.empty()) {
//		curNode = q.front();
//		q.pop();
//		printTime = onLine == needToPrint;
//		width = printTime ? (widthSt / onLine / 2) : (widthSt / onLine);
//		printStrangeTreeLine(width, curNode);
//		--needToPrint;
//		if (curNode) {
//			q.push(curNode->left);
//			q.push(curNode->right);
//		}
//		else {
//			q.push(nullptr);
//			q.push(nullptr);
//		}
//		if (needToPrint == 0) {
//			onLine *= 2;
//			needToPrint = onLine;
//			std::cout << std::endl;
//		}
//		if (onLine == 16)
//			break;
//	}
//	std::cout << std::endl;
//	std::cout << std::setfill('.') << std::setw(120) << " " << std::endl;
//	std::cout.fill(' ');
//	std::cout << std::endl;
//}

int main ()
{
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

	ftmap.erase(ftmap.find('b'), ftmap.find('e'));

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
