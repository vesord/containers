#include <iostream>
#include <vector>
//#include <list>
#include "list.hpp"

int main()
{
	ft::list<int> ftList;
	for (int i = 0; i < 10; ++i)
		ftList.push_front(i);

	typedef ft::list<int>::const_iterator (ft::list<int>::* foo1)() const;
	foo1 objFoo = &ft::list<int>::begin;

	ft::list<int>::const_iterator fIt = (ftList.*objFoo)();
}
