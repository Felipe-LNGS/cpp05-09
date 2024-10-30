#include "MutantStack.hpp"
template <typename Container>
void testContainer() {
    Container container;
    container.push_back(5); // ajout a la fin du container
    container.push_back(17);// ajout a la fin du container
    std::cout << "last element : " << container.back() << std::endl;//affichage du dernier element
    container.pop_back();//suppresion du derrnier element et modifie la taille du container
    std::cout << "size : "<<container.size() << std::endl;
    container.push_back(3);
    container.push_back(5);
    container.push_back(737);
    container.push_back(0);
    typename Container::iterator it = container.begin();
    typename Container::iterator ite = container.end();
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    std::cout << "size : "<<container.size() << std::endl;

}

int main(){
    std::cout << "\nTesting Mutant stack:" << std::endl<< std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size : "<< mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << " ";
    ++it;
    }
    std::cout << std::endl;
    std::cout << "size : "<<mstack.size() << std::endl;
    std::stack<int> s(mstack);

    std::cout << "\nTesting std::vector:" << std::endl<< std::endl;;
    testContainer<std::vector<int> >();

    std::cout << "\nTesting std::list:" << std::endl<< std::endl;;
    testContainer<std::list<int> >();
return 0;
}