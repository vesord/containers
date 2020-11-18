//#include <iostream>
//#include <vector>
//#include <list>
#include "list.hpp"
//#include "vector.hpp"

int main()
{
	ft::list<int> ftList;
	for (int i = 0; i < 10; ++i)
		ftList.push_front(i);

	typedef ft::list<int>::const_iterator (ft::list<int>::* foo1)() const;
	foo1 objFoo = &ft::list<int>::begin;

	ft::list<int>::const_iterator fIt = (ftList.*objFoo)();

//	typedef void (ft::list<int>::* fooInsert)(ft::list<int>::const_iterator, ft::iterator<in>)

//	ft::list<std::string> f;
//
//	f.push_back("It ");
//	f.push_back("compiles ");
//	f.push_back("successfully! ");
//	f.push_back("Go ");
//	f.push_back("check ");
//	f.push_back("unit ");
//	f.push_back("tests!");
//
//	ft::list<std::string>::iterator it;
//	ft::list<std::string>::iterator ite = f.end();
//	for (it = f.begin(); it != ite; ++it) {
//		std::cout << *it;
//	}
//
//	f.insert(f.begin(), ++f.begin(), --f.end());
//
//	std::cout << std::endl;

//	ft::vector<int> vf;

//	std::vector<int> v;
//
//	std::cout << v.capacity() << v.size() << std::endl;
//	v.push_back(54);
//	std::cout << v.capacity() << v.size() << std::endl;
//	v.push_back(42);
//	std::cout << v.capacity() << v.size() << std::endl;
//	v.push_back(42);
//	std::cout << v.capacity() << v.size() << std::endl;
//	std::vector<int>::iterator it = v.begin();
//	std::vector<int>::iterator ite = v.end();
//
//	std::cout << *it++ << ' ';
//	std::cout << *it++ << ' ';
//	std::cout << *it++ << ' ';
//	std::cout << *it++ << ' ';
//	std::cout << *it++ << ' ';
//	std::cout << *it++ << ' ';
//	std::cout << *it++ << ' ';
//	std::cout << std::endl;
//	std::cout << *ite;
}
