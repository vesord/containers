//#include <iostream>
#include <vector>
#include <list>
#include "list.hpp"
#include "vector.hpp"

int main()
{


//	ft::list<int> ftList;
//	for (int i = 0; i < 10; ++i)
//		ftList.push_front(i);
//
//	typedef ft::list<int>::const_iterator (ft::list<int>::* foo1)() const;
//	foo1 objFoo = &ft::list<int>::begin;
//
//	ft::list<int>::const_iterator fIt = (ftList.*objFoo)();


/*	LIST COMPILES	*/

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

/*	VECTOR COMPILES	*/
	ft::vector<int> v;
	std::vector<int> s;
	s.push_back(1);
	s.push_back(2);
	s.push_back(3);
//	std::vector<int>::iterator its = ++s.begin();

	s.clear();
	std::cout << s.size() << std::endl;
	std::cout << s.capacity() << std::endl;
//	s.push_front(3);
}
