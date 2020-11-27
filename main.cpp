//#include <iostream>
#include <vector>
#include <list>
#include "list.hpp"
#include "vector.hpp"
#include "map.hpp"

#include <map>
#include <string>


int main ()
{
//	std::map<std::string, int> sRef, s;
//	ft::map<std::string, int>  fRef, f;

//	for (int i = 0; i < 10; ++i) {
//		sRef.insert(std::make_pair(std::to_string(i), i));
//		fRef.insert(std::make_pair(std::to_string(i), i));
//	}
//	f = fRef;
//	s = sRef;
//
//	f._dPrintStrangeTree();
//
//	f.erase(++f.begin(), --f.end());
//	s.erase(++s.begin(), --s.end());
//
//	f._dPrintStrangeTree();



	ft::map<char, int>  fRef, f;

	f.insert(std::make_pair('0', 0));
//	f.insert(std::make_pair('7', 7));
	f.insert(std::make_pair('8', 8));
	f.insert(std::make_pair('9', 9));

	f._dPrintStrangeTree();

	f.erase('8');

	f._dPrintStrangeTree();





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




//	ft::map<char, int> ftmap;
//	ft::map<std::string, int> ftmapstr;
//	ft::map<char,int>::iterator it;
//
//	ftmap.insert(std::make_pair('a', 123));
//	ftmap.insert(std::make_pair('b', 123));
//	ftmap.insert(std::make_pair('c', 123));
//	ftmap.insert(std::make_pair('d', 123));
//	ftmap.insert(std::make_pair('e', 123));
//	ftmap.insert(std::make_pair('f', 123));
//	ftmap.insert(std::make_pair('g', 123));
//	ftmap.insert(std::make_pair('h', 123));
//	ftmap.insert(std::make_pair('j', 123));
//	ftmap.insert(std::make_pair('k', 123));
//
//	ftmap._dPrintStrangeTree();
//
//	it = ftmap.find('c');
//	std::cout << "before " << it->first << std::endl;
//	ftmap.erase(ftmap.find('b'));
//
//	std::cout << "after " << it->first << std::endl;
//	ftmap._dPrintStrangeTree();

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
