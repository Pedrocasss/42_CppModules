#include "MutantStack.hpp"

int main()
{
    std::cout << "----------SUBJECT MAIN----------\n";
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
    //Aqui ele mostra os elementos da stack em ordem inversa.
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "----------MY MAIN----------\n";
    MutantStack<int> mstack2;
    mstack2.push(5);
    mstack2.push(17);
    std::cout << "TOP : " << mstack2.top() << std::endl;
    mstack2.pop();
    std::cout << "STACK SIZE AFTER REMOVING THE FIRST ELEMENT: " << mstack2.size() << std::endl;
    mstack2.push(3);
    mstack2.push(5);
    mstack2.push(737);
    mstack2.push(0);
    std::cout << "Stack elements in reverse order (STACK): " << mstack2 << std::endl;
    MutantStack<int>::iterator it2 = mstack2.begin();
    MutantStack<int>::iterator ite2 = mstack2.end();
    --ite2;
    std::cout << "Stack elements in order (STACK): " << std::endl;
    while (ite2 >= it2)
    {
        std::cout << *ite2 << std::endl;
        --ite2;
    }
    std::cout << "----------SUBJECT MAIN WITH STD::LIST-----------" << std::endl;
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    //[...]
    mlist.push_back(0);
    std::list<int>::iterator it3 = mlist.begin();
    std::list<int>::iterator ite3 = mlist.end();
    ++it3;
    --it3;
    //Aqui ele mostra os elementos da lista em ordem.
    while (it3 != ite3)
    {
        std::cout << *it3 << std::endl;
        ++it3;
    }
    return 0;
}
