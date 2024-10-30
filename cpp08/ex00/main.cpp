#include "easyfind.hpp"

int main(){
    
    std::vector<int> vec;
    std::list<int> list;
    for(int i = 0; i <= 42; i++){
        vec.push_back(i);
        list.push_back(i+42);}
        
    try{
    easyfind(vec, 42);
    easyfind(list, 84);
    easyfind(vec, 84);
    }
    catch (const NotFind &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}