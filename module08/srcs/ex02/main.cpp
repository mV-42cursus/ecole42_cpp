#include <iostream>
#include "MutantStack.hpp"
#include "vector"

int main() 
{
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
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::stack<int> s(mstack);
        std::cout << "=============================================" << std::endl;
		std::vector<int> vector(mstack.begin(), mstack.end());
		std::vector<int>::iterator it2 = vector.begin();
		std::vector<int>::iterator ite2 = vector.end();
        ++it2;
        --it2;
        while (it2 != ite2)
        {
            std::cout << *it2 << std::endl;
            ++it2;
        }
    }
    {
        MutantStack<int> mstack;

        // Pushing elements into the stack
        mstack.push(5);
        mstack.push(17);
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        // Normal iterator
        std::cout << "Stack content (normal iterator): ";
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        // Const iterator
        std::cout << "Stack content (const iterator): ";
        const MutantStack<int> constMstack(mstack); // Create a const instance to use const_iterator
        for (MutantStack<int>::const_iterator cit = constMstack.cbegin(); cit != constMstack.cend(); ++cit) {
            std::cout << *cit << " ";
        }
        std::cout << std::endl;

        // Reverse iterator
        std::cout << "Stack content (reverse iterator): ";
        for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
            std::cout << *rit << " ";
        }
        std::cout << std::endl;

        // Const reverse iterator
        std::cout << "Stack content (const reverse iterator): ";
        for (MutantStack<int>::const_reverse_iterator crit = constMstack.crbegin(); crit != constMstack.crend(); ++crit) {
            std::cout << *crit << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}