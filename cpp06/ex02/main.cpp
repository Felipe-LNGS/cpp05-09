#include "Base.hpp"

int main(){
   Base* base = Base::generate();
    base->identify(base);
    base->identify(*base);

    delete base;
    return 0;
}