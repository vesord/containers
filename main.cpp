#include <iostream>
#include <vector>
#include "list.hpp"

int main()
{
	ft::list<int> l1;

	l1.push_front(2);
	l1.push_front(3);

	ft::list<int>::iterator it;
	ft::list<int>::iterator ite = l1.end();
	for (it = l1.begin(); it != ite; ++it)
		std::cout << *it << std::endl;
}
