#include <iostream>
#include <list>

#include "MutantStack.hpp"

int main()
{
	std::cout << "----------- TEST0 -----------" << std::endl;
	{
		MutantStack<int> mstack;
		std::list<int> lstack;

		std::list<int> *p = &lstack;


		mstack.push(5);
		lstack.push_back(5);
		mstack.push(17);
		lstack.push_back(17);

		std::cout << "mstack.top(): " << mstack.top() << std::endl;
		std::cout << "lstack.back(): " << lstack.back() << std::endl;

		mstack.pop();
		lstack.pop_back();

		std::cout << "mstack.size(): " << mstack.size() << std::endl;
		std::cout << "lstack.size(): " << lstack.size() << std::endl;

		mstack.push(3);
		lstack.push_back(3);
		mstack.push(5);
		lstack.push_back(5);
		mstack.push(737);
		lstack.push_back(737);
		mstack.push(0);
		lstack.push_back(0);

		
		std::cout << *p << std::endl;
		p++;
		std::cout << *p << std::endl;
		p++;
		std::cout << *p << std::endl;
		p++;
		std::cout << *p << std::endl;
		p++;
		MutantStack<int> mstack2(mstack);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		std::list<int>::iterator lit = lstack.begin();
		std::list<int>::iterator lite = lstack.end();
		MutantStack<int>::iterator it2 = mstack2.begin();
		MutantStack<int>::iterator ite2 = mstack2.end();

		++it;
		--it;
		std::cout << "mstack: ";
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		std::cout << "lstack: ";
		while (lit != lite)
		{
			std::cout << *lit << " ";
			++lit;
		}
		std::cout << std::endl;
		std::cout << "mstack2: ";
		while (it2 != ite2)
		{
			std::cout << *it2 << " ";
			++it2;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "----------- TEST1 -----------" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::reverse_iterator it = mstack.rbegin();
		MutantStack<int>::reverse_iterator ite = mstack.rend();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}
	return 0;
}